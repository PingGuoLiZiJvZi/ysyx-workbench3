extern char _data_lma[]; // 数据段加载地址(MA)
extern char _data_vma[]; // 数据段运行地址(SA)
extern unsigned _data_len;
extern char _bss_start[];
extern char _bss_end[];

void bootloader_main()
{
	/* 复制数据段到SRAM */
	for (unsigned i = 0; i < _data_len; i++)
	{
		_data_vma[i] = _data_lma[i];
	}

	/* 清零BSS段 */
	for (char *p = _bss_start; p < _bss_end; p++)
	{
		*p = 0;
	}
}