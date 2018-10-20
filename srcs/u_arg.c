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
	char		*ret;

	ret = NULL;
	if (arg_info->flag == 'h' && arg_info->specifier != 'U')
		ret = handle_ushort(arg);
	else if (arg_info->flag == 'l' || arg_info->specifier == 'U')
		ret = handle_ulong(arg);
	else if (arg_info->flag == ('l' + 'l'))
		ret = handle_ulonglong(arg);
	else if (arg_info->flag == 'j')
		ret = handle_uintmax(arg);
	else
		ret = handle_uint(arg);
	handle_precision(&ret, arg_info);
	handle_padding(&ret, arg_info);
	return (ret);
}
