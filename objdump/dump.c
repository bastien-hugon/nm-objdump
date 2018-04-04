/*
** EPITECH PROJECT, 2018
** nm / objdump
** File description:
** nm
*/

#include "objdump.h"

void print_numeric_val(Elf64_Ehdr *elf, Elf64_Shdr shdr, unsigned int i)
{
	while (i < shdr.sh_size) {
		print_hexa_char(elf, shdr, i);
		i++;
		if (!(i % 16)) {
			printf("  ");
			return ;
		}
		if (!(i % 4))
			printf(" ");
	}
	if (i >= shdr.sh_size && i % 16)
		print_tabs_hexa(i);
}

void dump_section(Elf64_Ehdr *elf, Elf64_Shdr shdr)
{
	unsigned int addr = shdr.sh_addr;
	unsigned int i = 0;

	while (i < shdr.sh_size) {
		if (!(i % 16)) {
			printf(" %04x ", addr);
			print_numeric_val(elf, shdr, i);
			addr += 16;
		}
		print_char(elf, shdr, i);
		i++;
		if (!(i % 16))
			printf("\n");
	}
	if (i >= shdr.sh_size && i % 16)
		print_tabs_section(i);
}

int is_tab(const char *section)
{
	char tab[4][10] = {".bss", ".shstrtab", ".symtab", ".strtab"};

	for (int i = 0; i < 5; i++)
		if (!section || !strcmp(tab[i], section))
			return (0);
	return (1);
}

void objdump(Elf64_Ehdr *elf)
{
	Elf64_Shdr *head = (Elf64_Shdr *) ((char *)elf + elf->e_shoff);
	Elf64_Shdr *sh_strtab = &head[elf->e_shstrndx];
	const char * const sh_strtab_p = ((char *)elf + sh_strtab->sh_offset);

	for (int i = 0; i < elf->e_shnum; i++) {
		if (is_tab(sh_strtab_p + head[i].sh_name)) {
			printf("Contents of section %s:\n", \
			sh_strtab_p + head[i].sh_name);
			dump_section(elf, head[i]);
		}
	}
}