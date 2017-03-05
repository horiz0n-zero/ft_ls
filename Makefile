# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/03 13:58:17 by afeuerst          #+#    #+#              #
#    Updated: 2017/03/05 03:35:11 by afeuerst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAGS = -Wall -Wextra -Werror -fsanitize=address -std=c99 -g -O0

C_SOURCES_SRC = ./ft_ls.c \
				./src/check.c \
				./src/ft_algo.c \
				./src/ft_print_directory.c \
				./src/ft_print_long.c \
				./src/ft_sort__shell.c \
				./src/print/ft_star.c \
				./src/print/print.c \
				./src/print/print_number.c \
				./src/utility/ft_memset_ll.c \
				./src/utility/ft_stc_strjoin.c \
				./src/utility/ft_string.c

O_SRC = $(C_SOURCES_SRC:.c=.o)
I = -I./includes

PRINTF = printf "\e[34m%-30s\e[36m-->>\e[33m %-30s\n" $@ $<

all: $(NAME)

$(NAME):
	gcc $(I) $(FLAGS) $(C_SOURCES_SRC) -o $(NAME)
	printf "\033[1;32mft_ls is now available\n"

clean:
	rm -rf $(O_SRC)
	printf "\e[32;1;5mremoved : ./src/ *.o\n"

fclean: clean
	rm -rf $(NAME)
	printf "\033[31mexecutable ft_ls removed\n"

re: fclean all

#.PHONY: all $(NAME) clean fclean re
.SILENT:
