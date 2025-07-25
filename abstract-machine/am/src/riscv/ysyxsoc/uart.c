#include <am.h>
#include "npc.h"
#include "riscv.h"
extern unsigned char getch();
void __am_uart_rx(AM_UART_RX_T *uart_rx)
{
	uart_rx->data = getch();
}