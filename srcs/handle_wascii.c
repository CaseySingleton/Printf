/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 22:23:09 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/24 22:23:09 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t				wchar_size(unsigned wide_char)
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

size_t			wstr_size(unsigned *s)
{
	size_t		len;
	int			i;

	len = 0;
	i = -1;
	while (s[++i] != L'\0')
		len += wchar_size(s[i]);
	return (len);
}

char			*wide_char(unsigned int wide, int num_bytes)
{
	char		ret[4];

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

void				handle_wide_char(t_pf *pf)
{
	unsigned int	c;
	int				num_bytes;
	char			*ret;

	c = va_arg(pf->arg, unsigned int);
	if (c == 0)
	{
		if (pf->padding > 0)
		{
			ret = ft_strnew(pf->padding - 1);
			ft_memset(ret, ' ', pf->padding - 1);
		}
		else
			ret = ft_strnew(0);
		write_to_buffer(pf, ret, ft_strlen(ret) + 1);
	}
	else
	{
		num_bytes = wchar_size(c);
		ret = wide_char(c, num_bytes);
		handle_padding(&ret, pf);
		if (pf->padding > 0)
			num_bytes += pf->padding - 1;
		write_to_buffer(pf, ret, num_bytes);
	}
	free(ret);
}

void			handle_wide_str(t_pf *pf)
{
	int			i;
	int			wstr_len;
	int			wchar_len;
	wchar_t		*temp;
	char		*ret;

	temp = va_arg(pf->arg, wchar_t *);
	wstr_len = (int)wstr_size((unsigned *)temp);
	ret = NULL;
	i = -1;
	while (temp[++i] != L'\0')
	{
		wchar_len = wchar_size(temp[i]);
		if (ret == NULL)
			ret = wide_char(temp[i], wchar_len);
		else
			ret = ft_strjoin_free(ret, wide_char(temp[i], wchar_len));
	}
	write_to_buffer(pf, ret, ft_strlen(ret));
	free(ret);
}
