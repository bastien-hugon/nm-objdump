/*
** EPITECH PROJECT, 2018
** nm objdump
** File description:
** core
*/

#include "core.h"

/*
** Check if the file is ELF formated
*/
Elf64_Ehdr *check_is_elf(Elf64_Ehdr *elf)
{
	if (elf->e_ident[EI_MAG0] == 0x7f && elf->e_ident[EI_MAG1] == 'E' && \
	elf->e_ident[EI_MAG2] == 'L' && elf->e_ident[EI_MAG3] == 'F')
		return (elf);
	return (NULL);
}

/*
** Get a filename as parameter and return an Elf64_Ehdr *
*/
Elf64_Ehdr *manage_file(char const *filename)
{
	int fd;
	void *buf;
	struct stat s;
	Elf64_Ehdr *elf;

	fd = open(filename, O_RDONLY);
	if (fd != -1) {
		fstat(fd, &s);
		buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
		close(fd);
		if (buf != (void *) -1) {
			elf = buf;
			return (elf);
		}
	}
	return (NULL);
}