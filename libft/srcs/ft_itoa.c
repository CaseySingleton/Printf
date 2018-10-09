/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:16:45 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/08 15:08:01 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	ncpy;

	ncpy = n;
	len = ft_numlen(ncpy *= ((n < 0) ? -1 : 1));
	if (n == 0)
		return (str = ft_strdup("0"));
	else if (!(str = ft_strnew(len += ((n < 0) ? 1 : 0))))
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
		str[0] = '-';
	while (ncpy != 0 && str[len] != '-')
	{
		str[len--] = (ncpy % 10) + '0';
		ncpy /= 10;
	}
	return (str);
}
