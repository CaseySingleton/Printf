/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:18:12 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/17 17:18:24 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(int n, int base, int upper)
{
	char	*ret;
	int		num_len;

	if (base < 2 || base > 16)
		return (NULL);
	num_len = ft_numlen(n) + ((n < 0) ? 1 : 0);
	ret = ft_strnew(num_len);
	ret[num_len] = '\0';
	num_len--;
	while (num_len >= 0 && ret[num_len != '\0'])
	{
		if (base > 10 && (n % base >= 10))
			ret[num_len] = (n % base) - 10 + ((upper == 0) ? 'a' : 'A');
		else
			ret[num_len] = (n % base) + '0';
		n /= base;
		num_len--;
	}
	return (ret);
}
