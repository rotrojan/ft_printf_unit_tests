/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 09:52:05 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/23 01:10:33 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_ft_printf.h"
#define INT_DATAPOINTS DataPoints(int,		\
	0, 1, 42, 2147483647,					\
	-1, -42, -2147483648)
#define FORMAT_DATAPOINTS DataPoints(char*,	\
	"le nombre %i est affiche.",			\
											\
	"le nombre %42i est affiche.",			\
	"le nombre %1i est affiche.",			\
	"le nombre %10000i est affiche.",		\
											\
	"le nombre %0i est affiche.",			\
	"le nombre %042i est affiche.",			\
	"le nombre %01i est affiche.",			\
	"le nombre %010000i est affiche.",		\
											\
	"le nombre %-i est affiche.",			\
	"le nombre %-42i est affiche.",			\
	"le nombre %-1i est affiche.",			\
	"le nombre %-10000i est affiche.",		\
											\
	"le nombre %-0i est affiche.",			\
	"le nombre %-042i est affiche.",		\
	"le nombre %-01i est affiche.",			\
	"le nombre %-010000i est affiche.",		\
											\
	"le nombre %0-i est affiche.",			\
	"le nombre %0-42i est affiche.",		\
	"le nombre %0-1i est affiche.",			\
	"le nombre %0-10000i est affiche.",		\
											\
	"le nombre %.i est affiche.",			\
	"le nombre %.42i est affiche.",			\
	"le nombre %.1i est affiche.",			\
	"le nombre %.0i est affiche.",			\
	"le nombre %.10000i est affiche.",		\
											\
	"le nombre %0.i est affiche.",			\
	"le nombre %0.42i est affiche.",		\
	"le nombre %0.1i est affiche.",			\
	"le nombre %0.0i est affiche.",			\
	"le nombre %0.10000i est affiche.",		\
											\
	"le nombre %-.i est affiche.",			\
	"le nombre %-.42i est affiche.",		\
	"le nombre %-.1i est affiche.",			\
	"le nombre %-0.0i est affiche.",		\
	"le nombre %-.10000i est affiche.",		\
											\
	"le nombre %42.42i est affiche.",		\
	"le nombre %1.42i est affiche.",		\
	"le nombre %42.1i est affiche.",		\
	"le nombre %-42.42i est affiche.",		\
	"le nombre %-1.42i est affiche.",		\
	"le nombre %-42.1i est affiche.",		\
	"le nombre %-0.0i est affiche.",		\
	"le nombre %042.42i est affiche.",		\
	"le nombre %01.42i est affiche.",		\
	"le nombre %042.1i est affiche.",		\
	"le nombre %-042.42i est affiche.",		\
	"le nombre %-01.42i est affiche.",		\
	"le nombre %-042.1i est affiche.",		\
	"le nombre %0.0i est affiche.",			\
	"le nombre %00.0i est affiche.",		\
											\
	"le nombre %-42.42.42i est affiche.",	\
	"le nombre %42-i est affiche.",			\
	"le nombre %--0020.000i est affiche.",	\
	"le nombre %99999999999i est affiche.")

TestSuite(one_int, .init = cr_redirect_stdout);

TheoryDataPoints(one_int, simple) = {
	FORMAT_DATAPOINTS,
	INT_DATAPOINTS,
};

Theory((char *format, int d), one_int, simple)
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
/
