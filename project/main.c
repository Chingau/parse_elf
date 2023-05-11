#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "elf.h"

#define FILE_APTH   "./test_elf"
int main(int argv, const char* argc[])
{
    int fd = -1;
    Elf32_Ehdr elf32_header;
    ssize_t count = 0;

    if ((fd = open((const char *)FILE_APTH, O_RDONLY)) < 0) {
        perror("open");
        return -1;
    }

    count = read(fd, (char *)&elf32_header, sizeof(Elf32_Ehdr));
    if (count != sizeof(Elf32_Ehdr)) {
        perror("read");
        goto __EXIT_PROC;
    }

    printf("e_ident:");
    for (int i = 0; i < EI_NIDENT; ++i) {
        printf("%02X ", elf32_header.e_ident[i]);
    }
    printf("\r\n");

    printf("文件类型: ");
    switch (elf32_header.e_type) {
        case ET_NONE:
            printf("非法类型\r\n");
        break;
        case ET_REL:
            printf("可重定位文件\r\n");
        break;
        case ET_EXEC:
            printf("可执行文件\r\n");
        break;
        case ET_DYN:
            printf("共享目标文件\r\n");
        break;
        case ET_CORE:
            printf("Core文件\r\n");
        break;
        default:
            printf("%04x\r\n", elf32_header.e_type);
        break;
    }

    printf("CPU架构: ");
    switch(elf32_header.e_machine) {
        case EM_386:
            printf("Intel 80386\r\n");
        break;
        case EM_860:
            printf("Intel 80860\r\n");
        break;
        case EM_ARM:
            printf("ARM\r\n");
        break;
        default:
            printf("%04x\r\n", elf32_header.e_machine);
        break;
    }

    printf("ELF版本:%08x\r\n", elf32_header.e_version);
    printf("程序虚拟入口地址:0x%08x\r\n", elf32_header.e_entry);

    printf("e_phoff:%08x\r\n", elf32_header.e_phoff);
    printf("e_shoff:%08x\r\n", elf32_header.e_shoff);
    printf("e_flags:%08x\r\n", elf32_header.e_flags);
    printf("e_ehsize:%04x\r\n", elf32_header.e_ehsize);
    printf("e_ehsize:%04x\r\n", elf32_header.e_ehsize);
    printf("e_phentsize:%04x\r\n", elf32_header.e_phentsize);
    printf("e_phnum:%04x\r\n", elf32_header.e_phnum);
    printf("e_shentsize:%04x\r\n", elf32_header.e_shentsize);
    printf("e_shnum:%04x\r\n", elf32_header.e_shnum);
    printf("e_shstrndx:%04x\r\n", elf32_header.e_shstrndx);

    close(fd);
    return 0;

__EXIT_PROC:
    close(fd);
    return -1;
}
