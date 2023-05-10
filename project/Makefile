CC		:= gcc
STRIP	:= strip
LD		:= ld
TEST_ELF := test_elf

PATHS := .
PATHS += ./src

FILES_ALL := $(foreach path, $(PATHS), $(wildcard $(path)/*.c))
FILE_ELF := $(filter %$(TEST_ELF).c, $(FILES_ALL))
FILES := $(filter-out %$(TEST_ELF).c, $(FILES_ALL))

OBJS_ALL := $(patsubst %.c, %.o, $(FILES_ALL))
OBJ_ELF := $(filter %$(TEST_ELF).o, $(OBJS_ALL))
OBJS := $(filter-out %$(TEST_ELF).o, $(OBJS_ALL))

INCS := ./inc
INC_PATH := $(foreach path, $(INCS), $(patsubst %, -I%, $(path)))

PHONY := all
PHONY += clean
PHONY += $(TEST_ELF)
.PHONY:$(PHONY)

all: $(TEST_ELF) main

$(TEST_ELF):$(OBJ_ELF)
	$(LD) $^ -Ttext 0xc0001500 -e main -m elf_i386 -o $@
	$(STRIP) $@

$(OBJ_ELF):$(FILE_ELF)
	$(CC) -c $^ -o $@ -m32

main:$(OBJS)
	$(CC) $^ -o $@ $(INC_PATH)

$(OBJS):$(FILES)
	$(CC) -c $^ -o $@ -Wall $(INC_PATH)

clean:
	$(RM) $(OBJS_ALL) main $(TEST_ELF)