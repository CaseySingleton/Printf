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

typedef struct		s_arg_info
{
	char			*arg;
	char			specifier;
	char			specifier_mod;
	int				hash_key;
	int				flag;
	int				width;
	int				precision;
	int				padding;
	int				rev_padding;
	int				pad_zeros;
	int				neg_flag;
	int				pos_flag;
	int				count_spaces;
}					t_arg_info;

/*
**	ft_printf.c
*/

int					ft_printf(const char *format, ...);
void				print_arg_info(t_arg_info *arg_info);

/*
**	argument_parsing.c
*/

int					get_mods(char *str, t_arg_info *arg_info, int i);
int					get_flags(char *str, t_arg_info *arg_info, int i);
int					get_padding(char *str, t_arg_info *arg_info, int i);
int					get_precision(char *str, t_arg_info *arg_info, int i);
void				other_get_specifier(char *str, t_arg_info *arg_info, int i);
int					get_specifier(char *str, t_arg_info *arg_info, int i);

/*
**	argument_handling.c
*/

void			handle_precision(char **str, t_arg_info *arg_info);
void				insert_arg(char **str, t_arg_info *arg_info);
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

int					d_arg_parse(char *str, t_arg_info *arg_info, int i);
char				*d_arg(va_list arg, t_arg_info *arg_info);

/*
**	x_arg.c
*/

void				x_arg_add_0x(char **fill, char **str, t_arg_info *arg_info);
char				*x_arg(va_list arg, t_arg_info *arg_info);


/*
**	struct_functions.c
*/

t_arg_info			*arg_info_init(void);
void				print_arg_info(t_arg_info *arg_info);
int					get_arg_info(char *str, t_arg_info *arg_info);

/*
**	padding.c
*/

void				add_spaces(char **str, t_arg_info *arg_info);
char				*add_padding(char *str, t_arg_info *arg_info);
void				handle_padding(char **str, t_arg_info *arg_info);

/*
**	utils.c
*/

void				check_pos_flag(char *str, t_arg_info *arg_info, int i);
int					check_only_spaces(char *str, t_arg_info *arg_info, int i);
int					specifier_check(char c);

#endif
