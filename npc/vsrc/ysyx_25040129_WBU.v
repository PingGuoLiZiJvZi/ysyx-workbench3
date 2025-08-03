module ysyx_25040129_WBU (

	input is_req_valid_from_lsu,
	output is_req_ready_to_lsu,
	input [`REGS_DIG-1:0] rd_in_wbu, 
	`ifdef DEBUG
	/* verilator lint_off UNUSEDSIGNAL */
	input [31:0] pc_in_wbu,
	input [31:0] inst_in_wbu,
	input is_device_in_wbu,
	/* verilator lint_on UNUSEDSIGNAL */
	`endif 
	input [31:0] result_in_wbu,
	input [`CSR_DIG-1:0] csr_addr_in_wbu,
	input csr_write_in_wbu,
	input reg_write_in_wbu,
	output [`REGS_DIG-1:0] rd_out_wbu,
	output [31:0] result_out_wbu,
	output csr_write_out_wbu, 
	output [`CSR_DIG-1:0] csr_addr_out_wbu, 
	output reg_write_out_wbu
);
`ifdef DEBUG
always @(*) begin
	update_wbu_state(is_req_valid_from_lsu);
	update_is_device(is_device_in_wbu);
	update_inst(inst_in_wbu);
end
`endif 
assign is_req_ready_to_lsu = is_req_valid_from_lsu;
assign rd_out_wbu = rd_in_wbu; 
assign result_out_wbu = result_in_wbu; 
assign csr_write_out_wbu = csr_write_in_wbu && is_req_valid_from_lsu; 
assign csr_addr_out_wbu = csr_addr_in_wbu; 
assign reg_write_out_wbu = reg_write_in_wbu && is_req_valid_from_lsu; 
endmodule
