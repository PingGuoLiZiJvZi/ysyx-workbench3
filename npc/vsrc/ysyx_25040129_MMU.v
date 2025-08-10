module ysyx_25040129_MMU (
	input clk,
	input rst,
	// verilator lint_off UNUSED
	// verilator lint_on UNUSED

	//-------------------读地址------------------
	input [31:0] in_araddr,
	input in_arvalid,
	input [2:0] in_arsize,
	output in_arready,
	input [7:0] in_arlen,
	input [1:0] in_arburst,
	input [31:0] in_arsatp,
	//-------------------读数据------------------
	output [31:0] in_rdata,
	output [1:0] in_rresp,
	output in_rvalid,
	input in_rready,
	output in_rlast,
	//-------------------写地址------------------
	input [31:0] in_awaddr,
	input in_awvalid,
	output in_awready,
	input [31:0] in_awsatp,
	//-------------------写数据------------------
	input [3:0] in_wstrb,
	input [31:0] in_wdata,
	input in_wvalid,
	output in_wready,
	//-------------------写响应------------------
	output [1:0] in_bresp,
	output in_bvalid,
	input in_bready,
	//-------------------请求转发------------------
	//-------------------读地址------------------
	output [31:0] out_araddr,
	output out_arvalid,
	output [2:0] out_arsize,
	input out_arready,
	output [7:0] out_arlen,
	output [1:0] out_arburst,
	//-------------------读数据------------------
	input [31:0] out_rdata,
	input [1:0] out_rresp,
	input out_rvalid,
	output out_rready,
	/* verilator lint_off UNUSEDSIGNAL */
	input out_rlast,
	/* verilator lint_on UNUSEDSIGNAL */
	//-------------------写地址------------------
	output [31:0] out_awaddr,
	output out_awvalid,
	input out_awready,
	//-------------------写数据------------------
	output [3:0] out_wstrb,
	output [31:0] out_wdata,
	output out_wvalid,
	input out_wready,
	//-------------------写响应------------------
	input [1:0] out_bresp,
	input out_bvalid,
	output out_bready
);
//-----------------------在不使用虚拟内存的情况下，直接转发请求-----------------------
wire direct_forward;
wire is_pte1, is_pte2, is_physical;
wire is_arvalid_out;
wire is_read;
assign is_read = state == READ_GET_PTE1_WAIT_READY || state == READ_GET_PTE1_WAIT_VALID ||
					state == READ_GET_PTE2_WAIT_READY || state == READ_GET_PTE2_WAIT_VALID ||
					state == READ_WAIT_READY || state == READ_WAIT_VALID || state == READ_DONE;
/* verilator lint_off UNUSEDSIGNAL */
reg [31:0] satp;
/* verilator lint_on UNUSEDSIGNAL */
assign is_arvalid_out = state == READ_GET_PTE1_WAIT_READY||state == READ_GET_PTE2_WAIT_READY
						|| state == READ_WAIT_READY || state == WRITE_GET_PTE1_WAIT_READY
						|| state == WRITE_GET_PTE2_WAIT_READY;
wire is_rready_out;

assign is_rready_out = state == READ_GET_PTE1_WAIT_VALID || state == READ_GET_PTE2_WAIT_VALID ||
						state == READ_WAIT_VALID || state == WRITE_GET_PTE1_WAIT_VALID ||
						state == WRITE_GET_PTE2_WAIT_VALID ;

assign is_physical = state == READ_WAIT_VALID || state == READ_WAIT_READY ||
						state == WRITE_WAIT_VALID || state == WRITE_WAIT_AW_READY ||
						state == WRITE_WAIT_W_READY || state == WRITE_WAIT_READY;

assign is_pte1 = state == READ_GET_PTE1_WAIT_READY || state == READ_GET_PTE1_WAIT_VALID ||
					   state == WRITE_GET_PTE1_WAIT_READY || state == WRITE_GET_PTE1_WAIT_VALID;

assign is_pte2 = state == READ_GET_PTE2_WAIT_READY || state == READ_GET_PTE2_WAIT_VALID ||
					   state == WRITE_GET_PTE2_WAIT_READY || state == WRITE_GET_PTE2_WAIT_VALID;

assign direct_forward = state == NO_VIRTUAL_MEMORY && satp[31] == 1'b0;

wire is_awvalid_out;
assign is_awvalid_out = state == WRITE_WAIT_AW_READY || state == WRITE_WAIT_READY;

wire is_wvalid_out;
assign is_wvalid_out = state == WRITE_WAIT_W_READY || state == WRITE_WAIT_READY;

wire is_bready_out;
assign is_bready_out = state == WRITE_WAIT_VALID ;
//---------------------------------------------------------------------------------
assign out_araddr = direct_forward ? in_araddr : (
						is_pte1 ? pte1_addr :
						is_pte2 ? pte2_addr :
						is_physical ? paddr : 32'hdeadbeef
					);
assign out_arvalid = direct_forward ? in_arvalid : is_arvalid_out;
assign out_arsize = direct_forward ? in_arsize : (
						(state == READ_WAIT_READY)? in_arsize :3'b010
					);
assign out_arlen =  in_arlen;
assign out_arburst = in_arburst;
assign out_rready = direct_forward ? in_rready : is_rready_out;
assign out_awaddr = direct_forward ? in_awaddr : (is_physical ? paddr : 32'hdeadbeef);
assign out_awvalid = direct_forward ? in_awvalid : is_awvalid_out;
assign out_wstrb =  in_wstrb ;
assign out_wdata =  in_wdata ;
assign out_wvalid = direct_forward ? in_wvalid : is_wvalid_out;
assign out_bready = direct_forward ? in_bready : is_bready_out;
//---------------------------------------------------------------------------------
assign in_arready = direct_forward ? out_arready : state == READ_DONE;
assign in_rdata = out_rdata ;
assign in_rresp = out_rresp;
assign in_rvalid = direct_forward ? out_rvalid :state == READ_DONE;
assign in_rlast =  1'b1; 
assign in_awready = direct_forward ? out_awready : state == WRITE_DONE;
assign in_wready = direct_forward ? out_wready : state == WRITE_DONE;
assign in_bresp = out_bresp ;
assign in_bvalid = direct_forward ? out_bvalid : state == WRITE_DONE;
//---------------------------------------------------------------------------------
localparam NO_VIRTUAL_MEMORY = 0;
localparam VIRTUAL_MEMORY = 1;
localparam READ_GET_PTE1_WAIT_READY = 2;
localparam READ_GET_PTE1_WAIT_VALID = 3;
localparam READ_GET_PTE2_WAIT_READY = 4;
localparam READ_GET_PTE2_WAIT_VALID = 5;
localparam READ_WAIT_READY = 6;
localparam READ_WAIT_VALID = 7;
localparam READ_DONE = 8;
localparam WRITE_GET_PTE1_WAIT_READY= 9;
localparam WRITE_GET_PTE1_WAIT_VALID = 10;
localparam WRITE_GET_PTE2_WAIT_READY = 11;
localparam WRITE_GET_PTE2_WAIT_VALID = 12;
localparam WRITE_WAIT_READY = 13;
localparam WRITE_WAIT_AW_READY = 14;
localparam WRITE_WAIT_W_READY = 15;
localparam WRITE_WAIT_VALID = 16;
localparam WRITE_DONE = 17;
//---------------------------------------------------------------------------------
wire [19:0] root_idx;
assign root_idx = satp[19:0]; 
wire [9:0] vpn1;
assign vpn1 = is_read? in_araddr[31:22]:in_awaddr[31:22]; 
wire [31:0] pte1_addr;
assign pte1_addr = {root_idx, vpn1, 2'b00}; 
wire [9:0] vpn2;
assign vpn2 = is_read? in_araddr[21:12]:in_awaddr[21:12];
wire [11:0] offset;
assign offset = is_read? in_araddr[11:0]:in_awaddr[11:0];
// verilator lint_off UNUSED
reg [31:0] pte1, pte2;
// verilator lint_on UNUSED
wire [19:0] table_idx;
assign table_idx = pte1[29:10];
wire [31:0] pte2_addr;
assign pte2_addr = {table_idx, vpn2, 2'b00};
wire [31:0] paddr;
assign paddr = {pte2[29:10], offset};
//--------------------------------------------------------------------------------- 
reg [4:0] state;
always @(posedge clk) begin
	if(rst)begin
		state <= NO_VIRTUAL_MEMORY;
	end
	else begin
		case (state)
		NO_VIRTUAL_MEMORY:begin
			if(in_arsatp[31] || in_awsatp[31])state <= VIRTUAL_MEMORY;
			else state <= NO_VIRTUAL_MEMORY; 
		end 
		VIRTUAL_MEMORY:begin
			if(in_awvalid && in_wvalid)begin
				state <= WRITE_GET_PTE1_WAIT_READY;
				satp <= in_awsatp; 
				if(!in_awsatp[31])$error("MMU: in_awsatp[31] should be 1 for virtual memory mode");
			end else if(in_arvalid)begin
				state <= READ_GET_PTE1_WAIT_READY;
				satp <= in_arsatp;
				if(!in_arsatp[31])$error("MMU: in_arsatp[31] should be 1 for virtual memory mode");
			end else begin
				state <= VIRTUAL_MEMORY;
				satp  <= 32'hdeadbeef;  
			end
		end
		READ_GET_PTE1_WAIT_READY:begin
			if(out_arready)state <= READ_GET_PTE1_WAIT_VALID;
			else state <= READ_GET_PTE1_WAIT_READY;
		end
		READ_GET_PTE1_WAIT_VALID:begin
			if(out_rvalid)begin
				pte1 <= out_rdata;
				state <= READ_GET_PTE2_WAIT_READY;
				if(out_rdata[0] == 1'b0)begin
					$error("MMU: PTE1 is not valid, pte1 = %h,addr = %h", out_rdata, pte1_addr);
				end
			end
			else state <= READ_GET_PTE1_WAIT_VALID;
		end
		READ_GET_PTE2_WAIT_READY:begin
			if(out_arready)state <= READ_GET_PTE2_WAIT_VALID;
			else state <= READ_GET_PTE2_WAIT_READY;
		end
		READ_GET_PTE2_WAIT_VALID:begin
			if(out_rvalid)begin
				pte2 <= out_rdata;
				state <= READ_WAIT_READY;
				if(out_rdata[0] == 1'b0)begin
					$error("MMU: PTE2 is not valid, pte2 = %h,addr = %h", out_rdata, pte1_addr);
				end
			end
			else state <= READ_GET_PTE2_WAIT_VALID;
		end
		READ_WAIT_READY:begin
			if(out_arready)state <= READ_WAIT_VALID;
			else state <= READ_WAIT_READY;
		end
		READ_WAIT_VALID:begin
			if(out_rvalid)state <= READ_DONE;
			else state <= READ_WAIT_VALID;
		end
		READ_DONE:begin
			if(in_rready)begin
				$display("MMU npc: read request is ready, paddr = %h, pte1 = %h, pte2 = %h", paddr, pte1, pte2);
				state <= VIRTUAL_MEMORY;
			end else begin
				state <= READ_DONE; 
			end
		end
		WRITE_GET_PTE1_WAIT_READY:begin
			if(out_arready)state <= WRITE_GET_PTE1_WAIT_VALID;
			else state <= WRITE_GET_PTE1_WAIT_READY;
		end
		WRITE_GET_PTE1_WAIT_VALID:begin
			if(out_rvalid)begin
				pte1 <= out_rdata;
				state <= WRITE_GET_PTE2_WAIT_READY;
				if(out_rdata[0] == 1'b0)begin
					$error("MMU: PTE1 is not valid, pte1 = %h,addr = %h", out_rdata, pte1_addr);
				end
			end
			else state <= WRITE_GET_PTE1_WAIT_VALID;
		end
		WRITE_GET_PTE2_WAIT_READY:begin
			if(out_arready)state <= WRITE_GET_PTE2_WAIT_VALID;
			else state <= WRITE_GET_PTE2_WAIT_READY;
		end
		WRITE_GET_PTE2_WAIT_VALID:begin
			if(out_rvalid)begin
				pte2 <= out_rdata;
				state <= WRITE_WAIT_READY;
				if(out_rdata[0] == 1'b0)begin
					$error("MMU: PTE2 is not valid, pte2 = %h,addr = %h", out_rdata, pte1_addr);
				end
			end
			else state <= WRITE_GET_PTE2_WAIT_VALID;
		end
		WRITE_WAIT_READY:begin
			if(out_awready&&out_wready) begin
				state <= WRITE_WAIT_VALID;
			end else if(out_awready) begin
				state <= WRITE_WAIT_W_READY;
			end else if(out_wready) begin
				state <= WRITE_WAIT_AW_READY;
			end else begin
				state <= WRITE_WAIT_READY; 
			end
		end
		WRITE_WAIT_AW_READY:begin
			if(out_awready)state <= WRITE_WAIT_VALID;
			else state <= WRITE_WAIT_AW_READY;
		end
		WRITE_WAIT_W_READY:begin
			if(out_wready)state <= WRITE_WAIT_VALID;
			else state <= WRITE_WAIT_W_READY;
		end
		WRITE_WAIT_VALID:begin
			if(out_bvalid)state <= WRITE_DONE;
			else state <= WRITE_WAIT_VALID;
		end
		WRITE_DONE:begin
			if(in_bready)begin
				state <= VIRTUAL_MEMORY;
			end else begin
				state <= WRITE_DONE; 
			end
		end
		endcase
	end
end
endmodule
