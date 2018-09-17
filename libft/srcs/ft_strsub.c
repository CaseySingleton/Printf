/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:31:20 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/20 16:31:21 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	index;

	if (s == NULL)
		return (0);
	if (!(new_str = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	index = 0;
	while (index < len)
		new_str[index++] = s[start++];
	new_str[index] = '\0';
	return (new_str);
}
