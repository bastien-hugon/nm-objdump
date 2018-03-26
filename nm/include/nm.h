/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm
*/

#ifndef NM_H_
	#define NM_H_

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	#include "core.h"

	typedef struct symlist_s
	{
		Elf64_Sym *sym;
		Elf64_Shdr *shdr;
		char *name;
		struct symlist_s *next;
	} symlist_t;

	symlist_t *my_nm(Elf64_Ehdr *elf, symlist_t *);
	char print_type(Elf64_Sym sym, Elf64_Shdr *shdr, Elf64_Ehdr *elf);
	void dump_list(symlist_t *list, Elf64_Ehdr *elf);
	symlist_t *sort_symlist(symlist_t *);

#endif