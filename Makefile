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
				  struct_functions.c argument_handling.c error_handling.c \
				  d_arg.c x_arg.c utils.c

SRC				= $(addprefix srcs/, $(FILES))
OBJ				= $(addprefix build/, $(FILES:.c=.o))

INC_LIBFT		= -I libft/includes

all: $(NAME)

ft:
	@make -C libft
	@make re

test: $(NAME)
	@$(CC) main.c $(NAME) -o printf

$(NAME): $(OBJ)
	@echo "Creating archive: libft.a"
	@make -C libft
	@echo "Creating archive: $@"
	@cp libft/libft.a ./$(NAME)
	@ar rc $@ $(OBJ)
	@ranlib $@

build:
	@echo "Creating build directory"
	@mkdir build

build/%.o: srcs/%.c | build
	@echo "Building $@"
	@$(CC) -I includes -c $< -o $@

clean:
	@rm -fr build
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
