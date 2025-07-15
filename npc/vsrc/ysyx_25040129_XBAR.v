module ysyx_25040129_XBAR (
	input clk,
	input rst,
	//---------------XBAR输入---------------
	//---------------读地址---------------
	input [31:0] araddr,
	input arvalid,
	output reg arready,
	//---------------读数据---------------
	output reg[31:0] rdata,
	output reg [1:0]rresp,
	output reg rvalid,
	input rready,
	//---------------写地址---------------
	input [31:0] awaddr,
	input awvalid,
	output reg awready,
	//---------------写数据---------------
	input [1:0] wstrb,
	input [31:0] wdata,
	input wvalid,
	output reg wready,
	//---------------写响应---------------
	output reg [1:0]bresp,
	output reg bvalid,
	input bready
	///--------------XBAR转发---------------
	//---------------MMEM---------------
	//---------------读地址---------------
	output reg [31:0] mmem_araddr,
	output reg mmem_arvalid,
	input mmem_arready,
	//---------------读数据---------------
	input [31:0] mmem_rdata,
	input [1:0]mmem_rresp,
	input mmem_rvalid,
	output reg mmem_rready,
	//---------------写地址---------------
	output reg [31:0] mmem_awaddr,
	output reg mmem_awvalid,
	input mmem_awready,
	//---------------写数据---------------
	output reg [1:0] mmem_wstrb,
	output reg [31:0] mmem_wdata,
	output reg mmem_wvalid,
	input mmem_wready,
	//---------------写响应---------------
	input [1:0]mmem_bresp,
	input mmem_bvalid,
	output reg mmem_bready,
	//---------------UART---------------
	//UART不支持读取，应该在XBAR中拦截并报错
	//---------------写地址---------------
	output reg [31:0] uart_awaddr,
	output reg uart_awvalid,
	input uart_awready,
	//---------------写数据---------------
	output reg [1:0] uart_wstrb,
	output reg [31:0] uart_wdata,
	output reg uart_wvalid,
	input uart_wready,
	//---------------写响应---------------
	input [1:0]uart_bresp,
	input uart_bvalid,
	output reg uart_bready
);
localparam IDLE = 3'b000;
localparam HANDLE_MMEM = 3'b001;
localparam HANDLE_UART = 3'b010;
reg [2:0] state;
reg [2:0] next_state;
always @(posedge clk) begin
	if (rst) begin
		state <= IDLE;
	end else begin
		state <= next_state;
	end
end
//-----------------------信号转接-----------------------
always @(*) begin
	case (state)
		HANDLE_MMEM:begin
			mmem_araddr = araddr;
			mmem_arvalid = arvalid;
			arready = mmem_arready;

			rdata = mmem_rdata;
			rresp = mmem_rresp;
			rvalid = mmem_rvalid;
			mmem_raddr = raddr;

			mmem_awaddr = awaddr;
			mmem_awvalid = awvalid;
			awready = mmem_awready;

			mmem_wstrb = wstrb;
			mmem_wdata = wdata;
			mmem_wvalid = wvalid;
			wready = mmem_wready;

			bresp = mmem_bresp;
			bvalid = mmem_bvalid;
			mmem_bready = bready;

			uart_awaddr = 32'b0; 
			uart_awvalid = 1'b0;

			uart_wstrb = 2'b0;
			uart_wdata = 32'b0;
			uart_wvalid = 1'b0;

			uart_bready = 1'b0;
		end
		HANDLE_UART:begin
			mmem_araddr = 32'b0;
			mmem_arvalid = 1'b0;
			arready = 1'b0;

			rdata = 32'b0;
			rresp = 2'b00;
			rvalid = 1'b0;
			mmem_rready = 1'b0;

			mmem_awaddr = 32'b0;
			mmem_awvalid = 1'b0;
			awready = 1'b0;

			mmem_wstrb = 2'b0;
			mmem_wdata = 32'b0;
			mmem_wvalid = 1'b0;
			wready = 1'b0;

			uart_awaddr = awaddr;
			uart_awvalid = awvalid;
			uart_awready = uart_awready;

			uart_wstrb = wstrb;
			uart_wdata = wdata;
			uart_wvalid = wvalid;
			uart_wready = uart_wready;

			bresp = uart_bresp;
			bvalid = uart_bvalid;
			uart_bready = bready;
		end
		default: begin
			arready = 1'b0;

			rdata = 32'b0;
			rresp = 2'b00;
			rvalid = 1'b0;

			awready = 1'b0;

			wready = 1'b0;

			bresp = 2'b00;
			bvalid = 1'b0;

			mmem_araddr = 32'b0;
			mmem_arvalid = 1'b0;

			mmem_rready = 1'b0;

			mmem_awaddr = 32'b0;
			mmem_awvalid = 1'b0;

			mmem_wstrb = 2'b0;
			mmem_wdata = 32'b0;
			mmem_wvalid = 1'b0;

			mmem_bready = 1'b0;

			uart_awaddr = 32'b0;
			uart_awvalid = 1'b0;

			uart_wstrb = 2'b0;
			uart_wdata = 32'b0;
			uart_wvalid = 1'b0;

			uart_bready = 1'b0;
		end
	endcase
end
//-----------------------下一状态产生逻辑-----------------------
always @(*) begin
	case (state)
		IDLE: begin

			end
	endcase
end
endmodule

