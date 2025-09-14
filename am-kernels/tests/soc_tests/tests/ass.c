int main(){

	asm volatile(
		"li   t0, 0x80000000\n"
		"jr   t0 \n");
return 0;

}