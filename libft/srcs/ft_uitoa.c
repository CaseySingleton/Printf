/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 01:28:23 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/03 01:28:24 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_uitoa_base(int n, int base, int upper)
{
	char	*ret;
	int		num_len;

	if (base < 2 || base > 16)
		return (NULL);
	// if (base == 10)
	// 	return (ft_uitoa((int)n));
	num_len = ft_numlen(n) + ((n < 0) ? 1 : 0);
	ret = ft_strnew(num_len);
	while (--num_len >= ((n < 0) ? 1 : 0))
	{
		if (base > 10 && (n % base >= 10))
			ret[num_len] = (n % base) - 10 + ((upper == 0) ? 'a' : 'A');
		else
			ret[num_len] = (n % base) + '0';
		n /= base;
	}
	return (ret);
}
