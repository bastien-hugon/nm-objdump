/*
** EPITECH PROJECT, 2018
** nm / objdump
** File description:
** nm
*/

#include "objdump.h"

void objdump(Elf64_Ehdr *elf)
{
	Elf64_Shdr *head = (Elf64_Shdr *) ((char *)elf + elf->e_shoff);
	Elf64_Shdr *sh_strtab = &head[elf->e_shstrndx];
	const char * const sh_strtab_p = ((char *)elf + sh_strtab->sh_offset);

	for (int i = 0; i < elf->e_shnum; i++) {
		//printf("%s\n", sh_strtab_p + head[i].sh_name);
	}
}