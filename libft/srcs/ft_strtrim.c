/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:29:34 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/20 17:29:34 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*new_str;
	int		index;
	int		len;

	if (s == NULL)
		return (0);
	len = ft_strlen(s);
	while (is_space(s[len - 1]))
		len--;
	while (is_space(*s) && len--)
		s++;
	if (!(new_str = (char *)malloc(len + 1)))
		return (0);
	index = -1;
	while (++index < len)
		new_str[index] = s[index];
	new_str[index] = '\0';
	return (new_str);
}
