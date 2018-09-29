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
	new->precision = -1;
	new->padding = -1;
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
	ft_putstr("\n\n");
}

void				*get_arg_info(char *str, t_arg_info *arg_info)
{
	get_flags(str, arg_info);
	get_padding(str, arg_info);
	get_precision(str, arg_info);
	get_specifier(str, arg_info);
	// print_arg_info(arg_info);
	return (arg_info);
}
