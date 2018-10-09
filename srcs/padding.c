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
**	if pad_zeros == 1 add 0x to start of fill
**	if pad_zeros == 0 add 0x to start of arg_info->arg
*/

void			add_spaces(char **str, t_arg_info *arg_info)
{
	char		*spaces;

	if (arg_info->count_spaces != 0)
	{
		if (!(spaces = ft_strnew(arg_info->count_spaces)))
			return ;
		ft_memset(spaces, ' ', arg_info->count_spaces);
		*str = ft_strjoin_free_s2(spaces, *str);
	}
}

 /*
 **	add padding should decide to add to the front or end of a string
 */

char			*add_padding(char *str, t_arg_info *arg_info)
{
	char		*fill;
	int			padding;
	int			arg_len;

	padding = arg_info->padding;
	arg_len = ft_strlen(str);
	if (padding <= 0 || arg_len >= padding ||
	(!(fill = ft_strnew(padding - arg_len))))
		return (NULL);
	if (arg_info->pad_zeros == 1 && arg_info->rev_padding != 1)
		ft_memset(fill, '0', padding - arg_len);
	else
		ft_memset(fill, ' ', padding - arg_len);
	return (fill);
}

void			handle_padding(char **str, t_arg_info *arg_info)
{
	char		*fill;

	fill = add_padding(*str, arg_info);
	if (fill != NULL && arg_info->rev_padding == 0)
		*str = ft_strjoin_free(fill, *str);
	else if (fill != NULL && arg_info->rev_padding == 1)
		*str = ft_strjoin_free(*str, fill);
}
