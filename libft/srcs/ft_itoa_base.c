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

#include <stdio.h> /* <------ DON'T FORGET TO REMOVE THIS */

/*
**	WORK IN PROGRESS
*/

char			*ft_itoa_base(int n, int base)
{
	char			*nums;
	char			*str;
	int				bcpy;
	unsigned int	ncpy;

	nums = "01234567889abcdef";
	if (!(str = (char *)malloc(ft_numlen(n) + 1)))
		return (NULL);
	return (str);
}
