/* Linker script for CC264-R2F */
MEMORY
{
  /* NOTE 1 K = 1 KiBi = 1024 bytes */
  FLASH : ORIGIN = 0x00000000, LENGTH = 128K
  RAM : ORIGIN = 0x20000000, LENGTH = 20K
}
