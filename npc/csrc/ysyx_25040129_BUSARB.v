module ysyx_25040129_BUSARB (
	input clk,
	input rst,

	input is_req_valid_from_ifu,
	output is_req_ready_to_ifu,
	output is_rsp_valid_to_ifu,
	input is_rsp_ready_from_ifu,

	input is_req_valid_from_lsu,
	output is_req_ready_to_lsu,
	output is_rsp_valid_to_ifu,
	input is_rsp_ready_from_mem,

	input [2:0] mmem_read_from_ifu, 
	input [1:0] mmem_write_from_ifu, 
	input [31:0] mmem_addr_from_ifu,
	input [31:0] mmem_write_data_from_ifu,
	output reg [31:0] mmem_read_data_to_ifu,

	input [2:0] mmem_read_from_mem,
	input [1:0] mmem_write_from_mem,
	input [31:0] mmem_addr_from_mem,
	input [31:0] mmem_write_data_from_mem,
	output reg [31:0] mmem_read_data_to_mem
);
	// 在IFU和MEM之间进行总线仲裁
	localparam IDLE = 3'b000;
	localparam WAIT_IFU_RSP = 3'b010;
	localparam WAIT_MEM_RSP = 3'b011;
	localparam DONE = 3'b100;
	reg [2:0] state;
	reg [2:0] next_state;      

	always @(posedge clk) begin
		if (rst) begin
			state <= IDLE;
		end else begin
			state <= next_state;
		end
	end

	always @(*) begin
		case(state)
			IDLE: begin
				if (is_req_valid_from_ifu) begin//仲裁优先允许
					next_state = WAIT_REQ;
				end else if (is_req_valid_from_lsu) begin
					next_state = WAIT_REQ;
				end else begin
					next_state = IDLE;
				end
			end
			WAIT_REQ: begin
				if (is_rsp_ready_from_ifu && is_rsp_ready_from_mem) begin
					next_state = DONE;
				end else if (is_rsp_ready_from_ifu) begin
					next_state = WAIT_IFU_RSP;
				end else if (is_rsp_ready_from_mem) begin
					next_state = WAIT_MEM_RSP;
				end else begin
					next_state = WAIT_REQ;
				end
			end
			WAIT_IFU_RSP: next_state = is_rsp_valid_to_ifu ? DONE : WAIT_IFU_RSP;
			WAIT_MEM_RSP: next_state = is_rsp_valid_to_ifu ? DONE : WAIT_MEM_RSP;
			DONE: next_state = IDLE; // 完成后返回空闲状态
			default: next_state = IDLE;
		endcase
	end
	 

endmodule
