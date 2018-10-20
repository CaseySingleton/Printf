/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_arg_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 20:07:46 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/19 20:07:47 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*handle_ushort(va_list arg)
{
	char				*ret;
	unsigned int		i;

	ret = NULL;
	i = (unsigned short)va_arg(arg, unsigned int);
	ret = ft_llutoa_base(i, 10, 0);
	return (ret);
}

char					*handle_ulong(va_list arg)
{
	char				*ret;
	unsigned long		i;

	ret = NULL;
	i = va_arg(arg, unsigned long);
	ret = ft_llutoa_base(i, 10, 0);
	return (ret);
}

char					*handle_ulonglong(va_list arg)
{
	char				*ret;
	unsigned long long	i;

	ret = NULL;
	i = va_arg(arg, unsigned long long);
	ret = ft_llutoa_base(i, 10, 0);
	return (ret);
}

char					*handle_uintmax(va_list arg)
{
	char				*ret;
	uintmax_t			i;

	ret = NULL;
	i = va_arg(arg, uintmax_t);
	ret = ft_llutoa_base(i, 10, 0);
	return (ret);
}

char					*handle_uint(va_list arg)
{
	char				*ret;
	unsigned int		i;

	ret = NULL;
	i = va_arg(arg, unsigned int);
	ret = ft_llutoa_base(i, 10, 0);
	return (ret);
}
