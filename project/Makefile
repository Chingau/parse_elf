TARGET := test_elf
CC		:= gcc
STRIP	:= strip
LD		:= ld

PATHS := .
PATHS += ./src
FILES := $(foreach path, $(PATHS), $(wildcard $(path)/*.c))
OBJS := $(patsubst %.c, %.o, $(FILES))

.PHONY:all clean

all: ${TARGET}

${TARGET}:$(OBJS)
	$(LD) $^ -Ttext 0xc0001500 -e main -m elf_i386 -o $@
	$(STRIP) $@

%.o:%.c
	$(CC) -c $^ -o $@ -m32

clean:
	$(RM) $(OBJS) $(TARGET)
