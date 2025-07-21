/*
	Copyright 2020 Efabless Corp.

	Author: Mohamed Shalan (mshalan@efabless.com)

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at:
	http://www.apache.org/licenses/LICENSE-2.0
	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/

`timescale              1ns/1ps
`default_nettype        none

// Using EBH Command
module EF_PSRAM_CTRL_wb (
    // WB bus Interface
    input   wire        clk_i,
    input   wire        rst_i,
    input   wire [31:0] adr_i,
    input   wire [31:0] dat_i,
    output  wire [31:0] dat_o,
    input   wire [3:0]  sel_i,
    input   wire        cyc_i,
    input   wire        stb_i,
    output  wire        ack_o,
    input   wire        we_i,

    // External Interface to Quad I/O
    output  wire            sck,
    output  wire            ce_n,
    input   wire [3:0]      din,
    output  wire [3:0]      dout,
    output  wire [3:0]      douten
);

    localparam  TYPE0 = 4'b0000,
				TYPE1 = 4'b0001,
				TYPE2 = 4'b0010,
				TYPE3 = 4'b0011,
				TYPE4 = 4'b0100,
				TYPE5 = 4'b0101,
				TYPE6 = 4'b0110,
				TYPE7 = 4'b0111,
				ST_IDLE = 4'b1000,
				ST_WAIT = 4'b1001;

    wire        mr_sck;
    wire        mr_ce_n;
    wire [3:0]  mr_din;
    wire [3:0]  mr_dout;
    wire        mr_doe;

    wire        mw_sck;
    wire        mw_ce_n;
    wire [3:0]  mw_din;
    wire [3:0]  mw_dout;
    wire        mw_doe;

    // PSRAM Reader and Writer wires
    wire        mr_rd;
    wire        mr_done;
    wire        mw_wr;
    wire        mw_done;

    //wire        doe;

    // WB Control Signals
    wire        wb_valid        =   cyc_i & stb_i;
    wire        wb_we           =   we_i & wb_valid;
    wire        wb_re           =   ~we_i & wb_valid;
    //wire[3:0]   wb_byte_sel     =   sel_i & {4{wb_we}};

    // The FSM
    reg      [3:0]   state, nstate;
	reg delay = 0;
    always @ (posedge clk_i or posedge rst_i)
        if(rst_i)
		begin
			 state <= TYPE0;
		end
           
        else
            state <= nstate;

    always @* begin
        case(state)
			TYPE0 :nstate = (~ delay)? TYPE1:TYPE0;
			TYPE1 :nstate = (~ delay)? TYPE2:TYPE1;
			TYPE2 :nstate = (~ delay)? TYPE3:TYPE2;
			TYPE3 :nstate = (~ delay)? TYPE4:TYPE3;
			TYPE4 :nstate = (~ delay)? TYPE5:TYPE4;
			TYPE5 :nstate = (~ delay)? TYPE6:TYPE5;
			TYPE6 :nstate = (~ delay)? TYPE7:TYPE6;
			TYPE7 :nstate = (~ delay)? ST_IDLE:TYPE7;
            ST_IDLE :
                if(wb_valid)
                    nstate = ST_WAIT;
                else
                    nstate = ST_IDLE;

            ST_WAIT :
                if((mw_done & wb_we) | (mr_done & wb_re))
                    nstate = ST_IDLE;
                else
                    nstate = ST_WAIT;
			default :
				nstate = TYPE0; // Default state to avoid latches
        endcase
    end
	wire is_init = (state == TYPE0) | (state == TYPE1) | (state == TYPE2) |
					(state == TYPE3) | (state == TYPE4) | (state == TYPE5) |
					(state == TYPE6) | (state == TYPE7);
    wire [2:0]  size =  (sel_i == 4'b0001) ? 1 :
                        (sel_i == 4'b0010) ? 1 :
                        (sel_i == 4'b0100) ? 1 :
                        (sel_i == 4'b1000) ? 1 :
                        (sel_i == 4'b0011) ? 2 :
                        (sel_i == 4'b1100) ? 2 :
                        (sel_i == 4'b1111) ? 4 : 4;



    wire [7:0]  byte0 = (sel_i[0])          ? dat_i[7:0]   :
                        (sel_i[1] & size==1)? dat_i[15:8]  :
                        (sel_i[2] & size==1)? dat_i[23:16] :
                        (sel_i[3] & size==1)? dat_i[31:24] :
                        (sel_i[2] & size==2)? dat_i[23:16] :
                        dat_i[7:0];

    wire [7:0]  byte1 = (sel_i[1])          ? dat_i[15:8]  :
                        dat_i[31:24];

    wire [7:0]  byte2 = dat_i[23:16];

    wire [7:0]  byte3 = dat_i[31:24];

    wire [31:0] wdata = {byte3, byte2, byte1, byte0};

    /*
    wire [1:0]  waddr = (size==1 && sel_i[0]==1) ? 2'b00 :
                        (size==1 && sel_i[1]==1) ? 2'b01 :
                        (size==1 && sel_i[2]==1) ? 2'b10 :
                        (size==1 && sel_i[3]==1) ? 2'b11 :
                        (size==2 && sel_i[2]==1) ? 2'b10 :
                        2'b00;
                      */

    assign mr_rd    = ( (state==ST_IDLE ) & wb_re );
    assign mw_wr    = ( (state==ST_IDLE ) & wb_we );

    PSRAM_READER MR (
        .clk(clk_i),
        .rst_n(~rst_i),
        .addr({adr_i[23:2],2'b0}),
        .rd(mr_rd),
        //.size(size), Always read a word
        .size(3'd4),
        .done(mr_done),
        .line(dat_o),
        .sck(mr_sck),
        .ce_n(mr_ce_n),
        .din(mr_din),
        .dout(mr_dout),
        .douten(mr_doe)
    );

    PSRAM_WRITER MW (
        .clk(clk_i),
        .rst_n(~rst_i),
        .addr({adr_i[23:0]}),
        .wr(mw_wr),
        .size(size),
        .done(mw_done),
        .line(wdata),
        .sck(mw_sck),
        .ce_n(mw_ce_n),
        .din(mw_din),
        .dout(mw_dout),
        .douten(mw_doe)
    );
	reg wb_init_sck;
	// reg wb_init_ce_n;
	reg [3:0] wb_init_dout;
	always @ (posedge clk_i) begin
		if(delay)
					begin
						wb_init_sck <= 1'b1;
						delay <= 1'b0;
					end
				else
					begin
						wb_init_sck <= 1'b0;
						delay <= 1'b1;
					end
		case (state)
			TYPE0:begin
				wb_init_dout <= 4'b0000;
			end 
			TYPE1:begin

				wb_init_dout <= 4'b0000;
			end
			TYPE2:begin

				wb_init_dout <= 4'b0001;
			end
			TYPE3:begin

				wb_init_dout <= 4'b0001;
			end
			TYPE4:begin

				wb_init_dout <= 4'b0000;
			end
			TYPE5:begin

				wb_init_dout <= 4'b0001;
			end
			TYPE6:begin

				wb_init_dout <= 4'b0000;
			end
			TYPE7:begin

				wb_init_dout <= 4'b0001;
			end
			default: begin

				wb_init_dout <= 4'b0000;
			end
		endcase

	end
    assign sck  = (is_init)?wb_init_sck:wb_we ? mw_sck  : mr_sck;
    assign ce_n = (is_init)?1'b0:wb_we ? mw_ce_n : mr_ce_n;
    assign dout =(is_init)?wb_init_dout: wb_we ? mw_dout : mr_dout;
    assign douten  = (is_init)?4'b1111:wb_we ? {4{mw_doe}}  : {4{mr_doe}};

    assign mw_din = din;
    assign mr_din = din;
    assign ack_o = wb_we ? mw_done :mr_done ;
endmodule
