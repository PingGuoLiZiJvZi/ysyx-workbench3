module vga_top_apb(
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

  output [7:0]  vga_r,
  output [7:0]  vga_g,
  output [7:0]  vga_b,
  output        vga_hsync,
  output        vga_vsync,
  output        vga_valid
);
  wire [31:0] vga_data;
  reg [31:0] vga_buffer [639:0][479:0]; // 640x480 resolution
  reg [1:0] state;
  reg [1:0] next_state;
  wire [31:0] relative_addr_4;
  wire [29:0] relative_addr;
  assign relative_addr_4 = (in_paddr - `ysyx_25040129_VGA_ADDR); // 32-bit address, 4-byte aligned
  assign relative_addr = relative_addr_4[31:2]; // 30-bit address for 640x480 resolution
  localparam IDLE = 2'b00;
  localparam WRITE = 2'b01;
  localparam DONE = 2'b10;

  always @(posedge clock) begin
	if(reset)state <= IDLE;
	else state <= next_state;
  end

  always @(*) begin
	case (state)
		IDLE:next_state = (in_psel && in_pwrite) ?  WRITE :IDLE;
		WRITE:next_state = DONE;
		DONE:next_state = IDLE;
		default:next_state = IDLE; 
	endcase
  end
  always @(posedge clock) begin
		if(state == WRITE) begin
			if(in_paddr < `ysyx_25040129_VGA_ADDR || in_paddr >= `ysyx_25040129_VGA_ADDR + `ysyx_25040129_VGA_SIZE) begin
				$error("vga write addr %h out of range [%h, %h),state = %b", in_paddr, `ysyx_25040129_VGA_ADDR, `ysyx_25040129_VGA_ADDR + `ysyx_25040129_VGA_SIZE, state);
			end
			// $display("vga write addr width %d height %d data %h", relative_addr%640, relative_addr/640, in_pwdata);
			vga_buffer[relative_addr[9:0]][relative_addr[18:10]] <= in_pwdata;
		end
  end
 assign in_pready = (state == DONE);
 assign in_pslverr = 1'b0; // No slave error

  parameter    h_frontporch = 96;
  parameter    h_active = 144;
  parameter    h_backporch = 784;
  parameter    h_total = 800;

  parameter    v_frontporch = 2;
  parameter    v_active = 35;
  parameter    v_backporch = 515;
  parameter    v_total = 525;

  //像素计数值
  reg [9:0]    x_cnt;
  reg [9:0]    y_cnt;
  wire         h_valid;
  wire         v_valid;
  wire [9:0] h_addr;
  wire [9:0] v_addr;
  assign vga_data = vga_buffer[h_addr][v_addr[8:0]];

  always @(posedge clock) //行像素计数
      if (reset == 1'b1)
        x_cnt <= 1;
      else
      begin
		// if(vga_data !== 32'h0) // Check if the pixel data is valid
		// $display("haddr = %d vaddr = %d data = %h", h_addr, v_addr, vga_data);
        if (x_cnt == h_total)
            x_cnt <= 1;
        else
            x_cnt <= x_cnt + 10'd1;
      end

  always @(posedge clock)  //列像素计数
      if (reset == 1'b1)
        y_cnt <= 1;
      else
      begin
        if (y_cnt == v_total & x_cnt == h_total)
            y_cnt <= 1;
        else if (x_cnt == h_total)
            y_cnt <= y_cnt + 10'd1;
      end
  //生成同步信号
  assign vga_hsync = (x_cnt > h_frontporch);
  assign vga_vsync = (y_cnt > v_frontporch);
  //生成消隐信号
  assign h_valid = (x_cnt > h_active) & (x_cnt <= h_backporch);
  assign v_valid = (y_cnt > v_active) & (y_cnt <= v_backporch);
  assign vga_valid = h_valid & v_valid;
  //计算当前有效像素坐标
  assign h_addr = h_valid ? (x_cnt - 10'd145) : {10{1'b0}};
  assign v_addr = v_valid ? (y_cnt - 10'd36) : {10{1'b0}};
  //设置输出的颜色值
  assign vga_r = vga_data[23:16];
  assign vga_g = vga_data[15:8];
  assign vga_b = vga_data[7:0];

endmodule
