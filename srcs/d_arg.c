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

static void			d_arg_add_sign(char **fill, char **str, t_arg_info *arg_info)
{
	if (arg_info->pad_zeros == 1 && arg_info->rev_padding != 1 &&
	arg_info->precision <= 0)
	{
		if (arg_info->neg_flag == 1)
			*fill = ft_strjoin_free_s2("-", *fill);
		else if (arg_info->pos_flag == 1)
			*fill = ft_strjoin_free_s2("+", *fill);
	}
	else if (arg_info->rev_padding == 1)
	{
		if (arg_info->neg_flag == 1)
			*str = ft_strjoin_free_s2("-", *str);
		else if (arg_info->pos_flag == 1)
			*str = ft_strjoin_free_s2("+", *str);
	}
	else
	{
		if (arg_info->neg_flag == 1)
			*fill = ft_strjoin_free_s1(*fill, "-");
		else if (arg_info->pos_flag == 1)
			*fill = ft_strjoin_free_s1(*fill, "+");
	}
	// ft_putstr("d_arg.c d_arg_add_sign() *fill: -->");
	// ft_putstr(*fill);
	// ft_putstr("<--\n");
}

int					d_arg_parse(char *str, t_arg_info *arg_info, int i)
{
	check_pos_flag(str, arg_info, i);
	i = check_only_spaces(str, arg_info, i);
	while (str[i] == '+' || str[i] == ' ')
		i++;
	i = get_mods(str, arg_info, i);
	while (str[i] == '+' || str[i] == ' ')
		i++;
	i = get_flags(str, arg_info, i);
	while (str[i] == '+' || str[i] == ' ')
		i++;
	i = get_padding(str, arg_info, i);
	while (str[i] == '+' || str[i] == ' ')
		i++;
	i = get_precision(str, arg_info, i);
	while (specifier_check(str[i]) != 1)
		i++;
	i++;
	return (i);
}

static char			*d_arg_get_padding(char *str, t_arg_info *arg_info)
{
	char			*fill;
	int				padding;
	int				len;

	fill = NULL;
	padding = arg_info->padding;
	len = padding - ft_strlen(str);
	if (arg_info->neg_flag == 1 || arg_info->pos_flag == 1)
		len--;
	if (arg_info->count_spaces > 0)
		len = arg_info->count_spaces;
	if (len > 0)
	{
		if (!(fill = ft_strnew(len)))
			return (NULL);
		if (arg_info->pad_zeros == 1 && arg_info->rev_padding != 1 &&
		arg_info->precision < 0)
			ft_memset(fill, '0', len);
		else
			ft_memset(fill, ' ', len);
	}
	else
		fill = ft_strnew(0);
	return (fill);
}

static void			d_arg_add_padding(char **str, t_arg_info *arg_info)
{
	char			*fill;
	int				padding;
	int				arg_len;

	// ft_putstr("d_arg_add_padding() arg_info->count_spaces: ");
	// ft_putnbr(arg_info->count_spaces);
	// ft_putchar('\n');
	fill = NULL;
	padding = arg_info->padding - arg_info->pos_flag;
	arg_len = ft_strlen(*str);
	// ft_putstr("d_arg.c d_arg_add_padding() *str: -->");
	// ft_putstr(*str);
	// ft_putstr("<--\n");
	// ft_putstr("arg_len: ");
	// ft_putnbr(arg_len);
	// ft_putchar('\n');
	if ((padding > 0 && arg_len < padding) ||
	(arg_info->count_spaces > 0 && arg_info->neg_flag != 1))
			fill = d_arg_get_padding(*str, arg_info);
	else
		fill = ft_strnew(0);
	d_arg_add_sign(&fill, str, arg_info);
	if (arg_info->rev_padding != 1)
		*str = ft_strjoin_free(fill, *str);
	else if (arg_info->rev_padding == 1)
		*str = ft_strjoin_free(*str, fill);
}

/*
**	flags for %d: h, hh, l, ll, j, z
*/

char				*d_arg(va_list arg, t_arg_info *arg_info)
{
	char			*ret;
	intmax_t		i;

	i = va_arg(arg, intmax_t);
	if (arg_info->flag == 'h')
		i = (short)i;
	else if (arg_info->flag == ('h' + 'h'))
		i = (char)i;
	else if (arg_info->flag == 'l')
		i = (long)i;
	else if (arg_info->flag == ('l' + 'l'))
		i = (long long)i;
	else if (arg_info->flag == 'z')
		i = (size_t)i;
	else
		i = (int)i;
	if (i == 0 && arg_info->precision == 0)
		ret = ft_strnew(0);
	else
		ret = ft_lltoa_base(ft_abs(i), 10, 0);
	handle_precision(&ret, arg_info);
	if (i < 0 && ret[0] != '-')
		arg_info->neg_flag = 1;
	d_arg_add_padding(&ret, arg_info);
	return (ret);
}
