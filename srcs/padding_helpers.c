/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:42:32 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/19 19:42:32 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			get_prefix(t_pf *pf)
{
	if (signed_specifier_check(pf->specifier))
	{
		if (pf->flags & F_MINUS)
			write_to_buffer(pf, "-", 1);
		else if (pf->flags & F_PLUS)
			write_to_buffer(pf, "+", 1);
	}
	else if (pf->flags & F_PREFIX)
	{
		if (pf->specifier == 'x' || pf->specifier == 'p')
			write_to_buffer(pf, "0x", 2);
		else if (pf->specifier == 'X')
			write_to_buffer(pf, "0X", 2);
		else if (pf->specifier == 'o')
			write_to_buffer(pf, "0", 1);
	}
}

char			*get_spaces(t_pf *pf)
{
	char		*spaces;

	spaces = NULL;
	if (pf->count_spaces != 0 && (pf->flags & F_MINUS) != 1)
	{
		if ((pf->flags & F_MINUS) || (pf->flags & F_PLUS))
			pf->count_spaces--;
		if (!(spaces = ft_strnew(pf->count_spaces)))
			return (NULL);
		ft_memset(spaces, ' ', pf->count_spaces);
	}
	return (spaces);
}
