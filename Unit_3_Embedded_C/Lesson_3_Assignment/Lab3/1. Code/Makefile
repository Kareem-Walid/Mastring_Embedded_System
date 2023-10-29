# @Copyright: Kareem

Project_Name = lab3


CC=arm-none-eabi-
CFLAGS=-gdwarf-2 -mcpu=cortex-m3 -mthumb 
INCS= -I .
LIBS=
SRC= $(wildcard *.c) 
OBJ = $(SRC:.c=.o)
As= $(wildcard *.s) 
AsOBJ = $(As:.s=.o)



all: $(Project_Name).hex
	@echo "--- DONE ---"
	

	
%.o: %.c
	$(CC)gcc.exe -c $(INCS)  $(CFLAGS) $< -o $@


$(Project_Name).elf: $(OBJ)  
	$(CC)ld.exe  -T  linker_script.ld $(LIBS) $(OBJ)  -o $@ -Map=MapFile.map
	
	
$(Project_Name).hex:	$(Project_Name).elf 
	$(CC)objcopy.exe -O ihex $<  $@
	
clean_all:
	rm *.o *.bin *.elf *.map *.hex
	
clean:
	rm *.bin *.elf