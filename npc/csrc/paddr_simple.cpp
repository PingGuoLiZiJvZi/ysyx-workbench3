#include "paddr_simple.h"
uint8_t pmem[MAX_SIZE] = {0};
int is_device = 0;
uint8_t *guest_to_host(paddr_t paddr)
{
	return pmem + paddr - START_ADDR;
}
word_t host_read(uint8_t *haddr, int len)
{
	word_t ret = 0;
	switch (len)
	{
	case 1:
		ret = *(uint8_t *)haddr;
		break;
	case 2:
		ret = *(uint16_t *)haddr;
		break;
	case 4:
		ret = *(uint32_t *)haddr;
		break;
	default:
		assert(0);
	}
	return ret;
}
extern "C" word_t paddr_read(paddr_t addr, int len, int is_fetch, int is_avail)
{
	if (!is_avail)
	{
		return 0;
	}
	word_t ret = 0;
	if (addr >= START_ADDR && addr < START_ADDR + MAX_SIZE)
	{
#ifdef DIFFTEST
		is_device = 0;
#endif
		ret = host_read(guest_to_host(addr), len);
	}
	else
	{
#ifdef DIFFTEST
		is_device = 1;
#endif
		ret = mmio_read(addr, len);
	}

#ifdef MEMTRACE
	if (!is_fetch)
		printf("paddr read addr=0x%08x len=%d data = 0x%08x\n", addr, len, ret);
#endif

	return ret;
}
extern "C" void paddr_write(paddr_t addr, int len, word_t data, int is_avail)
{
	if (!is_avail)
	{
		return;
	}
	if (addr == 0)
		return;
	if (addr >= START_ADDR && addr < START_ADDR + MAX_SIZE)
	{
#ifdef DIFFTEST
		is_device = 0;
#endif
		switch (len)
		{
		case 1:
			*(uint8_t *)guest_to_host(addr) = data;
			break;
		case 2:
			*(uint16_t *)guest_to_host(addr) = data;
			break;
		case 4:
			*(uint32_t *)guest_to_host(addr) = data;
			break;
		default:
			assert(0);
		}
	}
	else
	{
		mmio_write(addr, len, data);
#ifdef DIFFTEST
		is_device = 1;
#endif
	}

#ifdef MEMTRACE
	printf("paddr write addr=0x%08x len=%d data=0x%08x\n", addr, len, data);
#endif
}