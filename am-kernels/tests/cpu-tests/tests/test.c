#include "trap.h"
int main()
{
	check(-1 / -1 == 1);
	int res = -1 / -1;
	printf("res == %d\n%d\n", -1 / -1, res);
	char buf[1024];
	sprintf(buf, "res == %d\n%d\n", -1 / -1, res);
	printf("%s", buf);
	return 0;
}