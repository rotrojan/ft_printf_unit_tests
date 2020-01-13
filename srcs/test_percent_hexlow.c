/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent_hexlow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 20:10:08 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/12 04:57:47 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_ft_printf.h"
#define INT_DATAPOINTS DataPoints(unsigned int,		\
	0,										\
	1,										\
	2,										\
	42,										\
	2147483647,								\
	-1,										\
	-2,										\
	-42,									\
	-2147483648								\
	)
#define FORMAT_DATAPOINTS DataPoints(char*,	\
	"le nombre %x est affiche.",			\
											\
	"le nombre %42x est affiche.",			\
	"le nombre %1x est affiche.",			\
	"le nombre %10000x est affiche.",		\
											\
	"le nombre %0x est affiche.",			\
	"le nombre %042x est affiche.",			\
	"le nombre %01x est affiche.",			\
	"le nombre %02x est affiche.",			\
	"le nombre %010000x est affiche.",		\
											\
	"le nombre %-x est affiche.",			\
	"le nombre %-42x est affiche.",			\
	"le nombre %-1x est affiche.",			\
	"le nombre %-2x est affiche.",			\
	"le nombre %-10000x est affiche.",		\
											\
	"le nombre %-0x est affiche.",			\
	"le nombre %-042x est affiche.",		\
	"le nombre %-01x est affiche.",			\
	"le nombre %-02x est affiche.",			\
	"le nombre %-010000x est affiche.",		\
											\
	"le nombre %0-x est affiche.",			\
	"le nombre %0-42x est affiche.",		\
	"le nombre %0-1x est affiche.",			\
	"le nombre %0-2x est affiche.",			\
	"le nombre %0-10000x est affiche.",		\
											\
	"le nombre %.x est affiche.",			\
	"le nombre %.42x est affiche.",			\
	"le nombre %.1x est affiche.",			\
	"le nombre %.2x est affiche.",			\
	"le nombre %.0x est affiche.",			\
	"le nombre %.10000x est affiche.",		\
											\
	"le nombre %0.x est affiche.",			\
	"le nombre %0.42x est affiche.",		\
	"le nombre %0.1x est affiche.",			\
	"le nombre %0.2x est affiche.",			\
	"le nombre %0.0x est affiche.",			\
	"le nombre %0.10000x est affiche.",		\
											\
	"le nombre %-.x est affiche.",			\
	"le nombre %-.42x est affiche.",		\
	"le nombre %-.1x est affiche.",			\
	"le nombre %-.2x est affiche.",			\
	"le nombre %-0.0x est affiche.",		\
	"le nombre %-.10000x est affiche.",		\
											\
	"le nombre %42.42x est affiche.",		\
	"le nombre %1.42x est affiche.",		\
	"le nombre %2.42x est affiche.",		\
	"le nombre %42.1x est affiche.",		\
	"le nombre %42.2x est affiche.",		\
	"le nombre %-42.42x est affiche.",		\
	"le nombre %-1.42x est affiche.",		\
	"le nombre %-2.42x est affiche.",		\
	"le nombre %-42.1x est affiche.",		\
	"le nombre %-42.2x est affiche.",		\
	"le nombre %-1.2x est affiche.",		\
	"le nombre %-2.1x est affiche.",		\
	"le nombre %-0.0x est affiche.",		\
	"le nombre %042.42x est affiche.",		\
	"le nombre %01.42x est affiche.",		\
	"le nombre %02.42x est affiche.",		\
	"le nombre %042.1x est affiche.",		\
	"le nombre %042.2x est affiche.",		\
	"le nombre %01.2x est affiche.",		\
	"le nombre %02.1x est affiche.",		\
	"le nombre %-042.42x est affiche.",		\
	"le nombre %-01.42x est affiche.",		\
	"le nombre %-02.42x est affiche.",		\
	"le nombre %-042.1x est affiche.",		\
	"le nombre %-042.2x est affiche.",		\
	"le nombre %-01.2x est affiche.",		\
	"le nombre %-02.1x est affiche.",		\
	"le nombre %0.0x est affiche.",			\
	"le nombre %00.0x est affiche.",		\
											\
	"le nombre %-42.42.42x est affiche.",	\
	"le nombre %42-x est affiche.",			\
	"le nombre %--0020.000x est affiche."/*,	\
	"le nombre %99999999999x est affiche."	\
*/	)

TestSuite(one_x, .init = cr_redirect_stdout);

TheoryDataPoints(one_x, simple) = {
	FORMAT_DATAPOINTS,
	INT_DATAPOINTS,
};

Theory((char *format, unsigned int d), one_x, simple)
{
	FILE	*ft_printf_output;
	FILE	*printf_output;
	int		ret_printf;
	int		ret_ft_printf;

	printf_output = freopen("printf.output", "a+", stdout);
	ret_printf = printf(format, d);
	fclose(printf_output);

	ft_printf_output = freopen("ft_printf.output", "a+", stdout);
	ret_ft_printf = ft_printf(format, d);
	fclose(ft_printf_output);

	cr_expect_eq(ret_printf, ret_ft_printf,
		"ft_printf(\"%s\", unsigned int = %x) return a wrong value.", format, d);
	cr_expect_file_contents_eq(printf_output, ft_printf_output,
		"ft_printf(\"%s\", unsigned int = %x) return a wrong output.", format, d);

	remove("printf.output");
	remove("ft_printf.output");
}

/*
	char	*format = "le nombre %*d est affiche.";
	char	*format = "le nombre %.*d est affiche.";
	char	*format = "le nombre %-*d est affiche.";
	char	*format = "le nombre %0*d est affiche.";
	char	*format = "le nombre %-0*d est affiche.";
	char	*format = "le nombre %0.*d est affiche.";
	char	*format = "le nombre %-0.*d est affiche.";
	char	*format = "le nombre %-.*d est affiche.";

	char	*format = "le nombre %*.*d est affiche.";
*/
