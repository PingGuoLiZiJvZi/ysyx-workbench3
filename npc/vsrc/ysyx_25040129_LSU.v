
module ysyx_25040129_LSU (
	input clk,
	input rst,

	input [31:0] pc_in_lsu,
	output [31:0] pc_out_lsu,

	input [31:0] branch_target_in_lsu,
	output [31:0] branch_target_out_lsu,

	input [2:0] mmem_read_in_lsu, 
	input [1:0] mmem_write_in_lsu, 
	
	input [31:0] result_in_lsu,
	output [31:0] result_out_lsu, // 如果发送了读，则该信号会被数据覆盖
	
	input is_req_valid_from_exu,
	output is_req_ready_to_exu,

	input [31:0] mmem_write_data_in_lsu,
		
	//---------------读地址---------------
	output [31:0] araddr,
	output arvalid,
	input arready,
	output reg[2:0] arsize,
	//---------------读数据---------------
	input [31:0] rdata,
	input [1:0]rresp,
	input rvalid,
	output rready,
	//---------------写地址---------------
	output [31:0] awaddr,
	output awvalid,
	input awready,
	//---------------写数据---------------
	output reg[3:0] wstrb,
	output reg[31:0] wdata,
	output wvalid,
	input wready,
	//---------------写响应---------------
	input [1:0]bresp,
	input bvalid,
	output bready,

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
//---------------信号转发---------------
assign pc_out_lsu = pc_in_lsu; 
assign branch_target_out_lsu = branch_target_in_lsu;

assign is_branch_out_lsu = is_branch_in_lsu ; 
assign rd_out_lsu = rd_in_lsu;
assign mret_out_lsu = mret_in_lsu;
// assign wdata = mmem_write_data_in_lsu; 
assign ecall_out_lsu = ecall_in_lsu; 
always @(*) begin
	case (mmem_write_in_lsu)
		`NO_MEM_WRITE:wstrb = 4'b0000; // 不写
		`MEM_WRITE_BYTE:begin
			case (awaddr[1:0]) // 根据地址的低2位决定写入哪个字节
				2'b00:begin
					wstrb = 4'b0001; // 写入最低字节
					wdata = {24'b0, mmem_write_data_in_lsu[7:0]};
				end
				2'b01:begin
					wstrb = 4'b0010; // 写入次低字节
					wdata = {16'b0, mmem_write_data_in_lsu[7:0], 8'b0};
				end
				2'b10:begin
					wstrb = 4'b0100; // 写入次高字节
					wdata = {8'b0, mmem_write_data_in_lsu[7:0], 16'b0};
				end
				2'b11:begin
					wstrb = 4'b1000; // 写入最高字节
					wdata = {mmem_write_data_in_lsu[7:0], 24'b0};
				end
			endcase
		end
		`MEM_WRITE_HALF:begin
			case (awaddr[1]) // 根据地址的低1位决定写入哪个半字
				1'b0:begin
					wstrb = 4'b0011; // 写入低半字
					wdata = {16'b0, mmem_write_data_in_lsu[15:0]};
				end
				1'b1:begin
					wstrb = 4'b1100; // 写入高半字
					wdata = {mmem_write_data_in_lsu[15:0], 16'b0};
				end
			endcase
		end
		`MEM_WRITE_WORD:begin
			wstrb = 4'b1111; // 写入整个字
			wdata = mmem_write_data_in_lsu;
		end
	endcase
end
assign awaddr = result_in_lsu; // 由从元件锁存


localparam IDLE = 3'b000;
localparam WAIT_REQ_READ = 3'b001;
localparam WAIT_REQ_AW_WRITE = 3'b010;
localparam WAIT_RSP_READ = 3'b011;
localparam WAIT_RSP_WRITE = 3'b100;
localparam WAIT_WBU_READY = 3'b101;
localparam WAIT_REQ_W_WRITE = 3'b110;
localparam WAIT_REQ_WRITE = 3'b111;

reg [2:0] state;
reg [2:0] next_state;
reg [2:0] mmem_read_store;
reg [31:0] processed_rdata;
//---------------请求信号产生逻辑---------------
assign is_req_ready_to_exu = (state == IDLE);
assign arvalid = (state == WAIT_REQ_READ);
assign awvalid = (state == WAIT_REQ_WRITE)||(state == WAIT_REQ_AW_WRITE);
assign wvalid = (state == WAIT_REQ_WRITE)||(state == WAIT_REQ_W_WRITE);
assign rready = state == WAIT_RSP_READ;
assign bready = (state == WAIT_RSP_WRITE);
assign is_req_valid_to_wbu = (state == WAIT_WBU_READY);
assign result_out_lsu = (mmem_read_store != `NO_MEM_READ) ? processed_rdata : result_in_lsu; // 如果是读请求，则将读数据传递出去，否则传递计算结果
assign araddr = result_in_lsu;
wire [1:0] offset;
assign offset = result_in_lsu[1:0];

always @(*) begin
	case(mmem_read_in_lsu)
		`NO_MEM_READ: arsize = 3'b000; // 不读取
		`MEM_READ_BYTE: arsize = 3'b000; // 读取字节
		`MEM_READ_HALF: arsize = 3'b001; // 读取半
		`MEM_READ_WORD: arsize = 3'b010; // 读取字
		`MEM_READ_BYTE_U: arsize = 3'b000; // 无符
		`MEM_READ_HALF_U: arsize = 3'b001; // 无符半
		default: arsize = 3'b000; // 默认不读取
	endcase
end

always @(posedge clk) begin
	case (mmem_read_store)
		`NO_MEM_READ: processed_rdata <= processed_rdata; // 不处理数据
		`MEM_READ_BYTE: begin
			case (offset) // 根据地址的低2位决定读取哪个字节
				2'b00: processed_rdata <= {{24{rdata[7]}}, rdata[7:0]}; // 读取最低字节
				2'b01: processed_rdata <= {{24{rdata[15]}}, rdata[15:8]}; // 读取次低字节
				2'b10: processed_rdata <= {{24{rdata[23]}}, rdata[23:16]}; // 读取次高字节
				2'b11: processed_rdata <= {{24{rdata[31]}}, rdata[31:24]}; // 读取最高字节
			endcase
		end
		`MEM_READ_HALF: begin
			case (offset[1]) // 根据地址的低1位决定读取哪个半字
				1'b0: processed_rdata <= {{16{rdata[15]}}, rdata[15:0]}; // 读取低半字
				1'b1: processed_rdata <= {{16{rdata[31]}}, rdata[31:16]}; // 读取高半字
			endcase
		end
		`MEM_READ_WORD: processed_rdata <= rdata; // 读取字
		`MEM_READ_BYTE_U: begin
			case (offset) // 根据地址的低2位决定读取哪个字节
				2'b00: processed_rdata <= {24'b0, rdata[7:0]}; // 读取最低字节
				2'b01: processed_rdata <= {24'b0, rdata[15:8]}; // 读取次低字节
				2'b10: processed_rdata <= {24'b0, rdata[23:16]}; // 读取次高字节
				2'b11: processed_rdata <= {24'b0, rdata[31:24]}; // 读取最高字节
			endcase
		end
		`MEM_READ_HALF_U: begin
			case (offset[1]) // 根据地址的低1位决定读取哪个半字
				1'b0: processed_rdata <= {16'b0, rdata[15:0]}; // 读取低半字
				1'b1: processed_rdata <= {16'b0, rdata[31:16]}; // 读取高半字
			endcase
		end
		default: processed_rdata = processed_rdata;
	endcase
end
//---------------调试信号---------------
always @(posedge clk) begin
	`ifdef DEBUG
	load_store_count_inc({5'b0,state});
	`endif
end
//---------------综合时删除---------------
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
		WAIT_REQ_READ: next_state = arready ? WAIT_RSP_READ : WAIT_REQ_READ;
		WAIT_RSP_READ: next_state = rvalid &&(rresp == `OKAY) ? WAIT_WBU_READY : WAIT_RSP_READ;

		WAIT_REQ_WRITE: next_state =  awready ? (wready?WAIT_RSP_WRITE:WAIT_REQ_W_WRITE) :(wready?WAIT_REQ_AW_WRITE:WAIT_REQ_WRITE);
		WAIT_REQ_AW_WRITE: next_state = awready ? WAIT_RSP_WRITE : WAIT_REQ_AW_WRITE;
		WAIT_REQ_W_WRITE: next_state = wready ? WAIT_RSP_WRITE : WAIT_REQ_W_WRITE;
		WAIT_RSP_WRITE: next_state = bvalid && (bresp == `OKAY) ? WAIT_WBU_READY : WAIT_RSP_WRITE;
		
		WAIT_WBU_READY: next_state = is_req_ready_from_wbu ? IDLE : WAIT_WBU_READY;
		default: next_state = IDLE;
	endcase
end

always @(posedge clk) begin
	if(state == IDLE && next_state == WAIT_REQ_READ) mmem_read_store <= mmem_read_in_lsu;
	else if(state == WAIT_WBU_READY && next_state == IDLE) mmem_read_store <= `NO_MEM_READ;
end
endmodule
