/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 18:34:07 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/26 18:34:07 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

/*
**	Given the string to be printed and the current argument as a string,
**	this function appends the argument to the end of string
*/

char					*s_arg(va_list arg, t_arg_info *arg_info)
{
	char				*temp;
	char				*ret;

	temp = va_arg(arg, char *);
	if (temp == NULL)
		ret = ft_strdup("(null)");
	else if (arg_info->precision->total > 0)
		ret = ft_strndup(temp, arg_info->precision->total);
	else
		ret = ft_strdup(temp);
	handle_padding(&ret, arg_info);
	return (ret);
}

/*
**	I think u_arg() works about the same as x_arg()
*/

char					*o_arg(va_list arg, t_arg_info *arg_info)
{
	char				*ret;
	long long			i;

	i = va_arg(arg, long long);
	if (arg_info->precision->total == 0)
	{
		if (arg_info->padding->prefix == 1)
			ret = ft_strdup("0");
		else
			ret = ft_strnew(0);
	}
	else
		ret = ft_lltoa_base(i, 8, 0);
	handle_precision(&ret, arg_info);
	handle_padding(&ret, arg_info);
	return (ret);
}

char					*p_arg(va_list arg, t_arg_info *arg_info)
{
	char				*ret;
	unsigned long long	n;

	n = (unsigned long)va_arg(arg, char *);
	ret = ft_llutoa_base(n, 16, 0);
	ret = ft_strjoin_free("0x", ret);
	handle_padding(&ret, arg_info);
	return (ret);
}

char					*c_arg(va_list arg, t_arg_info *arg_info)
{
	char				*ret;

	ret = ft_strnew(1);
	*ret = va_arg(arg, int);
	handle_padding(&ret, arg_info);
	return (ret);
}

char					*percent_arg(va_list arg, t_arg_info *arg_info)
{
	char				*ret;

	if (!(ret = ft_strnew(1)))
		return (NULL);
	ret[0] = '%';
	handle_padding(&ret, arg_info);
	return (ret);
}

/*
**	I know that this works, I just don't exactly know what I need to
**	use it for yet. _Generic() is pretty sweet
*/

/*
** char					*get_type(void *arg)
** {
** 	return (_Generic(arg[0], char: "char", int: "int", default: "other"));
** }
*/
