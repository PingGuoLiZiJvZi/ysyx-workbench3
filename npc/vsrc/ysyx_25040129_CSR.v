
module ysyx_25040129_CSR (
	input clk,
	input rst,	
	input csr_write,
	input [11:0] csr_read_addr,
	input [11:0] csr_write_addr,
	input [31:0] csr_data,
	output reg [31:0] csr_out,
	input ecall,
	input mret,
	input [31:0] mepc_data,
	input [31:0] mcause_data,
	output reg [31:0] target_from_csr
);
	reg [31:0] mepc;
	reg [31:0] mstatus;
	reg [31:0] mcause;
	reg [31:0] mtvec;
	reg [31:0] mvendorid;
	reg [31:0] marchid;
	always @(*) begin
		case (csr_read_addr)
			12'h114: csr_out = mvendorid; // MVENDORID
			12'h514: csr_out = marchid; // MARCHID
			12'h300: csr_out = mstatus; // MSTATUS
			12'h305: csr_out = mtvec; // MTVEC
			12'h341: csr_out = mepc; // MEPC
			12'h342: csr_out = mcause; // MCAUSE
			default: csr_out = 32'b0;
		endcase
		target_from_csr = ecall ? mtvec : mepc; 
	end
	always @(posedge clk) begin
		if (rst) begin
			mstatus <= 32'b0;
			mtvec <= 32'b0;
			mepc <= 32'b0;
			mcause <= 32'b0;
			mvendorid <= 32'h79737978; 
			marchid <= 32'd25040129;
		end
		else begin
			if(ecall)begin
				mepc <= mepc_data;
				mcause <= mcause_data;
				
			end
			else begin 
				if (mret) begin
					mepc <= mepc_data;
					
				end
			else begin
					if (csr_write) begin
						case (csr_write_addr)
							12'h114: mvendorid <= csr_data; // MVENDORID
							12'h514: marchid <= csr_data; // MARCHID
							12'h300: mstatus <= csr_data; // MSTATUS
							12'h305: mtvec <= csr_data; // MTVEC
							12'h341: mepc <= csr_data; // MEPC
							12'h342: mcause <= csr_data; // MCAUSE
						default: begin end
					endcase
				end
			end
		end
		end
	end
endmodule
