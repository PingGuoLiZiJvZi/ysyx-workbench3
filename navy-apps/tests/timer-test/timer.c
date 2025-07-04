// output hello per 0.5 seconds
// by gettimeofday
#include <stdio.h>
#include <sys/time.h>
sleep_for(double seconds)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	do
	{
		gettimeofday(&end, NULL);
	} while ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0 < seconds);
}
int main()
{
	struct timeval tv;
	while (1)
	{
		printf("Hello World from Navy-apps!\n");
		gettimeofday(&tv, NULL);
	}
	return 0;
}