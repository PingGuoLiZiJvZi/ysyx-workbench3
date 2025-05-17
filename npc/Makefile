TOPNAME = top
VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

THIS_DIR := ~/ysyx-workbench/npc
BUILD_DIR =${THIS_DIR}/build
OBJ_DIR = $(THIS_DIR)/obj_dir
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

# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)

LIBCAPSTONE = ~/ysyx-workbench/nemu/tools/capstone/repo/libcapstone.so.5
CFLAGS += -I ~/ysyx-workbench/nemu/tools/capstone/repo/include

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator --cc --exe --build -j 0 -Wall ${THIS_DIR}/vsrc/top.v ${THIS_DIR}/csrc/top.cpp 
	${THIS_DIR}/obj_dir/Vtop

#run规则为调用sim
run:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator --cc --exe --build -j  0 -O3 -Wall ${THIS_DIR}/vsrc/top.v ${THIS_DIR}/csrc/main.cpp  ${THIS_DIR}/csrc/Sdb.cpp  ${THIS_DIR}/csrc/paddr_simple.cpp ${THIS_DIR}/csrc/disasm.cpp  ${THIS_DIR}/csrc/Iomap.cpp --LDFLAGS "-lreadline" --CFLAGS "-I ~/ysyx-workbench/nemu/tools/capstone/repo/include"
		${BIN}

autorun:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator --cc --exe --build -j  0 -O0 -Wall ${THIS_DIR}/vsrc/top.v ${THIS_DIR}/csrc/main.cpp  ${THIS_DIR}/csrc/Sdb.cpp  ${THIS_DIR}/csrc/paddr_simple.cpp ${THIS_DIR}/csrc/disasm.cpp --LDFLAGS "-lreadline" --CFLAGS "-I ~/ysyx-workbench/nemu/tools/capstone/repo/include"
	printf "c\nq\n" |${BIN}


gdb:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator --cc --exe --build -j 0 -Wall ${THIS_DIR}/vsrc/top.v ${THIS_DIR}/csrc/top.cpp --CFLAGS "-g -O0"
	gdb --args ${BIN}

clean:
	rm -rf $(BUILD_DIR)
