/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:06:51 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/19 19:06:51 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*get_signed_data_type(t_pf *pf, int base, int upper)
{
	char		*ret;
	intmax_t	i;

	if (pf->flags & F_H)
		i = ((intmax_t)((short)va_arg(pf->arg, int)));
	else if (pf->flags & F_HH)
		i = ((intmax_t)((char)va_arg(pf->arg, int)));
	else if (pf->flags & F_L || pf->specifier == 'D')
		i = ((intmax_t)va_arg(pf->arg, long));
	else if (pf->flags & F_LL)
		i = ((intmax_t)va_arg(pf->arg, long long));
	else if (pf->flags & F_Z)
		i = ((intmax_t)va_arg(pf->arg, size_t));
	else if (pf->flags & F_J)
		i = va_arg(pf->arg, intmax_t);
	else
		i = ((intmax_t)va_arg(pf->arg, int));
	ret = ft_lltoa_base(i, base, upper);
	return (ret);
}

char			*signed_get_sign(t_pf *pf)
{
	char		*sign;

	sign = NULL;
	if (pf->flags & F_MINUS)
		sign = ft_strdup("-");
	else if (pf->flags & F_PLUS)
		sign = ft_strdup("+");
	if ((pf->flags & F_MINUS) || (pf->flags & F_PLUS))
		pf->padding -= 1;
	return (sign);
}

char			*signed_get_fill(char *str, t_pf *pf)
{
	char		*fill;
	int			usable_padding;

	fill = NULL;
	if ((fill = get_spaces(pf)) != NULL)
		return (fill);
	usable_padding = ft_strlen(str);
	if (pf->precision > usable_padding)
		usable_padding = pf->precision;
	if ((pf->flags & F_PAD_ZEROS) && (pf->flags & F_REV))
		BIT_OFF(pf->flags, F_PAD_ZEROS);
	if (pf->padding > 0)
	{
		fill = ft_strnew(pf->padding);
		if ((pf->flags & F_PAD_ZEROS) && pf->precision <= 0)
			ft_memset(fill, '0', pf->padding - usable_padding);
		else
			ft_memset(fill, ' ', pf->padding - usable_padding);
	}
	return (fill);
}

char			*signed_get_precision(char *str, t_pf *pf)
{
	char		*precision;
	int			usable_precision;

	precision = NULL;
	usable_precision = pf->precision - ft_strlen(str);
	if (usable_precision > 0)
	{
		if (!(pf->flags & F_REV))
			if (usable_precision >= pf->padding)
				pf->padding = 0;
		precision = ft_strnew(usable_precision);
		ft_memset(precision, '0', usable_precision);
	}
	return (precision);
}
