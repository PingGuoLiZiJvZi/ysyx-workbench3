// output hello per 0.5 seconds
// by gettimeofday
#include <stdio.h>
#include <sys/time.h>
void sleep_for(double seconds)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	do
	{
		gettimeofday(&end, NULL);
	} while ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec) < seconds * 1000000);
}
int main()
{
	struct timeval tv;
	while (1)
	{
		printf("Hello World from Navy-apps!\n");
		sleep_for(0.5);
	}
	return 0;
}