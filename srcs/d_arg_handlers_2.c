/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_arg_handlers_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:13:02 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/19 19:13:03 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*handle_ssizet(va_list arg)
{
	char			*ret;
	ssize_t			i;

	ret = NULL;
	i = va_arg(arg, ssize_t);
	if (i == -1)
		ret = ft_strdup("-1");
	else
		ret = ft_llutoa_base(i, 10, 0);
	return (ret);
}

char				*handle_intmax(va_list arg)
{
	char			*ret;
	intmax_t		i;

	ret = NULL;
	i = va_arg(arg, intmax_t);
	ret = ft_lltoa_base(i, 10, 0);
	return (ret);
}
