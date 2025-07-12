import "DPI-C" function void ebreak_trigger();
import "DPI-C" function void unknown_inst(int inst);
import "DPI-C" function int paddr_read(int addr, int len,int is_fetch, int is_avail);
import "DPI-C" function void paddr_write(int addr, int len, int data, int is_avail);
/*verilator lint_off DECLFILENAME*/module ysyx_25040129_top(
	input clk,
	input rst,
	output [31:0] pc,
	output [31:0] inst,
	output [31:0][15:0] regs
);
	// wire [31:0] pc;
	// wire [31:0] inst;
	wire [4:0] src1_id;
	wire [31:0] src1 ;
	wire [4:0] src2_id;
	wire [31:0] src2 ;
	wire [31:0] imm;
	wire [31:0] result;
	wire [4:0] rd;
	wire [31:0] next_pc;
	wire [6:0] funct7;
	wire [2:0] funct3;
	wire [6:0] opcode;
	wire [31:0] jump_target;
	wire [31:0] mepc;
	wire [31:0] mtvec;
	wire is_branch;
	wire reg_write;
	wire mret;
	wire ecall;
	wire ebreak;
	wire csr_write;
	wire csr_read;
	wire [31:0] csr_data;
	wire [31:0] read_data;
	ysyx_25040129_REG u_ysyx_25040129_REG (
		.clk(clk),
		.rst(rst),
		.rd(rd),
		.regs_out(regs),
		.reg_write(reg_write),
		.result(result),
		.src1_id(src1_id),
		.src2_id(src2_id),
		.src1(src1),
		.src2(src2)
	);

	ysyx_25040129_PC u_ysyx_25040129_PC (
		.clk(clk),
		.rst(rst),
		.next_pc(next_pc),
		.pc(pc)
	);
	ysyx_25040129_IFU u_ysyx_25040129_IFU (
		.pc(pc),
		.inst(inst),
		.next_pc(next_pc),
		.mret(mret),
		.ecall(ecall),
		.mepc(mepc),
		.mtvec(mtvec),
		.is_branch(is_branch),
		.jump_target(jump_target)
	);

	ysyx_25040129_IDU u_ysyx_25040129_IDU (
		.inst(inst),
		.src1_id(src1_id),
		.src2_id(src2_id),
		.imm(imm),
		.rd(rd),
		.funct7(funct7),
		.funct3(funct3),
		.opcode(opcode),
		.reg_write(reg_write),
		.ecall(ecall),
		.ebreak(ebreak),
		.mret(mret),
		.csr_write(csr_write),
		.csr_read(csr_read)
	);

	ysyx_25040129_ALU u_ysyx_25040129_ALU (
		.src1(src1),
		.src2(src2),
		.imm(imm),
		.funct7(funct7),
		.funct3(funct3),
		.opcode(opcode),
		.result(result),
		.pc(pc),
		.read_data(read_data),
		.ebreak(ebreak),
		.csr_read(csr_read),
		.csr_data(csr_data)
	);

	ysyx_25040129_BRC u_ysyx_25040129_BRC (
		.pc(pc),
		.src1(src1),
		.src2(src2),
		.funct3(funct3),
		.imm(imm),
		.opcode(opcode),
		.is_branch(is_branch),
		.branch_target(jump_target)
	);

	ysyx_25040129_MEM u_ysyx_25040129_MEM (
		.opcode(opcode),
		.imm(imm),
		.src1(src1),
		.src2(src2),
		.funct3(funct3),
		.read_data(read_data)
	);

	ysyx_25040129_CSR u_ysyx_25040129_CSR (
		.clk(clk),
		.csr_write(csr_write),
		.csr_addr(imm[11:0]),
		.csr_data(src1),
		.csr_out(csr_data),
		.ecall(ecall),
		.mepc_data(pc),
		// .mstate_data(32'b0),
		.mcause_data(32'd11),
		.mtvec(mtvec),
		.mepc(mepc)
	);
endmodule/*verilator lint_on DECLFILENAME*/

