/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:23:27 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/25 14:23:28 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char			*w_str(va_list arg, t_arg_info *arg_info)
{
	int			i;
	int			wstr_len;
	int			wchar_len;
	wchar_t		*temp;
	char		*ret;

	temp = va_arg(arg, wchar_t *);
	wstr_len = (int)wstr_size((unsigned *)temp);
	ret = NULL;
	i = -1;
	while (temp[++i] != L'\0')
	{
		wchar_len = wchar_size(temp[i]);
		if (ret == NULL)
			ret = w_char(temp[i], wchar_len);
		else
			ret = ft_strjoin_free(ret, w_char(temp[i], wchar_len));
	}
	return (ret);
}

char			*s_arg(va_list arg, t_arg_info *arg_info)
{
	char		*temp;
	char		*ret;

	temp = va_arg(arg, char *);
	if (temp == NULL)
		ret = ft_strdup("(null)");
	else if (arg_info->precision->total > 0)
		ret = ft_strndup(temp, arg_info->precision->total);
	else
		ret = ft_strdup(temp);
	handle_padding(&ret, arg_info);
	return (ret);
}
