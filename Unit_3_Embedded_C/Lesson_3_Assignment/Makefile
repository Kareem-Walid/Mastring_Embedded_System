# @Copyright: Kareem

Project_Name = lab3


CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s -mthumb 
INCS= -I .
LIBS=
SRC= $(wildcard *.c) 
OBJ = $(SRC:.c=.o)
As= $(wildcard *.s) 
AsOBJ = $(As:.s=.o)



all: $(Project_Name).hex
	@echo "--- DONE ---"
	
startup.o: startup.s
	$(CC)as.exe   $(CFLAGS) $< -o $@
	
%.o: %.c
	$(CC)gcc.exe -c $(INCS)  $(CFLAGS) $< -o $@


$(Project_Name).elf: $(OBJ)  $(AsOBJ)
	$(CC)ld.exe  -T  linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=MapFile.map
	
	
$(Project_Name).hex:	$(Project_Name).elf 
	$(CC)objcopy.exe -O ihex $<  $@
	
clean_all:
	rm *.o *.bin *.elf *.map *.hex
	
clean:
	rm *.bin *.elf