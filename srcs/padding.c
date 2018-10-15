/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 16:00:22 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/21 16:00:23 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Padding will only show if the number to be padded is greater than the
**	length of the argument
**
**	ex:
**	  printf("|%3s|\n", "Hello 42!")   -> |Hello 42!|
**	  printf("|%-3s|\n", "Hello 42!")  -> |Hello 42!|
**	  printf("|%15s|\n", "Hello 42!")  -> |      Hello 42!|
**	  printf("|%-15s|\n", "Hello 42!") -> |Hello 42!      |
**
**	A positive value will place spaces to the right
**	A negative value will place spaces to the left
*/

/*
**	if pad_zeros == 1 add 0x to start of fill
**	if pad_zeros == 0 add 0x to start of arg_info->arg
*/

static char		*get_prefix(char *str, t_arg_info *arg_info)
{
	char		*ret;

	ret = NULL;
	if (arg_info->padding->prefix == 1 && str[0] != '0')
	{
		if (arg_info->specifier == 'x')
		{
			ret = ft_strdup("0x");
			arg_info->padding->total -= 2;
		}
		else if (arg_info->specifier == 'X')
		{
			ret = ft_strdup("0X");
			arg_info->padding->total -= 2;
		}
		else if (arg_info->specifier == 'o')
		{
			ret = ft_strdup("0");
			arg_info->padding->total -= 1;
		}
	}
	return (ret);
}

char			*get_spaces(t_arg_info *arg_info)
{
	char		*spaces;

	spaces = NULL;
	if (arg_info->padding->spaces != 0 && arg_info->padding->neg != 1)
	{
		if (!(spaces = ft_strnew(arg_info->padding->spaces)))
			return (NULL);
		ft_memset(spaces, ' ', arg_info->padding->spaces);
	}
	return (spaces);
}

 /*
 **	add padding should decide to add to the front or end of a string
 */

char			*padding(char *str, t_arg_info *arg_info)
{
	char		*fill;
	int			len;

	fill = NULL;
	if (arg_info->padding->spaces != 0 && arg_info->padding->neg != 1)
		return (get_spaces(arg_info));
	len = arg_info->padding->total - ft_strlen(str);
	if (len <= 0 || (!(fill = ft_strnew(len))))
		return (NULL);
	if ((arg_info->specifier == 'x' || arg_info->specifier == 'X' ||
	arg_info->specifier == 'o') && arg_info->padding->rev == 1 &&
	arg_info->padding->zero == 1)
		ft_memset(fill, ' ', len);
	else if (arg_info->padding->zero == 1)
		ft_memset(fill, '0', len);
	else
		ft_memset(fill, ' ', len);
	return (fill);
}

static char		*combine_padding_and_prefix(char **str, char *fill, char *prefix, t_arg_info *arg_info)
{
	char		*ret;

	ret = NULL;
	if (fill == NULL && prefix != NULL)
		ret = ft_strjoin_free(prefix, *str);
	else if (fill != NULL && prefix == NULL)
	{
		if (arg_info->padding->rev == 1 && arg_info->padding->zero != 1)
			ret = ft_strjoin(*str, fill);
		else if (arg_info->padding->rev == 1 && arg_info->padding->zero == 1
		&& fill[0] == ' ')
			ret = ft_strjoin(*str, fill);
		else if (arg_info->padding->rev != 1)
			ret = ft_strjoin(fill, *str);
	}
	else if (fill != NULL && prefix != NULL)
	{
		if (arg_info->padding->zero == 1 && arg_info->padding->rev == 1 && fill[0] == ' ')
		{
			ret = ft_strjoin_free(prefix, *str);
			ret = ft_strjoin_free(ret, fill);
		}
		else if (arg_info->padding->zero == 1)
		{
			ret = ft_strjoin_free(prefix, fill);
			ret = ft_strjoin_free(ret, *str);
		}
		else if (arg_info->padding->zero != 1 && arg_info->padding->rev == 1)
		{
			ret = ft_strjoin_free(prefix, *str);
			ret = ft_strjoin_free(ret, fill);
		}
		else if (arg_info->padding->zero != 1)
		{
			ret = ft_strjoin_free(prefix, *str);
			ret = ft_strjoin_free(fill, ret);
		}
	}
	else
	{
		ret = ft_strdup(*str);
		free(*str);
	}
	return (ret);
}

void			handle_padding(char **str, t_arg_info *arg_info)
{
	char		*prefix;
	char		*fill;

	prefix = NULL;
	fill = NULL;
	prefix = get_prefix(*str, arg_info);
	fill = padding(*str, arg_info);
	*str = combine_padding_and_prefix(str, fill, prefix, arg_info);
}
