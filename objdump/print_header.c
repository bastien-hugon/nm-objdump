/*
** EPITECH PROJECT, 2018
** OBJDUMP
** File description:
** Print Headers
*/

#include "objdump.h"

void print_flags(unsigned int flags)
{
	uint16_t tab[8] = {NO_FLAGS, HAS_RELOC, EXEC_P, HAS_DEBUG, HAS_SYMS, \
			HAS_LOCALS, DYNAMIC, D_PAGED};
	char tags[8][10] = {"NO_FLAGS", "HAS_RELOC", "EXEC_P", "HAS_DEBUG", \
	"HAS_SYMS", "HAS_LOCALS", "DYNAMIC", "D_PAGED"};
	int first = 0;

	for (int i = 0; i < 8; i++) {
		if (flags & tab[i]) {
			printf("%s%s", first ? ", " : "", tags[i]);
			first++;
			flags -= tab[i];
		}
	}
	printf("\n");
}

unsigned int has_syms(Elf64_Ehdr *elf)
{
	Elf64_Shdr *head = (Elf64_Shdr *) ((char *)elf + elf->e_shoff);

	for (int i = 0; i < elf->e_shnum; i++) {
		if (head[i].sh_type == SHT_SYMTAB)
			return (HAS_SYMS);
	}
	return (0);
}

unsigned int get_flags(Elf64_Ehdr *elf)
{
	unsigned int flags = NO_FLAGS;

	if (elf->e_type == ET_EXEC)
		flags += EXEC_P + D_PAGED;
	else if (elf->e_type == ET_DYN)
		flags += DYNAMIC + D_PAGED;
	else if (elf->e_type == ET_REL)
		flags += HAS_RELOC;
	flags += has_syms(elf);
	return (flags);
}

void print_header(const char *file, Elf64_Ehdr *elf)
{
	unsigned int flags = get_flags(elf);

	printf("\n%s:     file format elf64-x86-64\n", file);
	printf("architecture: i386:x86-64, flags 0x%08x:\n", flags);
	print_flags(flags);
	printf("start address 0x%016lx\n\n", elf->e_entry);
}