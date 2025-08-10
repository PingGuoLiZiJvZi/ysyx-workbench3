include $(NAVY_HOME)/scripts/riscv/common.mk
CFLAGS  += -march=rv32ia -mabi=ilp32  #overwrite
LDFLAGS += -melf32lriscv
