#include <stdio.h>
#include "elf.h"

int main(int argv, const char* argc[])
{
    printf("Hello world. sizeof(Elf32_Ehdr)=%ld\r\n", sizeof(Elf32_Ehdr));
    return 0;
}
