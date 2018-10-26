/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:27:25 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/29 02:38:58 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"

# define NUM_SPECIFIERS 14
# define NUM_FLAGS 6

# define BOLD "\033[1m\033[30m"
# define RESET "\033[0m"

typedef struct		s_padding
{
	int				total;
	int				prefix;
	int				zero;
	int				neg;
	int				pos;
	int				rev;
	int				spaces;
}					t_padding;

typedef struct		s_precision
{
	int				total;
}					t_precision;

typedef struct		s_arg_info
{
	int				hash_key;
	int				specifier;
	int				flag;
	t_padding		*padding;
	t_precision		*precision;
}					t_arg_info;

/*
**	ft_printf.c
*/

int					ft_printf(const char *format, ...);
void				print_arg_info(t_arg_info *arg_info);

/*
**	argument_parsing.c
*/

int					get_info(char *str, t_arg_info *arg_info);
int					get_mods(char *str, t_arg_info *arg_info, int i);
int					get_flags(char *str, t_arg_info *arg_info, int i);
int					get_padding(char *str, t_arg_info *arg_info, int i);
int					get_precision(char *str, t_arg_info *arg_info, int i);

/*
**	argument_handling.c
*/

char				*p_arg(va_list arg, t_arg_info *arg_info);
char				*o_arg(va_list arg, t_arg_info *arg_info);
char				*percent_arg(va_list arg, t_arg_info *arg_info);
char				*get_type(void *arg);

/*
**	c_arg.c
*/

int					wchar_size(unsigned wide_char);
char				*w_char(unsigned int wide, int num_bytes);
char				*c_arg(va_list arg, t_arg_info *arg_info);

/*
**	d_arg.c
**	d_arg_handlers_1.c
**	d_arg_handlers_2.c
**	d_arg_helpers.c
*/

char				*d_arg(va_list arg, t_arg_info *arg_info);

char				*handle_short(va_list arg);
char				*handle_char(va_list arg);
char				*handle_int(va_list arg);
char				*handle_long(va_list arg);
char				*handle_long_long(va_list arg);

char				*handle_ssizet(va_list arg);
char				*handle_intmax(va_list arg);

char				*d_arg_get_sign(t_arg_info *arg_info);
char				*d_arg_get_fill(char *str, t_arg_info *arg_info);
char				*d_arg_get_precision(char *str, t_arg_info *arg_info);
char				*d_arg_get_datatype_string(va_list arg, t_arg_info
					*arg_info);

/*
**	u_arg.c
**	u_arg_handlers.c
*/

char				*u_arg(va_list arg, t_arg_info *arg_info);

char				*handle_ushort(va_list arg);
char				*handle_ulong(va_list arg);
char				*handle_ulonglong(va_list arg);
char				*handle_uintmax(va_list arg);
char				*handle_uint(va_list arg);

/*
**	s_arg.c
*/

size_t				wstr_size(unsigned *s);
char				*w_str(va_list arg, t_arg_info *arg_info);
char				*s_arg(va_list arg, t_arg_info *arg_info);

/*
**	x_arg.c
*/

void				x_arg_add_0x(char **fill, char **str, t_arg_info *arg_info);
char				*x_arg(va_list arg, t_arg_info *arg_info);

/*
**	struct_functions.c
*/

void				arg_info_init(t_arg_info **arg_info);
void				print_arg_info(t_arg_info *arg_info);
int					get_arg_info(char *str, t_arg_info *arg_info);

/*
**	padding.c
**	padding_helpers.c
*/

void				handle_padding(char **str, t_arg_info *arg_info);

char				*get_prefix(char *str, t_arg_info *arg_info);
char				*get_spaces(t_arg_info *arg_info);
char				*padding(char *str, t_arg_info *arg_info);

/*
**	precision.c
*/

void				handle_precision(char **str, t_arg_info *arg_info);

/*
**	utils.c
*/

int					flag_check(char c);
int					specifier_check(char c);

#endif
