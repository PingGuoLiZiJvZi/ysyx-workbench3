#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef void (*io_callback_t)(uint32_t, int, bool);
uint8_t *new_space(int size);
typedef uint32_t paddr_t;
typedef uint16_t ioaddr_t;
typedef uint32_t word_t;
#define NR_MAP 16
#define PMEM_LEFT ((paddr_t)0x80000000)
#define PMEM_RIGHT ((paddr_t)0x80000000 + 0x8000000 - 1)
typedef struct
{
	const char *name;
	// we treat ioaddr_t as paddr_t here
	paddr_t low;
	paddr_t high;
	void *space;
	io_callback_t callback;
} IOMap;
static IOMap maps[NR_MAP] = {};
static int nr_map = 0;
static inline bool map_inside(IOMap *map, paddr_t addr)
{
	return (addr >= map->low && addr <= map->high);
}
static inline int in_pmem(paddr_t addr)
{
	return (addr >= 0x80000000 && addr < 0x80000000 + 0x8000000);
}
static inline int find_mapid_by_addr(IOMap *maps, int size, paddr_t addr)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (map_inside(maps + i, addr))
		{
			// difftest_skip_ref();
			return i;
		}
	}
	return -1;
}

void add_mmio_map(const char *name, paddr_t addr,
				  void *space, uint32_t len, io_callback_t callback);

word_t map_read(paddr_t addr, int len, IOMap *map);
void map_write(paddr_t addr, int len, word_t data, IOMap *map);
word_t mmio_read(paddr_t addr, int len);
void mmio_write(paddr_t addr, int len, word_t data);
