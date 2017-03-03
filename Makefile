# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/03 13:58:17 by afeuerst          #+#    #+#              #
#    Updated: 2017/03/03 21:39:12 by afeuerst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAGS = -Wall -Wextra -Werror -fsanitize=address -g -O0 -std=c99

C_SOURCES_SRC = $(shell find ./src -type f | grep "\.c")
C_SOURCES_UTI = $(shell find ./utility -type f | grep "\.c")
I = -I./includes

O_SOURCES_SRC = $(C_SOURCES_SRC:.c=.o)
O_SOURCES_UTI = $(C_SOURCES_UTI:.c=.o)

PRINTF = printf "\e[34m%-30s\e[36m-->>\e[33m %-30s\n" $@ $<

all:
	make -j $(NAME)

$(NAME): $(O_SOURCES_SRC) $(O_SOURCES_UTI)
	clang $(I) $(FLAGS) $(O_SOURCES_SRC) $(O_SOURCES_UTI) ft_ls.c -o $(NAME)
	printf "\033[1;32mft_ls is now available\n"

%.o: %.c
	clang $(I) $(FLAGS) -o $@ -c $< && $(PRINTF)

clean: $(O_SOURCES_SRC) $(O_SOURCES_UTI)
	rm -rf $(O_SOURCES_SRC)
	printf "\e[32;1;5mremoved : ./src/ *.o\n"
	rm -rf $(O_SOURCES_UTI)
	printf "removed : ./utility/ *.o\n\e[0;37m"

fclean: clean
	rm -rf $(NAME)
	printf "\033[31mexecutable ft_ls removed\n"

re: fclean all

.PHONY: all $(NAME) clean fclean re
.SILENT:
