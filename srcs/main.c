/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:26:26 by csinglet          #+#    #+#             */
/*   Updated: 2018/09/17 16:26:27 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int			main(int argc, char *argv[])
{
	char			hello[] = "hello";
	int				fourty_two = 42;
	int				octet_test = 123;
	unsigned int	u_int_test = 456;


	ft_printf("s: %s\n", hello);
	ft_printf("d: %d\n", fourty_two);
	ft_printf("p: %p\n", hello);
	ft_printf("o: %o\n", octet_test);
	ft_printf("u: %u\n", u_int_test);
	ft_printf("padding test:\n|%10s|\n|%-10s|\n|%s|\n", "10 left", "10 right", "none");
	// while (1)
	// 	;
	return (0);
}
