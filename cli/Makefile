NAME	= cli
CC		= gcc
CFLAGS	= -g3
RM		= rm -fr

SRC		=	src/check_args.c \
			src/count_methods.c \
			src/show_cli.c \
			src/main.c \

LIB_H	= include/cli.h

OBJ		= $(SRC:.c=.o)

all:	$(NAME) $(LIB_H)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# runv:	all
# 		valgrind --leak-check=full -s --trace-children=yes --error-exitcode=1 --track-origins=yes ./$(NAME)


re: fclean $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(OBJ)

re:		fclean all

.PHONY: clean fclean all re