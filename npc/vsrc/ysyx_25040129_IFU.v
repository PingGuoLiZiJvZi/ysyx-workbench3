module ysyx_25040129_IFU (
	input [31:0] pc,
	output reg[31:0] next_pc,
	input is_branch,
	input mret,
	input ecall,
	input [31:0] jump_target,
	input [31:0] mepc,
	input [31:0] mtvec,
	output reg[31:0] inst
);
assign inst = (pc==32'h0)?paddr_read(32'h80000000,4,1,1):paddr_read(pc, 4,1,1);
always @(*) begin
	if(ecall)next_pc = mtvec;
	else if(mret)next_pc = mepc;
	else if(is_branch)next_pc = jump_target;
	else if(pc == 32'h0)next_pc = 32'h80000000;
	else next_pc = pc + 4;
end
endmodule
