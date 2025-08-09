int main()
{
	unsigned int mode = 0x80000000;
	unsigned int pdir = 0x10000000; // Example page directory address
	asm volatile("csrw satp, %0" : : "r"(mode | pdir >> 12));
}