/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:08:16 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/12 04:59:48 by rotrojan         ###   ########.fr       */
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
	"le nombre %u est affiche.",			\
											\
	"le nombre %42u est affiche.",			\
	"le nombre %1u est affiche.",			\
	"le nombre %10000u est affiche.",		\
											\
	"le nombre %0u est affiche.",			\
	"le nombre %042u est affiche.",			\
	"le nombre %01u est affiche.",			\
	"le nombre %02u est affiche.",			\
	"le nombre %010000u est affiche.",		\
											\
	"le nombre %-u est affiche.",			\
	"le nombre %-42u est affiche.",			\
	"le nombre %-1u est affiche.",			\
	"le nombre %-2u est affiche.",			\
	"le nombre %-10000u est affiche.",		\
											\
	"le nombre %-0u est affiche.",			\
	"le nombre %-042u est affiche.",		\
	"le nombre %-01u est affiche.",			\
	"le nombre %-02u est affiche.",			\
	"le nombre %-010000u est affiche.",		\
											\
	"le nombre %0-u est affiche.",			\
	"le nombre %0-42u est affiche.",		\
	"le nombre %0-1u est affiche.",			\
	"le nombre %0-2u est affiche.",			\
	"le nombre %0-10000u est affiche.",		\
											\
	"le nombre %.u est affiche.",			\
	"le nombre %.42u est affiche.",			\
	"le nombre %.1u est affiche.",			\
	"le nombre %.2u est affiche.",			\
	"le nombre %.0u est affiche.",			\
	"le nombre %.10000u est affiche.",		\
											\
	"le nombre %0.u est affiche.",			\
	"le nombre %0.42u est affiche.",		\
	"le nombre %0.1u est affiche.",			\
	"le nombre %0.2u est affiche.",			\
	"le nombre %0.0u est affiche.",			\
	"le nombre %0.10000u est affiche.",		\
											\
	"le nombre %-.u est affiche.",			\
	"le nombre %-.42u est affiche.",		\
	"le nombre %-.1u est affiche.",			\
	"le nombre %-.2u est affiche.",			\
	"le nombre %-0.0u est affiche.",		\
	"le nombre %-.10000u est affiche.",		\
											\
	"le nombre %42.42u est affiche.",		\
	"le nombre %1.42u est affiche.",		\
	"le nombre %2.42u est affiche.",		\
	"le nombre %42.1u est affiche.",		\
	"le nombre %42.2u est affiche.",		\
	"le nombre %-42.42u est affiche.",		\
	"le nombre %-1.42u est affiche.",		\
	"le nombre %-2.42u est affiche.",		\
	"le nombre %-42.1u est affiche.",		\
	"le nombre %-42.2u est affiche.",		\
	"le nombre %-1.2u est affiche.",		\
	"le nombre %-2.1u est affiche.",		\
	"le nombre %-0.0u est affiche.",		\
	"le nombre %042.42u est affiche.",		\
	"le nombre %01.42u est affiche.",		\
	"le nombre %02.42u est affiche.",		\
	"le nombre %042.1u est affiche.",		\
	"le nombre %042.2u est affiche.",		\
	"le nombre %01.2u est affiche.",		\
	"le nombre %02.1u est affiche.",		\
	"le nombre %-042.42u est affiche.",		\
	"le nombre %-01.42u est affiche.",		\
	"le nombre %-02.42u est affiche.",		\
	"le nombre %-042.1u est affiche.",		\
	"le nombre %-042.2u est affiche.",		\
	"le nombre %-01.2u est affiche.",		\
	"le nombre %-02.1u est affiche.",		\
	"le nombre %0.0u est affiche.",			\
	"le nombre %00.0u est affiche.",		\
											\
	"le nombre %-42.42.42u est affiche.",	\
	"le nombre %42-u est affiche.",			\
	"le nombre %--0020.000u est affiche."/*,	\
	"le nombre %99999999999u est affiche."	\
*/	)

TestSuite(one_uint, .init = cr_redirect_stdout);

TheoryDataPoints(one_uint, simple) = {
	FORMAT_DATAPOINTS,
	INT_DATAPOINTS,
};

Theory((char *format, unsigned int d), one_uint, simple)
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
		"ft_printf(\"%s\", unsigned int = %u) return a wrong value.", format, d);
	cr_expect_file_contents_eq(printf_output, ft_printf_output,
		"ft_printf(\"%s\", unsigned int = %u) return a wrong output.", format, d);

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
