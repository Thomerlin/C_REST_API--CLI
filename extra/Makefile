CLI	= ./cli
API	= ./api

all: 
	$(MAKE) -C $(API)
	$(MAKE) -C $(CLI)

clean:
					$(MAKE) -C $(API) clean
					$(MAKE) -C $(CLI) clean

fclean:				clean
					$(MAKE) -C $(API) fclean
					$(MAKE) -C $(CLI) fclean

re:					fclean all

.PHONY:				all clean fclean re