/*
** EPITECH PROJECT, 2018
** nm / objdump
** File description:
** sort_sym
*/

#include "nm.h"

int my_strcoll(char *s1, char *s2)
{
	char *tmp1 = strdup(s1);
	char *tmp2 = strdup(s2);
	int j = 0;

	for (int i = 0; s1[i]; i++)
		if (isalpha(s1[i]))
			tmp1[j++] = tolower(s1[i]);
	tmp1[j] = '\0';
	j = 0;
	for (int i = 0; s2[i]; i++)
		if (isalpha(s2[i]))
			tmp2[j++] = tolower(s2[i]);
	tmp2[j] = '\0';
	j = strcoll(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
	return (j);
}

symlist_t *sort_symlist(symlist_t *list)
{
	symlist_t *tmp = list;
	char *tmp_name;
	Elf64_Sym *tmp_sym;

	while (tmp->next) {
		if (my_strcoll(tmp->name, tmp->next->name) > 0) {
			tmp_name = tmp->name;
			tmp_sym = tmp->sym;
			tmp->name = tmp->next->name;
			tmp->sym = tmp->next->sym;
			tmp->next->name = tmp_name;
			tmp->next->sym = tmp_sym;
			return (sort_symlist(list));
		}
		tmp = tmp->next;
	}
	return (list);
}