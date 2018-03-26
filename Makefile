##
## EPITECH PROJECT, 2018
## nm / Objdump
## File description:
## nm / objdump
##


NMNAME	= my_nm

OBJNAME	= my_objdump

CC	= gcc

RM	= rm -f

NMSRCS	= 	./nm/main.c \
		./nm/nm.c \
		./nm/sort_sym.c \
		./nm/print_type.c \
		./core/manage_file.c

OBJSRCS	= 	./objdump/main.c \
		./objdump/dump.c \
		./core/manage_file.c

NMOBJS	= $(NMSRCS:.c=.o)
OBJOBJS	= $(OBJSRCS:.c=.o)

CFLAGS = -I ./nm/include/ -I ./core/include/ -I ./objdump/include/
CFLAGS += -W -Wall -Wextra

all: $(NMNAME) $(OBJNAME)

$(NMNAME): $(NMOBJS)
	$(CC) $(NMOBJS) -o $(NMNAME) $(LDFLAGS)

$(OBJNAME): $(OBJOBJS)
	$(CC) $(OBJOBJS) -o $(OBJNAME) $(LDFLAGS)

clean:
	$(RM) ./my_nm
	$(RM) ./my_objdump

fclean: clean
	make fclean -C nm/
	make fclean -C objdump/

re: fclean all

.PHONY: all clean fclean re