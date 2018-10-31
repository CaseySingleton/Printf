/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 16:00:22 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/21 16:00:23 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Padding will only show if the number to be padded is greater than the
**	length of the argument
**
**	ex:
**	  printf("|%3s|\n", "Hello 42!")   -> |Hello 42!|
**	  printf("|%-3s|\n", "Hello 42!")  -> |Hello 42!|
**	  printf("|%15s|\n", "Hello 42!")  -> |      Hello 42!|
**	  printf("|%-15s|\n", "Hello 42!") -> |Hello 42!      |
**
**	A positive value will place spaces to the right
**	A negative value will place spaces to the left
*/

/*
**	if pad_zeros == 1 append 0x to start of fill
**	if pad_zeros == 0 append 0x to start of pf->arg
*/

static char		*only_fill(char **str, char *fill, t_pf *pf)
{
	char		*ret;

	ret = NULL;
	if ((pf->flags & F_REV) && !(pf->flags & F_PAD_ZEROS))
		ret = ft_strjoin(*str, fill);
	else if ((pf->flags & F_REV) && (pf->flags & F_PAD_ZEROS) &&
	fill[0] == ' ')
		ret = ft_strjoin(*str, fill);
	else if ((pf->flags & F_REV) != 1)
		ret = ft_strjoin(fill, *str);
	return (ret);
}

static char		*fill_and_prefix(char **str, char *fill, char *prefix,
				t_pf *pf)
{
	char		*ret;

	ret = NULL;
	if ((pf->flags & F_PAD_ZEROS) && (pf->flags & F_REV) &&
	fill[0] == ' ')
	{
		ret = ft_strjoin_free(prefix, *str);
		ret = ft_strjoin_free(ret, fill);
	}
	else if (pf->flags & F_PAD_ZEROS)
	{
		ret = ft_strjoin_free(prefix, fill);
		ret = ft_strjoin_free(ret, *str);
	}
	else if (!(pf->flags & F_PAD_ZEROS) && (pf->flags & F_REV))
	{
		ret = ft_strjoin_free(prefix, *str);
		ret = ft_strjoin_free(ret, fill);
	}
	else if (!(pf->flags & F_PAD_ZEROS))
	{
		ret = ft_strjoin_free(prefix, *str);
		ret = ft_strjoin_free(fill, ret);
	}
	return (ret);
}

static char		*combine_padding_and_prefix(char **str, char *fill,
				char *prefix, t_pf *pf)
{
	char		*ret;

	ret = NULL;
	if (fill == NULL && prefix != NULL)
		ret = ft_strjoin_free(prefix, *str);
	else if (fill != NULL && prefix == NULL)
		ret = only_fill(str, fill, pf);
	else if (fill != NULL && prefix != NULL)
		ret = fill_and_prefix(str, fill, prefix, pf);
	else
	{
		ret = ft_strdup(*str);
		free(*str);
	}
	return (ret);
}

void			handle_padding(char **str, t_pf *pf)
{
	// printf("padding.c handle_padding() top\n");
	char		*prefix;
	char		*fill;

	prefix = NULL;
	fill = NULL;
	prefix = get_prefix(*str, pf);
	fill = padding(*str, pf);
	*str = combine_padding_and_prefix(str, fill, prefix, pf);
	// printf("padding.c handle_padding prefix: %s\n", prefix);
	// printf("padding.c handle_padding fill: %s\n", fill);
	// printf("padding.c handle_padding str: %s\n", *str);
	// printf("padding.c handle_padding() end\n");
}
