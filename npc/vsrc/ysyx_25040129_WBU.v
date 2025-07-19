module ysyx_25040129_WBU (
	input clk,
	input rst,

	input [31:0] pc_in_wbu,
	output [31:0] pc_out_wbu,

	input is_req_valid_from_lsu,
	output is_req_ready_to_lsu,
	output is_req_valid_to_ifu,
	input is_req_ready_from_ifu,
	input [4:0] rd_in_wbu, // 该信号将被一路传递至WB阶段
	input [31:0] result_in_wbu,// 暂时认为，不需要提供对交换寄存器的支持
	input [11:0] csr_addr_in_wbu,
	input csr_write_in_wbu,
	input reg_write_in_wbu,
	output [4:0] rd_out_wbu, // 该信号将被一路传递至WB阶段
	output [31:0] result_out_wbu, // 该信号将被一路
	output csr_write_out_wbu, // 该信号将被一路传递至WB阶段
	output [11:0] csr_addr_out_wbu, // 该信号将被
	output reg_write_out_wbu, // 该信号将被一路传递至WB阶段

	input [31:0] branch_target_in_wbu,
	output reg[31:0]branch_target_out_wbu,
	input [31:0] target_from_csr_in_wbu, 

	input ecall_in_wbu,
	output ecall_out_wbu,
	input mret_in_wbu,
	output mret_out_wbu,
	input is_branch_in_wbu,
	output is_branch_out_wbu
);
reg [2:0] state;
reg [2:0] next_state;
localparam IDLE = 3'b000;
localparam WRITE_BACK = 3'b001;

always @(posedge clk) begin
	if (rst) begin
		state <= IDLE;
	end else begin
		state <= next_state;
	end
end

always @(*) begin
	case (state)
		IDLE: next_state = is_req_valid_from_lsu ? WRITE_BACK : IDLE;
		WRITE_BACK: next_state = is_req_ready_from_ifu ? IDLE : WRITE_BACK; 
		default: next_state = IDLE;
	endcase
end

assign pc_out_wbu = pc_in_wbu; // 直接传递PC

assign is_req_valid_to_ifu = (state == WRITE_BACK);
assign is_req_ready_to_lsu = (state == IDLE);

assign mret_out_wbu = mret_in_wbu && is_req_valid_from_lsu; 
assign ecall_out_wbu = ecall_in_wbu && is_req_valid_from_lsu; // 只有在LSU请求有效时才允许ecall信号
assign is_branch_out_wbu = is_branch_in_wbu || mret_in_wbu || ecall_in_wbu;
 
always @(posedge clk) begin
	if(state == IDLE &&next_state == WRITE_BACK)
		branch_target_out_wbu <= (mret_in_wbu || ecall_in_wbu )?target_from_csr_in_wbu:branch_target_in_wbu;
end


assign rd_out_wbu = rd_in_wbu; // 直接传递寄存器编号
assign result_out_wbu = result_in_wbu; // 直接传递计算结果
assign csr_write_out_wbu = csr_write_in_wbu && is_req_valid_from_lsu; // 直接传递CSR
assign csr_addr_out_wbu = csr_addr_in_wbu; // 直接传递CSR
assign reg_write_out_wbu = reg_write_in_wbu && is_req_valid_from_lsu; // 只有在LSU请求有效时才允许寄存器写入
endmodule
