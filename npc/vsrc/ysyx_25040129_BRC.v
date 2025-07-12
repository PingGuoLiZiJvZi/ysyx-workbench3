
module ysyx_25040129_BRC (
	input [31:0] pc,
	input [31:0] src1,
	input [31:0] src2,
	input [2:0] funct3,
	input [31:0] imm,
	input [6:0] opcode,
	output reg is_branch,
	output reg [31:0] branch_target
);
always @(*)begin
	case (opcode)
		7'b1100011: begin // B-type
			case (funct3)
				3'b000: is_branch = (src1 == src2); // BEQ
				3'b001: is_branch = (src1 != src2); // BNE
				3'b100: is_branch = ($signed(src1) < $signed(src2)); // BLT
				3'b101: is_branch = ($signed(src1) >= $signed(src2)); // BGE
				3'b110: is_branch = (src1 < src2); // BLTU
				3'b111: is_branch = (src1 >= src2); // BGEU
				default: begin is_branch = 0;
				end
			endcase
			branch_target = imm + pc;
		end
		7'b1101111: begin // JAL
			is_branch = 1;
			branch_target = imm + pc;
		end
		7'b1100111: begin // JALR
			is_branch = 1;
			branch_target = (src1 + imm) & 32'hfffffffe;
		end
		default: begin
			is_branch = 0;
			branch_target = 32'h00000000;
		end
	endcase
end
endmodule
