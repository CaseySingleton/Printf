/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:23:27 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/25 14:23:28 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			handle_str(t_pf *pf)
{
	char		*temp;
	char		*ret;

	temp = va_arg(pf->arg, char *);
	if (temp == NULL)
		ret = ft_strdup("(null)");
	else if (pf->precision > 0)
		ret = ft_strndup(temp, pf->precision);
	else
		ret = ft_strdup(temp);
	if (pf->flags & F_PAD_ZEROS)
		BIT_OFF(pf->flags, F_PAD_ZEROS);
	handle_padding(&ret, pf);
	write_to_buffer(pf, ret, ft_strlen(ret));
	free(ret);
}

void					handle_char(t_pf *pf)
{
	char				c;
	char				*ret;

	ret = NULL;
	c = ((char)va_arg(pf->arg, int));
	if (c == 0)
	{
		if (pf->padding > 0)
		{
			ret = ft_strnew(pf->padding - 1);
			ft_memset(ret, ' ', pf->padding - 1);
		}
		else
			ret = ft_strnew(0);
		write_to_buffer(pf, ret, ft_strlen(ret) + 1);
	}
	else
	{
		ret = ft_strnew(1);
		ret[0] = c;
		handle_padding(&ret, pf);
		write_to_buffer(pf, ret, ft_strlen(ret));
	}
	if (ret != NULL)
		free(ret);
}

void					handle_percent(t_pf *pf)
{
	char				*ret;

	if (!(ret = ft_strnew(1)))
		return ;
	ret[0] = '%';
	handle_padding(&ret, pf);
	write_to_buffer(pf, ret, ft_strlen(ret));
	free(ret);
}

void					handle_ascii(t_pf *pf)
{
	if (pf->specifier == 's')
		handle_str(pf);
	else if (pf->specifier == 'S')
		handle_wide_str(pf);
	else if (pf->specifier == 'c')
		handle_char(pf);
	else if (pf->specifier == 'C')
		handle_wide_char(pf);
	else if (pf->specifier == '%')
		handle_percent(pf);
	else
		return ;
}
