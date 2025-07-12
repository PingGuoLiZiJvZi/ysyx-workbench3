module ysyx_25040129_REG (
	input clk,
	input rst,
	input [4:0] rd,
	input reg_write,
	input [31:0] result,
	input [4:0] src1_id,
	input [4:0] src2_id,
	output [31:0] src1,
	output [31:0] src2,
	output [511:0] regs_out
);
	reg [511:0] regs;
	assign regs_out = regs;
	assign src1 =  regs[src1_id*32 +: 32];
	assign src2 =  regs[src2_id*32 +: 32];
	always @(posedge clk) begin
		if (rst) regs <= 512'b0;
		 else begin
			if (rd != 5'b00000 && reg_write) begin
				regs[rd*32 +:32] <=result;
			end
		end
	end
endmodule
