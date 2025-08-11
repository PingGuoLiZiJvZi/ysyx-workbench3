#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#define UART_PORT 0x10000000
unsigned char cmd[256];
unsigned char u_get_c()
{
	unsigned char *port = (unsigned char *)UART_PORT;
	return *port;
}

static void check_cmd()
{
	char n_cmd[256] = {};
	memcpy(n_cmd, cmd, 256);
	char *argv[8] = {};
	char *null_ptr[1] = {NULL}; // For execve to use the environment variables
	int argc = 0;
	argv[argc++] = n_cmd; // First argument is the cmd itself
	for (int i = 0; n_cmd[i] != '\0'; i++)
	{
		if (n_cmd[i] == '\n' || n_cmd[i] == ' ')
		{
			n_cmd[i] = '\0';
			if (n_cmd[i + 1] != '\0' && n_cmd[i + 1] != ' ')
				argv[argc++] = &n_cmd[i + 1]; // Next argument starts after the null terminator
		}
	}
	argv[argc] = NULL; // Null-terminate the argument list
	if (n_cmd[0] == '/')
		execve(n_cmd, argv, null_ptr);
	else
	{
		execvp(n_cmd, argv);
	}
}
static void run()
{
	unsigned char idx = 0;
	unsigned char temp = 0;
	cmd[idx] = '\0';
	while (1)
	{
		temp = u_get_c();
		printf("get %c\n", temp);
		if (temp == 255)
			continue;
		if (temp == '\b')
		{
			if (idx > 0)
				cmd[--idx] = '\0';
			continue;
		}
		else if (temp == '\n')
		{
			cmd[idx] = '\n';
			cmd[++idx] = '\0';
			check_cmd();
		}
		else
		{
			cmd[idx] = temp;
			cmd[++idx] = '\0';
		}
	}
}
int main()
{
	printf("Simple Term!\n\nsh> ");
	// setenv("PATH", "/bin:/usr/bin", 1);
	run();
}