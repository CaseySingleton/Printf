/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 22:23:09 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/24 22:23:09 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				wchar_size(unsigned wide_char)
{
	if (wide_char < 0x80)
		return (1);
	else if (wide_char < 0x800)
		return (2);
	else if (wide_char < 0x10000)
		return (3);
	else
		return (4);
}

char				*w_char(unsigned int wide, int num_bytes)
{
	char			ret[4];

	ft_bzero(ret, 4);
	if (num_bytes == 1)
	{
		ret[0] = wide;
		return (ft_strdup(ret));
	}
	if (num_bytes == 2)
		ret[0] = ((wide & 0x1F << 6) >> 6) | 0xC0;
	else
	{
		if (num_bytes == 3)
			ret[0] = ((wide >> 12) & 0x0F) | 0xE0;
		else
		{
			ret[0] = ((wide >> 18) & 0x07) | 0xF0;
			ret[1] = ((wide >> 12) & 0x3F) | 0x80;
		}
		ret[num_bytes - 2] = ((wide >> 6) & 0x3F) | 0x80;
	}
	ret[num_bytes - 1] = (wide & 0x3F) | 0x80;
	return (ft_strdup(ret));
}

char				*c_arg(va_list arg, t_arg_info *arg_info)
{
	unsigned int	c;
	int				num_bytes;
	char			*ret;

	c = va_arg(arg, unsigned int);
	num_bytes = wchar_size(c);
	ret = ft_strnew(num_bytes);
	ret = w_char(c, num_bytes);
	handle_padding(&ret, arg_info);
	return (ret);
}
