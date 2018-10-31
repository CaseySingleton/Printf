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

char			*get_prefix(char *str, t_pf *pf)
{
	char		*ret;

	ret = NULL;
	if ((pf->flags & F_PREFIX) && str[0] != '0')
	{
		if (pf->specifier == 'x')
		{
			ret = ft_strdup("0x");
			pf->padding -= 2;
		}
		else if (pf->specifier == 'X')
		{
			ret = ft_strdup("0X");
			pf->padding -= 2;
		}
		else if (pf->specifier == 'o')
		{
			ret = ft_strdup("0");
			pf->padding -= 1;
		}
	}
	return (ret);
}

char			*get_spaces(t_pf *pf)
{
	char		*spaces;

	spaces = NULL;
	if (pf->count_spaces != 0 && (pf->flags & F_MINUS) != 1)
	{
		pf->count_spaces -= (((pf->flags & F_MINUS) || (pf->flags & F_PLUS)) ? 1 : 0);
		if (!(spaces = ft_strnew(pf->count_spaces)))
			return (NULL);
		ft_memset(spaces, ' ', pf->count_spaces);
	}
	return (spaces);
}

void			handle_precision(char **str, t_pf *pf)
{
	int			len;
	char		*temp;

	len = pf->precision - ft_strlen(*str);
	if ((pf->flags & F_MINUS) && len + 1 > 0)
	{
		*str[0] = '0';
		len++;
	}
	temp = NULL;
	if (len > 0 && pf->precision != 0)
	{
		if (!(temp = ft_strnew(len)))
			return ;
		ft_memset(temp, '0', len);
		if ((pf->flags & F_MINUS) == 1)
			temp[0] = '-';
		*str = ft_strjoin_free(temp, *str);
	}
}

char			*padding(char *str, t_pf *pf)
{
	char		*fill;
	int			len;

	fill = NULL;
	if (pf->count_spaces != 0 && (pf->flags & F_MINUS) != 1)
		return (get_spaces(pf));
	len = pf->padding - ft_strlen(str);
	if (len <= 0 || (!(fill = ft_strnew(len))))
		return (NULL);
	if ((pf->specifier == 'x' || pf->specifier == 'X' || pf->specifier == 'o')
		&& (pf->flags & F_REV) && (pf->flags & F_PAD_ZEROS))
		ft_memset(fill, ' ', len);
	else if (pf->flags & F_PAD_ZEROS)
		ft_memset(fill, '0', len);
	else
		ft_memset(fill, ' ', len);
	return (fill);
}
