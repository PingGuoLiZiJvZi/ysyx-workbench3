module ysyx_25040129_IFU (
	input rst,
	input clk,

	input [31:0] pipeline_flush_target,
	input pipeline_flush,
	input is_req_ready_from_idu,

	output reg[31:0] pc,
	output reg[31:0] inst_to_idu,
	
	output is_req_valid_to_idu,
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
reg get_flush_signal_in_fetching;
reg [31:0] flush_target_latch;
reg[2:0] state;
assign araddr = pc;
assign arvalid = (state == WAIT_MMEM_READY);
assign rready = (state == WAIT_MMEM_REQ);
localparam WAIT_MMEM_READY = 3'b000;
localparam WAIT_MMEM_REQ = 3'b001;
localparam WAIT_IDU_READY = 3'b010;


//总线信号产生逻辑
assign is_req_valid_to_idu = (state == WAIT_IDU_READY && ~get_flush_signal_in_fetching && ~pipeline_flush);
//--------------------调试接口---------------------
always @(posedge clk) begin
	`ifdef DEBUG
	fetch_count_inc({5'b0,state});
	`endif
	`ifdef GENERATE_PC_QUEUE
		if(state==IDLE && next_state == WAIT_MMEM_READY)record_pc(pc);
	`endif
end
// always @(*) begin
// 	`ifdef DEBUG
// 	update_pc(pc);
// 	update_inst(inst_to_idu);
// 	update_ifu_state({5'b0,state});
// 	`endif
// end
//-------------------综合时直接删除-------------------
// pc 更新逻辑
always @(posedge clk) begin
	if(rst)begin
		pc <= `FLASH_START;
		inst_to_idu <= 32'b0; 
		get_flush_signal_in_fetching <= 1'b0;
		state <= WAIT_MMEM_READY;
	end
	else begin
		case (state)
			WAIT_MMEM_READY:begin
				if(arready) state <= WAIT_MMEM_REQ;
				else state <= WAIT_MMEM_READY;
				if(pipeline_flush)begin
					get_flush_signal_in_fetching <= 1'b1;
					flush_target_latch <= pipeline_flush_target;
				end
			end
			WAIT_MMEM_REQ:begin
				if(rvalid)begin 
					state <= WAIT_IDU_READY;
					inst_to_idu <= rdata;
					`ifdef DPI
					if(rresp != `OKAY)$error("IFU: Read error, rresp = %b", rresp);
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
