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
				  parsing.c \
				  padding.c padding_helpers.c \
				  handle_ascii.c handle_wascii.c \
				  handle_signed.c \
				  handle_unsigned.c \
				  utils.c \
				  buffer.c

SRC				= $(addprefix srcs/, $(FILES))
OBJ				= $(addprefix build/, $(FILES:.c=.o))

INC_LIBFT		= -I libft/includes

all: $(NAME)

ft:
	@make -C libft
	@make re

test:
	@$(CC) $(FLAGS) main.c libftprintf.a $(NAME) -o printf -I includes

$(NAME): $(OBJ)
	@echo "Creating archive: libft.a"
	@make -C libft
	@echo "Creating archive: $(NAME)"
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

build:
	@echo "Creating build directory"
	@mkdir build

build/%.o: srcs/%.c | build
	@echo "  Building $@"
	@$(CC) $(FLAGS) -I includes -c $< -o $@

clean:
	@rm -fr build
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
