/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:26:17 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/17 16:26:19 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		dispatch(t_pf *pf)
{
	pf->flags = 0;
	pf->precision = -1;
	pf->master += get_info(pf);
	if (ascii_specifier_check(pf->specifier) == 1)
		handle_ascii(pf);
	else if (signed_specifier_check(pf->specifier) == 1)
		handle_signed(pf);
	else if (unsigned_specifier_check(pf->specifier) == 1)
		handle_unsigned(pf);
	else
		exit(-1);
}

static void		handle_all_args(t_pf *pf)
{
	while (*pf->master != '\0')
	{
		if (*pf->master == '%')
			dispatch(pf);
		if (*pf->master != '\0' && *pf->master != '%')
		{
			write_to_buffer(pf, pf->master, 1);
			(pf->master)++;
		}
	}
	print_buffer(pf, pf->total_bytes);
}

/*
**	%[char flags][num width][num .precision][num length] char specifier
*/

int				ft_printf(const char *format, ...)
{
	t_pf		pf;

	ft_bzero(&pf, sizeof(pf));
	pf.master = (char *)format;
	va_start(pf.arg, format);
	handle_all_args(&pf);
	return (pf.total_bytes);
}
