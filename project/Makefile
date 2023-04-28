TARGET := test_elf
CC		:= gcc
STRIP	:= strip

.PHONY all clean

all: ${TARGET}

${TARGET}:%.o
	ld $^ -Ttext 0xc0001500 -e main -m elf_i386 -o $@
	$(STRIP) $@

%.o:%.c
	$(CC) $^ -m32 -o $@

clean:
	$(RM) *.o $(TARGET)