module ysyx_25040129_XBAR (
	input clk,
	input rst,
	//---------------XBAR输入---------------
	//---------------读地址---------------
	input [31:0] araddr,
	input arvalid,
	input [2:0] arsize,
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
	input [3:0] wstrb,
	input [31:0] wdata,
	input wvalid,
	output reg wready,
	//---------------写响应---------------
	output reg [1:0]bresp,
	output reg bvalid,
	input bready,
	///--------------XBAR转发---------------
	//---------------外部设备转发------------
	//---------------读地址---------------
	output reg [31:0] soc_araddr,
	output reg soc_arvalid,
	output reg [2:0] soc_arsize,
	input soc_arready,
	//---------------读数据---------------
	input [31:0] soc_rdata,
	input [1:0]soc_rresp,
	input soc_rvalid,
	output reg soc_rready,
	//---------------写地址---------------
	output reg [31:0] soc_awaddr,
	output reg soc_awvalid,
	input soc_awready,
	//---------------写数据---------------
	output reg [3:0] soc_wstrb,
	output reg [31:0] soc_wdata,
	output reg soc_wvalid,
	input soc_wready,
	//---------------写响应---------------
	input [1:0]soc_bresp,
	input soc_bvalid,
	output reg soc_bready,
	//---------------RTC---------------
	//RTC不支持写入，应该在XBAR中拦截并报错
	//---------------读地址---------------
	output reg [31:0] rtc_araddr,
	output reg rtc_arvalid,
	input rtc_arready,
	//---------------读数据---------------
	input [31:0] rtc_rdata,
	input [1:0]rtc_rresp,
	input rtc_rvalid,
	output reg rtc_rready
);
localparam IDLE = 3'b000;
localparam HANDLE_SOC = 3'b001;
localparam HANDLE_RTC = 3'b011;
reg is_device; 
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
//---------------------目前已经接入
always @(*) begin
	`ifdef DEBUG
	update_is_device(is_device);
	`endif
	case (state)
		HANDLE_SOC:begin
			soc_araddr = araddr;
			soc_arvalid = arvalid;
			arready = soc_arready;
			soc_arsize = arsize;

			rdata = soc_rdata;
			rresp = soc_rresp;
			rvalid = soc_rvalid;
			soc_rready = rready;

			soc_awaddr = awaddr;
			soc_awvalid = awvalid;
			awready = soc_awready;

			soc_wstrb = wstrb;
			soc_wdata = wdata;
			soc_wvalid = wvalid;
			wready = soc_wready;

			bresp = soc_bresp;
			bvalid = soc_bvalid;
			soc_bready = bready;

			rtc_araddr = 32'b0;
			rtc_arvalid = 1'b0;

			rtc_rready = 1'b0;
		end
		HANDLE_RTC:begin
			soc_araddr = 32'b0;
			soc_arvalid = 1'b0;
			arready = 1'b0;
			soc_arsize = 3'b000;

			rdata = 32'b0;
			rresp = 2'b00;
			rvalid = 1'b0;
			soc_rready = 1'b0;

			soc_awaddr = 32'b0;
			soc_awvalid = 1'b0;
			awready = 1'b0;

			soc_wstrb = 4'b0;
			soc_wdata = 32'b0;
			soc_wvalid = 1'b0;
			wready = 1'b0;

			rtc_araddr = araddr;
			rtc_arvalid = arvalid;
			arready = rtc_arready;

			rdata = rtc_rdata;
			rresp = rtc_rresp;
			rvalid = rtc_rvalid;
			rtc_rready = rready;
		end
		default: begin
			arready = 1'b0;
			soc_araddr = 32'b0;

			rdata = 32'b0;
			rresp = 2'b00;
			rvalid = 1'b0;

			awready = 1'b0;

			wready = 1'b0;

			bresp = 2'b00;
			bvalid = 1'b0;

			soc_araddr = 32'b0;
			soc_arvalid = 1'b0;

			soc_rready = 1'b0;

			soc_awaddr = 32'b0;
			soc_awvalid = 1'b0;

			soc_wstrb = 4'b0;
			soc_wdata = 32'b0;
			soc_wvalid = 1'b0;

			soc_bready = 1'b0;
		end
	endcase
end
//-----------------------下一状态产生逻辑-----------------------
always @(*) begin
	case (state)
		IDLE: begin
			if((awvalid&&wvalid)||arvalid)begin
				if(arvalid)begin
					if(araddr >= `RTC_PORT_ADDR && araddr < `RTC_PORT_ADDR + `RTC_PORT_SIZE)
					next_state = HANDLE_RTC;
					else next_state = HANDLE_SOC;
				end
				else begin
					next_state = HANDLE_SOC;
				end
			end
			else next_state = IDLE;
		end
		HANDLE_SOC: if(rready && soc_rvalid || bready && soc_bvalid) begin 
						next_state = IDLE;
					if(rresp != `OKAY && rready && soc_rvalid) 
						$error("XBAR: Invalid response %b %b", rresp, bresp);
					if(bresp != `OKAY && bready && soc_bvalid)
						$error("XBAR: Invalid response %b %b", rresp, bresp);
		end
					 else next_state = HANDLE_SOC;
		HANDLE_RTC: if(rready && rtc_rvalid)begin
			 next_state = IDLE;
			 if(rtc_rresp != `OKAY && rready && rtc_rvalid) 
					$error("XBAR: Invalid RTC response %b", rtc_rresp);
		end
					 else next_state = HANDLE_RTC;
		default: next_state = IDLE;
	endcase
end
//-----------------------调试信号产生逻辑-----------------------
always @(posedge clk) begin
	if(state == IDLE && next_state == HANDLE_RTC)is_device <= 1'b1;
	else if(state == IDLE && next_state == HANDLE_SOC)begin
		if(awvalid && wvalid)begin
			if(awaddr >= `UART_REG_ADDR && awaddr < `UART_REG_ADDR + `UART_REG_SIZE)
				is_device <= 1'b1;
			else if(awaddr >= `SRAM_START && awaddr < `SRAM_START + `SRAM_SIZE)
				is_device <= 1'b0;
			else if(awaddr >= `SPI_ADDR && awaddr < `SPI_ADDR + `SPI_SIZE)
				is_device <= 1'b1;
			else if(awaddr >= `PSRAM_ADDR && awaddr < `PSRAM_ADDR + `PSRAM_SIZE)
				is_device <= 1'b0;
			else if(awaddr >= `SDRAM_ADDR && awaddr < `SDRAM_ADDR + `SDRAM_SIZE)
				is_device <= 1'b0;
			else if(awaddr >= `GPIO_ADDR && awaddr < `GPIO_ADDR + `GPIO_SIZE)
				is_device <= 1'b1;
			else if(awaddr >= `VGA_ADDR && awaddr < `VGA_ADDR + `VGA_SIZE)
				is_device <= 1'b1;
			else begin
				is_device <= 1'b0;
				$error("XBAR: Invalid write address %h", awaddr);
			end
		end
		else if(arvalid)begin
			if(araddr >= `ROM_START && araddr < `ROM_START + `ROM_SIZE)
				is_device <= 1'b0;
			else if(araddr >= `SRAM_START && araddr < `SRAM_START + `SRAM_SIZE)
				is_device <= 1'b0;
			else if(araddr >= `UART_REG_ADDR && araddr < `UART_REG_ADDR + `UART_REG_SIZE)
				is_device <= 1'b1;
			else if(araddr >= `FLASH_START && araddr < `FLASH_SIZE+`FLASH_START)
				is_device <= 1'b0;
			else if(araddr >= `SPI_ADDR && araddr < `SPI_ADDR + `SPI_SIZE)
				is_device <= 1'b1;
			else if(araddr >= `PSRAM_ADDR && araddr < `PSRAM_ADDR + `PSRAM_SIZE)
				is_device <= 1'b0;
			else if(araddr >= `SDRAM_ADDR && araddr < `SDRAM_ADDR + `SDRAM_SIZE)
				is_device <= 1'b0;
			else if(araddr >= `GPIO_ADDR && araddr < `GPIO_ADDR + `GPIO_SIZE)
				is_device <= 1'b1;
			else if(araddr >= `PS2_ADDR && araddr < `PS2_ADDR + `PS2_SIZE)
				is_device <= 1'b1;
			else begin
				is_device <= 1'b0;
				$error("XBAR: Invalid read address %h", araddr);
			end
		end
		else is_device <= is_device;
	end
	else is_device <= is_device;
end
endmodule

