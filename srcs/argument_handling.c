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

char					*percent_arg(va_list arg, t_arg_info *arg_info)
{
	char				*ret;

	if (!(ret = ft_strnew(1)))
		return (NULL);
	ret[0] = '%';
	handle_padding(&ret, arg_info);
	return (ret);
}
