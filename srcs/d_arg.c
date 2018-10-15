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

static char			*d_arg_get_sign(t_arg_info *arg_info)
{
	char			*sign;

	sign = NULL;
	if (arg_info->padding->neg == 1)
		sign = ft_strdup("-");
	else if (arg_info->padding->pos == 1)
		sign = ft_strdup("+");
	if (arg_info->padding->neg == 1 || arg_info->padding->pos == 1)
		arg_info->padding->total -= 1;
	return (sign);
}

static char			*d_arg_get_fill(char *str, t_arg_info *arg_info)
{
	char			*fill;
	int				usable_padding;

	fill = NULL;
	if ((fill = get_spaces(arg_info)) != NULL)
		return (fill);
	usable_padding = ft_strlen(str);
	if (arg_info->precision->total > usable_padding)
		usable_padding = arg_info->precision->total;
	if (arg_info->padding->zero == 1 && arg_info->padding->rev == 1)
		arg_info->padding->zero = 0;
	if (arg_info->padding->total > 0)
	{
		fill = ft_strnew(arg_info->padding->total);
		if (arg_info->padding->zero == 1 && arg_info->precision->total <= 0)
			ft_memset(fill, '0', arg_info->padding->total - usable_padding);
		else
			ft_memset(fill, ' ', arg_info->padding->total - usable_padding);
	}
	return (fill);
}

static char			*d_arg_get_precision(char *str, t_arg_info *arg_info)
{
	char			*precision;
	int				usable_precision;

	precision = NULL;
	usable_precision = arg_info->precision->total - ft_strlen(str);
	if (usable_precision > 0)
	{
		if (arg_info->padding->rev != 1)
			if (usable_precision >= arg_info->padding->total)
				arg_info->padding->total = 0;
		precision = ft_strnew(usable_precision);
		ft_memset(precision, '0', usable_precision);
	}
	return (precision);
}

static void			append_sign(char **sign, char **fill, char **precision, char **str)
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
	// printf("\nstr: %s\nsign: %s\nprecision: ->%s<-\nfill: ->%s<-\n\n", *str, sign, precision, fill);
	append_sign(&sign, &fill, &precision, str);
	append_precision(str, &precision);
	append_fill(str, &fill, arg_info);
	// printf("\nstr: %s\nsign: %s\nprecision: ->%s<-\nfill: ->%s<-\n\n", *str, sign, precision, fill);
}

char				*handle_short(va_list arg)
{
	char			*ret;
	int				i;

	ret = NULL;
	i = (short)va_arg(arg, int);
	ret = ft_lltoa_base(i, 10, 0);
	return (ret);
}

char				*handle_char(va_list arg)
{
	char			*ret;
	int				i;

	ret = NULL;
	i = (char)va_arg(arg, int);
	ret = ft_lltoa_base(i, 10, 0);
	return (ret);
}

char				*handle_int(va_list arg)
{
	char			*ret;
	int				i;

	ret = NULL;
	i = va_arg(arg, int);
	ret = ft_lltoa_base(i, 10, 0);
	return (ret);
}

char				*handle_long(va_list arg)
{
	char			*ret;
	long			i;

	ret = NULL;
	i = va_arg(arg, long);
	ret = ft_lltoa_base(i, 10, 0);
	return (ret);
}

char				*handle_long_long(va_list arg)
{
	char			*ret;
	long long		i;

	ret = NULL;
	i = va_arg(arg, long long);
	ret = ft_lltoa_base(i, 10, 0);
	return (ret);
}

char				*handle_ssizet(va_list arg)
{
	char			*ret;
	ssize_t			i;

	ret = NULL;
	i = va_arg(arg, ssize_t);
	if (i == -1)
		ret = ft_strdup("-1");
	else
		ret = ft_llutoa_base(i, 10, 0);
	return (ret);
}

char				*handle_intmax(va_list arg)
{
	char			*ret;
	intmax_t		i;

	ret = NULL;
	i = va_arg(arg, intmax_t);
	ret = ft_lltoa_base(i, 10, 0);
	return (ret);
}

char				*d_arg(va_list arg, t_arg_info *arg_info)
{
	char			*ret;
	char			*temp;

	if (arg_info->flag == 'h')
		ret = handle_short(arg);
	else if (arg_info->flag == ('h' + 'h'))
		ret = handle_char(arg);
	else if (arg_info->flag == 'l')
		ret = handle_long(arg);
	else if (arg_info->flag == ('l' + 'l'))
		ret = handle_long_long(arg);
	else if (arg_info->flag == 'z')
		ret = handle_ssizet(arg);
	else if (arg_info->flag == 'j')
		ret = handle_intmax(arg);
	else
		ret = handle_int(arg);
	if (ft_strcmp(ret, "0") == 0 && arg_info->precision->total == 0)
	{
		free(ret);
		ret = ft_strnew(0);
	}
	if (ret[0] == '-')
	{
		arg_info->padding->neg = 1;
		temp = ft_strdup(ret + 1);
		free(ret);
		ret = temp;
	}
	d_arg_combine_all(&ret, arg_info);
	return (ret);
}

/*
**	Should make arg_d_handle_padding() and use combine_fill_and_prefix() manually here.
**	%d is a bitch to deal with
*/
