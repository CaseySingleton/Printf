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

size_t			wchar_size(unsigned int wide_char)
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

void			wide_char(t_pf *pf, unsigned int wide, int num_bytes)
{
	char		ret[4];

	// if (num_bytes <= MB_CUR_MAX)
	// {
		if (num_bytes == 1 || num_bytes > MB_CUR_MAX)
			ret[0] = wide;
		else
		{
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
		}
		write_to_buffer(pf, ret, num_bytes);
	// }
}

void			handle_wide_char(t_pf *pf)
{
	unsigned int	c;
	wchar_t			l;
	int				char_len;

	c = va_arg(pf->arg, unsigned int);
	char_len = wchar_size(c);
	// if (c == 0)
	// {
	// 	ret = ft_strnew(pf->padding - ((pf->padding > 0) ? 1 : 0));
	// 	ft_memset(ret, ' ', pf->padding - ((pf->padding > 0) ? 1 : 0));
	// }
	// else
	// {
		wide_char(pf, c, char_len);
		// if (pf->padding > 0)
		// 	char_len += pf->padding - 1;
	// }
	// write_to_buffer(pf, ret, ((c == 0) ? ft_strlen(ret) + 1 : char_len));
}

void			handle_wide_str(t_pf *pf)
{
	int			i;
	int			wstr_len;
	int			wchar_len;
	wchar_t		*temp;

	temp = va_arg(pf->arg, wchar_t *);
	wstr_len = (int)wstr_size((unsigned *)temp);
	i = -1;
	while (temp[++i] != L'\0')
	{
		wchar_len = wchar_size(temp[i]);
		wide_char(pf, temp[i], wchar_len);
	}
}
