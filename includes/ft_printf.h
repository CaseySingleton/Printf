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
# include <stdlib.h>
# include <stdarg.h>

// Specifiers: sSpdDioOuUxXcC

# define FLAG_CHECK(c) (c == 'h' || c == 'l' || c == 'j' || c == 'z') ? 1 : 0
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
	int				hash_key;
	int				flag;
	int				width;
	int				precision;
	int				padding;
}					t_arg_info;

/*
**	ft_printf.c
*/

int					ft_printf(const char *format, ...);
void				print_arg_info(t_arg_info *arg_info);

/*
**	argument_parsing.c
*/

void				get_flags(char *str, t_arg_info *arg_info);
void				get_padding(char *str, t_arg_info *arg_info);
void				get_precision(char *str, t_arg_info *arg_info);
int					specifier_check(char c);
void				get_specifier(char *str, t_arg_info *arg_info);

/*
**	argument_handling.c
*/

void				insert_arg(char **str, char *arg, int padding);
char				*s_arg(va_list arg);
char				*d_arg(va_list arg);
char				*p_arg(va_list arg);
char				*o_arg(va_list arg);
char				*u_arg(va_list arg);
char				*get_type(void *arg);

/*
**	struct_functions.c
*/

t_arg_info			*arg_info_init(void);
void				print_arg_info(t_arg_info *arg_info);
void				*get_arg_info(char *str, t_arg_info *arg_info);

/*
**	padding.c
*/

void				add_padding(char **str, char *arg, int padding);

/*
**	utils
**
**	These are functions from my libft repository. The reason I did not
**	include my libft repository is I am not sure how to merge archives
**	so the simple solution was to copy the c files and archive them along
**	with the printf c files
*/

int					ft_atoi(const char *str);
int					ft_copy_until(char **dest, char *src, int stop);
int					ft_isdigit(int c);
char				*ft_itoa(int n);
char				*ft_lltoa_base(long long n, int base, int upper);
char				*ft_llutoa_base(unsigned long long n, int base, int upper);
void				*ft_memcpy(void *dest, const void *src, size_t size);
void				*ft_memset(void *ptr, int value, size_t length);
int					ft_numlen(unsigned long long n);
void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_strjoin_free_s1(char *s1, const char *s2);
size_t				ft_strlen(const char *str);
char				*ft_strnew(size_t size);


#endif
