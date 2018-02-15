/*
** EPITECH PROJECT, 2018
** nm / objdump
** File description:
** nm
*/

#include "nm.h"

void dumm_list(symlist_t *list)
{
	while (list) {
		printf("%016x %c %s\n", list->sym->st_value, \
		list->sym->st_info, list->name);
		list = list->next;
	}
}

symlist_t *symlist_add_elem(symlist_t *list, Elf64_Sym *sym, char *name)
{
	symlist_t *tmp = list;
	symlist_t *new = malloc(sizeof(symlist_t));


	if (name[0] < 33)
		return (list);
	new->sym = sym;
	new->name = name;
	new->next = NULL;
	if (!list)
		list = new;
	else {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (list);
}

void my_nm(Elf64_Ehdr *elf)
{
	Elf64_Shdr *head = (Elf64_Shdr *) ((char *)elf + elf->e_shoff);
//	Elf64_Shdr *sh_strtab = &head[elf->e_shstrndx];
//	const char * const sh_strtab_p = ((char *)elf + sh_strtab->sh_offset);
	Elf64_Shdr *stab;
	Elf64_Sym *sym;
	Elf64_Shdr *strtab;
	char *symmaddr;
	symlist_t *list = NULL;

	for (int i = 0; i < elf->e_shnum; i++) {
		//printf("%016x ? %s\n", head[i].sh_name, sh_strtab_p + head[i].sh_name);
		if (head[i].sh_type == SHT_SYMTAB) {
			stab = &head[i];
			symmaddr = (char *)elf + (&head[i])->sh_offset;
			break;
		}
	}
	for (int j = 0; j < ((int)(stab->sh_size / stab->sh_entsize)); j++) {
		sym = &((Elf64_Sym *) symmaddr)[j];
		strtab = &head[stab->sh_link];
		list = symlist_add_elem(list, sym, \
		(char *)elf + strtab->sh_offset + sym->st_name);
	}
	dumm_list(list);
}