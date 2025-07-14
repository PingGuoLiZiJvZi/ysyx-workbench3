module ysyx_25040129_MMEM (//真正的主存模块，而不是访存模块
input is_req_valid,
output is_req_ready,
output is_rsp_valid,
input is_rsp_ready,
input clk,
input rst,
input [2:0] mmem_read, 
input [1:0] mmem_write, // 
input [31:0] mmem_addr,
input [31:0] mmem_write_data,
output reg [31:0] mmem_read_data
);
//如果收到请求，即is_req_valid为真,则is_req_ready为真
//在当前单周期中，预期表现为，若收到读req，立即读出，若收到写req，则在下一个时钟到来时写入
//唉，固定实现两个周期工作得了
localparam  IDLE = 3'b000;
localparam  PROCESS_READ = 3'b001;
localparam  PROCESS_WRITE = 3'b010;
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
	case (state)
		IDLE: begin
			if (is_req_valid) begin
				if (mmem_read != `NO_MEM_READ) begin
					next_state = PROCESS_READ;
				end else if (mmem_write != `NO_MEM_WRITE) begin
					next_state = PROCESS_WRITE;
				end else begin
					next_state = IDLE;
				end
			end else begin
				next_state = IDLE;
			end
		end
		PROCESS_READ: next_state = is_rsp_ready ? IDLE : PROCESS_READ;
		PROCESS_WRITE: next_state = is_rsp_ready ? IDLE : PROCESS_WRITE;
		default: next_state = IDLE;
	endcase
end
always @(posedge clk) begin
	case (state)
		IDLE:begin
			if(is_req_valid)begin
				if(mmem_read != `NO_MEM_READ)begin
					case (mmem_read)
						`MEM_READ_BYTE:mmem_read_data <= {{24{paddr_read(mmem_addr,1,0,mmem_read == `MEM_READ_BYTE ? 32'b1 : 32'b0)[7]}}, paddr_read(mmem_addr,1,0,mmem_read == `MEM_READ_BYTE ? 32'b1 : 32'b0)[7:0]};
						`MEM_READ_HALF:mmem_read_data <= {{16{paddr_read(mmem_addr,2,0,mmem_read == `MEM_READ_HALF ? 32'b1 : 32'b0)[15]}}, paddr_read(mmem_addr,2,0,mmem_read == `MEM_READ_HALF ? 32'b1 : 32'b0)[15:0]};
						`MEM_READ_WORD:mmem_read_data <= paddr_read(mmem_addr,4,0,mmem_read == `MEM_READ_WORD ? 32'b1 : 32'b0);
						`MEM_READ_BYTE_U:mmem_read_data <= {24'b0, paddr_read(mmem_addr,1,0,mmem_read == `MEM_READ_BYTE_U ? 32'b1 : 32'b0)[7:0]};
						`MEM_READ_HALF_U:mmem_read_data <= {16'b0, paddr_read(mmem_addr,2,0,mmem_read == `MEM_READ_HALF_U ? 32'b1 : 32'b0)[15:0]}; 
						default: begin	end
					endcase
				end
				else if(mmem_write != `NO_MEM_WRITE)begin
					case (mmem_write)
						`MEM_WRITE_BYTE:paddr_write(mmem_addr,1,{24'b0,mmem_write_data[7:0]},mmem_write == `MEM_WRITE_BYTE ? 32'b1 : 32'b0);
						`MEM_WRITE_HALF:paddr_write(mmem_addr,2,{16'b0,mmem_write_data[15:0]},mmem_write == `MEM_WRITE_HALF ? 32'b1 : 32'b0);
						`MEM_WRITE_WORD: paddr_write(mmem_addr,4,mmem_write_data,mmem_write == `MEM_WRITE_WORD ? 32'b1 : 32'b0);
						default: begin	end
					endcase
				end
			end
		end 
		default:mmem_read_data = mmem_read_data; 
	endcase
end




assign is_req_ready = (state == IDLE);
assign is_rsp_valid = (state == PROCESS_READ)||(state == PROCESS_WRITE);
// 通过paddr_read()和paddr_write()函数来实现对主存的读写操作







endmodule
