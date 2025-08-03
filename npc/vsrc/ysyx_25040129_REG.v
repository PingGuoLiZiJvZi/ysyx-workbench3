module ysyx_25040129_REG (
	input clk,
	input rst,
	input [`REGS_DIG-1:0] rd,
	input [`REGS_DIG-1:0] src1_id,
	input [`REGS_DIG-1:0] src2_id,
	input reg_write,
	input [31:0] result,
	output [31:0] src1,
	output [31:0] src2
);
	reg [31:0] regs[15:0];
	
	
	assign src1 =  regs[src1_id];
	assign src2 =  regs[src2_id];
	always @(*) begin
		`ifdef DEBUG
		update_regs(
			regs[0],
			regs[1], 
			regs[2], 
			regs[3], 
			regs[4], 
			regs[5], 
			regs[6], 
			regs[7], 
			regs[8], 
			regs[9], 
			regs[10], 
			regs[11], 
			regs[12], 
			regs[13], 
			regs[14], 
			regs[15]
		);
		`endif
	end
	always @(posedge clk) begin
		
		if (rst)  begin
            regs[0] <= 32'b0; 
        end
		 else begin
			if (rd != 4'b0000 && reg_write) begin
				regs[rd] <=result;
			end
		end
	end
endmodule
