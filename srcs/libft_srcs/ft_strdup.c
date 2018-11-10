/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:35:39 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/18 10:35:40 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *new;

	if ((new = (char *)malloc(ft_strlen(src) + 1)))
	{
		ft_strcpy(new, src);
		return (new);
	}
	else
		return (0);
}
