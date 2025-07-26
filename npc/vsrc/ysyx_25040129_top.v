import "DPI-C" function void ebreak_trigger();
import "DPI-C" function void unknown_inst(int inst);
import "DPI-C" function int paddr_read(int addr, int len,int is_fetch, int is_avail);
import "DPI-C" function void paddr_write(int addr, int len, int data, int is_avail);
import "DPI-C" function void update_regs(int reg1, int reg2, int reg3, int reg4, int reg5, int reg6, int reg7, int reg8, int reg9, int reg10, int reg11, int reg12, int reg13, int reg14, int reg15, int reg16);
import "DPI-C" function void update_pc(int pc);
import "DPI-C" function void update_inst(int inst);
import "DPI-C" function void update_is_device(bit is_device);
import "DPI-C" function void update_ifu_state(byte ifu_state);
import "DPI-C" function void fetch_count_inc(byte ifu_state);
import "DPI-C" function void execute_count_inc(byte exu_state);
import "DPI-C" function void load_store_count_inc(byte lsu_state);
import "DPI-C" function void track_inst_in_idu(byte idu_state,byte opcode);
/*verilator lint_off DECLFILENAME*/module ysyx_25040129_top(
	input clock,
	input reset,
  // --------------- master -----------------
  input  io_interrupt,

  // --------------- master 写地址 AW -----------------
  input  io_master_awready,
  output io_master_awvalid,
  output [3:0]  io_master_awid,
  output [31:0] io_master_awaddr,
  output [7:0]  io_master_awlen,
  output [2:0]  io_master_awsize,
  output [1:0]  io_master_awburst,

  // --------------- master 写数据 W -----------------
  input  io_master_wready,
  output io_master_wvalid,
  output [31:0] io_master_wdata,
  output [3:0]  io_master_wstrb,
  output io_master_wlast,

  // --------------- master 写响应 B -----------------
  output io_master_bready,
  input  io_master_bvalid,
  input  [3:0] io_master_bid,
  input  [1:0] io_master_bresp,

  // --------------- master 读地址 AR -----------------
  input  io_master_arready,
  output io_master_arvalid,
  output [3:0]  io_master_arid,
  output [31:0] io_master_araddr,
  output [7:0]  io_master_arlen,
  output [2:0]  io_master_arsize,
  output [1:0]  io_master_arburst,

  // --------------- master 读数据 R -----------------
  output io_master_rready,
  input  io_master_rvalid,
  input  [3:0]  io_master_rid,
  input  [31:0] io_master_rdata,
  input  [1:0]  io_master_rresp,
  input  io_master_rlast,

  // --------------- slave 写地址 AW -----------------
  output io_slave_awready,
  input  io_slave_awvalid,
  input  [3:0]  io_slave_awid,
  input  [31:0] io_slave_awaddr,
  input  [7:0]  io_slave_awlen,
  input  [2:0]  io_slave_awsize,
  input  [1:0]  io_slave_awburst,

  // --------------- slave 写数据 W -----------------
  output io_slave_wready,
  input  io_slave_wvalid,
  input  [31:0] io_slave_wdata,
  input  [3:0]  io_slave_wstrb,
  input  io_slave_wlast,

  // --------------- slave 写响应 B -----------------
  input  io_slave_bready,
  output io_slave_bvalid,
  output [3:0] io_slave_bid,
  output [1:0] io_slave_bresp,

  // --------------- slave 读地址 AR -----------------
  output io_slave_arready,
  input  io_slave_arvalid,
  input  [3:0]  io_slave_arid,
  input  [31:0] io_slave_araddr,
  input  [7:0]  io_slave_arlen,
  input  [2:0]  io_slave_arsize,
  input  [1:0]  io_slave_arburst,

  // --------------- slave 读数据 R -----------------
  input  io_slave_rready,
  output io_slave_rvalid,
  output [3:0]  io_slave_rid,
  output [31:0] io_slave_rdata,
  output [1:0]  io_slave_rresp,
  output io_slave_rlast
);
	wire clk;
	assign clk = clock;
	wire rst;
	assign rst = reset;
	assign io_master_arlen = 8'b0;
	assign io_master_arburst = 2'b01; // INCR
	assign io_master_arid = 4'b0;
	
	

	ysyx_25040129_XBAR u_ysyx_25040129_XBAR(
		.clk(clk),
		.rst(rst),

		.araddr(araddr_to_xbar),
		.arvalid(arvalid_to_xbar),
		.arready(arready_from_xbar),
		.arsize(arsize_to_xbar),

		.rdata(rdata_from_xbar),
		.rresp(rresp_from_xbar),
		.rvalid(rvalid_from_xbar),
		.rready(rready_to_xbar),

		.awaddr(awaddr_from_lsu),
		.awvalid(awvalid_from_lsu),
		.awready(awready_to_lsu),

		.wstrb(wstrb_from_lsu),
		.wdata(wdata_from_lsu),
		.wvalid(wvalid_from_lsu),
		.wready(wready_to_lsu),

		.bresp(bresp_to_lsu),
		.bvalid(bvalid_to_lsu),
		.bready(bready_from_lsu),

		.soc_araddr(io_master_araddr),
		.soc_arvalid(io_master_arvalid),
		.soc_arready(io_master_arready),
		.soc_arsize(io_master_arsize),

		.soc_rdata(io_master_rdata),
		.soc_rresp(io_master_rresp),
		.soc_rvalid(io_master_rvalid),
		.soc_rready(io_master_rready),

		.soc_awaddr(io_master_awaddr),
		.soc_awvalid(io_master_awvalid),
		.soc_awready(io_master_awready),

		.soc_wstrb(io_master_wstrb),
		.soc_wdata(io_master_wdata),
		.soc_wvalid(io_master_wvalid),
		.soc_wready(io_master_wready),

		.soc_bresp(io_master_bresp),
		.soc_bvalid(io_master_bvalid),
		.soc_bready(io_master_bready),

		.rtc_araddr(araddr_to_rtc),
		.rtc_arvalid(arvalid_to_rtc),
		.rtc_arready(arready_from_rtc),

		.rtc_rdata(rdata_from_rtc),
		.rtc_rresp(rresp_from_rtc),
		.rtc_rvalid(rvalid_from_rtc),
		.rtc_rready(rready_to_rtc)
	);
	wire [31:0] araddr_to_rtc;
	wire arvalid_to_rtc;
	wire arready_from_rtc;

	wire [31:0] rdata_from_rtc;
	wire [1:0] rresp_from_rtc;
	wire rvalid_from_rtc;
	wire rready_to_rtc;

	ysyx_25040129_CLINT u_ysyx_25040129_CLINT (
		.clk(clk),
		.rst(rst),

		.araddr(araddr_to_rtc),
		.arvalid(arvalid_to_rtc),
		.arready(arready_from_rtc),

		.rdata(rdata_from_rtc),
		.rresp(rresp_from_rtc),
		.rvalid(rvalid_from_rtc),
		.rready(rready_to_rtc)
	);


 	wire [31:0] araddr_to_soc;
	wire arvalid_to_soc;
	wire arready_from_soc;

	wire [31:0] rdata_from_soc;
	wire [1:0] rresp_from_soc;
	wire rvalid_from_soc;
	wire rready_to_soc;

	wire [31:0] awaddr_to_soc;
	wire awvalid_to_soc;
	wire awready_from_soc;

	wire [3:0] wstrb_to_soc;
	wire [31:0] wdata_to_soc;
	wire wvalid_to_soc;
	wire wready_from_soc;

	wire [1:0] bresp_from_soc;
	wire bvalid_from_soc;
	wire bready_to_soc;


	ysyx_25040129_BUSARB u_ysyx_25040129_BUSARB(
		.clk(clk),
		.rst(rst),

		.ifu_araddr(araddr_from_ifu),
		.ifu_arvalid(arvalid_from_ifu),
		.ifu_arready(rready_to_ifu),

		.ifu_rdata(rdata_to_ifu),
		.ifu_rresp(rresp_to_ifu),
		.ifu_rvalid(rvalid_to_ifu),
		.ifu_rready(rready_from_ifu),

		.lsu_araddr(araddr_from_lsu),
		.lsu_arvalid(arvalid_from_lsu),
		.lsu_arready(rready_to_lsu),
		.lsu_arsize(arsize_from_lsu),

		.lsu_rdata(rdata_to_lsu),
		.lsu_rresp(rresp_to_lsu),
		.lsu_rvalid(rvalid_to_lsu),
		.lsu_rready(rready_from_lsu),

		.araddr(araddr_to_xbar),
		.arvalid(arvalid_to_xbar),
		.arready(arready_from_xbar),
		.arsize(arsize_to_xbar),

		.rdata(rdata_from_xbar),
		.rresp(rresp_from_xbar),
		.rvalid(rvalid_from_xbar),
		.rready(rready_to_xbar)
	);	
	wire [2:0] arsize_to_xbar;
	wire [31:0] araddr_to_xbar;
	wire arvalid_to_xbar;
	wire rready_to_xbar;
	wire [31:0] rdata_from_xbar;
	wire [1:0] rresp_from_xbar;
	wire rvalid_from_xbar;
	wire arready_from_xbar;
	
	/* verilator lint_off UNUSEDSIGNAL */
	wire empty_awready;
	wire empty_wready;
	wire empty_bvalid;
	wire [1:0] empty_bresp;
	/* verilator lint_on UNUSEDSIGNAL */


	ysyx_25040129_IFU u_ysyx_25040129_IFU (
		.pc(pc_from_ifu),
		.is_branch(is_branch_out_wbu),
		.jump_target(branch_target_out_wbu),
	
		.inst_to_idu(inst_to_idu),
		.is_req_valid_to_idu(is_req_valid_from_ifu_to_idu),
		
		.is_req_ready_to_wbu(is_req_ready_from_ifu_to_wbu),
		
		.is_req_valid_from_wbu(is_req_valid_from_wb_to_ifu),
		.is_req_ready_from_idu(is_req_ready_from_idu_to_ifu),
		
		.rst(rst),
		.clk(clk),

		.araddr(araddr_from_ifu),
		.arvalid(arvalid_from_ifu),
		.arready(rready_to_ifu),

		.rdata(rdata_to_ifu),
		.rresp(rresp_to_ifu),
		.rvalid(rvalid_to_ifu),
		.rready(rready_from_ifu)
	);

	wire [31:0] pc_from_ifu;

	wire [31:0] inst_to_idu;

	wire is_req_valid_from_wb_to_ifu;
	wire [31:0] araddr_from_ifu;
	wire arvalid_from_ifu;
	wire rready_to_ifu;

	wire [31:0] rdata_to_ifu;
	wire [1:0] rresp_to_ifu;
	wire rvalid_to_ifu;
	wire rready_from_ifu;
	// wire is_req_valid_from_ifu_to_mmem;
	// wire is_rsp_ready_from_ifu_to_mmem;
	// wire is_rsp_valid_from_mmem_to_ifu;
	wire is_req_ready_from_idu_to_ifu;
	// wire is_req_ready_from_mmem_to_ifu;
	wire is_req_valid_from_ifu_to_idu;
	wire is_req_ready_from_ifu_to_wbu;

	ysyx_25040129_IDU u_ysyx_25040129_IDU (
		.clk(clk),
		.rst(rst),

		.inst(inst_to_idu),
		.pc(pc_from_ifu),
		.src1_id(src1_id_out_idu),
		.src2_id(src2_id_out_idu),
		.csr_id_out_idu(csr_id_out_idu),
		.src1_in_idu(src1_in_idu),
		.src2_in_idu(src2_in_idu),
		.lsu_write_data_out_idu(lsu_write_data_out_idu),
		.csr_in_idu(csr_in_idu),
	
		.src1_out_idu(src1_out_idu),
		.src2_out_idu(src2_out_idu),
		
		.imm(imm),
		.rd_out_idu(rd_out_idu),
		.alu_opcode(alu_opcode),
		.reg_write_out_idu(reg_write_out_idu),
		.is_jalr_out_idu(is_jalr_out_idu),
		.lsu_write_out_idu(lsu_write_out_idu),
		.lsu_read_out_idu(lsu_read_out_idu),
		.ecall_out_idu(ecall_out_idu),
		.is_jump_out_idu(is_jump_out_idu),
		.ebreak_out_idu(ebreak_out_idu),
		.mret_out_idu(mret_out_idu),

		.csr_write_out_idu(csr_write_out_idu),

		.is_req_valid_from_ifu(is_req_valid_from_ifu_to_idu),
		.is_req_ready_to_ifu(is_req_ready_from_idu_to_ifu),
		.is_req_valid_to_exu(is_req_valid_from_idu_to_exu),
		.is_req_ready_from_exu(is_req_ready_from_exu_to_idu)
	);
	wire is_jalr_out_idu;
	wire is_req_valid_from_idu_to_exu;
	wire is_req_ready_from_exu_to_idu;
	wire [31:0] src1_in_idu;
	wire [31:0] src2_in_idu;
	wire [31:0] csr_in_idu;
	wire [11:0] csr_id_out_idu;
	wire [31:0] src1_out_idu;
	wire [31:0] src2_out_idu;
	wire [31:0] lsu_write_data_out_idu;
	wire [4:0] src1_id_out_idu;
	wire [4:0] src2_id_out_idu;
	
	wire [31:0] imm;
	wire [4:0] rd_out_idu;
	wire [3:0] alu_opcode;
	wire reg_write_out_idu;
	wire [1:0] lsu_write_out_idu;
	wire [2:0] lsu_read_out_idu;
	wire ecall_out_idu;
	wire is_jump_out_idu;
	wire ebreak_out_idu;
	wire mret_out_idu;

	wire csr_write_out_idu;

	ysyx_25040129_REG u_ysyx_25040129_REG (
		.clk(clk),
		.rst(rst),
		.rd(rd_out_wbu),
		.reg_write(reg_write_out_wbu),
		.result(result_out_wbu),
		.src1_id(src1_id_out_idu),
		.src2_id(src2_id_out_idu),
		.src1(src1_in_idu),
		.src2(src2_in_idu)
	);

	ysyx_25040129_CSR u_ysyx_25040129_CSR (
		.clk(clk),
		.rst(rst),
		.csr_write(csr_write_out_wbu),
		.csr_read_addr(csr_id_out_idu),
		.csr_write_addr(csr_addr_out_wbu),
		.csr_data(result_out_wbu),
		.csr_out(csr_in_idu),
		.ecall(ecall_out_wbu),
		.mret(mret_out_wbu),
		.mepc_data(pc_out_wbu),
		.mcause_data(32'd11),
		.target_from_csr(target_from_csr_to_wbu)
	);
	
	ysyx_25040129_EXU u_ysyx_25040129_EXU (
		.clk(clk),
		.rst(rst),

		.pc(pc_from_ifu),
		.pc_out_exu(pc_out_exu),
		.src1(src1_out_idu),
		.src2(src2_out_idu),
		.imm(imm),
		.alu_opcode(alu_opcode),
		.result_out_exu(result_out_exu),

		.is_jalr_in_exu(is_jalr_out_idu),

		.lsu_write_data_in_exu(lsu_write_data_out_idu), // 该信号将被一路传递至MEM阶段
		.lsu_write_data_out_exu(lsu_write_data_out_exu),
		.branch_target_out_exu(branch_target_out_exu),

		.ebreak_in_exu(ebreak_out_idu),
		.rd_in_exu(rd_out_idu),
		.csr_write_in_exu(csr_write_out_idu),
		.ecall_in_exu(ecall_out_idu),
		.mret_in_exu(mret_out_idu),
		.reg_write_in_exu(reg_write_out_idu),

		.rd_out_exu(rd_out_exu),
		.csr_write_out_exu(csr_write_out_exu),
		.ecall_out_exu(ecall_out_exu),
		.mret_out_exu(mret_out_exu),
		.reg_write_out_exu(reg_write_out_exu),

		.lsu_read_in_exu(lsu_read_out_idu),
		.lsu_write_in_exu(lsu_write_out_idu),
		.lsu_read_out_exu(lsu_read_out_exu),
		.lsu_write_out_exu(lsu_write_out_exu),
		.is_jump_in_exu(is_jump_out_idu),
		.is_branch_out_exu(is_branch_out_exu),
		.is_req_valid_from_idu(is_req_valid_from_idu_to_exu),
		.is_req_ready_to_idu(is_req_ready_from_exu_to_idu),
		.is_req_valid_to_lsu(is_req_valid_from_exu_to_lsu),
		.is_req_ready_from_lsu(is_req_ready_from_lsu_to_exu)
	);
	wire [31:0] pc_out_exu;
	wire [31:0] lsu_write_data_out_exu;
	wire [31:0] result_out_exu;
	wire [31:0] branch_target_out_exu;
	wire [4:0] rd_out_exu;
	wire [2:0] lsu_read_out_exu;
	wire [1:0] lsu_write_out_exu;

	wire is_branch_out_exu;
	wire csr_write_out_exu;
	wire ecall_out_exu;
	wire mret_out_exu;
	wire reg_write_out_exu;
	wire is_req_valid_from_exu_to_lsu;
	wire is_req_ready_from_lsu_to_exu;

	ysyx_25040129_LSU u_ysyx_25040129_LSU (
		.clk(clk),
		.rst(rst),
		
		.pc_in_lsu(pc_out_exu),
		.pc_out_lsu(pc_out_lsu),

		.mmem_read_in_lsu(lsu_read_out_exu),
		.mmem_write_in_lsu(lsu_write_out_exu),

		.branch_target_in_lsu(branch_target_out_exu),
		.branch_target_out_lsu(branch_target_out_lsu),

		.result_in_lsu(result_out_exu),
		.result_out_lsu(result_out_lsu), // 如果发送了读，则该信号会被数据覆盖

		.is_req_valid_from_exu(is_req_valid_from_exu_to_lsu),
		.is_req_ready_to_exu(is_req_ready_from_lsu_to_exu),
		.mmem_write_data_in_lsu(lsu_write_data_out_exu),

		.araddr(araddr_from_lsu),
		.arvalid(arvalid_from_lsu),
		.arready(rready_to_lsu),
		.arsize(arsize_from_lsu),

		.rdata(rdata_to_lsu),
		.rresp(rresp_to_lsu),
		.rvalid(rvalid_to_lsu),
		.rready(rready_from_lsu),

		.awaddr(awaddr_from_lsu),
		.awvalid(awvalid_from_lsu),
		.awready(awready_to_lsu),

		.wstrb(wstrb_from_lsu),
		.wdata(wdata_from_lsu),
		.wvalid(wvalid_from_lsu),
		.wready(wready_to_lsu),

		.bresp(bresp_to_lsu),
		.bvalid(bvalid_to_lsu),
		.bready(bready_from_lsu),

		.is_req_valid_to_wbu(is_req_valid_from_lsu_to_wbu),
		.is_req_ready_from_wbu(is_req_ready_from_wb_to_lsu),

		.ecall_in_lsu(ecall_out_exu),
		.ecall_out_lsu(ecall_out_lsu),
		.rd_in_lsu(rd_out_exu),
		.rd_out_lsu(rd_out_lsu),
		.mret_in_lsu(mret_out_exu),
		.mret_out_lsu(mret_out_lsu),
		.is_branch_in_lsu(is_branch_out_exu),
		.is_branch_out_lsu(is_branch_out_lsu)
	);
	wire [31:0] araddr_from_lsu;
	wire arvalid_from_lsu;
	wire [2:0] arsize_from_lsu;
	wire rready_to_lsu;

	wire [31:0] rdata_to_lsu;
	wire [1:0] rresp_to_lsu;
	wire rvalid_to_lsu;
	wire rready_from_lsu;

	wire [31:0] awaddr_from_lsu;
	wire awvalid_from_lsu;
	wire awready_to_lsu;

	wire [3:0] wstrb_from_lsu;
	wire [31:0] wdata_from_lsu;
	wire wvalid_from_lsu;
	wire wready_to_lsu;

	wire [1:0] bresp_to_lsu;
	wire bvalid_to_lsu;
	wire bready_from_lsu;

	wire [4:0] rd_out_lsu;
	wire mret_out_lsu;
	wire ecall_out_lsu;
	wire is_branch_out_lsu;


	wire [31:0] pc_out_lsu;
	wire [31:0] branch_target_out_lsu;

	wire [31:0] result_out_lsu;




	wire is_req_valid_from_lsu_to_wbu;
	wire is_req_ready_from_wb_to_lsu;


	ysyx_25040129_WBU u_ysyx_25040129_WBU (
		.clk(clk),
		.rst(rst),

		.pc_in_wbu(pc_out_lsu),
		.pc_out_wbu(pc_out_wbu),

		.is_req_valid_from_lsu(is_req_valid_from_lsu_to_wbu),
		.is_req_ready_to_lsu(is_req_ready_from_wb_to_lsu),
		.is_req_valid_to_ifu(is_req_valid_from_wb_to_ifu),
		.is_req_ready_from_ifu(is_req_ready_from_ifu_to_wbu),
		.rd_in_wbu(rd_out_lsu),
		.result_in_wbu(result_out_lsu),
		.csr_addr_in_wbu(imm[11:0]),
		.csr_write_in_wbu(csr_write_out_exu),
		.reg_write_in_wbu(reg_write_out_exu),
		.rd_out_wbu(rd_out_wbu),
		.result_out_wbu(result_out_wbu),
		.csr_write_out_wbu(csr_write_out_wbu),
		.csr_addr_out_wbu(csr_addr_out_wbu),
		.reg_write_out_wbu(reg_write_out_wbu),

		.branch_target_in_wbu(branch_target_out_lsu),
		.branch_target_out_wbu(branch_target_out_wbu),

		.ecall_in_wbu(ecall_out_lsu),
		.ecall_out_wbu(ecall_out_wbu),
		.mret_in_wbu(mret_out_lsu),
		.mret_out_wbu(mret_out_wbu),
		.is_branch_in_wbu(is_branch_out_lsu),
		.is_branch_out_wbu(is_branch_out_wbu),
		.target_from_csr_in_wbu(target_from_csr_to_wbu)
	);
	wire [31:0] target_from_csr_to_wbu;
	wire mret_out_wbu;
	wire [31:0] pc_out_wbu;

	wire [31:0] result_out_wbu;
	wire [4:0] rd_out_wbu;
	wire csr_write_out_wbu;
	wire [11:0] csr_addr_out_wbu;
	wire reg_write_out_wbu;
	wire is_branch_out_wbu;
	wire [31:0] branch_target_out_wbu;
	wire ecall_out_wbu;
		
	

endmodule/*verilator lint_on DECLFILENAME*/

