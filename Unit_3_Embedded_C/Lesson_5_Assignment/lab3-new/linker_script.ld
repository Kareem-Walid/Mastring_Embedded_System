
MEMORY
{
		flash(RX) : ORIGIN = 0x08000000,  LENGTH = 128K
		sram(RWX) : ORIGIN = 0x20000000,  LENGTH = 20K
}  


SECTIONS
{
    .text : {
		*(.vectors*)
		*(.text*)
		*(.rodata*)
		*(.rodata.*)
		. = ALIGN(4);
		_E_TEXT = . ;
     } > flash

     .data : {
	    _S_DATA = .;
		*(data)
		*(data.*)
		_E_DATA = .;
	 }>sram AT> flash 
	 
	 
	 .bss : {
	 _S_BSS = .;
	 *(.bss*)
	 . = ALIGN(4);
	 _E_BSS = .;
	 } > sram
	 
	 . = . + 0x1000;
	   . = ALIGN(4);
     _Heap_End = . ;
	 
	 . = . + 0x1000;
     . = ALIGN(4);
	 _STACK_TOP = .;
	
	
	.debug : {
	    *(.debug*)
		*(.debug.*)
		
		}
		
	.kareem: {
	     *(data._*)
	  }

}