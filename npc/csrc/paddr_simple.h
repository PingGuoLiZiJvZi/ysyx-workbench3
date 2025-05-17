#pragma once
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "Iomap.h"
#include "config.h"
typedef uint32_t paddr_t;
typedef uint32_t word_t;
#define START_ADDR 0x80000000
#define MAX_SIZE 0x8000000
extern uint8_t pmem[MAX_SIZE];
uint8_t *guest_to_host(paddr_t paddr);
word_t host_read(uint8_t *haddr, int len);
extern "C" word_t paddr_read(paddr_t addr, int len, int is_fetch, int is_avail);
extern "C" void paddr_write(paddr_t addr, int len, word_t data, int is_avail);
extern int is_device;
