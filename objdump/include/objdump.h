/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm
*/

#ifndef DUMP_H_
	#define DUMP_H_

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	#include "core.h"

	#define NO_FLAGS	(0x0000)
	#define HAS_RELOC	(0x0001)
	#define EXEC_P		(0x0002)
	#define HAS_DEBUG	(0x0008)
	#define HAS_SYMS	(0x0010)
	#define HAS_LOCALS	(0x0020)
	#define DYNAMIC		(0x0040)
	#define D_PAGED		(0x0100)

	void objdump(Elf64_Ehdr *);
	void print_header(const char *file, Elf64_Ehdr *elf);
#endif