module ysyx_25040129_IFU (
	output reg[31:0] pc,
	input [31:0] jump_target,
	output reg[31:0] inst_to_idu,

	input is_branch,
	input rst,
	input clk,
	output is_req_valid_to_idu,
	
	output is_req_ready_to_wbu,
	
	input is_req_valid_from_wbu,//
	input is_req_ready_from_idu,//
	
	//---------------读地址---------------
	output [31:0] araddr,
	output arvalid,
	input arready,
	//---------------读数据---------------
	input [31:0] rdata,
	input [1:0]rresp,
	input rvalid,
	output rready
	);
reg[2:0] state;
assign araddr = pc;
reg [2:0] next_state;
assign arvalid = (state == WAIT_MMEM_READY);
assign rready = (state == WAIT_MMEM_REQ);
localparam IDLE = 3'b000;
localparam WAIT_MMEM_READY = 3'b001;
localparam WAIT_MMEM_REQ = 3'b010;
localparam WAIT_IDU_READY = 3'b011;

// pc 更新块
// 在原先的单周期设计中，我们所假设的，是inst能以组合逻辑的形式直接读取，这是很不现实的
// 取指->译码->执行->访存->写回
// 当前我们没有加装流水线，所以，pc的更新需要得到写回结束信号才会开始
// 与此同时，ifu收到了wb的valid信号，若处在空闲状态，则以ready信号握手回应，进入wait状态，更新pc之后开始取指

// pc 更新逻辑
always @(posedge clk) begin
	if(rst)begin
		pc <= `FLASH_START;
		inst_to_idu <= 32'b0; // 初始化指令
	end
	else begin
		if(state==IDLE && next_state == WAIT_MMEM_READY) begin
			pc <= is_branch ? jump_target : pc + `WORD_T;
			end
		else pc <= pc; // 保持pc不变
		if (next_state == WAIT_IDU_READY && rresp ==`OKAY) begin
			inst_to_idu <= rdata; 
		end
	end
end
//总线信号产生逻辑
assign is_req_ready_to_wbu = (state == IDLE);

assign is_req_valid_to_idu = (state == WAIT_IDU_READY);
//--------------------调试接口---------------------
always @(posedge clk) begin
	`ifdef DEBUG
	fetch_count_inc({5'b0,state});
	`endif
end
always @(*) begin
	`ifdef DEBUG
	update_pc(pc);
	update_inst(inst_to_idu);
	update_ifu_state({5'b0,state});
	`endif
end
//-------------------综合时直接删除-------------------
always @(*) begin
	case (state)
		IDLE: next_state = is_req_valid_from_wbu ? WAIT_MMEM_READY : IDLE;
		WAIT_MMEM_READY: next_state = arready ? WAIT_MMEM_REQ : WAIT_MMEM_READY;
		WAIT_MMEM_REQ: next_state = rvalid ? WAIT_IDU_READY : WAIT_MMEM_REQ;
		WAIT_IDU_READY: next_state = is_req_ready_from_idu ? IDLE : WAIT_IDU_READY;
		default: next_state = WAIT_MMEM_READY;
	endcase
end
// 状态转移
always @(posedge clk) begin
	if(rst)state <= WAIT_MMEM_READY;
	else state <= next_state;
end

endmodule
