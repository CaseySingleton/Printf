/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:26:17 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/17 16:26:19 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static int		count_args(char *str)
{
	int			args;
	int			i;

	args = 0;
	i = -1;
	while (str[++i])
		if (str[i] == '%')
			args++;
	return (args);
}

int				handle_arg(char *master, char **str, va_list ap,
				char *(**f)(va_list, t_arg_info *arg_info))
{
	int			i;
	char		*append;
	t_arg_info	*arg_info;

	arg_info_init(&arg_info);
	i = get_info(master, arg_info);
	if (arg_info->specifier == 'o')
		append = f[6](ap, arg_info);
	else if (arg_info->specifier == 'C')
		append = f['c' % NUM_SPECIFIERS](ap, arg_info);
	else if (arg_info->specifier == 'U')
		append = f['u' % NUM_SPECIFIERS](ap, arg_info);
	else if (arg_info->specifier == '%')
		append = percent_arg(ap, arg_info);
	else
		append = f[arg_info->hash_key](ap, arg_info);
	*str = ft_strjoin_free(*str, append);
	free(arg_info);
	return (i);
}

void			hash_init(char *(**f)(va_list, t_arg_info *))
{
	f[6] = &o_arg;
	f[10] = NULL;
	f['s' % NUM_SPECIFIERS] = &s_arg;
	f['S' % NUM_SPECIFIERS] = &s_arg;
	f['c' % NUM_SPECIFIERS] = &c_arg;
	f['d' % NUM_SPECIFIERS] = &d_arg;
	f['D' % NUM_SPECIFIERS] = &d_arg;
	f['i' % NUM_SPECIFIERS] = &d_arg;
	f['p' % NUM_SPECIFIERS] = &p_arg;
	f['u' % NUM_SPECIFIERS] = &u_arg;
	f['x' % NUM_SPECIFIERS] = &x_arg;
	f['X' % NUM_SPECIFIERS] = &x_arg;
}

void			handle_all_args(char *master, char **str, va_list ap)
{
	char		*temp;
	int			i;
	char		*(*function_hash[NUM_SPECIFIERS])(va_list, t_arg_info *);

	hash_init(function_hash);
	temp = NULL;
	i = 0;
	while (master[i] != '\0')
	{
		i += ft_copy_until(&temp, master + i, '%');
		if (i > 0)
			*str = ft_strjoin_free(*str, temp);
		if (master[i] == '\0')
			break ;
		i += handle_arg(master + i, str, ap, function_hash);
	}
	if (master[i] != '\0')
		*str = ft_strjoin_free_s1(*str, master + i);
}

/*
**	%[char flags][num width][num .precision][num length] char specifier
*/

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*master;
	char		*str;
	int			ret;

	va_start(ap, format);
	master = ft_strdup(format);
	str = ft_strnew(0);
	handle_all_args(master, &str, ap);
	ft_putstr(str);
	ret = ft_strlen(str);
	free(master);
	free(str);
	return (ret);
}

/*
**	Start by creating a function that iterates through a string.
**	  if a '%' is found
**		do something about it
*/
