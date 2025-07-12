
module ysyx_25040129_CSR (
	input clk,
	input csr_write,
	input [11:0] csr_addr,
	input [31:0] csr_data,
	output reg [31:0] csr_out,
	input ecall,
	input [31:0] mepc_data,
	input [31:0] mcause_data,
	output reg [31:0] mtvec,
	output reg [31:0] mepc
);
	reg [31:0] mstatus;
	reg [31:0] mcause;
	always @(*) begin
		case (csr_addr)
			12'h300: csr_out = mstatus; // MSTATUS
			12'h305: csr_out = mtvec; // MTVEC
			12'h341: csr_out = mepc; // MEPC
			12'h342: csr_out = mcause; // MCAUSE
			default: csr_out = 32'b0;
		endcase
	end
	always @(posedge clk) begin
		if(ecall)begin
			mepc <= mepc_data;
			mcause <= mcause_data;
		end
		else begin
				if (csr_write) begin
					case (csr_addr)
						12'h300: mstatus <= csr_data; // MSTATUS
						12'h305: mtvec <= csr_data; // MTVEC
						12'h341: mepc <= csr_data; // MEPC
						12'h342: mcause <= csr_data; // MCAUSE
					default: begin end
					endcase
				end
		end
	end
endmodule
