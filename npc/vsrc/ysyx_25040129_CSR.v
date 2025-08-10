
module ysyx_25040129_CSR (
	input clk,
	input rst,	
	input csr_write,
	input [`ysyx_25040129_CSR_DIG-1:0] csr_read_addr,
	input [`ysyx_25040129_CSR_DIG-1:0] csr_write_addr,
	input [31:0] csr_data,
	output reg [31:0] csr_out,
	output [31:0] satp_in_ifu
);
	assign satp_in_ifu = satp;
	reg [31:0] mepc;
	reg [31:0] mstatus;
	reg [31:0] mtvec;
	reg [31:0] satp;
	reg [31:0] mscratch;
	always @(*) begin
		case (csr_read_addr)
			`ysyx_25040129_MVENDORID: csr_out = 32'h79737978; // MVENDORID
			`ysyx_25040129_MARCHID: csr_out = 32'd25040129; // MARCHID
			`ysyx_25040129_MSTATUS: csr_out = mstatus; // MSTATUS
			`ysyx_25040129_MTVEC: csr_out = mtvec; // MTVEC
			`ysyx_25040129_MEPC: csr_out = mepc; // MEPC
			`ysyx_25040129_MCAUSE: csr_out = 32'd11; // MCAUSE
			`ysyx_25040129_SATP: csr_out = satp; // SATP
			`ysyx_25040129_MSCRATCH: csr_out = mscratch; // MSCRATCH
			default: begin 
				csr_out = 32'b0;
				if(csr_read_addr != 0)
				$display("Unknown CSR read address: %h", csr_read_addr);
			end
		endcase
	end
	always @(posedge clk) begin
		if (rst) begin
			mstatus <= 32'b0;
			mtvec <= 32'b0;
			mepc <= 32'b0;
			satp <= 32'b0;
			mscratch <= 32'b0;
		end
		else begin
				if (csr_write) begin
					case (csr_write_addr)
						`ysyx_25040129_MTVEC: mtvec <= csr_data; 
						`ysyx_25040129_MSTATUS: mstatus <= csr_data; 
						`ysyx_25040129_MEPC: mepc <= csr_data; 
						`ysyx_25040129_SATP: satp <= csr_data;
						`ysyx_25040129_MSCRATCH: mscratch <= csr_data;
					default: begin
						$display("Unknown CSR write address: %h", csr_write_addr);
					 end
				endcase
			end
		end
	end
endmodule
