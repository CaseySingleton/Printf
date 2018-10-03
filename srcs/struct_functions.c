/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 23:18:43 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/25 23:18:44 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg_info			*arg_info_init(void)
{
	t_arg_info		*new;

	if (!(new = (t_arg_info *)malloc(sizeof(t_arg_info))))
		return (NULL);
	new->arg = NULL;
	new->specifier = -1;
	new->flag = -1;
	new->width = 0;
	new->precision = 0;
	new->padding = -1;
	new->pad_zeros = 0;
	return (new);
}

void				print_arg_info(t_arg_info *arg_info)
{
	ft_putstr("arg_info->flag: ");
	ft_putnbr(arg_info->flag);
	ft_putchar('\n');
	ft_putstr("arg_info->padding: ");
	ft_putnbr(arg_info->padding);
	ft_putchar('\n');
	ft_putstr("arg_info->precision: ");
	ft_putnbr(arg_info->precision);
	ft_putchar('\n');
	ft_putstr("arg_info->specifier: ");
	ft_putnbr(arg_info->specifier);
	ft_putchar('\n');
	ft_putstr("arg_info->hash_key: ");
	ft_putnbr(arg_info->hash_key);
	ft_putstr("\n\n");
}

/*
**	printf format: %[char flags][num width][num .precision][num length] char specifier
*/

#include <stdio.h>

int					get_arg_info(char *str, t_arg_info *arg_info)
{
	int				i;

	i = 1;
	// printf("start -> str: %s\n", str);
	i = get_flags(str, arg_info, i);
	// printf("after get_flags() -> str[%d]: %c\n", i, str[i]);
	i = get_padding(str, arg_info, i);
	// printf("after get_padding() -> str[%d]: %c\n", i, str[i]);
	i = get_precision(str, arg_info, i);
	// printf("after get_precision() -> str[%d]: %c\n", i, str[i]);
	i = get_specifier(str, arg_info, i);
	// printf("after get_a_room fuck -> str[%d]: %c\n", i, str[i]);
	// print_arg_info(arg_info);
	return (i);
}
