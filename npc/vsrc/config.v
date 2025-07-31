`ifdef SIMULATE
	`define DEBUG 1
	`define DPI 1
	// `define GENERATE_PC_QUEUE 1
	// `define GENERATE_LOAD_STORE_QUEUE 1
`endif
`define WORD_T 4
`define START_ADDR 32'h20000000
`define I_TYPE_IMM 7'b0010011
`define B_TYPE 7'b1100011
`define I_TYPE_LOAD 7'b0000011
`define I_TYPE_FENCE 7'b0001111
`define S_TYPE 7'b0100011
`define J_TYPE 7'b1101111
`define I_TYPE_JALR 7'b1100111
`define I_TYPE_SYSTEM 7'b1110011
`define R_TYPE 7'b0110011
`define U_TYPE_LUI 7'b0110111
`define U_TYPE_AUIPC 7'b0010111
`define EBREAK 12'b000000000001
`define MRET 12'b001100000010
`define ECALL 12'b000000000000

		`define NO_MEM_WRITE 2'b00
		`define MEM_WRITE_BYTE 2'b01
		`define MEM_WRITE_HALF 2'b10
		`define MEM_WRITE_WORD 2'b11

		`define NO_MEM_READ 3'b000
		`define MEM_READ_BYTE 3'b001
		`define MEM_READ_HALF 3'b010
		`define MEM_READ_WORD 3'b011
		`define MEM_READ_BYTE_U 3'b100
		`define MEM_READ_HALF_U 3'b101

		`define ADD 4'b0000//0 1 2 3 4 5 6 7 8 13已使用
		`define SUB 4'b1000//9 10 11 12 14 15
		`define SLL 4'b0001
		`define SLT 4'b0010
		`define SLTU 4'b0011
		`define XOR 4'b0100
		`define SRL 4'b0101
		`define SRA 4'b1101
		`define OR 4'b0110
		`define AND 4'b0111//b指令func3:0 1 4 5 6 7 （15-func3刚好使用剩余编码）
		`define EQ 4'b1001
		`define NEQ 4'b1010
		`define LT 4'b1011
		`define GE 4'b1100
		`define LTU 4'b1110
		`define GEU 4'b1111

`define OKAY 2'b00
`define EXOKAY 2'b01
`define SLVERR 2'b10
`define DECERR 2'b11

`define ROM_START 32'h20000000
`define ROM_SIZE 32'h00001000
`define SRAM_START 32'h0f000000
`define SRAM_SIZE 32'h00002000
`define UART_REG_ADDR 32'h10000000
`define UART_REG_SIZE 32'h00000008
`define RTC_PORT_ADDR 32'hb0000048
`define RTC_PORT_SIZE 32'h00000008
`define FLASH_START 32'h30000000
`define FLASH_SIZE 32'h10000000
`define SPI_ADDR 32'h10001000
`define SPI_SIZE 32'h00001000
`define PSRAM_ADDR 32'h80000000
`define PSRAM_SIZE 32'h00400000
`define SDRAM_ADDR 32'ha0000000
`define SDRAM_SIZE 32'h08000000
`define GPIO_ADDR 32'h10002000
`define GPIO_SIZE 32'h00000010
`define PS2_ADDR 32'h10011000
`define PS2_SIZE 32'h00000008
`define VGA_ADDR 32'h21000000
`define VGA_SIZE 32'h140000