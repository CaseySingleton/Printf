/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_arg_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:06:51 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/19 19:06:51 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*d_arg_get_sign(t_arg_info *arg_info)
{
	char		*sign;

	sign = NULL;
	if (arg_info->padding->neg == 1)
		sign = ft_strdup("-");
	else if (arg_info->padding->pos == 1)
		sign = ft_strdup("+");
	if (arg_info->padding->neg == 1 || arg_info->padding->pos == 1)
		arg_info->padding->total -= 1;
	return (sign);
}

char			*d_arg_get_fill(char *str, t_arg_info *arg_info)
{
	char		*fill;
	int			usable_padding;

	fill = NULL;
	if ((fill = get_spaces(arg_info)) != NULL)
		return (fill);
	usable_padding = ft_strlen(str);
	if (arg_info->precision->total > usable_padding)
		usable_padding = arg_info->precision->total;
	if (arg_info->padding->zero == 1 && arg_info->padding->rev == 1)
		arg_info->padding->zero = 0;
	if (arg_info->padding->total > 0)
	{
		fill = ft_strnew(arg_info->padding->total);
		if (arg_info->padding->zero == 1 && arg_info->precision->total <= 0)
			ft_memset(fill, '0', arg_info->padding->total - usable_padding);
		else
			ft_memset(fill, ' ', arg_info->padding->total - usable_padding);
	}
	return (fill);
}

char			*d_arg_get_precision(char *str, t_arg_info *arg_info)
{
	char		*precision;
	int			usable_precision;

	precision = NULL;
	usable_precision = arg_info->precision->total - ft_strlen(str);
	if (usable_precision > 0)
	{
		if (arg_info->padding->rev != 1)
			if (usable_precision >= arg_info->padding->total)
				arg_info->padding->total = 0;
		precision = ft_strnew(usable_precision);
		ft_memset(precision, '0', usable_precision);
	}
	return (precision);
}

char			*d_arg_get_datatype_string(va_list arg, t_arg_info *arg_info)
{
	intmax_t	i;
	char		*ret;

	if (arg_info->flag == 'h')
		i = ((intmax_t)((short)va_arg(arg, int)));
	else if (arg_info->flag == ('h' + 'h'))
		i = ((intmax_t)((char)va_arg(arg, int)));
	else if (arg_info->flag == 'l')
		i = ((intmax_t)va_arg(arg, long));
	else if (arg_info->flag == ('l' + 'l'))
		i = ((intmax_t)va_arg(arg, long long));
	else if (arg_info->flag == 'z')
		i = ((intmax_t)va_arg(arg, size_t));
	else if (arg_info->flag == 'j')
		i = va_arg(arg, intmax_t);
	else
		i = ((intmax_t)va_arg(arg, int));
	ret = ft_lltoa_base(i, 10, 0);
	return (ret);
}
