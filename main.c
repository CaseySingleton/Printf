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

	// ft_printf("ft_printf:\n");
	// ft_printf("asdf\n");
	// ft_printf("s: %s\n", NULL);
	// ft_printf("s: %s\n", ";)");
	// ft_printf("d: %.5d\n", fourty_two);
	// printf("d: %.5d\n", fourty_two);
	// ft_printf("%%.15s: %.15s\n", "fourty_two");
	// printf("%%.15s: %.15s\n", "fourty_two");
	// ft_printf("D: %D\n", fourty_two);
	// ft_printf("d: %d\n", -42);
	// ft_printf("D: %D\n", -42);
	// ft_printf("+d: %+d\n", 42);
	// ft_printf("+D: %+D\n", 42);
	// ft_printf("@moulitest: %o\n", 0);
	// ft_printf("p: %p\n", &"hello");
	// ft_printf("o: %#o\n", octet_test);
	// ft_printf("u: %u\n", u_int_test);
	// ft_printf("x: %#x\n", 42);
	// ft_printf("x: %x\n", -42);
	// ft_printf("padding test 1:\n|%15s|\n|%-15s|\n|%s|\n", "15 left", "15 right", "none");
	// ft_printf("padding test 2:\n|%015s|\n|%-015s|\n|%s|\n", "15 left", "15 right", "none");
	// ft_printf("%%\n");
	// ft_printf("%     %\n");
	// ft_printf("%.0%\n\n");
	// ft_printf("precision test:\nfull string: 123456789\nprecision: 3\nresult: %.3s\n\n", "123456789");
	// ft_printf("x: %x\n", 4294967296);
	// ft_printf("lx: %lx\n", 4294967296);
	// ft_printf("llx: %llx\n", 4294967296);
	// ft_printf("jx: %jx\n", 4294967296);
	// ft_printf("llx: %#llx\n", 9223372036854775807);
	// ft_printf("%x\n", -42);
	// ft_printf("%#8x\n", -42);
	// ft_printf("%#08x\n", -42);
	// ft_printf("%#08x\n", -42);
	// ft_printf("%#-08x\n", -42);
	// ft_printf("%#-08x\n", 42);
	// ft_printf("%010x\n", -42);
	// ft_printf("%#-08X\n", 42);
	// ft_printf("%010X\n", 542);
	// ft_printf("@moulitest: %#.x %#.0x", 0, 0);
	// ft_printf("%.2c\n", NULL);
	// ft_printf("%.2c\n", 'a');
	// printf("%#x\n", 123);
	// printf("precision test:\nfull string: 123456789\nprecision: 3\nresult: %.3s\n", "123456789");
	// printf("%.15d\n", 123);
	// ft_printf("-5%%:    -->%-5%<--\n");
	// ft_printf("%%5:     -->%5s<--\n", "123");
	// ft_printf("%%10x:   -->%010x<--\n", 542);
	// ft_printf("%%#08:   -->%#08x<--\n", 42);
	// ft_printf("%%#-08:  -->%#-08x<--\n", 42);
	// ft_printf("%%#x:    -->%#x<--\n", 123);
	// ft_printf("%%#.x %%#.0x: -->%#.x %#.0x<--\n", 0, 0);
	// ft_printf("%%#llx:  -->%#llx<--\n", 9223372036854775807);
	// ft_printf("%%#8x:  -->%#8x<--\n", 42);
	// ft_printf("%%-10x: -->%-10x<--\n", 42);
	// ft_printf("%%5.x %%5.0x: -->%5.x %5.0x<--\n", 0, 0);
	// ft_printf("%%010x: -->%010x<--\n", 542);
	// ft_printf("%%+d:   -->%+d<--\n", 0);
	// ft_printf("%%.o %%.0o: -->%.o %.0o<--\n", 0);
	// ft_printf("%%#.o %%#.0o: -->%#.o %#.0o<--\n", 0);
	// ft_printf("%%#6o: -->%#6o<--\n", 2500);
	// ft_printf("%% d: -->% d<--\n", 42);
	// ft_printf("%%+ d: -->%+ d<--\n", 42);
	// ft_printf("%% +d: -->% +d<--\n", 42);
	// ft_printf("%%+ d: -->%+ d<--\n", -42);
	// ft_printf("%%d: -->%d<--\n", 2147483648);
	// ft_printf("%%d: -->%d<--\n", -2147483648);
	// ft_printf("%%0+5d: -->%0+5d<--\n", 42);
	// ft_printf("%%-5d:        -->%-5d<--\n", 42);
	// ft_printf("%%0+5d:       -->%0+5d<--\n", -42);
	// ft_printf("%%+10.5d:     -->%+010.5d<--\n", 4242);
	// ft_printf("%%5.d %%5.0d: -->%5.d %5.0d<--\n", 123, 123);
	// ft_printf("%%hd:         -->%hd<--\n", -123);
	// ft_printf("%%hhd:        -->%hhd<--\n", 128);
	// ft_printf("%%.d %%.0d: %.d %.0d\n", 0, 0);
	ft_printf("%%ju:         -->%ju<--\n", 4999999999);
	ft_printf("%%hU:         -->%hU<--\n", 4294967296);
	ft_printf("%%lu:         -->%lu<--\n", 4294967295);
	// printf("\nprintf:\n");
	// printf("%%5.x %%5.0x: -->%5.x %5.0x<--\n", 0, 0);
	// printf("%%+10.5d: -->%+010.5d<--\n", 4242);
	// printf("%lu\n", 4294967295);
	// printf("%lld\n", INTMAX_MAX);
	// printf("%%#-08: %#-08x\n", 42);
	// ft_printf("%-10.5o\n", 2500);
	// ft_printf("@moulitest: %.o %.0o\n", 0, 0);
	// ft_printf("@moulitest: %5.o %5.0o\n", 0, 0);
	// ft_printf("%-05o\n", 2500);
	// ft_printf("%0+5d\n", -42);
	// while (1)
	// 	;
	return (0);
}
