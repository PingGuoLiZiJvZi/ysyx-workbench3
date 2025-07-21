.section entry, "ax"
.globl _start
.type _start, @function

_start:
  la sp, _stack_pointer
  mv s0, zero
  
  call bootloader
  call uart_init
  call display_message
  call _trm_init
