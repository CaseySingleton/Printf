/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:26:03 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/19 18:26:04 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*u_arg(va_list arg, t_arg_info *arg_info)
{
	uintmax_t	i;
	char		*ret;

	if (arg_info->flag == 'h' && arg_info->specifier != 'U')
		i = ((intmax_t)((unsigned short)va_arg(arg, unsigned int)));
	else if (arg_info->flag == 'l' || arg_info->specifier == 'U')
		i = ((intmax_t)va_arg(arg, unsigned long));
	else if (arg_info->flag == ('l' + 'l'))
		i = ((intmax_t)va_arg(arg, unsigned long long));
	else if (arg_info->flag == 'j')
		i = va_arg(arg, uintmax_t);
	else
		i = (intmax_t)va_arg(arg, unsigned int);
	ret = ft_llutoa_base(i, 10, 0);
	handle_precision(&ret, arg_info);
	handle_padding(&ret, arg_info);
	return (ret);
}
