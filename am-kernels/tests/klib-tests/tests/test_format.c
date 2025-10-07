#include <trap.h>
void check_sprintf_int(const char *expected, const char *fmt, int arg)
{
	char buf[256];
	// 检查输出内容
	int written = sprintf(buf, fmt, arg);
	check(strcmp(buf, expected) == 0);
	// 检查返回值（不包括终止符）
	check(written == strlen(expected));
}
void check_sprintf_hex(const char *expected, const char *fmt, unsigned int arg)
{
	char buf[256];
	// 检查输出内容
	int written = sprintf(buf, fmt, arg);
	check(strcmp(buf, expected) == 0);
	// 检查返回值（不包括终止符）
	check(written == strlen(expected));
}
void check_sprintf_str(const char *expected, const char *fmt, char *arg)
{
	char buf[256];
	// 检查输出内容
	int written = sprintf(buf, fmt, arg);
	check(strcmp(buf, expected) == 0);
	// 检查返回值（不包括终止符）
	check(written == strlen(expected));
}
void check_sprintf_char(const char *expected, const char *fmt, char arg)
{
	char buf[256];
	// 检查输出内容
	int written = sprintf(buf, fmt, arg);
	check(strcmp(buf, expected) == 0);
	// 检查返回值（不包括终止符）
	check(written == strlen(expected));
}
void check_sprintf(const char *expected, const char *buf, int written)
{
	check(strcmp(buf, expected) == 0);
	// 检查返回值（不包括终止符）
	check(written == strlen(expected));
}
// 测试整数 %d
void test_sprintf_int()
{
	check_sprintf_int("123", "%d", 123);
	check_sprintf_int("-456", "%d", -456);
	check_sprintf_int("0", "%d", 0);
	check_sprintf_int("2147483647", "%d", 2147483647);	 // INT_MAX
	check_sprintf_int("-2147483648", "%d", -2147483648); // INT_MIN (假设32位)
}

// 测试字符串 %s
void test_sprintf_str()
{
	check_sprintf_str("hello", "%s", "hello");
	check_sprintf_str("", "%s", "");				 // 空字符串
	check_sprintf_str("(null)", "%s", (char *)NULL); // 处理 NULL 指针（模仿 glibc 行为？）
}

// 测试字符 %c
void test_sprintf_char()
{
	check_sprintf_char("A", "%c", 'A');
	check_sprintf_char(" ", "%c", ' ');
	check_sprintf_char("\x01", "%c", 1); // ASCII 控制字符
}

// 测试十六进制 %x
void test_sprintf_hex()
{
	check_sprintf_hex("1a3f", "%x", 0x1A3F); // 小写输出
	check_sprintf_hex("0", "%x", 0);
	check_sprintf_hex("deadbeef", "%x", 0xDEADBEEF);
}

// 测试百分号 %%
void test_sprintf_percent()
{
	char buf[256];
	int res = sprintf(buf, "Percent: %%");
	check_sprintf("Percent: %", buf, res);
	res = sprintf(buf, "Value: %d%%", 50);
	check_sprintf("Value: 50%", buf, res);
}

// 测试混合格式
void test_sprintf_mixed()
{
	char buf[256];
	int res = sprintf(buf, "Value: %d, Str: %s, Char: %c", 123, "test", 'A');
	check_sprintf("Value: 123, Str: test, Char: A", buf, res);
	res = sprintf(buf, "Hex: %x, Dec: %d", 0xDEAD, -42);
	check_sprintf("Hex: dead, Dec: -42", buf, res);
}
void test_sprintf()
{
	test_sprintf_int();
	test_sprintf_str();
	test_sprintf_char();
	test_sprintf_hex();
	test_sprintf_percent();
	test_sprintf_mixed();

	// 测试边界情况
	check_sprintf_str("", "%s", "");					 // 空字符串
	check_sprintf_str(" ", "%s", " ");					 // 空格字符串
	check_sprintf_str("1234567890", "%s", "1234567890"); // 较长字符串
}
int main()
{
	test_sprintf();
	return 0;
}