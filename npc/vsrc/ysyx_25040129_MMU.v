// module ysyx_25040129_MMU (
// 	input clk,
// 	input rst,
// 	input [31:0] satp,

// 	//-------------------读地址------------------
// 	input [31:0] in_araddr;
// 	input in_arvalid,
// 	input [2:0] in_arsize,
// 	output reg in_arready,
// 	input [7:0] in_arlen,
// 	input [1:0] in_arburst,
// 	//-------------------读数据------------------
// 	output reg [31:0] in_rdata,
// 	output reg [1:0] in_rresp,
// 	output reg in_rvalid,
// 	input in_rready,
// 	output reg in_rlast,
// 	//-------------------写地址------------------
// 	input [31:0] in_awaddr;
// 	input in_awvalid,
// 	output reg in_awready,
// 	//-------------------写数据------------------
// 	input [3:0] in_wstrb,
// 	input [31:0] in_wdata,
// 	input in_wvalid,
// 	output reg in_wready,
// 	//-------------------写响应------------------
// 	output reg [1:0] in_bresp,
// 	output reg in_bvalid,
// 	input in_bready,
// 	//-------------------请求转发------------------
// 	//-------------------读地址------------------
// 	output reg [31:0] out_araddr,
// 	output reg out_arvalid,
// 	output reg [2:0] out_arsize,
// 	input out_arready,
// 	output reg [7:0] out_arlen,
// 	output reg [1:0] out_arburst,
// 	//-------------------读数据------------------
// 	input [31:0] out_rdata,
// 	input [1:0] out_rresp,
// 	input out_rvalid,
// 	output reg out_rready,
// 	input out_rlast,
// 	//-------------------写地址------------------
// 	output reg [31:0] out_awaddr,
// 	output reg out_awvalid,
// 	input out_awready,
// 	//-------------------写数据------------------
// 	output reg [3:0] out_wstrb,
// 	output reg [31:0] out_wdata,
// 	output reg out_wvalid,
// 	input out_wready,
// 	//-------------------写响应------------------
// 	input [1:0] out_bresp,
// 	input out_bvalid,
// 	output reg out_bready,
// );
// 	localparam NO_VIRTUAL_MEMORY = 0;
// 	//表示不使用虚拟内存
// 	//通过satp寄存器的值来判断是否使用虚拟内存
// 	//在此情况下，直接将输入输出相连
// 	//如果需要使用虚拟内存，需要经历以下步骤：
// 	//总线协议规定，valid信号不能被拉低
// 	//首先，确认收到总线请求，但不握手，拿到虚拟地址
// 	//随后，根据satp的值，发送读取根页表的请求
// 	//拿到根页表的物理地址
// 	//然后，发送读取页表的请求
// 	//拿到页表项的物理地址
// 	//最后，发送读取物理地址的请求
// 	//利用物理地址成功完成读取/写入操作
// 	//回复ready信号
// 	//但这样有一个问题
// 	//理论上，AXI协议是读写双工的
// 	//但是在MMU，无法同时处理读和写
// 	//而且，AXI突发的自增地址模式可能会横跨页表
// 	//可能需要修改仿真环境，自增在MMU中完成?
// endmodule
