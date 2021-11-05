/* 
 * Trying to build a linker using: 
 * https://microcontrollerslab.com/bare-metal-embedded-systems-linker-script-file/
 */


STACKSIZE = 1024;
HEAPSIZE = 256;

ENTRY(ResetISR)

MEMORY
{
    FLASH (rx)      : ORIGIN = 0x00000000, LENGTH = 0x0001ffa8 /* Main programable flash */
    FLASH_CCFG (rx) : ORIGIN = 0x0001ffa8, LENGTH = 0x00000058 /* Customer config flash area */
    RAM (RWX)      : ORIGIN = 0x20000000, LENGTH = 0x00005000
}

SECTIONS {
	/*
	 * Initial stack pointer. Starts at higher address ORIGIN(RAM) + LENGTH(RAM) - 1
	 */
	PROVIDE(_stack_ptr = ORIGIN(RAM) + LENGTH(RAM));

    /* constants  and other code stored in FLASH */
    .text :
    {
        _text = .;               /* beginning of .text segment,also called code memory */
        KEEP(*(.vector_table)) /* vector table defined in startup.c to be included */
        *(.text*)                   /* other code */
        *(.rodata*)                /* constants go here */
        _etext = .;             /* end of .text segment */
    } > FLASH

    /* data, initialized variables, to be copied to RAM upon <RESET> by startup.c */
    .data : 
    {
        _data = .;          /* beginning of .data segment */
        *(.data*)           /* data goes here */
        _edata = .;         /* end of .data segment */
    } > RAM AT >FLASH   /* .data segment starts directly after the .text section in FLASH */

    /* uninitialized data which is initialized to 0 upon <RESET> by startup.c */
    .bss :
    {
        _bss = .;       /* beginning of .bss segment */
        *(.bss*)        /* .bss content goes here */
        *(COMMON)       
        _ebss = .;      /* end of .bss segment */
    } > RAM
    .heap :
	{
        __heap_start__ = .;
        end = __heap_start__;
        _end = end;
        __end = end;
        . = . + HEAPSIZE;
        KEEP(*(.heap))
        __heap_end__ = .;
        __HeapLimit = __heap_end__;
    } > RAM

    .stack (NOLOAD) : ALIGN(0x8)
	{
        _stack = .;
        __stack = .;
        KEEP(*(.stack))
        . += STACKSIZE;
        _stack_end = .;
        __stack_end = .;
    } > RAM
}
