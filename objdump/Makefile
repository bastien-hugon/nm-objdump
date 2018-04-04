##
## EPITECH PROJECT, 2018
## nm / objdump
## File description:
## nm
##

NAME	= my_objdump

CC	= gcc

RM	= rm -f

SRCS	= 	./main.c \
		./print_header.c \
		./dump.c \
		./print_char.c \
		../core/manage_file.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/ -I ../core/include/
CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re