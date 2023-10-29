# @Copyright: Kareem

Project_Name = lab4_M4


CC=arm-none-eabi-
CFLAGS=  -g -mcpu=cortex-m4 -mthumb 
INCS= -I .
LIBS=
SRC= $(wildcard *.c) 
OBJ = $(SRC:.c=.o)
As= $(wildcard *.s) 
AsOBJ = $(As:.s=.o)



all: $(Project_Name).bin
	@echo "======= DONE ======"
	

%.o: %.c
	$(CC)gcc.exe -c $(INCS)  $(CFLAGS) $< -o $@


$(Project_Name).elf: $(OBJ)  
	$(CC)ld.exe  -T  linker_script.ld $(LIBS) $(OBJ)  -o $@ -Map=MapFile.map
	cp $(Project_Name).elf   $(Project_Name).axf
	
	
$(Project_Name).bin:	$(Project_Name).elf 
	$(CC)objcopy.exe -O ihex $<  $@
	
clean_all:
	rm *.o *.bin *.elf *.map *.hex
	
clean:
	rm *.bin *.elf