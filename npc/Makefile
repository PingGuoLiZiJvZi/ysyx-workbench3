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
VSRCS += $(shell find ~/ysyx-workbench/ysyxSoC/perip -name "*.v")
VSRCS += $(SOC_HOME)/build/*.v
CSRCS = ${THIS_DIR}/csrc/*.cpp
CSRCS += ${THIS_DIR}/csrc/*.c
CSRCS += $(SRC_AUTO_BIND)

LIBCAPSTONE = ~/ysyx-workbench/nemu/tools/capstone/repo/libcapstone.so.5
CFLAGS += -I ~/ysyx-workbench/nemu/tools/capstone/repo/include

include $(NVBOARD_HOME)/scripts/nvboard.mk



#run规则为调用sim
run: $(SRC_AUTO_BIND) $(NVBOARD_ARCHIVE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(VERILATOR) $(VERILATOR_CFLAGS) $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE) \
	$(addprefix -LDFLAGS , $(LDFLAGS)) --LDFLAGS "-lreadline" $(addprefix -CFLAGS , $(CXXFLAGS)) --CFLAGS "-I ~/ysyx-workbench/nemu/tools/capstone/repo/include" --CFLAGS "-I $(NVBOARD_HOME)/usr/include" \
	-I$(SOC_HOME)/perip/uart16550/rtl -I$(SOC_HOME)/perip/spi/rtl -I$(NPC_HOME)/vsrc \
	--timescale "1ns/1ns" --no-timing --autoflush
	${BIN}

autorun:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(VERILATOR) $(VERILATOR_CFLAGS) $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE) \
	$(addprefix -LDFLAGS , $(LDFLAGS)) --LDFLAGS "-lreadline" $(addprefix -CFLAGS , $(CXXFLAGS)) --CFLAGS "-I ~/ysyx-workbench/nemu/tools/capstone/repo/include" --CFLAGS "-I $(NVBOARD_HOME)/usr/include" \
	-I$(SOC_HOME)/perip/uart16550/rtl -I$(SOC_HOME)/perip/spi/rtl -I$(NPC_HOME)/vsrc \
	--timescale "1ns/1ns" --no-timing --autoflush
	printf "c\nq\n" |${BIN}


gdb:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator --cc --exe --build -j 0 -Wall ${THIS_DIR}/vsrc/top.v ${THIS_DIR}/csrc/top.cpp --CFLAGS "-g -O0"
	gdb --args ${BIN}

clean:
	rm -rf $(BUILD_DIR)
