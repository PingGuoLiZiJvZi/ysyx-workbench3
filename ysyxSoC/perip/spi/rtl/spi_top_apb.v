module spi_top_apb #(
  parameter flash_addr_start = 32'h30000000,
  parameter flash_addr_end   = 32'h3fffffff,
  parameter spi_ss_num       = 8
) (
  input         clock,
  input         reset,
  input  [31:0] in_paddr,
  input         in_psel,
  input         in_penable,
  input  [2:0]  in_pprot,
  input         in_pwrite,
  input  [31:0] in_pwdata,
  input  [3:0]  in_pstrb,
  output        in_pready,
  output [31:0] in_prdata,
  output        in_pslverr,

  output                  spi_sck,
  output [spi_ss_num-1:0] spi_ss,
  output                  spi_mosi,
  input                   spi_miso,
  output                  spi_irq_out
);

// 状态定义
localparam APB           = 4'b0000;
localparam XIP_SET_DIV   = 4'b0001;
localparam XIP_SET_CTRL  = 4'b0010;
localparam XIP_SET_ADDR0 = 4'b0011;
localparam XIP_SET_ADDR1 = 4'b0100;
localparam XIP_SET_SS    = 4'b0101;
localparam XIP_START     = 4'b0110;
localparam XIP_WAIT      = 4'b0111;
localparam XIP_READ_RESP1 = 4'b1000;
localparam XIP_READ_RESP2 = 4'b1001; // 读取响应状态
localparam XIP_SET_DONE = 4'b1010;

reg [3:0] state;
reg [31:0] latch_addr;
reg [31:0] xip_data;

// SPI控制信号
wire [4:0]  wb_adr_i;
wire [31:0] wb_dat_i;
wire [31:0] wb_dat_o;
wire [3:0]  wb_sel_i;
wire        wb_we_i;
wire        wb_stb_i;
wire        wb_cyc_i;
wire        wb_ack_o;
wire        wb_err_o;

// 多路选择器控制信号
reg        spi_control;
reg [4:0]  wb_adr_reg;
reg [31:0] wb_dat_reg;
reg [3:0]  wb_sel_reg;
reg        wb_we_reg;
reg        wb_stb_reg;
reg        wb_cyc_reg;

// 状态机
always @(posedge clock) begin
  if (reset) begin
    state <= APB;
    spi_control <= 1'b0;
  end else begin
    case (state)
      APB: begin
        if (in_psel && in_penable) begin
          // Flash地址空间读请求
          if (!in_pwrite && (in_paddr >= flash_addr_start) && (in_paddr <= flash_addr_end)) begin
            latch_addr <= in_paddr;
            state <= XIP_SET_DIV;
            spi_control <= 1'b1;
          end
		  else if(in_pwrite && (in_paddr >= flash_addr_start) && (in_paddr <= flash_addr_end))
		  $error("SPI Flash write operation is not supported.");
        end
      end
      
      XIP_SET_DIV: begin
        if (wb_ack_o) state <= XIP_SET_CTRL;
      end
      
      XIP_SET_CTRL: begin
        if (wb_ack_o) state <= XIP_SET_ADDR0;
      end
      XIP_SET_ADDR0:begin
		if(wb_ack_o) state <= XIP_SET_ADDR1;
	  end
      XIP_SET_ADDR1: begin
        if (wb_ack_o) state <= XIP_SET_SS;
      end
      
      XIP_SET_SS: begin
        if (wb_ack_o) state <= XIP_START;
      end
      
      XIP_START: begin
        if (wb_ack_o) state <= XIP_WAIT;
      end
      
      XIP_WAIT: begin
        if (wb_ack_o && !wb_dat_o[8]) begin  // 等待GO_BSY清零            // 保存接收数据
          state <= XIP_READ_RESP1;
          spi_control <= 1'b1;
        end
      end
      XIP_READ_RESP1: begin
		if (wb_ack_o) begin
		  state <= XIP_READ_RESP2; // 读取完成后返回APB状态
		  xip_data <= {wb_dat_o[7:0], wb_dat_o[15:8], wb_dat_o[23:16], wb_dat_o[31:24]};
		  spi_control <= 1'b1;
		end
	  end
	  XIP_READ_RESP2: begin
		if (wb_ack_o) begin
		  state <= XIP_SET_DONE; // 读取完成后返回APB状态
		  spi_control <= 1'b1;
		  xip_data <= {wb_dat_o[7:0], wb_dat_o[15:8], wb_dat_o[23:16], wb_dat_o[31:24]};
		end
	  end
	  XIP_SET_DONE: begin
		state <= APB; // 返回APB状态
		spi_control <= 1'b0;
	  end
      default: state <= APB;
    endcase
  end
end

// SPI控制信号生成
always @(posedge clock) begin
  case (state)
    XIP_SET_DIV: begin
      wb_adr_reg <= 5'h14;    // DIVIDER寄存器地址
      wb_dat_reg <= 32'd0;    // 最高速度
      wb_sel_reg <= 4'hf;
      wb_we_reg <= 1'b1;
      wb_stb_reg <= 1'b1;
      wb_cyc_reg <= 1'b1;
    end
    
    XIP_SET_CTRL: begin
      wb_adr_reg <= 5'h10;    // CTRL寄存器地址
      wb_dat_reg <= {18'b0, 1'b1, 3'b0, 1'b0, 1'b0, 1'b0, 7'h40}; // ASS=1, CHAR_LEN=64
      wb_sel_reg <= 4'hf;
      wb_we_reg <= 1'b1;
      wb_stb_reg <= 1'b1;
      wb_cyc_reg <= 1'b1;
    end
    
	XIP_SET_ADDR0:begin
		wb_adr_reg <= 5'h00;    // TX1寄存器地址
      wb_dat_reg <= {8'h03, latch_addr[23:0]};    // 后续数据为0
      wb_sel_reg <= 4'hf;
      wb_we_reg <= 1'b1;
      wb_stb_reg <= 1'b1;
      wb_cyc_reg <= 1'b1;
	end

    XIP_SET_ADDR1: begin
      wb_adr_reg <= 5'h04;    // TX1寄存器地址
      wb_dat_reg <= {8'h03, latch_addr[23:0]};    // 后续数据为0
      wb_sel_reg <= 4'hf;
      wb_we_reg <= 1'b1;
      wb_stb_reg <= 1'b1;
      wb_cyc_reg <= 1'b1;
    end
    
    XIP_SET_SS: begin
      wb_adr_reg <= 5'h18;    // SS寄存器地址
      wb_dat_reg <= 32'h01;   // 选择从机0
      wb_sel_reg <= 4'hf;
      wb_we_reg <= 1'b1;
      wb_stb_reg <= 1'b1;
      wb_cyc_reg <= 1'b1;
    end
    
    XIP_START: begin
      wb_adr_reg <= 5'h10;    // CTRL寄存器地址
      wb_dat_reg <= {18'b0, 1'b1, 3'b0, 1'b0, 1'b1, 1'b0, 7'h40}; // 设置GO_BSY=1
      wb_sel_reg <= 4'hf;
      wb_we_reg <= 1'b1;
      wb_stb_reg <= 1'b1;
      wb_cyc_reg <= 1'b1;
    end
    
    XIP_WAIT: begin
      wb_adr_reg <= 5'h10;    // CTRL寄存器地址
      wb_dat_reg <= 32'd0;
      wb_sel_reg <= 4'hf;
      wb_we_reg <= 1'b0;      // 读操作
      wb_stb_reg <= 1'b1;
      wb_cyc_reg <= 1'b1;
    end
	XIP_READ_RESP1: begin
	  wb_adr_reg <= 5'h00;    // RX1寄存器地址
	  wb_dat_reg <= 32'd0;    // 读取数据
	  wb_sel_reg <= 4'hf;
	  wb_we_reg <= 1'b0;      // 读操作
	  wb_stb_reg <= 1'b1;
	  wb_cyc_reg <= 1'b1;
	end
    XIP_READ_RESP2: begin
	  wb_adr_reg <= 5'h00;    // RX1寄存器地址
	  wb_dat_reg <= 32'd0;    // 读取数据
	  wb_sel_reg <= 4'hf;
	  wb_we_reg <= 1'b0;      // 读操作
	  wb_stb_reg <= 1'b1;
	  wb_cyc_reg <= 1'b1;
	end
    default: begin
      wb_adr_reg <= 5'd0;
      wb_dat_reg <= 32'd0;
      wb_sel_reg <= 4'h0;
      wb_we_reg <= 1'b0;
      wb_stb_reg <= 1'b0;
      wb_cyc_reg <= 1'b0;
    end
  endcase
end

// SPI信号多路选择器
assign wb_adr_i = spi_control ? wb_adr_reg : in_paddr[4:0];
assign wb_dat_i = spi_control ? wb_dat_reg : in_pwdata;
assign wb_sel_i = spi_control ? wb_sel_reg : in_pstrb;
assign wb_we_i  = spi_control ? wb_we_reg  : in_pwrite;
assign wb_stb_i = spi_control ? wb_stb_reg : in_psel;
assign wb_cyc_i = spi_control ? wb_cyc_reg : in_penable;

// APB响应逻辑
assign in_pready = (state == APB) ? wb_ack_o : 
                  (state == XIP_SET_DONE) ? 1'b1 : 1'b0;
                  
assign in_prdata = (state == APB) ? wb_dat_o :
                  (state == XIP_SET_DONE) ? xip_data : 32'd0;
                  
assign in_pslverr = (state == APB) ? wb_err_o : 
                   (in_psel && in_penable && in_pwrite && 
                    (in_paddr >= flash_addr_start) && (in_paddr <= flash_addr_end)) ? 1'b1 : 1'b0;

// SPI主控制器实例化
spi_top u_spi_top (
  .wb_clk_i(clock),
  .wb_rst_i(reset),
  .wb_adr_i(wb_adr_i),
  .wb_dat_i(wb_dat_i),
  .wb_dat_o(wb_dat_o),
  .wb_sel_i(wb_sel_i),
  .wb_we_i(wb_we_i),
  .wb_stb_i(wb_stb_i),
  .wb_cyc_i(wb_cyc_i),
  .wb_ack_o(wb_ack_o),
  .wb_err_o(wb_err_o),
  .wb_int_o(spi_irq_out),

  .ss_pad_o(spi_ss),
  .sclk_pad_o(spi_sck),
  .mosi_pad_o(spi_mosi),
  .miso_pad_i(spi_miso)
);

endmodule
