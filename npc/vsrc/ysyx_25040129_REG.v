module ysyx_25040129_REG (
	input clk,
	input rst,
	input [4:0] rd,
	input reg_write,
	input [31:0] result,
	input [4:0] src1_id,
	input [4:0] src2_id,
	output [31:0] src1,
	output [31:0] src2
);
	reg [511:0] regs;
	
	
	assign src1 =  regs[src1_id*32 +: 32];
	assign src2 =  regs[src2_id*32 +: 32];
	always @(*) begin
		`ifdef DEBUG
		update_regs(
			regs[0*32 +: 32],
			regs[1*32 +: 32], 
			regs[2*32 +: 32], 
			regs[3*32 +: 32], 
			regs[4*32 +: 32], 
			regs[5*32 +: 32], 
			regs[6*32 +: 32], 
			regs[7*32 +: 32], 
			regs[8*32 +: 32], 
			regs[9*32 +: 32], 
			regs[10*32 +: 32], 
			regs[11*32 +: 32], 
			regs[12*32 +: 32], 
			regs[13*32 +: 32], 
			regs[14*32 +: 32], 
			regs[15*32 +: 32]
		);
		`endif
	end
	always @(posedge clk) begin
		
		if (rst) regs <= 512'b0;
		 else begin
			if (rd != 5'b00000 && reg_write) begin
				regs[rd*32 +:32] <=result;
			end
		end
	end
endmodule
