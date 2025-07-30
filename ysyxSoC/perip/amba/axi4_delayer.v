module axi4_delayer(
  input         clock,
  input         reset,

  output        in_arready,
  input         in_arvalid,
  input  [3:0]  in_arid,
  input  [31:0] in_araddr,
  input  [7:0]  in_arlen,
  input  [2:0]  in_arsize,
  input  [1:0]  in_arburst,
  input         in_rready,
  output        in_rvalid,
  output [3:0]  in_rid,
  output [31:0] in_rdata,
  output [1:0]  in_rresp,
  output        in_rlast,
  output        in_awready,
  input         in_awvalid,
  input  [3:0]  in_awid,
  input  [31:0] in_awaddr,
  input  [7:0]  in_awlen,
  input  [2:0]  in_awsize,
  input  [1:0]  in_awburst,
  output        in_wready,
  input         in_wvalid,
  input  [31:0] in_wdata,
  input  [3:0]  in_wstrb,
  input         in_wlast,
                in_bready,
  output        in_bvalid,
  output [3:0]  in_bid,
  output [1:0]  in_bresp,

  input         out_arready,
  output        out_arvalid,
  output [3:0]  out_arid,
  output [31:0] out_araddr,
  output [7:0]  out_arlen,
  output [2:0]  out_arsize,
  output [1:0]  out_arburst,
  output        out_rready,
  input         out_rvalid,
  input  [3:0]  out_rid,
  input  [31:0] out_rdata,
  input  [1:0]  out_rresp,
  input         out_rlast,
  input         out_awready,
  output        out_awvalid,
  output [3:0]  out_awid,
  output [31:0] out_awaddr,
  output [7:0]  out_awlen,
  output [2:0]  out_awsize,
  output [1:0]  out_awburst,
  input         out_wready,
  output        out_wvalid,
  output [31:0] out_wdata,
  output [3:0]  out_wstrb,
  output        out_wlast,
                out_bready,
  input         out_bvalid,
  input  [3:0]  out_bid,
  input  [1:0]  out_bresp
);
  localparam DELAY_CYCLE = 5191; 
  localparam EXTRA_DELAY = DELAY_CYCLE - 1024; 
  //----------------------写逻辑延迟----------------------
  handshake_delayer u_aw_delayer (
	.clk(clock),
	.rst(reset),
	.in_valid(in_awvalid),
	.in_ready(in_awready),
	.out_valid(out_awvalid),
	.out_ready(out_awready)
  );
  handshake_delayer u_w_delayer (
	.clk(clock),
	.rst(reset),
	.in_valid(in_wvalid),
	.in_ready(in_wready),
	.out_valid(out_wvalid),
	.out_ready(out_wready)
 );
 handshake_delayer_back u_b_delayer (
	.clk(clock),
	.rst(reset),
	.in_rvalid(in_bvalid),
	.in_rready(in_bready),
	.in_rdata(),
	.out_rvalid(out_bvalid),
	.out_rready(out_bready),
	.out_rdata(0),
	.handshaked(in_awready|in_wready)
 );
  //---------------------------------------------------	
  //----------------------读逻辑延迟----------------------
  handshake_delayer u_ar_delayer (
	.clk(clock),
	.rst(reset),
	.in_valid(in_arvalid),
	.in_ready(in_arready),
	.out_valid(out_arvalid),
	.out_ready(out_arready)
  );

  handshake_delayer_back u_r_delayer (
	.clk(clock),
	.rst(reset),
	.in_rvalid(in_rvalid),
	.in_rready(in_rready),
	.in_rdata({in_rid, in_rdata,in_rresp,in_rlast}),
	.out_rvalid(out_rvalid),
	.out_rready(out_rready),
	.out_rdata({out_rid, out_rdata,out_rresp,out_rlast}),
	.handshaked(in_arready)
);

  assign out_arid = in_arid;
  assign out_araddr = in_araddr;
  assign out_arlen = in_arlen;
  assign out_arsize = in_arsize;
  assign out_arburst = in_arburst;

  assign out_awid = in_awid;
  assign out_awaddr = in_awaddr;
  assign out_awlen = in_awlen;
  assign out_awsize = in_awsize;
  assign out_awburst = in_awburst;
	
  assign out_wdata = in_wdata;
  assign out_wstrb = in_wstrb;
  assign out_wlast = in_wlast;

  assign in_bid = out_bid;
  assign in_bresp = out_bresp;

endmodule


module handshake_delayer (
  input         clk,
  input         rst,
  input 	    in_valid,
  output    in_ready,
  output    out_valid,
  input         out_ready
);
  reg [1:0] state;
  localparam WAIT_VALID = 2'b00;
  localparam WAIT_READY = 2'b01;
  localparam DELAY = 2'b10;
  localparam DONE = 2'b11;
  reg [31:0] counter;
  reg [21:0] device_counter;
  localparam DELAY_CYCLE = 5191; // 延迟周期
  localparam EXTRA_DELAY = DELAY_CYCLE - 1024; // 附加延迟
  always @(posedge clk) begin
	if(rst) begin
	  state <= WAIT_VALID;
	  counter <= 0;
	  device_counter <= 0;
  end
  else begin
	case (state)
	  WAIT_VALID: begin
		if (in_valid) begin
		  if (out_ready) begin
			state <= DONE;
		  end
		  else begin
			state <= WAIT_READY;
			counter <= 0;
		  end
		end
	end
	  WAIT_READY: begin
		counter <= counter + EXTRA_DELAY;
		if (out_ready) begin
		  state <= DELAY;
		  device_counter <= 0;
		end
	  end
	  DELAY: begin
		device_counter <= device_counter + 1;
		if (device_counter == counter[31:10]) begin
		  state <= DONE;
		end
	  end
	  DONE: begin
		state <= WAIT_VALID; // Reset to wait for next valid input
	  end
	endcase
  end
end
assign in_ready = (state == DELAY && device_counter == counter[31:10])|| (state == WAIT_VALID&& in_valid&& out_ready);
assign out_valid = (state == WAIT_VALID || state == WAIT_READY) ? in_valid : 1'b0;
endmodule

module handshake_delayer_back (
  input         clk,
  input         rst,
  output 	    in_rvalid,
  input    in_rready,
  output reg[38:0] in_rdata,
  input    out_rvalid,
  output         out_rready,
  input  [38:0] out_rdata,
  input 	   handshaked
);
  reg [1:0] state;
  localparam WAIT_VALID = 2'b00;
  localparam WAIT_READY = 2'b01;
  localparam DELAY = 2'b10;
  localparam DONE = 2'b11;
  reg [31:0] counter;
  reg [21:0] device_counter;
  localparam DELAY_CYCLE = 5191; // 延迟周期
  localparam EXTRA_DELAY = DELAY_CYCLE - 1024; // 附加延迟

  always @(posedge clk) begin
	if(rst) begin
	  state <= WAIT_READY;
	  counter <= 0;
	  device_counter <= 0;
  end
  else begin
	if(handshaked && state == DELAY && state == DONE)$error("handshaked should not be true when state is DELAY");
	if(handshaked)counter<=0;
	else if(state==DELAY) counter <= counter;
	else counter <= counter + EXTRA_DELAY;
	case (state)
	  WAIT_READY: begin
		if(in_rready) begin
		  if (out_rvalid) begin
			state <= (counter == 0) ? DONE : DELAY;
			in_rdata <= out_rdata;
			device_counter <=0;
		  end
		  else begin
			state <= WAIT_VALID;
		  end
		end
	  end
	  WAIT_VALID: begin
		if(~in_rready)begin
			state <= WAIT_READY;
		end 
		else
		 if (out_rvalid) begin
		  state <= DELAY;
		  device_counter <= 0;
		  in_rdata <= out_rdata;
		end
	  end
	  DELAY: begin
		device_counter <= device_counter + 1;
		if (device_counter == counter[31:10]) begin
		  state <= DONE;
		end
	  end
	  DONE: begin
		if(in_rready) begin
		  state <= WAIT_READY; // Reset to wait for next valid input
		end
	  end
	endcase
  end
end
assign in_rvalid = (state == DONE);
assign out_rready = (state == WAIT_READY || state == WAIT_VALID) ? in_rready : 1'b0;
endmodule


