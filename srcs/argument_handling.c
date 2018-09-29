/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 18:34:07 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/26 18:34:07 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

/*
**	Given the string to be printed and the current argument as a string,
**	this function appends the argument to the end of string
*/

// s(x) S(x) p() d(x) D(?) i(x) o(x) O(?) u() U() x() X() c() C()

void					insert_arg(char **str, char *arg, int padding)
{
	// ft_putstr(*str);
	// ft_putchar(' ');
	// ft_putstr(arg);
	// ft_putchar('\n');
	if (padding > 0)
		add_padding(str, arg, padding);
	*str = ft_strjoin_free_s1(*str, arg);
	if (padding < 0)
		add_padding(str, arg, (padding * -1));
}

char					*s_arg(va_list arg)
{
	char				*ret;

	ret = ft_strdup(va_arg(arg, char *));
	return (ret);
}

char					*d_arg(va_list arg)
{
	char				*ret;
	int					i;

	i = va_arg(arg, int);
	ret = ft_itoa(i);
	return (ret);
}

char					*u_arg(va_list arg)
{
	char 				*ret;

	ret = ft_llutoa_base(va_arg(arg, unsigned long long), 10, 0);
	return (ret);
}

char					*o_arg(va_list arg)
{
	char				*ret;
	
	ret = ft_lltoa_base(va_arg(arg, long long), 8, 0);
	return (ret);
}

char					*p_arg(va_list arg)
{
	char				*ret;
	unsigned long long	n;

	n = (unsigned long)va_arg(arg, char *);
	ret = ft_llutoa_base(n, 16, 0);
	return (ret);
}

/*
**	I know that this works, I just don't exactly know what I need to
**	use it for yet. _Generic() is pretty sweet
*/

char					*get_type(void *arg)
{
	return (_Generic(arg[0], char: "char", int: "int", default: "other"));
}
