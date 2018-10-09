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
	new->specifier = '\0';
	new->specifier_mod = '\0';
	new->flag = -1;
	new->width = 0;
	new->precision = -1;
	new->padding = 0;
	new->rev_padding = 0;
	new->pad_zeros = 0;
	new->neg_flag = 0;
	new->pos_flag = 0;
	new->count_spaces = 0;
	return (new);
}

void				print_arg_info(t_arg_info *arg_info)
{
	ft_putstr("\narg_info->arg: ");
	ft_putstr(arg_info->arg);
	ft_putstr("\narg_info->specifier: ");
	ft_putchar(arg_info->specifier);
	ft_putstr("\narg_info->specifier_mod: ");
	ft_putnbr(arg_info->specifier_mod);
	ft_putstr("\narg_info->flag: ");
	ft_putnbr(arg_info->flag);
	ft_putstr("\narg_info->padding: ");
	ft_putnbr(arg_info->padding);
	ft_putstr("\narg_info->rev_padding: ");
	ft_putnbr(arg_info->rev_padding);
	ft_putstr("\narg_info->pad_zeros: ");
	ft_putnbr(arg_info->pad_zeros);
	ft_putstr("\narg_info->precision: ");
	ft_putnbr(arg_info->precision);
	ft_putstr("\narg_info->hash_key: ");
	ft_putnbr(arg_info->hash_key);
	ft_putstr("\narg_info->neg_flag: ");
	ft_putnbr(arg_info->neg_flag);
	ft_putstr("\narg_info->pos_flag: ");
	ft_putnbr(arg_info->pos_flag);
	ft_putstr("\narg_info->count_spaces: ");
	ft_putnbr(arg_info->count_spaces);
	ft_putstr("\n");
}

/*
**	printf format: %[char flags][num width][num .precision][num length] char specifier
*/

#include <stdio.h>

int					get_arg_info(char *str, t_arg_info *arg_info)
{
	int				i;

	i = 1;
	other_get_specifier(str, arg_info, i);
	if (arg_info->specifier == 'd')
		return (d_arg_parse(str, arg_info, i));
	i = get_mods(str, arg_info, i);
	i = get_flags(str, arg_info, i);
	i = get_padding(str, arg_info, i);
	i = get_precision(str, arg_info, i);
	while (specifier_check(str[i]) != 1)
		i++;
	i++;
	return (i);
}
