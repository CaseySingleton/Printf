/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 00:27:19 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/29 00:27:20 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lltoa_base(long long n, int base, int upper)
{
	char	*ret;
	int		num_len;

	if (base < 2 || base > 16)
		return (NULL);
	if (base == 10)
		return (ft_itoa((int)n));
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

