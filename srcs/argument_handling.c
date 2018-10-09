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

void					handle_precision(char **str, t_arg_info *arg_info)
{
	int					len;
	char				*temp;

	// printf("argument_handling.c handle_precision() arg_info->precision: %d\n", arg_info->precision);
	len = arg_info->precision - ft_strlen(*str);
	temp = NULL;
	if (len > 0 && arg_info->precision != 0)
	{
		if (!(temp = ft_strnew(len)))
			return ;
		ft_memset(temp, '0', len);
		*str = ft_strjoin_free(temp, *str);
	}
}

void					insert_arg(char **str, t_arg_info *arg_info)
{
	// handle_padding(str, arg_info);
	*str = ft_strjoin_free_s1(*str, arg_info->arg);
}

char					*s_arg(va_list arg, t_arg_info *arg_info)
{
	char				*temp;
	char				*ret;

	temp = va_arg(arg, char *);
	if (temp == NULL)
		ret = ft_strdup("(null)");
	else if (arg_info->precision > 0)
		ret = ft_strndup(temp, arg_info->precision);
	else
		ret = ft_strdup(temp);
	handle_padding(&ret, arg_info);
	return (ret);
}

/*
**	I think u_arg() works about the same as x_arg()
*/

char					*u_arg(va_list arg, t_arg_info *arg_info)
{
	char 				*ret;
	uintmax_t			i;
	if (arg_info->flag == 'h')
		i = (unsigned short)va_arg(arg, unsigned int);
	else if (arg_info->flag == 'l')
		i = (unsigned long)va_arg(arg, unsigned long);
	else if (arg_info->flag == ('l' + 'l'))
		i = (unsigned long long)va_arg(arg, unsigned long long);
	else if (arg_info->flag == 'j')
		i = va_arg(arg, uintmax_t);
	else
		i = (unsigned int)va_arg(arg, unsigned long long);
	ret = ft_llutoa_base(i, 10, (arg_info->specifier == 'U' ? 1 : 0));
	handle_padding(&ret, arg_info);
	return (ret);
}

char					*o_arg(va_list arg, t_arg_info *arg_info)
{
	char				*ret;
	long long			i;
	
	// print_arg_info(arg_info);
	i = va_arg(arg, long long);
	if (arg_info->precision == 0)
	{
		if (arg_info->specifier_mod == '#')
			ret = ft_strdup("0");
		else
			ret = ft_strnew(0);
	}
	else
	{
		ret = ft_lltoa_base(i, 8, 0);
		if (arg_info->specifier_mod == '#')
			ret = ft_strjoin_free_s2("0", ret);
		handle_precision(&ret, arg_info);
	}
	handle_padding(&ret, arg_info);
	return (ret);
}

char					*p_arg(va_list arg, t_arg_info *arg_info)
{
	char				*ret;
	unsigned long long	n;

	n = (unsigned long)va_arg(arg, char *);
	ret = ft_llutoa_base(n, 16, 0);
	handle_padding(&ret, arg_info);
	return (ret);
}

char					*c_arg(va_list arg, t_arg_info *arg_info)
{
	char				*ret;

	ret = ft_strnew(1);
	*ret = va_arg(arg, int);
	if (*ret == '\0' || arg_info->precision != -1)
	{
		free(ret);
		ret = ft_strdup("\\0");
	}
	handle_padding(&ret, arg_info);
	return (ret);
}

char					*percent_arg(va_list arg, t_arg_info *arg_info)
{
	char				*ret;

	if (!(ret = ft_strnew(1)))
		return (NULL);
	ret[0] = '%';
	handle_padding(&ret, arg_info);
	return (ret);
}

/*
**	I know that this works, I just don't exactly know what I need to
**	use it for yet. _Generic() is pretty sweet
*/

/* char					*get_type(void *arg)
** {
** 	return (_Generic(arg[0], char: "char", int: "int", default: "other"));
** }
*/
