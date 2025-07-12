module ysyx_25040129_ALU (
	input [31:0] pc,
	input [31:0] src1,
	input [31:0] src2,
	input [31:0] imm,
	/* verilator lint_off UNUSEDSIGNAL */
	input [6:0] funct7,
	/* verilator lint_on UNUSEDSIGNAL */
	input [2:0] funct3,
	input [6:0] opcode,
	output reg [31:0] result,
	input [31:0] read_data,
	input ebreak,
	input csr_read,
	input [31:0] csr_data
);	
	always @(*) begin
		case (opcode)
			7'b0000011: begin
				case (funct3)
					3'b000: result = {{24{read_data[7]}}, read_data[7:0]}; // LB
					3'b001: result = {{16{read_data[15]}}, read_data[15:0]}; // LH
					3'b010: result = read_data; // LW
					3'b100: result = {24'b0, read_data[7:0]}; // LBU
					3'b101: result = {16'b0, read_data[15:0]}; // LHU
					default: result = 32'b0;
				endcase
			end
			7'b0110111: result = imm;
			7'b0010111: result = imm + pc; // AUIPC
			7'b1110011: begin // ECALL/EBREAK
				if(ebreak)ebreak_trigger();
				if(csr_read)result = csr_data;
				else result = 32'b0;
			end
			7'b1101111: // JAL
				result = pc + 4;
			7'b1100111:  // JALRR
				result = pc + 4;
			7'b0010011: begin // I-type
				case (funct3)
					3'b000: result = src1 + imm; // ADDI
					3'b010: result = ($signed(src1) < $signed(imm)) ? 1 : 0; // SLTI
					3'b011: result = (src1 < imm) ? 1 : 0; // SLTIU
					3'b100: result = src1 ^ imm; // XORI
					3'b110: result = src1 | imm; // ORI
					3'b111: result = src1 & imm; // ANDI
					3'b001: result = src1 << imm[4:0]; // SLLI
					3'b101: begin // SRLI/SRAI
						if (funct7[5] == 0) begin
							result = src1 >> imm[4:0];
						end else begin
							result = $signed(src1) >>> imm[4:0];
						end
					end
				endcase
			end
			7'b0110011: begin // R-type
				case (funct3)
					3'b000: begin // ADD
						if (funct7[5] == 0) begin
							result = src1 + src2;
						end else begin
							result = src1 - src2;
						end
					end
					3'b001: result = src1 << src2[4:0]; // SLL
					3'b010: result = ($signed(src1) < $signed(src2)) ? 1 : 0; // SLT
					3'b011: result = (src1 < src2) ? 1 : 0; // SLTU
					3'b100: result = src1 ^ src2; // XOR
					3'b101: begin // SRL/SRA
						if (funct7[5] == 0) begin
							result = src1 >> src2[4:0];
						end else begin
							result = $signed(src1) >>> src2[4:0];
						end
					end
					3'b110: result = src1 | src2; // OR
					3'b111: result = src1 & src2; // AND
				endcase
			end
			default:begin
				result = 32'b0;
			end
		endcase
	end



endmodule
