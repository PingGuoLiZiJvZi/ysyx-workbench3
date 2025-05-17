import "DPI-C" function int paddr_read(int addr, int len);
import "DPI-C" function void paddr_write(int addr, int len, int data);
module test (
	input [6:0] opcode,
	input [31:0] imm,
	input [31:0] src1,
	input [31:0] src2,
	input [2:0] funct3,
	output reg [31:0] read_data
);
wire [31:0] addr;
reg [2:0] write_len;
assign addr = src1 + imm;

always @(*) begin
	case (opcode)
		7'b0000011: begin // LOAD
			read_data = paddr_read(addr, 4);
		end
		7'b0100011: begin // STORE
			case (funct3)
				3'b000: begin // SB
					write_len = 1;
				end
				3'b001: begin // SH
					write_len = 2;
				end
				3'b010: begin // SW
					write_len = 4;
				end
				default: begin
					write_len = 0;
					unknown_inst(32'b0); // Unknown store instruction
				end
				 // Write data to memory
				endcase
			paddr_write(addr, {29'b0,write_len}, src2);
		end
		default: begin
		end
	endcase
end
	
endmodule
