/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm
*/

#include "objdump.h"

int main(int ac, char const * const *av)
{
	char const *file = ((ac >= 2) ? (av[1]) : ("a.out"));
	Elf64_Ehdr *elf;

	elf = manage_file(file);
	if (!elf) {
		fprintf(stderr, "objdump: '%s': No such file\n", file);
		return (84);
	}
	elf = check_is_elf(elf);
	if (!elf) {
		fprintf(stderr, "objdump: '%s': File format not \
		recognized\n", file);
		return (84);
	}
	objdump(elf);
	return (0);
}