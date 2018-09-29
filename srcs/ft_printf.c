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



void				handle_arg(char *master, char **str, va_list ap, char *(**f)(va_list))
{
	t_arg_info		*arg_info;

	arg_info = arg_info_init();
	get_arg_info(master, arg_info);
	// ft_putstr("arg_info->specifier: ");
	// ft_putnbr(arg_info->specifier);
	// ft_putchar('\n');
	if (arg_info->specifier == 'o')
		arg_info->arg = f[6](ap);
	else if (arg_info->specifier == 'c')
		arg_info->arg = f[10](ap);
	else
		arg_info->arg = f[arg_info->hash_key](ap);
	insert_arg(str, arg_info->arg, arg_info->padding);
	free(arg_info->arg);
	free(arg_info);
}

// s S  p d D  i o  O u U! x X c C!

// 3 13 0 2 12 7 13 9 5 1  8 4 1 11

// 0 1(2) 2 3 4 5 # 7 8 9 # 11 13(2) No 10 or 6
void				hash_init(char *(**f)(va_list))
{
	f[6] = &o_arg; // set equal to function that handles 'o' specifier
	f[10] = NULL; // set equal to the function that handles 'c' specifier
	f['s' % NUM_SPECIFIERS] = &s_arg;
	f['S' % NUM_SPECIFIERS] = &s_arg;
	f['d' % NUM_SPECIFIERS] = &d_arg;
	f['D' % NUM_SPECIFIERS] = &d_arg;
	f['i' % NUM_SPECIFIERS] = &d_arg;
	f['p' % NUM_SPECIFIERS] = &p_arg;
	f['u' % NUM_SPECIFIERS] = &u_arg;
}

void				handle_all_args(char *master, char **str, va_list ap)
{
	char			*(*function_hash[NUM_SPECIFIERS])(va_list arg);
	char			*temp;
	int				i;

	hash_init(function_hash);
	temp = NULL;
	i = 0;
	while (master[i] != '\0')
	{
		i += ft_copy_until(&temp, master + i, '%');
		*str = ft_strjoin_free(*str, temp);
		if (master[i] == '\0')
			break ;
		handle_arg(master + i, str, ap, function_hash);
		while (specifier_check(master[i]) != 1 && master[i] != '\0')
			i++;
		if (specifier_check(master[i]) == 1 && master[i] != '\0' && master[i + 1] != '\0')
			i++;
	}
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
	int				i;

	va_start(ap, format);
	master = ft_strdup(format);
	str = ft_strnew(0);
	handle_all_args(master, &str, ap);
	ft_putstr(str);
	free(master);
	free(str);
	return (0);
}

/*
**	Start by creating a function that iterates through a string.
**	  if a '%' is found
**		do something about it
*/
