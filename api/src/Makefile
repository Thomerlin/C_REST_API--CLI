NAME		= api
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIBFLAGS	= -lcurl -ljson-c #-lmysqlclient
RM			= rm -fr

SRCS		=	libs/mongoose.c \
				src/logger.c \
				src/server_mongoose.c \
				src/client_http_curl.c \
				src/main.c \
				
LIB_H		= include/api.h

OBJS		= $(SRCS:.c=.o)

all:	$(NAME) $(LIB_H)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFLAGS)
	
	mkdir -p ../logs
	

# runv:	all
# 		valgrind --leak-check=full -s --trace-children=yes --error-exitcode=1 --track-origins=yes ./$(NAME)

clean:
		$(RM) $(OBJS)

fclean:
		$(RM) $(NAME) $(OBJS) ../logs *.o

re:		fclean all

.PHONY: clean fclean all re