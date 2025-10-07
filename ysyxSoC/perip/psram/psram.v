module psram(
  input        sck,      // SPI时钟
  input        ce_n,     // 片选（低有效）
  inout [3:0]  dio      // 双向数据线
);

  // 存储阵列（4MB）
  reg [7:0] mem [0:4*1024*1024-1]; 

  // 状态定义
  localparam SPI_S_IDLE      = 0;
  localparam SPI_S_CMD       = 1;
  localparam SPI_S_ADDR      = 2;
  localparam SPI_S_DUMMY     = 3;
  localparam SPI_S_READ_DATA = 4;
  localparam SPI_S_WRITE_DATA= 5;
  reg is_qpi = 0; // 是否为QPI模式s
  reg [3:0] state;
  reg [7:0] cmd;          // 命令寄存器
  reg [23:0] addr;        // 地址寄存器
  reg [2:0] bit_cnt;      // 位计数器
  reg [2:0] dummy_cnt;    // 空周期计数器
  reg nibble_flag;        // 半字节标志（0=高4位,1=低4位）
  reg [3:0] data_out;     // 数据输出缓冲

  // 三态控制：仅在读数据时驱动dio
  assign dio = (state == SPI_S_READ_DATA) ? data_out : 4'bz;

  // 状态转移 + 数据处理.
  always @(posedge sck or posedge ce_n) begin
    if (ce_n) begin
      state <= SPI_S_IDLE;    // 片选无效时复位
	  bit_cnt <= 0;
	  cmd <= 0;
	  addr <= 0;
	  dummy_cnt <= 0;
	  nibble_flag <= 0;
	end 
    else begin
      case (state)
        SPI_S_IDLE: begin
          state <= SPI_S_CMD;
          bit_cnt <= 1;
		  if(is_qpi)cmd <= {cmd[3:0],dio};
		  else
          	cmd <= {cmd[6:0], dio[0]};  // 单线接收命令
        end

        SPI_S_CMD: begin
         
          bit_cnt <= bit_cnt + 1;
		  if(is_qpi)begin
			cmd <= {cmd[3:0], dio};  // QPI模式接收命令
			if(bit_cnt == 1)begin
				state <= SPI_S_ADDR; // 8位接收完成
				addr <= 0; // 清空地址寄存器
				bit_cnt <= 0;
			end
		  end
		  else begin
			cmd <= {cmd[6:0], dio[0]};  // 单线接收命令
          if (bit_cnt == 7) begin      // 8位接收完成
		  	if({cmd[6:0],dio[0]} == 8'h35)begin
				is_qpi <= 1; // 设置为QPI模式
				state <= SPI_S_IDLE; // 回到空闲状态
			end
			else
			begin
            	state <= SPI_S_ADDR;
            	bit_cnt <= 0;
            	addr <= 0;
			end
          end
		  end
        end

        SPI_S_ADDR: begin
          addr <= {addr[19:0], dio};  // 4线接收地址
          bit_cnt <= bit_cnt + 1;
          if (bit_cnt == 5) begin      // 24位=6时钟
            if (cmd == 8'hEB) begin
              state <= SPI_S_DUMMY;        // 读命令进入空周期
              dummy_cnt <= 0;
            end else if (cmd == 8'h38) begin
              state <= SPI_S_WRITE_DATA;   // 写命令直接写数据
              nibble_flag <= 0;
            end
			else begin
				$error("Unsupported command: %02x", cmd);
				state <= SPI_S_IDLE;          // 不支持的命令，回到空闲状态
			end
          end
        end

        SPI_S_DUMMY: begin
          dummy_cnt <= dummy_cnt + 1;
          if (dummy_cnt == 5) begin    // 6空周期结束
            state <= SPI_S_READ_DATA;
            nibble_flag <= 0;
          end
        end

		SPI_S_READ_DATA: begin
      	if (nibble_flag == 0) begin
        	data_out <= mem[addr[21:0]][7:4];   // 输出高4位
        	nibble_flag <= 1;
      	end else begin
       		data_out <= mem[addr[21:0]][3:0];   // 输出低4位
        	addr <= addr + 1;             // 地址递增
        	nibble_flag <= 0;
      	end
	  end

        SPI_S_WRITE_DATA: begin
          if (nibble_flag == 0) begin
            mem[addr[21:0]][7:4] <= dio;   // 存高4位
            nibble_flag <= 1;
          end else begin
            mem[addr[21:0]][3:0] <= dio;  // 写入存储
            addr <= addr + 1;         // 地址递增
            nibble_flag <= 0;
          end
        end
      endcase
    end
  end


endmodule
