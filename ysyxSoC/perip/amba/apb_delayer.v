module apb_delayer(
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

  output [31:0] out_paddr,
  output        out_psel,
  output        out_penable,
  output [2:0]  out_pprot,
  output        out_pwrite,
  output [31:0] out_pwdata,
  output [3:0]  out_pstrb,
  input         out_pready,
  input  [31:0] out_prdata,
  input         out_pslverr
);
//CPU主频为569.39MHZ//507
//APB时钟为100MHZ
//频率比r = 569.39 / 100 = 5.6939
//APB中的一个周期对应CPU中的5.6939个周期
//此模块负责将APB的时序延迟5.6939个周期
//放大系数s=1024
localparam s = 1024;
localparam DELAY_CYCLE = 6758; // 5.07 * 1024 = 5830.4, 取整为5830
localparam IDLE = 2'b00;
localparam WAIT = 2'b01;
localparam DELAY = 2'b10;
reg [31:0] counter;
reg [21:0] device_counter;

reg [1:0]state;
reg [31:0] prdata_latch;
reg pslverr_latch;
reg delay_done;
always @(posedge clock) begin
	if(reset)begin
		state <= IDLE;
		counter <= 0;
		device_counter <= 0;
		prdata_latch <= 0;
		pslverr_latch <= 0;
	end
else begin
	case (state)
		IDLE: begin
			delay_done <= 1;
			if (in_psel && in_penable) begin
				if(out_pready)begin
					state <= DELAY;
				    prdata_latch <= out_prdata;
					pslverr_latch <= out_pslverr;
					delay_done <= 0;
				end
				else
					state <= WAIT;
				counter <= 0;
				device_counter <= 0;
			end
		end
		WAIT: begin
			counter <= counter + DELAY_CYCLE;
			if (out_pready) begin
				state <= DELAY;
				device_counter <= 0;
				prdata_latch <= out_prdata;
				pslverr_latch <= out_pslverr;
			end
		end
		DELAY: begin
			device_counter <= device_counter + 1;
			if(device_counter == counter[31:10]) begin
				state <= IDLE;
				device_counter <= 0;
				delay_done <= 0;
			end
		end
		default: begin
			state <= IDLE; // 默认状态
			counter <= 0;
			device_counter <= 0;
			prdata_latch <= 0;
			pslverr_latch <= 0;
		end
	endcase
end
end
  
  assign out_paddr   = in_paddr;
  assign out_psel    = in_psel&&((state != DELAY));
  assign out_penable = in_penable&&(state != DELAY)&&delay_done;
  assign out_pprot   = in_pprot;
  assign out_pwrite  = in_pwrite;
  assign out_pwdata  = in_pwdata;
  assign out_pstrb   = in_pstrb;
  assign in_pready   = (state == DELAY && device_counter == counter[31:10]);
  assign in_prdata   = prdata_latch;
  assign in_pslverr  = pslverr_latch;

endmodule
