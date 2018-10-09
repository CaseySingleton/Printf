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

/*
**	# can be before or after -
**
**	if there are spaces between % and d and there is nothing but spaces
**	between the two, those spaces are added to the front of the d arg
**	(%+d, 42)    -> '+42'
**	(% d, 42)    -> ' 42'
**	(%+ d, 42)   -> '+42'
**	(% +d, 42)   -> '+42'
**	(%+  d, 42)  -> '+42'
**	(% ++d, 42)  -> '+42'
**	(%++ d, 42)  -> '+42'
**	(%0+5d, 42)  -> '+0042' the '+' takes up a padding spot
**	(%05d, -42)  -> '-0042' same goes for if the number is negative
**	(%0+5d, -42) -> '-0042'
**	looks like if a postive symbol is given but the number is negative,
**	the number being negative wins over the positive symbol
**
**	so the question is: how do I parse all the info correctly for %d while
**	not messing up anything for the other specifiers?
**
**	I could go back through the string if the specifier == 'd' and parse again?
**	But that seems slow seeing as I would have to iterate a second time
*/

int				get_mods(char *str, t_arg_info *arg_info, int i)
{
	if (str[i] == '#')
		arg_info->specifier_mod = str[i++];
	if (str[i] == '-')
	{
		arg_info->rev_padding = 1;
		i++;
	}
	if (str[i] == '#')
		arg_info->specifier_mod = str[i++];
	if (str[i] == '0')
	{
		arg_info->pad_zeros = 1;
		i++;
	}
	return (i);
}

int				get_flags(char *str, t_arg_info *arg_info, int i)
{
	if (str[i] != 'h' && str[i] != 'l' && str[i] != 'j' && str[i] != 'z')
		arg_info->flag = -1;
	else if (str[i] == str[i + 1])
	{
		arg_info->flag = (str[i] + str[i]);
		i += 2;
	}
	else
		arg_info->flag = str[i];
	return (i);
}

int				get_padding(char *str, t_arg_info *arg_info, int i)
{
	if (!ft_isdigit(str[i]))
	{
		arg_info->padding = 0;
		return (i);
	}
	if (str[i] == '0' || (str[i] == '0' && !ft_isdigit(str[i + 1])))
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
	if (str[i] != '.')
		return (i);
	i++;
	if (str[i] == '+')
		i++;
	if (ft_isdigit(str[i]))
	{
		arg_info->precision = ft_atoi(str + i);
		if (arg_info->precision < 0)
		{
			ft_putstr("Precision can not be negative\n");
			exit(-1);
		}
	}
	else
		arg_info->precision = 0;
	if (arg_info->precision > 0)
		return (i += ft_numlen(arg_info->precision));
	return (i);
}

/*
**	printf format: %[char flags][num width][num .precision][num length] char specifier
**	Specifiers: sSpdDioOuUxXcC
*/

void			other_get_specifier(char *str, t_arg_info *arg_info, int i)
{
	while (specifier_check(str[i]) != 1 && str[i] != '\0')
		i++;
	if (str[i] != '\0')
	{
		arg_info->specifier = str[i];
		arg_info->hash_key = str[i] % NUM_SPECIFIERS;
	}
}

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
