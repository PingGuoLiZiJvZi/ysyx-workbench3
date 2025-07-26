module ysyx_25040129_CLINT (
	input clk,
	input rst,
	//---------------只读设备---------------
	//---------------读地址---------------
	input [31:0] araddr,
	input arvalid,
	output reg arready,
	//---------------读数据---------------
	output reg [31:0] rdata,
	output reg [1:0] rresp,
	output reg rvalid,
	input rready
);
	// CLINT的实现代码
	reg [63:0] mtime;
	localparam IDLE = 2'b00;
	localparam HANDLE_READ = 2'b01;
	reg [1:0] state, next_state;
	always @(posedge clk) begin
		if (rst) begin
			state <= IDLE;
			mtime <= 64'b0;
		end else begin
			state <= next_state;
			mtime <= mtime + 1; 
		end
	end
	//-----------------------下一状态逻辑-----------------------
	always @(*) begin
		case (state)
			IDLE: next_state = arvalid ? HANDLE_READ : IDLE;
			HANDLE_READ: next_state = rready ? IDLE : HANDLE_READ;
			default: next_state = IDLE;
		endcase
	end
	//-----------------------输出逻辑-----------------------
	assign arready = (state == IDLE);
	assign rvalid = (state == HANDLE_READ);
	assign rresp = `OKAY;
	always @(posedge clk) begin
		if(next_state == HANDLE_READ) begin
			if(~araddr[2]) rdata <= mtime[31:0]; // 返回低32位
			else rdata <= mtime[63:32]; // 返回高32位
		end
	end

endmodule
