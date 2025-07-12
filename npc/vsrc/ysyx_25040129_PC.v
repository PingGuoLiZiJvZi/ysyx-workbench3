
module ysyx_25040129_PC (
	input clk,
	input rst,
	input [31:0] next_pc,
	output reg[31:0] pc
);
always @(posedge clk)
		if(rst)pc <= 32'h80000000;
	 else pc <= next_pc;
endmodule
