TOPNAME = ysyxSoCFull
NXDC_FILES = constr/top.nxdc
VERILATOR = verilator
VERILATOR_CFLAGS += --cc --exe --build -j  0 -O3 -Wwarn-LATCH -Wwarn-MULTIDRIVEN --trace --top-module ysyxSoCFull \
	--Mdir build/obj_dir

THIS_DIR := $(NPC_HOME)

BUILD_DIR =${THIS_DIR}/build
OBJ_DIR = $(THIS_DIR)/build/obj_dir
BIN = $(OBJ_DIR)/V$(TOPNAME)

override ARGS ?= 
override ARGS += --log=$(BUILD_DIR)/npc-log.txt
override ARGS_FTRACE ?= --elf=$(IMG:.bin=.elf)
override ARGS += $(ARGS_FTRACE)
override ARGS += $(ARGS_DIFF)

# Command to execute NEMU
IMG ?=
BIN := $(BIN) $(ARGS) $(IMG)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

SRC_AUTO_BIND = $(BUILD_DIR)/auto_bind.cpp
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
VSRCS = ${THIS_DIR}/vsrc/*.v
SOC_VSRCS = $(shell find ~/ysyx-workbench/ysyxSoC/perip -name "*.v")
SOC_VSRCS += $(SOC_HOME)/build/*.v
CSRCS = ${THIS_DIR}/csrc/*.cpp
CSRCS += ${THIS_DIR}/csrc/*.c

LIBCAPSTONE = ~/ysyx-workbench/nemu/tools/capstone/repo/libcapstone.so.5
CFLAGS += -I ~/ysyx-workbench/nemu/tools/capstone/repo/include

include $(NVBOARD_HOME)/scripts/nvboard.mk



build: $(SRC_AUTO_BIND) $(NVBOARD_ARCHIVE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(VERILATOR) $(VERILATOR_CFLAGS) $(THIS_DIR)/platform/simulation.v $(VSRCS) $(SOC_VSRCS) $(CSRCS) $(SRC_AUTO_BIND) $(NVBOARD_ARCHIVE) \
	$(addprefix -LDFLAGS , $(LDFLAGS)) --LDFLAGS "-lreadline" $(addprefix -CFLAGS , $(CXXFLAGS)) --CFLAGS "-I ~/ysyx-workbench/nemu/tools/capstone/repo/include" --CFLAGS "-I $(NVBOARD_HOME)/usr/include" \
	-I$(SOC_HOME)/perip/uart16550/rtl -I$(SOC_HOME)/perip/spi/rtl -I$(NPC_HOME)/vsrc \
	--timescale "1ns/1ns" --no-timing --autoflush
#run规则为调用sim

npc_build:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(VERILATOR) $(VERILATOR_CFLAGS) -Wall $(THIS_DIR)/platform/simulation.v $(THIS_DIR)/platform/npc/*.v $(VSRCS) $(CSRCS) $(THIS_DIR)/platform/npc/*.c \
	--LDFLAGS "-lreadline" $(addprefix -CFLAGS , $(CXXFLAGS)) --CFLAGS "-I ~/ysyx-workbench/nemu/tools/capstone/repo/include" \
	--CFLAGS "-DIS_NPC=1" \
	--timescale "1ns/1ns" --no-timing --autoflush

run: build
	${BIN}

autorun: build
	printf "c\nq\n" |${BIN}

npc_run: npc_build
	${BIN}

npc_autorun: npc_build
	printf "c\nq\n" |${BIN}

#perf需要做两件事：1. 在sta目录下调用make sta，生成综合报告；2. 在microbench目录下调用make run ARCH=riscv32e-ysyxsoc,生成性能报告
perf: 
	$(MAKE) -C $(SOC_HOME)/../yosys-sta sta
	$(MAKE) -C $(SOC_HOME)/../am-kernels/benchmarks/microbench autorun ARCH=riscv32e-ysyxsoc mainargs=train

sta:
	$(MAKE) -C $(SOC_HOME)/../yosys-sta sta

gdb:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator --cc --exe --build -j 0 -Wall ${THIS_DIR}/vsrc/top.v ${THIS_DIR}/csrc/top.cpp --CFLAGS "-g -O0"
	gdb --args ${BIN}

clean:
	rm -rf $(BUILD_DIR)
.PHONY: clean run perf npc_build npc_run npc_autorun autorun build npc_build