
module ysyx_25040129_LSU (
	input clk,
	input rst,

	input [31:0] pc_in_lsu,
	output [31:0] pc_out_lsu,

	input [31:0] branch_target_in_lsu,
	output [31:0] branch_target_out_lsu,

	input [2:0] mmem_read_in_lsu, 
	input [1:0] mmem_write_in_lsu, 
	input [31:0] mmem_addr_in_lsu,
	input [31:0] result_in_lsu,
	output [31:0] result_out_lsu, // 如果发送了读，则该信号会被数据覆盖
	output [31:0] mmem_read_addr_out_lsu, // 直接传递地址
	input [31:0] mmem_read_data_in_lsu,
	input [31:0] mmem_write_data_in_lsu,
	output [31:0] mmem_write_data_out_lsu,
	
	output [2:0] mmem_read_out_lsu,
	output [1:0] mmem_write_out_lsu,

	input is_req_valid_from_exu,
	output is_req_ready_to_exu,
	output is_req_valid_to_mmem,
	input is_req_ready_from_mmem,
	input is_rsp_valid_from_mmem,
	output is_rsp_ready_to_mmem,
	output is_req_valid_to_wbu,
	input is_req_ready_from_wbu,

	input ecall_in_lsu,
	output ecall_out_lsu,

	input [4:0] rd_in_lsu,
	output [4:0] rd_out_lsu,
	input mret_in_lsu,
	output mret_out_lsu,
	input is_branch_in_lsu,
	output is_branch_out_lsu
);
assign pc_out_lsu = pc_in_lsu; // 直接传递PC地址
assign branch_target_out_lsu = branch_target_in_lsu; // 直接传递分支目标地址
assign mmem_read_out_lsu = mmem_read_in_lsu; // 直接传递MEM阶段的读请求
assign mmem_write_out_lsu = mmem_write_in_lsu; // 直接传
assign is_branch_out_lsu = is_branch_in_lsu ; // 直接传递分支信号
assign rd_out_lsu = rd_in_lsu; // 直接传递寄存器
assign mret_out_lsu = mret_in_lsu; // 直接传递mret信号
assign mmem_write_data_out_lsu = mmem_write_data_in_lsu ;
assign ecall_out_lsu = ecall_in_lsu; // 直接传递ecall信号
localparam IDLE = 3'b000;
localparam WAIT_REQ_READ = 3'b001;
localparam WAIT_REQ_WRITE = 3'b010;
localparam WAIT_RSP_READ = 3'b011;
localparam WAIT_RSP_WRITE = 3'b100;
localparam WAIT_WBU_READY = 3'b101;

reg [2:0] state;
reg [2:0] next_state;

assign is_req_ready_to_exu = (state == IDLE);
assign is_req_valid_to_mmem = (state == WAIT_REQ_READ || state == WAIT_REQ_WRITE);
assign is_rsp_ready_to_mmem = (state == WAIT_RSP_READ || state == WAIT_RSP_WRITE);
assign is_req_valid_to_wbu = (state == WAIT_WBU_READY);
assign result_out_lsu = (mmem_read_in_lsu != `NO_MEM_READ) ? mmem_read_data_in_lsu : result_in_lsu; // 如果是读请求，则将读数据传递出去，否则传递计算结果
assign mmem_read_addr_out_lsu = mmem_addr_in_lsu; // 直接传递地址


always @(posedge clk) begin
	if (rst) state <= IDLE;
	else state <= next_state;
end

always @(*) begin
	case(state)
		IDLE: if(is_req_valid_from_exu) begin
			if (mmem_read_in_lsu != `NO_MEM_READ) next_state = WAIT_REQ_READ;
			else if (mmem_write_in_lsu != `NO_MEM_WRITE) next_state = WAIT_REQ_WRITE;
			else next_state = WAIT_WBU_READY;
		end else next_state = IDLE;
		WAIT_REQ_READ: next_state = is_req_ready_from_mmem ? WAIT_RSP_READ : WAIT_REQ_READ;
		WAIT_REQ_WRITE: next_state = is_req_ready_from_mmem ? WAIT_RSP_WRITE : WAIT_REQ_WRITE;
		WAIT_RSP_READ: next_state = is_rsp_valid_from_mmem ? WAIT_WBU_READY : WAIT_RSP_READ;
		WAIT_RSP_WRITE: next_state = is_rsp_valid_from_mmem ? WAIT_WBU_READY : WAIT_RSP_WRITE;
		WAIT_WBU_READY: next_state = is_req_ready_from_wbu ? IDLE : WAIT_WBU_READY;
		default: next_state = IDLE;
	endcase
end


endmodule
