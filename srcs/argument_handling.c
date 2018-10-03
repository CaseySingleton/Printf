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

static void				s_precision(char **str, t_arg_info *arg_info)
{
	char				*temp;

	temp = NULL;
	if (arg_info->precision <= 0)
		*str = ft_strjoin_free_s1(*str, arg_info->arg);
	else
	{
		temp = ft_strndup(arg_info->arg, arg_info->precision);
		*str = ft_strjoin_free_s1(*str, temp);
	}
}

static void				d_precision(char **str, t_arg_info *arg_info)
{
	char				*temp;
	int					difference;

	temp = NULL;
	difference = arg_info->precision - (int)ft_strlen(arg_info->arg);
	if (difference > 0)
	{
		temp = ft_strnew(difference);
		ft_memset(temp, '0', difference);
		*str = ft_strjoin_free(temp, *str);
	}
	else
		s_precision(str, arg_info);
}

void					insert_arg(char **str, t_arg_info *arg_info)
{
	if (arg_info->padding > 0)
		add_padding(str, arg_info);
	*str = ft_strjoin_free_s1(*str, arg_info->arg);
	if (arg_info->padding < 0)
		add_padding(str, arg_info);
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
	return (ret);
}

char					*d_arg(va_list arg, t_arg_info *arg_info)
{
	char				*ret;
	char				*temp;
	int					difference;
	int					i; 

	ret = NULL;
	temp = NULL;
	i = va_arg(arg, int);
	ret = ft_itoa(i);
	difference = arg_info->precision - (int)ft_strlen(ret);
	if (difference > 0)
	{
		temp = ft_strnew(difference);
		ft_memset(temp, '0', difference);
		ret = ft_strjoin_free(temp, ret);
	}
	return (ret);
}

char					*u_arg(va_list arg, t_arg_info *arg_info)
{
	char 				*ret;

	ret = ft_llutoa_base(va_arg(arg, unsigned long long), 10, (arg_info->specifier == 'U' ? 1 : 0));
	return (ret);
}

char					*x_arg(va_list arg, t_arg_info *arg_info)
{
	char 				*ret;
	if (arg_info->flag == ('l') % NUM_FLAGS)
		ret = ft_llutoa_base(va_arg(arg, unsigned long), 16, (arg_info->specifier == 'X' ? 1 : 0));
	else if (arg_info->flag == ('l' + 31) % NUM_FLAGS)
		ret = ft_llutoa_base(va_arg(arg, unsigned long long), 16, (arg_info->specifier == 'X' ? 1 : 0));
	else
		ret = ft_llutoa_base(va_arg(arg, unsigned int), 16, (arg_info->specifier == 'X' ? 1 : 0));
	return (ret);
}

char					*o_arg(va_list arg, t_arg_info *arg_info)
{
	char				*ret;
	
	ret = ft_lltoa_base(va_arg(arg, long long), 8, 0);
	return (ret);
}

char					*p_arg(va_list arg, t_arg_info *arg_info)
{
	char				*ret;
	unsigned long long	n;

	n = (unsigned long)va_arg(arg, char *);
	ret = ft_llutoa_base(n, 16, 0);
	return (ret);
}

char					*percent_arg(va_list arg, t_arg_info *arg_info)
{
	char				*ret;

	if (!(ret = ft_strnew(1)))
		return (NULL);
	ret[0] = '%';
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
