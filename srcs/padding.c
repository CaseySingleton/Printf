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

static int		ft_abs(int value)
{
	if (value < 0)
		value *= -1;
	return (value);
}

void			add_padding(char **str, char *arg, int padding)
{
	char		*spaces;
	char		*temp;
	int			arg_len;

	arg_len = ft_strlen(arg);
	if (padding == 0 || arg_len >= padding)
		return ;
	spaces = ft_strnew(padding - arg_len);
	ft_memset(spaces, ' ', padding - arg_len);
	temp = ft_strjoin(*str, spaces);
	free(*str);
	*str = ft_strdup(temp);
	free(temp);
	free(spaces);
}
