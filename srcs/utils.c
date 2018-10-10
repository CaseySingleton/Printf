/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:54:31 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/06 16:54:31 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			check_pos_flag(char *str, t_arg_info *arg_info, int i)
{
	int			j;

	j = i - 1;
	while (str[++j] != '\0')
		if (str[j] == '+')
			arg_info->pos_flag = 1;
}

int				specifier_check(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
		|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X'
		|| c == 'c' || c == 'C' || c == '%')
		return (1);
	return (0);
}

int				check_only_spaces(char *str, t_arg_info *arg_info, int i)
{
	int			j;

	j = i;
	while (str[j] == ' ' && specifier_check(str[j]) != 1 && str[j] != '\0')
	{
		arg_info->count_spaces++;
		j++;
	}
	// ft_putstr("check_only_spaces() str[");
	// ft_putnbr(j);
	// ft_putstr("]: ");
	// ft_putchar(str[j]);
	// ft_putchar('\n');
	if (specifier_check(str[j]) == 1)
		return (j);
	arg_info->count_spaces = 0;
	return (i);
}
/*
char			*check_max_values()
{

}
*/