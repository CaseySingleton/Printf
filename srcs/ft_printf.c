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

static int			count_args(char *str)
{
	int				args;
	int				i;

	args = 0;
	i = -1;
	while (str[++i])
		if (str[i] == '%')
			args++;
	return (args);
}

/*
typedef struct		s_print
{
	void			*arg;
	int				specifier;
	int				flag;
	int				width;
	int				precision;
	int				length;
}					t_print;
*/



int					handle_arg(char *master, char **str, va_list ap, char *(**f)(va_list, t_arg_info *arg_info))
{
	int				i;
	t_arg_info		*arg_info;

	arg_info = arg_info_init();
	i = get_arg_info(master, arg_info);
	if (arg_info->specifier == 'o')
		arg_info->arg = f[6](ap, arg_info);
	else if (arg_info->specifier == '%')
		arg_info->arg = percent_arg(ap, arg_info);
	else
		arg_info->arg = f[arg_info->hash_key](ap, arg_info);
	*str = ft_strjoin_free(*str, arg_info->arg);
	free(arg_info);
	return (i);
}

// s  S  p  d  D  i  o  O  u  U  x  X  c  C  %

// 10 8  7  10 8  0  6  4  12 10 0  13 9  7  7

// 0 1(2) 2 3 4 5 # 7 8 9 # 11 13(2) No 10 or 6
void				hash_init(char *(**f)(va_list, t_arg_info *))
{
	f[6] = &o_arg; // set equal to function that handles 'o' specifier
	f[10] = NULL; // set equal to the function that handles 'c' specifier
	f['s' % NUM_SPECIFIERS] = &s_arg; // 3
	f['S' % NUM_SPECIFIERS] = &s_arg; // 13
	f['c' % NUM_SPECIFIERS] = &c_arg; // 1
	f['d' % NUM_SPECIFIERS] = &d_arg; // 2
	f['D' % NUM_SPECIFIERS] = &d_arg; // 12
	f['i' % NUM_SPECIFIERS] = &d_arg; // 7
	f['p' % NUM_SPECIFIERS] = &p_arg; // 0
	f['u' % NUM_SPECIFIERS] = &u_arg; // 5
	f['x' % NUM_SPECIFIERS] = &x_arg; // 8
	f['X' % NUM_SPECIFIERS] = &x_arg; // 4
}

void				handle_all_args(char *master, char **str, va_list ap)
{
	char			*(*function_hash[NUM_SPECIFIERS])(va_list arg, t_arg_info *arg_info);
	char			*temp;
	int				i;

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
**	printf format: %[char flags][num width][num .precision][num length] char specifier
*/

int					ft_printf(const char *format, ...)
{
	va_list			ap;
	char			*master;
	char			*str;
	int				ret;

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
