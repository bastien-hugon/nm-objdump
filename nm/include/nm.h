/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm
*/

#ifndef NM_H_
	#define NM_H_

	#include <stdio.h>
	#include "core.h"

	typedef struct symlist_s
	{
		Elf64_Sym *sym;
		char *name;
		struct symlist_s *next;
	} symlist_t;

	void my_nm(Elf64_Ehdr *elf);

#endif /* !NM_H_ */
