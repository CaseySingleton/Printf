/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 23:50:02 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/28 23:50:02 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_llutoa_base(unsigned long long n, int base, int upper)
{
	char	*ret;
	int		num_len;

	if (base < 2 || base > 16)
		return (NULL);
	if (base == 10)
		return (ft_itoa((int)n));
	num_len = ft_numlen(n);
	ret = ft_strnew(num_len);
	while (--num_len >= 0)
	{
		if (base > 10 && (n % base >= 10))
			ret[num_len] = (n % base) - 10 + ((upper == 0) ? 'a' : 'A');
		else
			ret[num_len] = (n % base) + '0';
		n /= base;
	}
	return (ret);
}
