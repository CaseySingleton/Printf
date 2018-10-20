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

void				arg_info_init(t_arg_info **arg_info)
{
	if (!((*arg_info) = (t_arg_info *)malloc(sizeof(t_arg_info))))
		return ;
	if (!((*arg_info)->padding = (t_padding *)malloc(sizeof(t_padding))))
		return ;
	if (!((*arg_info)->precision = (t_precision *)malloc(sizeof(t_precision))))
		return ;
	(*arg_info)->hash_key = -1;
	(*arg_info)->specifier = 0;
	(*arg_info)->flag = 0;
	(*arg_info)->padding->total = 0;
	(*arg_info)->padding->prefix = 0;
	(*arg_info)->padding->zero = 0;
	(*arg_info)->padding->neg = 0;
	(*arg_info)->padding->pos = 0;
	(*arg_info)->padding->rev = 0;
	(*arg_info)->padding->spaces = 0;
	(*arg_info)->precision->total = -1;
}

static void			print_arg_info_padding(t_arg_info *arg_info)
{
	ft_putstr(BOLD);
	ft_putstr("\narg_info->padding:");
	ft_putstr(RESET);
	ft_putstr("\n      total: ");
	ft_putnbr(arg_info->padding->total);
	ft_putstr("\n     prefix: ");
	ft_putnbr(arg_info->padding->prefix);
	ft_putstr("\n       zero: ");
	ft_putnbr(arg_info->padding->zero);
	ft_putstr("\n        neg: ");
	ft_putnbr(arg_info->padding->neg);
	ft_putstr("\n        pos: ");
	ft_putnbr(arg_info->padding->pos);
	ft_putstr("\n        rev: ");
	ft_putnbr(arg_info->padding->rev);
	ft_putstr("\n     spaces: ");
	ft_putnbr(arg_info->padding->spaces);
}

static void			print_arg_info_precision(t_arg_info *arg_info)
{
	ft_putstr(BOLD);
	ft_putstr("\narg_info->precision:");
	ft_putstr(RESET);
	ft_putstr("\n      total: ");
	ft_putnbr(arg_info->precision->total);
	ft_putstr("\n****************************\n");
}

void				print_arg_info(t_arg_info *arg_info)
{
	ft_putstr("****************************");
	ft_putstr(BOLD);
	ft_putstr("\narg_info:\033[0m");
	ft_putstr(RESET);
	ft_putstr("\n   hash_key: ");
	ft_putnbr(arg_info->hash_key);
	ft_putstr("\n  specifier: ");
	ft_putchar(arg_info->specifier);
	ft_putstr("\n       flag: ");
	ft_putnbr(arg_info->flag);
	print_arg_info_padding(arg_info);
	print_arg_info_precision(arg_info);
}
