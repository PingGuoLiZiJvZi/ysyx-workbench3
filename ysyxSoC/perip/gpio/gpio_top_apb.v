module gpio_top_apb(
  input         clock,
  input         reset,
  input  [31:0] in_paddr,
  input         in_psel,
  input         in_penable,
  input  [2:0]  in_pprot,
  input         in_pwrite,
  input  [31:0] in_pwdata,
  input  [3:0]  in_pstrb,
  output        in_pready,
  output [31:0] in_prdata,
  output        in_pslverr,

  output reg[15:0] gpio_out,
  input  [15:0] gpio_in,
  output [7:0]  gpio_seg_0,
  output [7:0]  gpio_seg_1,
  output [7:0]  gpio_seg_2,
  output [7:0]  gpio_seg_3,
  output [7:0]  gpio_seg_4,
  output [7:0]  gpio_seg_5,
  output [7:0]  gpio_seg_6,
  output [7:0]  gpio_seg_7
);
//----------------译码--------------------
reg [3:0] gpio_seg_data [7:0];

wire [6:0] seg_raw [7:0]; 
genvar i;
generate
  for (i = 0; i < 8; i = i + 1) begin : gen_bcd_decoder
    BCD_to_7Seg decoder (
      .BCD(gpio_seg_data[i]),
      .hseg(seg_raw[i])
    );
  end
endgenerate
assign gpio_seg_0 = {1'b0, seg_raw[0]};
assign gpio_seg_1 = {1'b0, seg_raw[1]};
assign gpio_seg_2 = {1'b0, seg_raw[2]};
assign gpio_seg_3 = {1'b0, seg_raw[3]};
assign gpio_seg_4 = {1'b0, seg_raw[4]};
assign gpio_seg_5 = {1'b0, seg_raw[5]};
assign gpio_seg_6 = {1'b0, seg_raw[6]};
assign gpio_seg_7 = {1'b0, seg_raw[7]};
//----------------------------------------
assign in_pslverr = 1'b0; 
assign in_prdata[15:0] = gpio_in;
assign in_prdata[31:16] = 16'b0;
reg [1:0]state;
reg [1:0]next_state;
localparam IDLE = 2'b00;
localparam WRITE = 2'b01;
localparam READ = 2'b10;
localparam DONE = 2'b11;
reg [7:0] seg_decode_res;
always @(posedge clock) begin
	  if (reset) begin
	state <= IDLE;
  end else begin
	state <= next_state;
  end	
end

always @(*) begin
	case (state)
		IDLE: begin
			if (in_psel && !in_penable) begin
				if (in_pwrite) begin
					next_state = WRITE;
				end else begin
					next_state = READ;
				end
			end else begin
				next_state = IDLE;
			end
		end
		WRITE:  next_state = DONE;
		READ:   next_state = DONE;
		DONE:   next_state = IDLE;
	endcase
end
always @(posedge clock) begin
	case (state)
		IDLE:begin
			
		end
		READ:begin
			if(in_paddr != 32'h10002004)$error("gpio_top_apb: read from invalid address 0x%h", in_paddr);
		end  
		WRITE: begin
			if(in_paddr != 32'h10002000 && in_paddr != 32'h10002008)$error("gpio_top_apb: write to invalid address 0x%h", in_paddr);
			if(in_paddr == 32'h10002000)begin
				if(in_pstrb[0]) gpio_out[7:0] <= in_pwdata[7:0];
				if(in_pstrb[1]) gpio_out[15:8] <= in_pwdata[15:8];
			end
			else if(in_paddr == 32'h10002008) begin
				if(in_pstrb[0])begin
					gpio_seg_data[0] <= in_pwdata[3:0];
					gpio_seg_data[1] <= in_pwdata[7:4];
				end
				if(in_pstrb[1])begin
					gpio_seg_data[2] <= in_pwdata[11:8];
					gpio_seg_data[3] <= in_pwdata[15:12];
				end
				if(in_pstrb[2])begin
					gpio_seg_data[4] <= in_pwdata[19:16];
					gpio_seg_data[5] <= in_pwdata[23:20];
				end
				if(in_pstrb[3])begin
					gpio_seg_data[6] <= in_pwdata[27:24];
					gpio_seg_data[7] <= in_pwdata[31:28];
				end
			end
		end
		DONE: begin
			
		end
	endcase
end
assign in_pready = (state == DONE);
endmodule


module BCD_to_7Seg (
    input [3:0] BCD,        // 4位BCD码输入 理论上已经不是BCD了，是四位二进制数
	output reg [6:0] hseg
);

always @(*) begin
    case (BCD)
        4'h0 : hseg = 7'b0000001;
        4'h1 : hseg = 7'b1001111;
        4'h2 : hseg = 7'b0010010;
        4'h3 : hseg = 7'b0000110;
        4'h4 : hseg = 7'b1001100;
        4'h5 : hseg = 7'b0100100;
        4'h6 : hseg = 7'b0100000;
        4'h7 : hseg = 7'b0001111;
        4'h8 : hseg = 7'b0000000;
        4'h9 : hseg = 7'b0000100;
		4'ha : hseg = 7'b0001000;
		4'hb : hseg = 7'b1100000;
		4'hc : hseg = 7'b0110001;
		4'hd : hseg = 7'b1000010;
		4'he : hseg = 7'b0110000;
		4'hf : hseg = 7'b0111000;
    endcase
end

endmodule
