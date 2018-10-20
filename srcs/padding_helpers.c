/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:42:32 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/19 19:42:32 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*get_prefix(char *str, t_arg_info *arg_info)
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
