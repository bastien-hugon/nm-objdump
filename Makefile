##
## EPITECH PROJECT, 2018
## nm / Objdump
## File description:
## nm / objdump
##

all:
	make -C nm/
	mv nm/my_nm .
	make -C objdump/
	mv objdump/my_objdump .

clean:
	$(RM) ./my_nm
	$(RM) ./my_objdump

fclean: clean
	make fclean -C nm/
	make fclean -C objdump/

re: fclean all

.PHONY: all clean fclean re
