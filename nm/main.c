/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm
*/

#include "nm.h"

int main(int ac, char const * const *av)
{
	char const *file = ((ac >= 2) ? (av[1]) : ("a.out"));
	Elf64_Ehdr *elf;
	symlist_t *list = NULL;

	elf = manage_file(file);
	if (!elf) {
		fprintf(stderr, "nm: '%s': No such file\n", file);
		return (84);
	}
	elf = check_is_elf(elf);
	if (!elf) {
		fprintf(stderr, "nm: '%s': File format not recognized\n", \
		file);
		return (84);
	}
	list = sort_symlist(my_nm(elf, list));
	dump_list(list, elf);
	return (0);
}