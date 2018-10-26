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
CFLAGS			= -Wall -Werror -Wextra -O3
FLAGS			= $(CFLAGS)

FILES			= ft_printf.c \
				  argument_parsing.c \
				  padding.c padding_helpers.c \
				  struct_functions.c argument_handling.c \
				  c_arg.c \
				  d_arg.c d_arg_handlers_1.c d_arg_handlers_2.c d_arg_helpers.c \
				  u_arg.c u_arg_handlers.c \
				  s_arg.c \
				  x_arg.c \
				  utils.c precision.c

SRC				= $(addprefix srcs/, $(FILES))
OBJ				= $(addprefix build/, $(FILES:.c=.o))

INC_LIBFT		= -I libft/includes

all: $(NAME)

ft:
	@make -C libft
	@make re

test: $(NAME)
	@$(CC) $(CFLAGS) main.c $(NAME) -o printf

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
