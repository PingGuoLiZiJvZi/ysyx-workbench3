include $(NAVY_HOME)/scripts/riscv/common.mk
CFLAGS  += -march=rv32iaf -mabi=ilp32  #overwrite
LDFLAGS += -melf32lriscv
