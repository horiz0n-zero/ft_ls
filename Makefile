NAME = ft_ls

C_SOURCES = $(shell find . -type f | grep "\.c")

all:
	make -j $(NAME)

$(NAME):
	gcc -I. $(C_SOURCES) -o $(NAME) -fsanitize=address
	printf "\033[32mft_ls is now available\n"

clean:
	printf "\033[32mthis option do nothing !\r"

fclean: clean
	rm -rf $(NAME)
	printf "\033[31mexecutable ft_ls removed\n"

re: fclean all

.PHONY: all $(NAME) clean fclean re
.SILENT:
