module sdram(
  input        clk,
  input        cke,
  input        cs,
  input        ras,
  input        cas,
  input        we,
  input [12:0] a,
  input [ 1:0] ba,
  input [ 1:0] dqm,
  inout [15:0] dq
);
  reg [15:0] memory [0:3][0:8191][0:511];
  
  // 模式寄存器设置
  reg [2:0] cas_latency;  // CAS 延迟 (2 或 3)
  reg [2:0] burst_length; // 突发长度 (1,2,4,8)
  
  // Bank 状态
  reg [12:0] active_row [0:3];  // 每个 bank 激活的行
  reg [3:0]  bank_active;       // Bank 激活标志
  
  // 突发传输状态
  reg burst_active;      // 突发传输进行中
  reg burst_write;       // 突发传输类型 (0=读, 1=写)
  reg [1:0] burst_bank;  // 突发传输的 bank
  reg [8:0] burst_col;   // 突发起始列地址
  reg [2:0] burst_cnt;   // 突发计数器
  
  // 读操作状态
  reg [2:0] read_pipeline;  // 读流水线延迟计数器
  
  // 数据总线控制
  reg [15:0] data_out;
  reg data_out_en;
  
  assign dq = data_out_en ? data_out : 16'bz;
  
  // 命令解码
  wire [3:0] command = {cs, ras, cas, we};
  
  always @(posedge clk) begin
    if (cke) begin
      // 命令处理
      if (!cs) begin  // 片选有效
        case (command)
          // LOAD MODE REGISTER
          4'b0000: begin
            cas_latency <= a[6:4];   // M4-M6
            burst_length <= a[2:0] + 1;  // M0-M2
          end
          
          // ACTIVE (激活行)
          4'b0011: begin
            active_row[ba] <= a;     // 存储行地址
            bank_active[ba] <= 1'b1; // 标记 bank 激活

          end
          
          // READ (读操作)
          4'b0101: if (bank_active[ba]) begin
            burst_active <= 1'b1;
            burst_write <= 1'b0;
            burst_bank <= ba;
            burst_col <= a[8:0];    // 列地址 A0-A8
            burst_cnt <= 3'd0;
            read_pipeline <= cas_latency - 2; // 设置延迟计数器
          end
          
          4'b0100: if (bank_active[ba]) begin
			if(burst_length == 1)begin
				burst_active <= 1'b0; 
				burst_write <= 1'b0; 
				burst_cnt <= 3'd0; 
			end
			else begin
				burst_active <= 1'b1;
            	burst_write <= 1'b1;
				burst_cnt <= 3'd0;
			end
           
            burst_bank <= ba;
            burst_col <= a[8:0];    // 列地址 A0-A8
            if (!dqm[0]) memory[ba][active_row[ba]][a[8:0]][7:0] <= dq[7:0];
            if (!dqm[1]) memory[ba][active_row[ba]][a[8:0]][15:8] <= dq[15:8];
            burst_cnt <= burst_cnt + 1;
          end
          
          // PRECHARGE/AUTO REFRESH (NOP)
          4'b0010, 4'b0001,4'b0111: ; // 无操作
          
          default:$error("SDRAM: Unsupported command %b", command)
		   ; // NOP 或其他未实现命令
        endcase
      end
   
      if (burst_active) begin
        if (burst_write) begin
          if (burst_cnt < burst_length && burst_cnt > 0) begin
            
            // 应用数据掩码
            if (!dqm[0]) memory[burst_bank][active_row[burst_bank]][burst_col + {6'b0,burst_cnt}][7:0] <= dq[7:0];
            if (!dqm[1]) memory[burst_bank][active_row[burst_bank]][burst_col + {6'b0,burst_cnt}][15:8] <= dq[15:8];
            
            burst_cnt <= burst_cnt + 1;
            if (burst_cnt == burst_length - 1) begin 
					burst_active <= 1'b0;
					burst_write <= 1'b0; // 写完突发后结束
					burst_cnt <= 3'd0; // 重置计数器
			end
          end
        end else begin
          // 读突发：处理流水线延迟
          if (read_pipeline > 0) begin
            read_pipeline <= read_pipeline - 1;
          end else begin
            data_out_en <= 1'b1;
            data_out <= memory[burst_bank][active_row[burst_bank]][burst_col + {6'b0,burst_cnt}];
            burst_cnt <= burst_cnt + 1;
            if (burst_cnt == burst_length - 1) begin
              burst_active <= 1'b0;
			  burst_write <= 1'b0;
			  burst_cnt <= 3'd0; // 重置计数器
            end
          end
        end
      end else begin
        data_out_en <= 1'b0; // 非突发时释放总线
      end
    end
  end

endmodule
