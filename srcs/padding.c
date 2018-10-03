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
**	  printf("|%3s|\n", "Hello 42!") -> |Hello 42!|
**	  printf("|%-3s|\n", "Hello 42!") -> |Hello 42!|
**	  printf("|%15s|\n", "Hello 42!") -> |      Hello 42!|
**	  printf("|%-15s|\n", "Hello 42!") -> |Hello 42!      |
**
**	A positive value will place spaces to the right
**	A negative value will place spaces to the left
*/

void			add_padding(char **str, t_arg_info *arg_info)
{
	char		*spaces;
	char		*temp;
	int			padding;
	int			arg_len;

	if (arg_info->padding < 0)
		padding = -1 * arg_info->padding;
	else
		padding = arg_info->padding;
	arg_len = ft_strlen(arg_info->arg);
	if (padding == 0 || arg_len >= padding)
		return ;
	spaces = ft_strnew(padding - arg_len);
	if (arg_info->pad_zeros == 1)
		ft_memset(spaces, '0', padding - arg_len);
	else
		ft_memset(spaces, ' ', padding - arg_len);
	*str = ft_strjoin_free(*str, spaces);
}
