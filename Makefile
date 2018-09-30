# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csinglet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 18:59:57 by csinglet          #+#    #+#              #
#    Updated: 2018/09/29 03:56:09 by csinglet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
FLAGS			= $(CFLAGS)

FILES			= ft_printf.c argument_parsing.c padding.c \
				  struct_functions.c argument_handling.c error_handling.c

SRC				= $(addprefix srcs/, $(FILES))
OBJ				= $(addprefix build/, $(FILES:.c=.o))

all: $(NAME)

ft:
	@make -C libft
	@make re

test: $(OBJ)
	@$(CC) $(FLAGS) -I includes $(OBJ) -o printf

$(NAME): $(OBJ)
	@echo "Creating archive: $@"
	@ar rc $@ $(OBJ)
	@ranlib $@

build:
	@echo "Creating build directory"
	@mkdir build

build/%.o: srcs/%.c | build
	@echo "Building $@"
	@cp libft/libft.a ./$(NAME)
	@$(CC) -I includes -c $< -o $@

clean:
	@rm -fr build

fclean: clean
	@rm -f $(NAME)

re: fclean all
