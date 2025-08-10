include $(NAVY_HOME)/scripts/riscv/common.mk
CFLAGS  += -march=rv32i_zicsr -mabi=ilp32  #overwrite
LDFLAGS += -melf32lriscv
