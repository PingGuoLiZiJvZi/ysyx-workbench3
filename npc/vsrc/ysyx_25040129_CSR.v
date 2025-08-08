
module CSR (
	input clk,
	input rst,	
	input csr_write,
	input [`CSR_DIG-1:0] csr_read_addr,
	input [`CSR_DIG-1:0] csr_write_addr,
	input [31:0] csr_data,
	output reg [31:0] csr_out
);
	reg [31:0] mepc;
	reg [31:0] mstatus;
	reg [31:0] mtvec;
	always @(*) begin
		case (csr_read_addr)
			`MVENDORID: csr_out = 32'h79737978; // MVENDORID
			`MARCHID: csr_out = 32'd25040129; // MARCHID
			`MSTATUS: csr_out = mstatus; // MSTATUS
			`MTVEC: csr_out = mtvec; // MTVEC
			`MEPC: csr_out = mepc; // MEPC
			`MCAUSE: csr_out = 32'd11; // MCAUSE
			default: csr_out = 32'b0;
		endcase
	end
	always @(posedge clk) begin
		if (rst) begin
			mstatus <= 32'b0;
			mtvec <= 32'b0;
			mepc <= 32'b0;
		end
		else begin
				if (csr_write) begin
					case (csr_write_addr)
						`MTVEC: mtvec <= csr_data; 
						`MSTATUS: mstatus <= csr_data; 
						`MEPC: mepc <= csr_data; 
					default: begin end
				endcase
			end
		end
	end
endmodule
