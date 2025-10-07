#include <trap.h>
#include <string.h>
#include <stdlib.h>
#define N 32
unsigned char data[N];

void reset()
{
	for (int i = 0; i < N; i++)
	{
		data[i] = i + 1;
	}
}

void check_seq(int l, int r, int val)
{
	for (int i = l; i < r; i++)
	{
		check(data[i] == val + i - l);
	}
}

void check_eq(int l, int r, unsigned char val)
{
	for (int i = l; i < r; i++)
	{
		check(data[i] == val);
	}
}

void test_memset()
{
	for (int l = 0; l < N; l++)
	{
		for (int r = l + 1; r <= N; r++)
		{
			reset();
			unsigned char val = (l + r) / 2;
			memset(data + l, val, r - l); // data 是 unsigned char 数组，r-l 即字节数
			check_seq(0, l, 1);
			check_eq(l, r, val);
			check_seq(r, N, r + 1);
		}
	}
	reset();
	memset(data, 0, N);
	check_eq(0, N, 0);

	reset();
	memset(data, 0xFF, N);
	check_eq(0, N, 0xFF);

	// 测试单字节操作
	reset();
	memset(data + 5, 0xAA, 1);
	check(data[5] == 0xAA);
	check(data[4] == 5); // 确保其他位置未被修改
	check(data[6] == 7);
}

void test_strlen()
{
	memset(data, 'A', N - 1);
	data[N - 1] = '\0';
	check(strlen((char *)data) == N - 1);
	check(strlen((char *)data + 1) == N - 2);
	check(strlen((char *)data + N - 1) == 0);

	data[0] = '\0';
	check(strlen((char *)data) == 0);

	// 测试中间包含 '\0'
	memset(data, 'A', N);
	data[10] = '\0';
	check(strlen((char *)data) == 10);
}

void test_strcpy()
{
	memset(data, 'A', N - 1);
	data[N - 1] = '\0';
	char str[N];
	strcpy(str, (char *)data);
	check(strcmp(str, (char *)data) == 0);

	data[0] = '\0';
	strcpy(str, (char *)data);
	check(strlen(str) == 0);
}

void test_strcat()
{
	memset(data, 'A', N - 1);
	data[N - 1] = '\0';
	char str[2 * N];
	str[0] = '\0';
	strcat(str, (char *)data);
	strcat(str, (char *)data);
	check(strlen(str) == 2 * (N - 1));

	char exact_buf[2 * (N - 1) + 1];
	exact_buf[0] = '\0';
	strcat(exact_buf, (char *)data);
	strcat(exact_buf, (char *)data);
	check(strlen(exact_buf) == 2 * (N - 1));
}

void test_strcmp()
{
	char *s1 = "hello";
	char *s2 = "world";
	check(strcmp(s1, s1) == 0);
	check(strcmp(s1, s2) < 0);
}

void test_strncpy()
{
	memset(data, 'A', N - 1);
	data[N - 1] = '\0';
	char str[N + 1];
	strncpy(str, (char *)data, N);
	str[N] = '\0';
	check(strcmp(str, (char *)data) == 0);
	// 测试截断且不添加终止符
	char src[10] = "123456789";
	char dst[5];
	strncpy(dst, src, 5);
	check(memcmp(dst, "12345", 5) == 0); // 无终止符

	// 测试 n 小于源长度
	memset(data, 'A', 10);
	data[10] = '\0';
	char buf[5];
	strncpy(buf, (char *)data, 4);
	buf[4] = '\0'; // 手动终止
	check(strcmp(buf, "AAAA") == 0);
}

void test_strncmp()
{
	char *s1 = "hello";
	char *s2 = "hella";
	check(strncmp(s1, s2, 4) == 0); // 前4字符相同
	check(strncmp(s1, s2, 5) > 0);	// 第5字符不同
}

void test_memmove()
{
	char buf[10] = "123456789";
	memmove(buf + 2, buf, 5);
	check(memcmp(buf, "121234589", 10) == 0);
	char overlap1[10] = "123456789";
	memmove(overlap1 + 1, overlap1 + 3, 4); // 复制 "4567" 到位置1
	check(memcmp(overlap1, "145676789", 10) == 0);

	// 测试目标在源之后的重叠
	char overlap2[10] = "123456789";
	memmove(overlap2 + 3, overlap2 + 1, 4); // 复制 "2345" 到位置3
	check(memcmp(overlap2, "123234589", 10) == 0);
}

void test_memcpy()
{
	char src[10] = "12345";
	char dst[10];
	memcpy(dst, src, 6);
	check(strcmp(dst, "12345") == 0);
}

void test_memcmp()
{
	char a[5] = {1, 2, 3, 4, 5};
	char b[5] = {1, 2, 3, 4, 5};
	check(memcmp(a, b, 5) == 0);
	char c[5] = {1, 2, 3, 4, 6};
	check(memcmp(a, c, 4) == 0); // 前4字节相等
	check(memcmp(a, c, 5) < 0);	 // 第5字节不同

	// 测试符号位差异
	unsigned char d[2] = {0xFF, 0x00};
	unsigned char e[2] = {0x7F, 0x00};
	check(memcmp(d, e, 2) > 0); // 0xFF > 0x7F（按字节无符号比较）
}

int main()
{
	test_memset();
	test_strlen();
	test_strcpy();
	test_strcat();
	test_strcmp();
	test_strncpy();
	test_strncmp();
	test_memmove();
	test_memcpy();
	test_memcmp();
	return 0;
}