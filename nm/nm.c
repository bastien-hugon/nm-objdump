/*
** EPITECH PROJECT, 2018
** nm / objdump
** File description:
** nm
*/

#include "nm.h"

void dump_list(symlist_t *list)
{
	while (list) {
		if (list->sym->st_value)
			printf("%016lx ", list->sym->st_value);
		else
			printf("                 ");
		printf("%c %s\n", print_type(*(list->sym), list->shdr), \
		list->name);
		list = list->next;
	}
}

symlist_t *symlist_add_elem(symlist_t *list, Elf64_Sym *sym, char *name, \
Elf64_Shdr *shdr)
{
	symlist_t *tmp = list;
	symlist_t *new = malloc(sizeof(symlist_t));


	if (name[0] < 33 || sym->st_info == STT_FILE)
		return (list);
	new->sym = sym;
	new->name = name;
	new->next = NULL;
	new->shdr = shdr;
	if (!list)
		list = new;
	else {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (list);
}

symlist_t *my_nm(Elf64_Ehdr *elf, symlist_t *list)
{
	Elf64_Shdr *head = (Elf64_Shdr *) ((char *)elf + elf->e_shoff);
	Elf64_Shdr *stab;
	Elf64_Sym *sym;
	Elf64_Shdr *strtab;
	char *symmaddr;

	for (int i = 0; i < elf->e_shnum; i++) {
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
		(char *)elf + strtab->sh_offset + sym->st_name, head);
	}
	return (list);
}