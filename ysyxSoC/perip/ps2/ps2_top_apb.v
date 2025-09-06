module ps2_top_apb(
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

  input         ps2_clk,
  input         ps2_data
);

	wire is_nege;
	reg[8:0]data;
	reg[7:0]buffer[7:0];
	reg[2:0]buffer_cnt;
	reg[2:0]datacnt;
	reg[2:0] state,next_state;
	reg[1:0]apb_state,apb_next_state;
	reg[2:0]ps2_record;
	parameter WAIT0=0,WAITDATA=1,WAITPARITY=2,WAITSTOP=3,RECVED=4;
	parameter IDLE=0,READ=1,DONE=2;
	always @(posedge clock) begin
		ps2_record <= {ps2_record[1:0],ps2_clk};
	end
	assign is_nege = ps2_record[2]&~ps2_record[1];

	always @(*) begin
		case (state)
			WAIT0:next_state=(ps2_data)?WAIT0:WAITDATA;
			WAITDATA:next_state=(datacnt==3'b111)?WAITPARITY:WAITDATA;
			WAITPARITY:next_state=(^ps2_record)?WAITSTOP:WAIT0;
			WAITSTOP:next_state=ps2_data?RECVED:WAIT0;
			RECVED:next_state=ps2_data?WAIT0:WAITDATA;
			default: next_state=WAIT0;
		endcase
	end

	always @(*) begin
		case (apb_state)
			IDLE:apb_next_state = (in_psel && !in_penable && !in_pwrite) ? READ :  IDLE;
			READ:apb_next_state = (state == RECVED&&is_nege) ?READ  :DONE ;
			DONE:apb_next_state = IDLE;
		endcase
	end

	always @(posedge clock) begin
		if(reset)apb_state <= IDLE;
		else apb_state <= apb_next_state;
	end

	always @(posedge clock) begin
		if(apb_state == DONE)begin 
			buffer_cnt <= (buffer_cnt == 0)?0 : buffer_cnt - 1;
			if(buffer_cnt!=0)
			buffer[0] <= buffer[1];
			buffer[1] <= buffer[2];
			buffer[2] <= buffer[3];
			buffer[3] <= buffer[4];
			buffer[4] <= buffer[5];
			buffer[5] <= buffer[6];
			buffer[6] <= buffer[7];
		end
	end

	assign in_prdata = buffer_cnt == 0 ? 32'h00 :{24'b0, buffer[0]};
	assign in_pready = (apb_state == DONE);
	assign in_pslverr = 1'b0;

	always @(posedge clock) begin
		if(reset)begin
			data <= 9'b0;
			buffer_cnt <= 3'b0;
			datacnt <= 3'b0;
			state <= WAIT0;
		end

		 else 
		if(is_nege)begin
			state<=next_state;
			if(state == WAITDATA || state == WAITPARITY)data<={ps2_data,data[8:1]};
			if(state == WAITDATA)datacnt <= (datacnt+3'b1);
			else datacnt <= 3'b0;
			if (state == RECVED) begin 
				buffer[buffer_cnt] <= data[7:0];
				buffer_cnt <= buffer_cnt + 1;
			end
		end
		else begin
			if (state == RECVED) begin 
				buffer[buffer_cnt] <= data[7:0];
				buffer_cnt <= buffer_cnt + 1;
				state <= WAIT0;
			end
		end
	end
	

endmodule

