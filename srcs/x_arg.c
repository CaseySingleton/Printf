/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 23:08:27 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/06 23:08:27 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Gotta make this so it either appends to the fill or to the str
**	fill being padding and str being the hex number
**	if padding == '0'
**	  append to left side of fill
**	if padding != '0'
**	  append to the left side of str or the right side of fill <-- probably best idea
*/

void			x_arg_add_0x(char **fill, char **str, t_arg_info *arg_info)
{
	if (arg_info->rev_padding == 0 && arg_info->specifier_mod == '#'
	&& ft_strcmp(*str, "0") != 0)
	{
		if (arg_info->pad_zeros == 1 && arg_info->neg_flag == 0)
		{
			if (arg_info->specifier == 'x')
				*fill = ft_strjoin_free_s2("0x", *fill);
			else
				*fill = ft_strjoin_free_s2("0X", *fill);
		}
		else
		{
			if (arg_info->specifier == 'x')
				*fill = ft_strjoin_free_s1(*fill, "0x");
			else
				*fill = ft_strjoin_free_s1(*fill, "0X");
		}
	}
	else if (arg_info->specifier_mod == '#' && ft_strcmp(*str, "0") != 0)
	{
		if (arg_info->specifier == 'x')
			*str = ft_strjoin_free_s2("0x", *str);
		else
			*str = ft_strjoin_free_s2("0X", *str);
	}
}

static char		*x_arg_get_padding(char *str, t_arg_info *arg_info)
{
	char		*fill;
	int			len;

	len = arg_info->padding - ft_strlen(str);
	if (arg_info->specifier_mod == '#')
		len -= 2;
	if (len <= 0 || (!(fill = ft_strnew(len))))
			return (NULL);
	if (arg_info->pad_zeros == 1 && arg_info->rev_padding != 1)
		ft_memset(fill, '0', len);
	else
		ft_memset(fill, ' ', len);
	return (fill);
}

static void		x_arg_add_padding(char **str, t_arg_info *arg_info)
{
	char			*fill;

	fill = x_arg_get_padding(*str, arg_info);
	if (fill == NULL)
		fill = ft_strnew(0);
	if (arg_info->precision != 0)
		x_arg_add_0x(&fill, str, arg_info);
	if (arg_info->rev_padding != 1)
		*str = ft_strjoin_free(fill, *str);
	else
		*str = ft_strjoin_free(*str, fill);
}

/*
**	Not handling padding of ' ' or '0' and no appending 0x or 0X
*/

char			*x_arg(va_list arg, t_arg_info *arg_info)
{
	// print_arg_info(arg_info);
	char 		*ret;
	if (arg_info->precision == 0)
		ret = ft_strnew(0);
	else if (arg_info->flag == 'l' || arg_info->flag == 'j')
		ret = ft_llutoa_base(va_arg(arg, unsigned long), 16,
		(arg_info->specifier == 'X' ? 1 : 0));
	else if (arg_info->flag == ('l' + 'l'))
		ret = ft_llutoa_base(va_arg(arg, unsigned long long), 16,
		(arg_info->specifier == 'X' ? 1 : 0));
	else
		ret = ft_llutoa_base(va_arg(arg, unsigned int), 16,
		(arg_info->specifier == 'X' ? 1 : 0));
	x_arg_add_padding(&ret, arg_info);
	return (ret);
}
