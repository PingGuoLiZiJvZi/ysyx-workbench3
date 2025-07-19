MEMORY {
    mrom : ORIGIN = 0x20000000, LENGTH = 4K
    sram : ORIGIN = 0x0f000000, LENGTH = 8K
}
ENTRY(_start)
SECTIONS {
    .text : {
        *(entry)    
        *(.text*)         
    } > mrom AT> mrom
	.rodata : {
		*(.rodata*)
	} > mrom AT> mrom
    .data : {
        _data_vma = .; 
		*(.sdata*)
        *(.data*)
        _data_vma_end = .;
    } > sram AT> mrom

    _data_lma = LOADADDR(.data);


    .bss : {
        _bss_start = .;
         *(.bss*)
		*(.sbss*)
		*(.scommon)
        _bss_end = .;
    } > sram

    .stack : {
        . = ALIGN(16);
        _stack_top = .;
		 . = _stack_top + 0x1800;
		_stack_pointer = .;
		end = .;
		_end = .;
    } > sram

	. = ALIGN(16);
    _heap_start = .;
}