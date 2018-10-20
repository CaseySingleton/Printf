/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_arg_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:05:29 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/19 19:05:30 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*handle_short(va_list arg)
{
	char			*ret;
	int				i;

	ret = NULL;
	i = (short)va_arg(arg, int);
	ret = ft_lltoa_base(i, 10, 0);
	return (ret);
}

char				*handle_char(va_list arg)
{
	char			*ret;
	int				i;

	ret = NULL;
	i = (char)va_arg(arg, int);
	ret = ft_lltoa_base(i, 10, 0);
	return (ret);
}

char				*handle_int(va_list arg)
{
	char			*ret;
	int				i;

	ret = NULL;
	i = va_arg(arg, int);
	ret = ft_lltoa_base(i, 10, 0);
	return (ret);
}

char				*handle_long(va_list arg)
{
	char			*ret;
	long			i;

	ret = NULL;
	i = va_arg(arg, long);
	ret = ft_lltoa_base(i, 10, 0);
	return (ret);
}

char				*handle_long_long(va_list arg)
{
	char			*ret;
	long long		i;

	ret = NULL;
	i = va_arg(arg, long long);
	ret = ft_lltoa_base(i, 10, 0);
	return (ret);
}
