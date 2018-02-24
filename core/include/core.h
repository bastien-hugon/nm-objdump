/*
** EPITECH PROJECT, 2018
** nm objdump
** File description:
** core
*/

#ifndef CORE_H_
	#define CORE_H_

	#include <fcntl.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <elf.h>
	#include <sys/mman.h>
	#include <sys/stat.h>

	Elf64_Ehdr *manage_file(char const *filename);
	Elf64_Ehdr *check_is_elf(Elf64_Ehdr *elf);

#endif /* !CORE_H_ */
