#include "trap.h"
int main()
{
	unsigned int vec = 0x114;
	unsigned int res = 0;
	asm volatile(
		"csrw mtvec, %[vec_val]\n" // 将 vec 的值写入 mtvec 寄存器
		"csrr %[res_val], mtvec\n" // 从 mtvec 寄存器读取值到 res
		: [res_val] "=r"(res)	   // 输出操作数，将寄存器的值赋给 res
		: [vec_val] "r"(vec)	   // 输入操作数，将 vec 的值传递给寄存器
	);
	check(res == vec); // 检查 res 是否等于 vec
	return 0;
}