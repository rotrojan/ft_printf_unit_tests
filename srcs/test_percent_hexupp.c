/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent_hexupp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 20:14:52 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/08 20:16:22 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_ft_printf.h"
#define INT_DATAPOINTS DataPoints(unsigned int,		\
	0,												\
	1,												\
	42,												\
	2147483647,										\
	2147483648,										\
	2147483700,										\
	4294967295										\
	)
#define FORMAT_DATAPOINTS DataPoints(char*,	\
	"le nombre %X est affiche.",			\
											\
	"le nombre %42X est affiche.",			\
	"le nombre %1X est affiche.",			\
	"le nombre %10000X est affiche.",		\
											\
	"le nombre %0X est affiche.",			\
	"le nombre %042X est affiche.",			\
	"le nombre %01X est affiche.",			\
	"le nombre %010000X est affiche.",		\
											\
	"le nombre %-X est affiche.",			\
	"le nombre %-42X est affiche.",			\
	"le nombre %-1X est affiche.",			\
	"le nombre %-10000X est affiche.",		\
											\
	"le nombre %-0X est affiche.",			\
	"le nombre %-042X est affiche.",		\
	"le nombre %-01X est affiche.",			\
	"le nombre %-010000X est affiche.",		\
											\
	"le nombre %0-X est affiche.",			\
	"le nombre %0-42X est affiche.",		\
	"le nombre %0-1X est affiche.",			\
	"le nombre %0-10000X est affiche.",		\
											\
	"le nombre %.X est affiche.",			\
	"le nombre %.42X est affiche.",			\
	"le nombre %.1X est affiche.",			\
	"le nombre %.0X est affiche.",			\
	"le nombre %.10000X est affiche.",		\
											\
	"le nombre %0.X est affiche.",			\
	"le nombre %0.42X est affiche.",		\
	"le nombre %0.1X est affiche.",			\
	"le nombre %0.0X est affiche.",			\
	"le nombre %0.10000X est affiche.",		\
											\
	"le nombre %-.X est affiche.",			\
	"le nombre %-.42X est affiche.",		\
	"le nombre %-.1X est affiche.",			\
	"le nombre %-0.0X est affiche.",		\
	"le nombre %-.10000X est affiche.",		\
											\
	"le nombre %42.42X est affiche.",		\
	"le nombre %1.42X est affiche.",		\
	"le nombre %42.1X est affiche.",		\
	"le nombre %-42.42X est affiche.",		\
	"le nombre %-1.42X est affiche.",		\
	"le nombre %-42.1X est affiche.",		\
	"le nombre %-0.0X est affiche.",		\
	"le nombre %042.42X est affiche.",		\
	"le nombre %01.42X est affiche.",		\
	"le nombre %042.1X est affiche.",		\
	"le nombre %-042.42X est affiche.",		\
	"le nombre %-01.42X est affiche.",		\
	"le nombre %-042.1X est affiche.",		\
	"le nombre %0.0X est affiche.",			\
	"le nombre %00.0X est affiche."/*,		\
											\
	"le nombre %-42.42.42X est affiche.",	\
	"le nombre %42-X est affiche.",			\
	"le nombre %--0020.000X est affiche.",	\
	"le nombre %99999999999X est affiche."	\
*/	)

TestSuite(one_X, .init = cr_redirect_stdout);

TheoryDataPoints(one_X, simple) = {
	FORMAT_DATAPOINTS,
	INT_DATAPOINTS,
};

Theory((char *format, unsigned int d), one_X, simple)
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
		"ft_printf(\"%s\", int = %d) return a wrong value.", format, d);
	cr_expect_file_contents_eq(printf_output, ft_printf_output,
		"ft_printf(\"%s\", int = %d) return a wrong output.", format, d);

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
