/*
** EPITECH PROJECT, 2018
** Objdump
** File description:
** Print Char
*/

#include "objdump.h"

void print_hexa_char(Elf64_Ehdr *elf, Elf64_Shdr shdr, unsigned int i)
{
	printf("%02x", (unsigned char) (((char *) elf) + shdr.sh_offset)[i]);
}

void print_char(Elf64_Ehdr *elf, Elf64_Shdr shdr, unsigned int i)
{
	char c = (unsigned char) (((char *) elf) + shdr.sh_offset)[i];

	if (isprint(c))
		printf("%c", c);
	else
		printf(".");
}

void print_tabs_section(unsigned int i)
{
	while (i % 16)
	{
		printf(" ");
		i += 1;
	}
	printf("\n");
}

void print_tabs_hexa(unsigned int i)
{
	while (i % 16)
	{
		printf("  ");
		i += 1;
		if (!(i % 4))
			printf(" ");
		if (!(i % 16))
			printf(" ");
	}
}