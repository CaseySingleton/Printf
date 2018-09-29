/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 02:13:09 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/25 02:13:11 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// flags: hh, h, l, ll, j, z

void			get_flags(char *str, t_arg_info *arg_info)
{
	int			i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
	{
		// ft_putnbr(FLAG_CHECK(str[i]));
		// ft_putchar(' ');
		// ft_putchar(str[i]);
		// ft_putchar('\n');
		if (FLAG_CHECK(str[i]) == 1)
			break ;
		i++;
	}
	// ft_putstr("exit get_flags while loop\n");
	// ft_putchar(str[i]);
	// ft_putchar('\n');
	if (str[i] == ' ' || str[i] == '\0')
		arg_info->flag = -1;
	else if (str[i] == str[i + 1])
		arg_info->flag = (str[i] + 31) % NUM_FLAGS;
	else
		arg_info->flag = (str[i] % NUM_FLAGS);
	// ft_putstr("flag: ");
	// ft_putchar(str[i]);
	// ft_putchar('\n');
	// ft_putstr("get_flags exit\n");
}

void			get_padding(char *str, t_arg_info *arg_info)
{
	int			i;

	i = 0;
	while (!ft_isdigit(str[i]) && str[i] != '.' && str[i] != ' ' && str[i] != '\0')
		i++;
	if (str[i] == '.' || str[i] == '\0')
		arg_info->padding = 0;
	else if (str[i - 1] == '-')
		arg_info->padding = ft_atoi(str + (i - 1));
	else
		arg_info->padding = ft_atoi(str + i);
	// ft_putstr("padding: ");
	// ft_putnbr(arg_info->padding);
	// ft_putstr("\n");
}

/*
**	Precision value can not be negative. If the value is negative
**	an error occures
*/

void			get_precision(char *str, t_arg_info *arg_info)
{
	int			i;

	i = 0;
	while (str[i] != '.' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		arg_info->precision = -1;
	// ft_putstr("precision: |");
	// ft_putchar(str[i + 1]);
	// ft_putstr("|\n");
	arg_info->precision = ft_atoi(str + i + 1);
	if (arg_info->precision < 0)
	{
		ft_putstr("Precision can not be negative\n");
		exit(-1);
	}
}

// Specifiers: sSpdDioOuUxXcC

int				specifier_check(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
		|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X'
		|| c == 'c' || c == 'C')
		return (1);
	return (0);
}

void			get_specifier(char *str, t_arg_info *arg_info)
{
	int			i;

	i = 0;
	while (specifier_check(str[i]) != 1 && str[i] != '\0')
	{
		i++;
		if (str[i] == '%')
			break ;
	}
	// ft_putstr("specifier: ");
	// ft_putchar(str[i]);
	// ft_putchar('\n');
	if (str[i] == '%' || str[i] == '\0')
	{
		ft_putstr("No given specifier\n");
		exit(-1);
	}
	else
	{
		arg_info->specifier = str[i];
		arg_info->hash_key = str[i] % NUM_SPECIFIERS;
	}
}
