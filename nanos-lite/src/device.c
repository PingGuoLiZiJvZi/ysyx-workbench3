#include <common.h>

#if defined(MULTIPROGRAM) && !defined(TIME_SHARING)
#define MULTIPROGRAM_YIELD() yield()
#else
#define MULTIPROGRAM_YIELD()
#endif

#define NAME(key) \
	[AM_KEY_##key] = #key,

static const char *keyname[256] __attribute__((used)) = {
	[AM_KEY_NONE] = "NONE",
	AM_KEYS(NAME)};

size_t serial_write(const void *buf, size_t offset, size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		putch(((const char *)buf)[i]);
	}
	return len;
}

size_t events_read(void *buf, size_t offset, size_t len)
{
	AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
	if (ev.keycode == AM_KEY_NONE)
		return 0;
	char p[64] = {0};
	if (ev.keydown)
		sprintf(p, "kd %s", keyname[ev.keycode]);
	else
		sprintf(p, "ku %s", keyname[ev.keycode]);
	size_t n = strlen(p);
	if (n > len)
		panic("events_read: buffer too small");
	memcpy(buf, p, n);
	return n;
}

size_t dispinfo_read(void *buf, size_t offset, size_t len)
{
	AM_GPU_CONFIG_T gpu_config = io_read(AM_GPU_CONFIG);
	uint32_t width = gpu_config.width;
	uint32_t height = gpu_config.height;
	char p[256] = {0};
	sprintf(p, "WIDTH:%u\nHEIGHT:%u\n", width, height);
	size_t n = strlen(p);
	if (n + 1 > len)
	{
		panic("dispinfo_read: buffer too small");
	}
	printf("dispinfo_read: %s\n", p);
	memcpy(buf, p, n);
	return 0;
}

size_t fb_write(const void *buf, size_t offset, size_t len)
{
	return 0;
}

void init_device()
{
	Log("Initializing devices...");
	ioe_init();
}
