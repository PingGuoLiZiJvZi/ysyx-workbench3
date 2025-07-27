import "DPI-C" function void soc_write(int addr,byte strb, int data);
import "DPI-C" function int soc_read(int addr);
module ysyxSoCFull (
	input clock,
	input reset
);
//这是脱离了soc的功能验证模块
//所有从top中传出的AXI-Lite信号都在这里被DPI-C瞬间处理

ysyx_25040129_top u_top (
	.clock                   (clock),
    .reset                   (reset),
    .io_interrupt            (1'h0),	//:35:23, :36:19, :38:21
    .io_master_awready      (awready),
    .io_master_awvalid      (awvalid),
    .io_master_awid    (/* unused */),
    .io_master_awaddr  (awaddr),
    .io_master_awlen   (/* unused */),
    .io_master_awsize  (/* unused */),
    .io_master_awburst (/* unused */),
    .io_master_wready       (wready),
    .io_master_wvalid       (wvalid),
    .io_master_wdata   (wdata),
    .io_master_wstrb   (wstrb),
    .io_master_wlast   (/* unused */),
    .io_master_bready       (bready),
    .io_master_bvalid       (bvalid),
    .io_master_bid     (4'b0),
    .io_master_bresp   (bresp),
    .io_master_arready      (arready),
    .io_master_arvalid      (arvalid),
    .io_master_arid    (/* unused */),
    .io_master_araddr  (araddr),
    .io_master_arlen   (/* unused */),
    .io_master_arsize  (/* unused */),
    .io_master_arburst (/* unused */),
    .io_master_rready       (rready),
    .io_master_rvalid       (rvalid),
    .io_master_rid     (4'b0),
    .io_master_rdata   (rdata),
    .io_master_rresp   (rresp),
    .io_master_rlast   (1'b0),
    .io_slave_awready       (/* unused */),
    .io_slave_awvalid       (1'h0),	//:35:23, :36:19, :38:21
    .io_slave_awid     (4'h0),	//:36:19, :38:21
    .io_slave_awaddr   (32'h0),	//:36:19, :38:21
    .io_slave_awlen    (8'h0),	//:36:19, :38:21
    .io_slave_awsize   (3'h0),	//:36:19, :38:21
    .io_slave_awburst  (2'h0),	//:36:19, :38:21
    .io_slave_wready        (/* unused */),
    .io_slave_wvalid        (1'h0),	//:35:23, :36:19, :38:21
    .io_slave_wdata    (32'h0),	//:36:19, :38:21
    .io_slave_wstrb    (4'h0),	//:36:19, :38:21
    .io_slave_wlast    (1'h0),	//:35:23, :36:19, :38:21
    .io_slave_bready        (1'h0),	//:35:23, :36:19, :38:21
    .io_slave_bvalid        (/* unused */),
    .io_slave_bid      (/* unused */),
    .io_slave_bresp    (/* unused */),
    .io_slave_arready       (/* unused */),
    .io_slave_arvalid       (1'h0),	//:35:23, :36:19, :38:21
    .io_slave_arid     (4'h0),	//:36:19, :38:21
    .io_slave_araddr   (32'h0),	//:36:19, :38:21
    .io_slave_arlen    (8'h0),	//:36:19, :38:21
    .io_slave_arsize   (3'h0),	//:36:19, :38:21
    .io_slave_arburst  (2'h0),	//:36:19, :38:21
    .io_slave_rready        (1'h0),	//:35:23, :36:19, :38:21
    .io_slave_rvalid        (/* unused */),
    .io_slave_rid      (/* unused */),
    .io_slave_rdata    (/* unused */),
    .io_slave_rresp    (/* unused */),
    .io_slave_rlast    (/* unused */));
//-------------------读地址-----------------------
wire [31:0] araddr;
wire arvalid;
wire arready;
//-------------------读数据-----------------------
reg [31:0] rdata;
wire [1:0] rresp;
wire rvalid;
wire rready;
//-------------------写地址-----------------------
wire [31:0] awaddr;
wire awvalid;
wire awready;
//-------------------写数据-----------------------
wire [3:0] wstrb;
wire [31:0] wdata;
wire wvalid;
wire wready;
//-------------------写响应-----------------------
wire [1:0] bresp;
wire bvalid;
wire bready;
//-------------------DPI-C-----------------------

wire [4:0] delay = 5'b1;
localparam  R_IDLE = 3'b000;
localparam  R_READING = 3'b001;
localparam  R_WAIT_R_READY = 3'b010;

localparam  W_IDLE = 3'b000;
localparam  W_WAIT_AW_VALID = 3'b001; 
localparam  W_WAIT_W_VALID = 3'b010;
localparam  W_WRITING = 3'b100;
localparam  W_WAIT_B_READY = 3'b101;
/* verilator lint_off UNUSEDSIGNAL */
reg [31:0] read_addr_store;
reg [31:0] write_addr_store;
reg [31:0] write_data_store;
reg [3:0] write_strb_store;
/* verilator lint_on UNUSEDSIGNAL */
reg [2:0] r_state;
reg [2:0] next_r_state;
reg [2:0] w_state;
reg [2:0] next_w_state;
reg [4:0] r_delay_cnt;
reg [4:0] r_delay;
reg [4:0] w_delay_cnt;
reg [4:0] w_delay;
always @(*) begin
	case (r_state)
		R_IDLE: next_r_state = arvalid ?R_READING : R_IDLE;
		R_READING: next_r_state = (r_delay_cnt == r_delay) ? R_WAIT_R_READY : R_READING;
		R_WAIT_R_READY: next_r_state = rready ? R_IDLE : R_WAIT_R_READY;
		default: next_r_state = R_IDLE;
	endcase
	case (w_state)
		W_IDLE: next_w_state = awvalid ? (wvalid?W_WRITING:W_WAIT_W_VALID) : (wvalid?W_WAIT_AW_VALID:W_IDLE);
		W_WAIT_AW_VALID: next_w_state = awvalid ?W_WRITING : W_WAIT_AW_VALID;
		W_WAIT_W_VALID: next_w_state = wvalid ?W_WRITING: W_WAIT_W_VALID;
		W_WRITING: next_w_state = (w_delay_cnt == w_delay) ? W_WAIT_B_READY : W_WRITING;
		W_WAIT_B_READY: next_w_state = bready ? W_IDLE : W_WAIT_B_READY;
		default: next_w_state = W_IDLE;
endcase
end

assign arready = (r_state == R_IDLE);
assign rvalid = (r_state == R_WAIT_R_READY);
assign rresp = 2'b00; // OKAY
assign awready = (w_state == W_IDLE) || (w_state == W_WAIT_AW_VALID);
assign wready = (w_state == W_WAIT_W_VALID) || (w_state == W_IDLE);
assign bvalid = (w_state == W_WAIT_B_READY);
assign bresp = 2'b00; // OKAY

always @(posedge clock) begin
	if(reset)begin
		r_state <= R_IDLE;
		w_state <= W_IDLE;
	end else begin
		r_state <= next_r_state;
		if((r_state !=R_READING)&&(next_r_state == R_READING))begin
			r_delay <= delay; 
			r_delay_cnt <= 1; 
		end
		else r_delay_cnt <= r_delay_cnt + 1;
		w_state <= next_w_state;
		if(w_state!= W_WRITING&&next_w_state == W_WRITING) begin
			w_delay <= delay; 
			w_delay_cnt <= 1;
		end
		else w_delay_cnt <= w_delay_cnt + 1;
	end
end

always @(posedge clock) begin
	if(next_r_state == R_WAIT_R_READY)begin
		rdata <= soc_read(read_addr_store);
	end
	else if(next_w_state == W_WAIT_B_READY) begin
		soc_write(write_addr_store, {4'b0,write_strb_store}, write_data_store);
	end
end
//在进入对应状态时，锁存必要数据
always @(posedge clock) begin
	if(r_state == R_IDLE && arvalid) read_addr_store <= araddr;
	if(w_state == W_IDLE && awvalid && wvalid) begin 
		write_addr_store <= awaddr;
		write_data_store <= wdata;
		write_strb_store <= wstrb;
	end
	else if(w_state == W_WAIT_AW_VALID && awvalid) write_addr_store <= awaddr;
	else if(w_state == W_WAIT_W_VALID && wvalid) begin
		write_data_store <= wdata;
		write_strb_store <= wstrb;
	end
end
endmodule