#include <trap.h>

int main()
{
	unsigned int csr_value;
	unsigned int new_value = 0x114;
	unsigned int reg_value = 0x514;

	unsigned int csr_address = 0x300;

	__asm__ __volatile__(
		"csrw %[csr], %[new]\n\t"
		:
		: [csr] "i"(csr_address), [new] "r"(new_value));

	// 使用内联汇编读取 CSR 寄存器的当前值
	__asm__ __volatile__(
		"csrr %[old], %[csr]\n\t"
		: [old] "=r"(csr_value)
		: [csr] "i"(csr_address));

	// 使用内联汇编将 CSR 寄存器的值与通用寄存器的值互换
	__asm__ __volatile__(
		"csrrw %[reg], %[csr], %[reg]\n\t"
		: [reg] "+r"(reg_value)
		: [csr] "i"(csr_address));

	// 输出 CSR 的原始值、新值和通用寄存器的值
	printf("Original CSR value: 0x%08x\n", csr_value);
	printf("New CSR value: 0x%08x\n", new_value);
	printf("Register value after swap: 0x%08x\n", reg_value);

	return 0;
}