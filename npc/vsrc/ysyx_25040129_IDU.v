 module ysyx_25040129_IDU (
	input rst,
	input clk,

	input [31:0] inst,
	input [31:0] pc,
	output [4:0] src1_id,
	output [4:0] src2_id,
	output [11:0] csr_id_out_idu,
	input [31:0] src1_in_idu,
	input [31:0] src2_in_idu,
	input [31:0] csr_in_idu,
	
	output reg[31:0] src1_out_idu,
	output reg[31:0] src2_out_idu,
	output [31:0] lsu_write_data_out_idu,
	output reg is_jalr_out_idu,
	output reg[31:0] imm,
	output [4:0] rd_out_idu,//该信号将被一路传递至WB阶段
	output reg[3:0] alu_opcode, // 该信号将被一路传递至ALU阶段
	
	output reg reg_write_out_idu,//该信号将被一路传递至WB阶段
	output reg[1:0] lsu_write_out_idu, // 该信号将被一路传递至MEM阶段
	output reg[2:0] lsu_read_out_idu, // 该信号将被一路传递至MEM阶段
	output reg ecall_out_idu,
	output reg is_jump_out_idu,
	output reg ebreak_out_idu,
	output reg mret_out_idu,
	
	output reg csr_write_out_idu,//该信号将被一路传递至WB阶段
	
	input is_req_valid_from_ifu,
	output is_req_ready_to_ifu,
	output is_req_valid_to_exu,
	input is_req_ready_from_exu,
	output reg fence_i
);
	reg [2:0] state;
	reg [2:0] next_state;
	localparam IDLE = 3'b000;
	localparam DECODE = 3'b001;

	always @(posedge clk) begin

		if (rst) begin
			state <= IDLE;
		end else begin
			state <= next_state;
		end
	end

	always @(*) begin
		case (state)
			IDLE: next_state = is_req_valid_from_ifu ? DECODE : IDLE;
			DECODE: next_state = is_req_ready_from_exu ? IDLE : DECODE; 
			default: next_state = IDLE;
		endcase
	end
	assign lsu_write_data_out_idu = src2_in_idu; // 如果是写请求，则将计算结果传递出去，否则传递计算结果
	assign is_req_ready_to_ifu = (state == IDLE);
	assign is_req_valid_to_exu = (state == DECODE);

	assign csr_id_out_idu = inst[31:20]; // CSR ID直接从指令中获取
	wire  funct7_5;
	wire [2:0] funct3;
	wire [6:0] opcode;
	assign funct7_5 = inst[30];
	assign funct3 = inst[14:12];
	assign opcode = inst[6:0];
	assign rd_out_idu = inst[11:7];
	assign src1_id = inst[19:15];
	assign src2_id = inst[24:20];
//---------------调试信号---------------
always @(posedge clk) begin
	`ifdef DEBUG
	track_inst_in_idu({5'b0,state},{1'b0,opcode});
	`endif
end
//--------------综合时删除---------------
	always @(*) begin
		reg_write_out_idu = 1'b0;
		is_jump_out_idu = 1'b0;
		ecall_out_idu = 1'b0;
		ebreak_out_idu = 1'b0;
		mret_out_idu = 1'b0;
		is_jalr_out_idu = 1'b0;
		csr_write_out_idu = 1'b0;
		lsu_write_out_idu = `NO_MEM_WRITE;
		lsu_read_out_idu = `NO_MEM_READ;
		
		
		src1_out_idu = src1_in_idu;
		src2_out_idu = src2_in_idu;
		case (opcode)
			`I_TYPE_IMM:begin
				 imm = {{20{inst[31]}},inst[31:20]};
				 src2_out_idu= imm;
				 reg_write_out_idu = 1'b1;
				 alu_opcode = {(funct3==3'b101)?funct7_5:1'b0,funct3};
			end // I-type immediate
			`B_TYPE: begin 
				imm = {{20{inst[31]}},inst[7], inst[30:25], inst[11:8], 1'b0};
				case (funct3)
					3'b000: alu_opcode = `EQ; // BEQ
					3'b001: alu_opcode = `NEQ; // BNE
					3'b100: alu_opcode = `LT; // BLT
					3'b101: alu_opcode = `GE; // BGE
					3'b110: alu_opcode = `LTU; // BLTU
					3'b111: alu_opcode = `GEU; // BGEU
					default: begin
						alu_opcode = 4'b0000; // 默认值
						`ifdef DPI
						unknown_inst(inst); // Unknown instruction
						`endif
					 end
				endcase			
			end// B-type branch

			`I_TYPE_LOAD: begin 
				imm = {{20{inst[31]}},inst[31:20]};
				src2_out_idu= imm; 
				reg_write_out_idu = 1'b1;
				alu_opcode = `ADD; // LOAD指令的ALU操作是加法

				case (funct3)
					3'b000: lsu_read_out_idu = `MEM_READ_BYTE; // LB
					3'b001: lsu_read_out_idu = `MEM_READ_HALF; // LH
					3'b010: lsu_read_out_idu = `MEM_READ_WORD; // LW
					3'b100: lsu_read_out_idu = `MEM_READ_BYTE_U; // LBU
					3'b101: lsu_read_out_idu = `MEM_READ_HALF_U; // LHU
					default: begin end
				endcase

			end // I-type load
			`I_TYPE_FENCE: begin
				imm = {{20{inst[31]}},inst[31:20]}; 
				fence_i = 1'b1; 
			end
			`S_TYPE: begin
				imm = {{20{inst[31]}},inst[31:25],inst[11:7]}; // S-type store
				src2_out_idu= imm;
				
				alu_opcode = `ADD; // STORE指令的ALU操作是加法

				case (funct3)
					3'b000: lsu_write_out_idu = `MEM_WRITE_BYTE; // SB
					3'b001: lsu_write_out_idu = `MEM_WRITE_HALF; // SH
					3'b010: lsu_write_out_idu = `MEM_WRITE_WORD; // SW
					default: begin end
				endcase

				
			end
			`J_TYPE: begin 
				imm = {{12{inst[31]}},inst[19:12],inst[20],inst[30:21],1'b0}; // J-type jump
				src1_out_idu= pc; 
				src2_out_idu= imm; 
				alu_opcode = `ADD; // JAL指令的ALU操作是加法
				is_jump_out_idu = 1'b1;
				is_jalr_out_idu = 1'b1;
				reg_write_out_idu = 1'b1;
			end
			`I_TYPE_JALR: begin 
				imm = {{20{inst[31]}},inst[31:20]}; // JALR
				src2_out_idu= imm;
				alu_opcode = `ADD; // JALR指令的ALU操作是加法
				is_jump_out_idu = 1'b1;
				is_jalr_out_idu = 1'b1;
				reg_write_out_idu = 1'b1;
			end
			`I_TYPE_SYSTEM: begin
				imm = {{20{inst[31]}},inst[31:20]}; // I-type system
				
				case (funct3)
					3'b000: begin
						case(inst[31:20])
							`EBREAK:begin
								ebreak_out_idu = 1'b1;
							end
							`MRET:begin
								mret_out_idu = 1'b1;
							end
							`ECALL: begin
								ecall_out_idu = 1'b1;
							end
							default: begin
								`ifdef DPI
								unknown_inst(inst); // Unknown instruction
								`endif
							end
						endcase
						
					end
					3'b001:begin
					 // CSR操作
						csr_write_out_idu = 1'b1;
						reg_write_out_idu = 1'b0;
						src2_out_idu= 32'b0; // CSR write
						alu_opcode = `ADD; 
					end
					3'b010:begin
		 // CSR操作
						
						reg_write_out_idu = 1'b1;
						src2_out_idu= csr_in_idu; // CSR read
						alu_opcode = `OR; 
					end
					default: begin
						`ifdef DPI
						unknown_inst(inst); // Unknown instruction
						`endif
						alu_opcode = 4'b0000; // 默认值
					end
				endcase
			end
			`R_TYPE: begin 
				imm = 32'b0; // R-type
				reg_write_out_idu = 1'b1;
				alu_opcode = {(funct7_5), funct3}; // 根据funct7的第6位决定是加法还是减法
			end
			`U_TYPE_LUI: begin 
				imm = {inst[31:12], 12'b0}; // LUI
				reg_write_out_idu = 1'b1;
				src1_out_idu= 32'b0; // LUI指令不需要src1
				src2_out_idu= imm; // src2_out为立即数
				alu_opcode = `ADD; // LUI指令的ALU操作是加法
			end
			`U_TYPE_AUIPC: begin 
				imm = {inst[31:12], 12'b0}; // AUIPC
				reg_write_out_idu = 1'b1;
				src1_out_idu= pc; // AUIPC指令的src1为pc
				src2_out_idu= imm; // src2_out为立即数
				alu_opcode = `ADD; // AUIPC指令的ALU操作是加法
			end
			default: begin
				imm = 32'b0;
				`ifdef DPI
				unknown_inst(inst); // Unknown instruction
				`endif
			end
		endcase
	end
	
endmodule
