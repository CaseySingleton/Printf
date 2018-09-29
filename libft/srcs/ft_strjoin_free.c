/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 21:37:32 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/25 21:37:33 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new_str;
	int		len;
	int		i;
	int		j;
	int		index;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = ft_strnew(len);
	i = 0;
	j = 0;
	index = -1;
	while (++index < len)
	{
		if (s1[i])
			new_str[index] = s1[i++];
		else if (s2[j])
			new_str[index] = s2[j++];
	}
	free(s1);
	free(s2);
	return (new_str);
}
