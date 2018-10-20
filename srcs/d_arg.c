/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:24:44 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/06 15:24:44 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	arg -> precision -> sign (+ or -) -> padding
**
**	if there's precision pad the left of the argument with
**	num_precision - numlen(arg) '0' characters
**	  if num is negative or positive is explicit append to the
**	  beginning of the argument
*/

static void			append_sign(char **sign, char **fill, char **precision,
					char **str)
{
	if (*fill != NULL && *fill[0] == '0' && *sign != NULL)
		*fill = ft_strjoin(*sign, *fill);
	else if (*precision != NULL && *sign != NULL)
		*precision = ft_strjoin_free(*sign, *precision);
	else if (*precision == NULL && *sign != NULL)
		*str = ft_strjoin_free(*sign, *str);
	else if (*fill == NULL && *precision == NULL && *sign != NULL)
		*str = ft_strjoin_free(*sign, *str);
}

static void			append_precision(char **str, char **precision)
{
	if (*precision != NULL)
		*str = ft_strjoin_free(*precision, *str);
}

static void			append_fill(char **str, char **fill, t_arg_info *arg_info)
{
	if (*fill != NULL)
	{
		if (arg_info->padding->rev == 1)
			*str = ft_strjoin_free(*str, *fill);
		else
			*str = ft_strjoin_free(*fill, *str);
	}
}

static void			d_arg_combine_all(char **str, t_arg_info *arg_info)
{
	char			*sign;
	char			*precision;
	char			*fill;

	sign = d_arg_get_sign(arg_info);
	precision = d_arg_get_precision(*str, arg_info);
	fill = d_arg_get_fill(*str, arg_info);
	append_sign(&sign, &fill, &precision, str);
	append_precision(str, &precision);
	append_fill(str, &fill, arg_info);
}

char				*d_arg(va_list arg, t_arg_info *arg_info)
{
	char			*ret;
	char			*temp;

	ret = d_arg_get_datatype_string(arg, arg_info);
	if (ft_strcmp(ret, "0") == 0 && arg_info->precision->total == 0)
	{
		free(ret);
		ret = ft_strnew(0);
	}
	else if (ret[0] == '-')
	{
		arg_info->padding->neg = 1;
		temp = ft_strdup(ret + 1);
		free(ret);
		ret = temp;
	}
	d_arg_combine_all(&ret, arg_info);
	return (ret);
}
