/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 09:52:05 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/06 19:08:27 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_ft_printf.h"
#define INT_DATAPOINTS DataPoints(int,		\
	0,										\
	1,										\
	42,										\
	MAX_INT,								\
	-1,										\
	-42,									\
	MIN_INT									\
	)
#define FORMAT_DATAPOINTS DataPoints(char*,	\
	"le nombre %d est affiche.",			\
											\
	"le nombre %42d est affiche.",			\
	"le nombre %1d est affiche.",			\
	"le nombre %10000d est affiche.",		\
											\
	"le nombre %0d est affiche.",			\
	"le nombre %042d est affiche.",			\
	"le nombre %01d est affiche.",			\
	"le nombre %010000d est affiche.",		\
											\
	"le nombre %-d est affiche.",			\
	"le nombre %-42d est affiche.",			\
	"le nombre %-1d est affiche.",			\
	"le nombre %-10000d est affiche.",		\
											\
	"le nombre %-0d est affiche.",			\
	"le nombre %-042d est affiche.",		\
	"le nombre %-01d est affiche.",			\
	"le nombre %-010000d est affiche.",		\
											\
	"le nombre %0-d est affiche.",			\
	"le nombre %0-42d est affiche.",		\
	"le nombre %0-1d est affiche.",			\
	"le nombre %0-10000d est affiche.",		\
											\
	"le nombre %.d est affiche.",			\
	"le nombre %.42d est affiche.",			\
	"le nombre %.1d est affiche.",			\
	"le nombre %.0d est affiche.",			\
	"le nombre %.10000d est affiche.",		\
											\
	"le nombre %0.d est affiche.",			\
	"le nombre %0.42d est affiche.",		\
	"le nombre %0.1d est affiche.",			\
	"le nombre %0.0d est affiche.",			\
	"le nombre %0.10000d est affiche.",		\
											\
	"le nombre %-.d est affiche.",			\
	"le nombre %-.42d est affiche.",		\
	"le nombre %-.1d est affiche.",			\
	"le nombre %-0.0d est affiche.",		\
	"le nombre %-.10000d est affiche.",		\
											\
	"le nombre %42.42d est affiche.",		\
	"le nombre %1.42d est affiche.",		\
	"le nombre %42.1d est affiche.",		\
	"le nombre %-42.42d est affiche.",		\
	"le nombre %-1.42d est affiche.",		\
	"le nombre %-42.1d est affiche.",		\
	"le nombre %-0.0d est affiche.",		\
	"le nombre %042.42d est affiche.",		\
	"le nombre %01.42d est affiche.",		\
	"le nombre %042.1d est affiche.",		\
	"le nombre %-042.42d est affiche.",		\
	"le nombre %-01.42d est affiche.",		\
	"le nombre %-042.1d est affiche.",		\
	"le nombre %0.0d est affiche.",			\
	"le nombre %00.0d est affiche."/*,		\
											\
	"le nombre %-42.42.42d est affiche.",	\
	"le nombre %42-d est affiche.",			\
	"le nombre %--0020.000d est affiche.",	\
	"le nombre %99999999999d est affiche."	\
*/	)

TheoryDataPoints(one_digit, simple) = {
	FORMAT_DATAPOINTS,
	INT_DATAPOINTS,
};

TestSuite(one_digit, .init = cr_redirect_stdout);

Theory((char *format, int d), one_digit, simple)
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
