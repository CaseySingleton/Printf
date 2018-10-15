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

// Specifiers: sSpdDioOuUxXcC

# define FLAG_CHECK(c) (c == 'h' || c == 'l' || c == 'j' || c == 'z') ? 0 : 1
# define NUM_SPECIFIERS 14
# define NUM_FLAGS 6

# define BOLD "\033[1m\033[30m"
# define RESET "\033[0m"

# define GET_TYPE(x) _Generic((x), \
	_Bool: "_Bool", \
	unsigned char: "unsigned char", \
	char: "char", \
	signed char: "signed char", \
	short int: "short int", \
	unsigned short int: "unsigned short int", \
	int: "int", \
	unsigned int: "unsigned int", \
	long int: "long int", \
	unsigned long int: "unsigned long int", \
	long long int: "long long int", \
	unsigned long long int: "unsigned long long int", \
	float: "float", \
	double: "double", \
	long double: "long double", \
	char *: "pointer to char", \
	void *: "pointer to void", \
	int *: "pointer to int", \
	default: "other")

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
int					flag_check(char c);
int					get_flags(char *str, t_arg_info *arg_info, int i);
int					get_padding(char *str, t_arg_info *arg_info, int i);
int					get_precision(char *str, t_arg_info *arg_info, int i);
// void				other_get_specifier(char *str, t_arg_info *arg_info, int i);
// int					get_specifier(char *str, t_arg_info *arg_info, int i);

/*
**	argument_handling.c
*/

char				*s_arg(va_list arg, t_arg_info *arg_info);
char				*c_arg(va_list arg, t_arg_info *arg_info);
char				*p_arg(va_list arg, t_arg_info *arg_info);
char				*o_arg(va_list arg, t_arg_info *arg_info);
char				*u_arg(va_list arg, t_arg_info *arg_info);
char				*percent_arg(va_list arg, t_arg_info *arg_info);
char				*get_type(void *arg);

/*
**	d_arg.c
*/

char				*d_arg(va_list arg, t_arg_info *arg_info);

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
*/

char				*get_spaces(t_arg_info *arg_info);
char				*add_padding(char **str, t_arg_info *arg_info);
char				*padding(char *str, t_arg_info *arg_info);
void				handle_padding(char **str, t_arg_info *arg_info);

/*
**	precision.c
*/

void				handle_precision(char **str, t_arg_info *arg_info);

/*
**	utils.c
*/

int					specifier_check(char c);

#endif
