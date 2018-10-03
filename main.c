/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:26:26 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/01 01:06:50 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

#include <stdio.h>

int			main(void)
{
	char			hello[] = "hello";
	int				fourty_two = 42;
	int				neg_fourty_two = -42;
	int				octet_test = 123;
	unsigned int	u_int_test = 456;


	ft_printf("asdf\n");
	ft_printf("s: %s\n", NULL);
	ft_printf("s: %s\n", ";)");
	ft_printf("d: %d\n", fourty_two);
	ft_printf("D: %D\n", fourty_two);
	ft_printf("p: %p\n", hello);
	ft_printf("o: %o\n", octet_test);
	ft_printf("u: %u\n", u_int_test);
	ft_printf("x: %x\n", 42);
	ft_printf("X: %X\n", -42);
	ft_printf("padding test 1:\n|%10s|\n|%-15s|\n|%s|\n", "10 left", "10 right", "none");
	ft_printf("padding test 2:\n|%010s|\n|%-015s|\n|%s|\n", "10 left", "10 right", "none");
	ft_printf("%%\n");
	ft_printf("%     %\n");
	ft_printf("%.0%\n\n");
	ft_printf("precision test:\nfull string: 123456789\nprecision: 3\nresult: %.3s\n\n", "123456789");
	ft_printf("%x\n", 4294967296);
	ft_printf("%lx\n", 4294967296);
	ft_printf("%llx\n", 4294967296);
	// printf("precision test:\nfull string: 123456789\nprecision: 3\nresult: %.3s\n", "123456789");
	// while (1)
	// 	;
	return (0);
}
