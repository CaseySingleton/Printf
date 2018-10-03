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

int				specifier_check(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
		|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X'
		|| c == 'c' || c == 'C' || c == '%')
		return (1);
	return (0);
}

// flags: hh, h, l, ll, j, z

int				get_flags(char *str, t_arg_info *arg_info, int i)
{
	if (str[i] != 'h' && str[i] != 'l' && str[i] != 'j' && str[i] != 'z')
	{
		arg_info->flag = -1;
		return (i);
	}
	else if (str[i] == str[i + 1])
	{
		arg_info->flag = (str[i] + 31) % NUM_FLAGS;
		return (i + 2);
	}
	else
		arg_info->flag = (str[i] % NUM_FLAGS);
	return (i);
}

int				get_padding(char *str, t_arg_info *arg_info, int i)
{
	if ((!ft_isdigit(str[i]) && str[i] != '-') || str[i] == '\0')
	{
		arg_info->padding = 0;
		return (i);
	}
	if (str[i] == '0' || (str[i] == '-' && str[i + 1] == '0'))
		arg_info->pad_zeros = 1;
	arg_info->padding = ft_atoi(str + i);
	if (arg_info->padding < 0)
		i++;
	return (i += ft_numlen(ft_abs(arg_info->padding)));
}

/*
**	Precision value can not be negative. If the value is negative
**	an error occures
*/

int				get_precision(char *str, t_arg_info *arg_info, int i)
{
	if (str[i] != '.' || str[i] == '\0')
		return (i);
	arg_info->precision = ft_atoi(str + ++i);
	if (arg_info->precision < 0)
	{
		ft_putstr("Precision can not be negative\n");
		exit(-1);
	}
	if (arg_info->precision != 0)
		return (i += ft_numlen(arg_info->precision));
	return (i);
}

/*
**	printf format: %[char flags][num width][num .precision][num length] char specifier
**	Specifiers: sSpdDioOuUxXcC
*/

int				get_specifier(char *str, t_arg_info *arg_info, int i)
{
	while (specifier_check(str[i]) != 1 && str[i] != '\0')
		i++;
	if (str[i] != '\0')
	{
		arg_info->specifier = str[i];
		arg_info->hash_key = str[i] % NUM_SPECIFIERS;
	}
	return (i + 1);
}
