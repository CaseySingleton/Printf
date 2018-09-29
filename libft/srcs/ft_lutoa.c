/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 22:48:13 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/28 22:48:13 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_lutoa(unsigned long n)
{
	char			*str;
	int				len;
	unsigned long	ncpy;

	len = ft_numlen(n);
	ncpy = n;
	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
	str[len--] = '\0';
	str[len--] = (ncpy % 10) + '0';
	while (ncpy /= 10)
		str[len--] = (ncpy % 10) + '0';
	return (str);
}
