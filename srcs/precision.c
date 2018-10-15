/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 22:45:51 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/11 22:45:51 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					handle_precision(char **str, t_arg_info *arg_info)
{
	int					len;
	char				*temp;

	len = arg_info->precision->total - ft_strlen(*str);
	if (arg_info->padding->neg == 1 && len + 1 > 0)
	{
		*str[0] = '0';
		len++;
	}
	temp = NULL;
	if (len > 0 && arg_info->precision->total != 0)
	{
		if (!(temp = ft_strnew(len)))
			return ;
		ft_memset(temp, '0', len);
		if (arg_info->padding->neg == 1)
			temp[0] = '-';
		*str = ft_strjoin_free(temp, *str);
	}
}
