#include "Iomap.h"
static void map_space_write(uint8_t *addr, int len, word_t data)
{
	switch (len)
	{
	case 1:
		*(uint8_t *)addr = data;
		break;
	case 2:
		*(uint16_t *)addr = data;
		break;
	case 4:
		*(uint32_t *)addr = data;
		break;
	default:
		assert(0);
	}
}
static word_t map_space_read(uint8_t *addr, int len, int is_fetch)
{
	word_t ret = 0;
	switch (len)
	{
	case 1:
		ret = *(uint8_t *)addr;
		break;
	case 2:
		ret = *(uint16_t *)addr;
		break;
	case 4:
		ret = *(uint32_t *)addr;
		break;
	default:
		assert(0);
	}
	return ret;
}
static void check_bound(IOMap *map, paddr_t addr)
{
	if (map == NULL)
	{
		printf("address %x is out of bound", addr);
		assert(0);
	}
	else
	{
		if (addr > map->high || addr < map->low)
		{
			printf("address %x is out of bound %s %x-%x", addr, map->name, map->low, map->high);
			assert(0);
		}
	}
}
void report_mmio_overlap(const char *name1, paddr_t l1, paddr_t r1,
						 const char *name2, paddr_t l2, paddr_t r2)
{
	printf("MMIO region %s %x-%x is overlapped "
		   "with %s %x-%x\n",
		   name1, l1, r1, name2, l2, r2);
	assert(0);
}
static void invoke_callback(io_callback_t c, paddr_t offset, int len, bool is_write)
{
	if (c != NULL)
	{
		c(offset, len, is_write);
	}
}
void add_mmio_map(const char *name, paddr_t addr,
				  void *space, uint32_t len, io_callback_t callback)
{
	assert(nr_map < NR_MAP);
	paddr_t left = addr, right = addr + len - 1;
	if (in_pmem(left) || in_pmem(right))
	{
		report_mmio_overlap(name, left, right, "pmem", PMEM_LEFT, PMEM_RIGHT);
	}
	for (int i = 0; i < nr_map; i++)
	{
		if (left <= maps[i].high && right >= maps[i].low)
		{
			report_mmio_overlap(name, left, right, maps[i].name, maps[i].low, maps[i].high);
		}
	}

	maps[nr_map] = (IOMap){.name = name, .low = addr, .high = addr + len - 1, .space = space, .callback = callback};

	nr_map++;
}

word_t map_read(paddr_t addr, int len, IOMap *map)
{
	assert(len >= 1 && len <= 8);
	check_bound(map, addr);
	paddr_t offset = addr - map->low;
	invoke_callback(map->callback, offset, len, false); // prepare data to read
	word_t ret = map_space_read((uint8_t *)map->space + offset, len, 0);
	return ret;
}
void map_write(paddr_t addr, int len, word_t data, IOMap *map)
{
	assert(len >= 1 && len <= 8);
	check_bound(map, addr);
	paddr_t offset = addr - map->low;
	map_space_write((uint8_t *)map->space + offset, len, data);
	invoke_callback(map->callback, offset, len, true);
}
word_t mmio_read(paddr_t addr, int len)
{
	int mapid = find_mapid_by_addr(maps, nr_map, addr);
	if (mapid == -1)
	{
		printf("address %x is out of bound", addr);
		assert(0);
	}
	return map_read(addr, len, &maps[mapid]);
}
void mmio_write(paddr_t addr, int len, word_t data)
{
	int mapid = find_mapid_by_addr(maps, nr_map, addr);
	if (mapid == -1)
	{
		printf("address %x is out of bound", addr);
		assert(0);
	}
	map_write(addr, len, data, &maps[mapid]);
}