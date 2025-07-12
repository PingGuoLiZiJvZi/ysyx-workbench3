//解码指令，准备好数据以及给EXU的控制信号
module ysyx_25040129_IDU (
	input [31:0] inst,
	output [4:0] src1_id,
	output [4:0] src2_id,
	output reg[31:0] imm,
	output [4:0] rd,
	output [6:0] funct7,
	output [2:0] funct3,
	output [6:0] opcode,
	output reg reg_write,
	output reg ecall,
	output reg ebreak,
	output reg mret,
	output reg csr_write,
	output reg csr_read
);
	assign funct7 = inst[31:25];
	assign funct3 = inst[14:12];
	assign opcode = inst[6:0];
	assign rd = inst[11:7];
	assign src1_id = inst[19:15];
	assign src2_id = inst[24:20];
	always @(*) begin
		reg_write = 1'b0;
		ecall = 1'b0;
		ebreak = 1'b0;
		mret = 1'b0;
		csr_write = 1'b0;
		csr_read = 1'b0;
		case (opcode)
			7'b0010011:begin
				 imm = {{20{inst[31]}},inst[31:20]};
				 reg_write = 1'b1;
			end // I-type immediate
			7'b1100011: begin 
				imm = {{20{inst[31]}},inst[7], inst[30:25], inst[11:8], 1'b0};
				reg_write = 1'b0;
			end// B-type branch
			7'b0000011: begin 
				imm = {{20{inst[31]}},inst[31:20]};
				reg_write = 1'b1;
			end // I-type load
			7'b0100011: begin
				imm = {{20{inst[31]}},inst[31:25],inst[11:7]}; // S-type store
				reg_write = 1'b0;
			end
			7'b1101111: begin 
				imm = {{12{inst[31]}},inst[19:12],inst[20],inst[30:21],1'b0}; // J-type jump
				reg_write = 1'b1;
			end
			7'b1100111: begin 
				imm = {{20{inst[31]}},inst[31:20]}; // JALR
				reg_write = 1'b1;
			end
			7'b1110011: begin
				imm = {{20{inst[31]}},inst[31:20]}; // I-type system
				reg_write = 1'b0;
				case (funct3)
					3'b000: begin
						case(inst[31:20])
							12'b000000000001:begin
								ebreak = 1'b1;
							end
							12'b001100000010:begin
								mret = 1'b1;
							end
							default: begin
								ecall = 1'b1;
							end
							
						endcase
						reg_write = 1'b0;
					end
					3'b001:begin
						csr_write = 1'b1;
						reg_write = 1'b0;
					end
					3'b010:begin
						csr_read = 1'b1;
						reg_write = 1'b1;
					end
					default: begin
						mret = 1'b0;
						reg_write = 1'b0;
					end
				endcase
			end
			7'b0110011: begin 
				imm = 32'b0; // R-type
				reg_write = 1'b1;
			end
			7'b0110111: begin 
				imm = {inst[31:12], 12'b0}; // LUI
				reg_write = 1'b1;
			end
			7'b0010111: begin 
				imm = {inst[31:12], 12'b0}; // AUIPC
				reg_write = 1'b1;
			end
			default: begin
				imm = 32'b0;
				reg_write = 1'b0;
				unknown_inst(inst); // Unknown instruction
			end
		endcase
	end
	
endmodule
