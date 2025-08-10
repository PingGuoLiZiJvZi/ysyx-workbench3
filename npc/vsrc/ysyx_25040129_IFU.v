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
		pc <= `START_ADDR;
		inst_to_idu <= 32'b0; // 初始化指令
	end
	else begin
		case (state)
			WAIT_MMEM_READY:begin
				if(arready & !raw)begin
					if(rvalid) begin
						inst <= rdata;
						if(pipeline_flush)begin
							pc <= pipeline_flush_target;
							get_flush_signal_in_fetching <= 1'b0;
							flush_target_latch <= 32'b0;
							state <= WAIT_MMEM_READY;
						end
						else begin
							if(is_req_ready_from_idu)begin 
								state <= WAIT_MMEM_READY;
								pc <= pc + 4;
							end
							else state <= WAIT_IDU_READY;
						end
						`ifdef ysyx_25040129_DPI
						if(rresp != `ysyx_25040129_OKAY)$error("IFU: Read error, rresp = %b", rresp);
						`endif
					end
					else begin
						if(pipeline_flush)begin
							get_flush_signal_in_fetching <= 1'b1;
							flush_target_latch <= pipeline_flush_target;
						end
						state <= WAIT_MMEM_REQ;
					end
				end
			else state <= WAIT_MMEM_READY;
			
			end
			WAIT_MMEM_REQ:begin
				if(rvalid)begin 
					state <= WAIT_IDU_READY;
					inst <= rdata;
					`ifdef ysyx_25040129_DPI
					if(rresp != `ysyx_25040129_OKAY)$error("IFU: Read error, rresp = %b", rresp);
					`endif
				end
				else state <= WAIT_MMEM_REQ;
				if(pipeline_flush)begin
					get_flush_signal_in_fetching <= 1'b1;
					flush_target_latch <= pipeline_flush_target;
				end
			end
			WAIT_IDU_READY:begin
				if(pipeline_flush)begin
					pc <= pipeline_flush_target;
					get_flush_signal_in_fetching <= 1'b0;
					flush_target_latch <= 32'b0;
					state <= WAIT_MMEM_READY;
				end
				else if(get_flush_signal_in_fetching)begin
					pc <= flush_target_latch;
					get_flush_signal_in_fetching <= 1'b0;
					flush_target_latch <= 32'b0;
					state <= WAIT_MMEM_READY;
				end
				else begin
					if(is_req_ready_from_idu)begin 
						state <= WAIT_MMEM_READY;
						pc <= pc + 4;
					end
					else state <= WAIT_IDU_READY;
				end
			end
			default: state <= WAIT_MMEM_READY;
		endcase
	end
end

endmodule
