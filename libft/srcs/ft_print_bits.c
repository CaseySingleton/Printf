/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:08:43 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/29 18:15:02 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_bits(int num, int num_bits)
{
	while (--num_bits)
	{
		if (num & (1 << num_bits))
			ft_putchar('1');
		else
			ft_putchar('0');
		if (num_bits % 8 == 0 && num_bits != 0)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
