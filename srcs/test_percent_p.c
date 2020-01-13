/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 20:26:31 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/12 04:56:10 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_ft_printf.h"
#define INT_DATAPOINTS DataPoints(void*,			\
	"chaine non vide, non nulle",					\
	"",												\
	NULL											\
	)
#define FORMAT_DATAPOINTS DataPoints(char*,	\
	"l'adresse %p est affiche.",			\
											\
	"l'adresse %42p est affiche.",			\
	"l'adresse %1p est affiche.",			\
	"l'adresse %10000p est affiche.",		\
											\
	"l'adresse %0p est affiche.",			\
	"l'adresse %042p est affiche.",			\
	"l'adresse %01p est affiche.",			\
	"l'adresse %02p est affiche.",			\
	"l'adresse %010000p est affiche.",		\
											\
	"l'adresse %-p est affiche.",			\
	"l'adresse %-42p est affiche.",			\
	"l'adresse %-1p est affiche.",			\
	"l'adresse %-2p est affiche.",			\
	"l'adresse %-10000p est affiche.",		\
											\
	"l'adresse %-0p est affiche.",			\
	"l'adresse %-042p est affiche.",		\
	"l'adresse %-01p est affiche.",			\
	"l'adresse %-02p est affiche.",			\
	"l'adresse %-010000p est affiche.",		\
											\
	"l'adresse %0-p est affiche.",			\
	"l'adresse %0-42p est affiche.",		\
	"l'adresse %0-1p est affiche.",			\
	"l'adresse %0-2p est affiche.",			\
	"l'adresse %0-10000p est affiche.",		\
											\
	"l'adresse %.p est affiche.",			\
	"l'adresse %.42p est affiche.",			\
	"l'adresse %.1p est affiche.",			\
	"l'adresse %.2p est affiche.",			\
	"l'adresse %.0p est affiche.",			\
	"l'adresse %.10000p est affiche.",		\
											\
	"l'adresse %0.p est affiche.",			\
	"l'adresse %0.42p est affiche.",		\
	"l'adresse %0.1p est affiche.",			\
	"l'adresse %0.2p est affiche.",			\
	"l'adresse %0.0p est affiche.",			\
	"l'adresse %0.10000p est affiche.",		\
											\
	"l'adresse %-.p est affiche.",			\
	"l'adresse %-.42p est affiche.",		\
	"l'adresse %-.1p est affiche.",			\
	"l'adresse %-.2p est affiche.",			\
	"l'adresse %-0.0p est affiche.",		\
	"l'adresse %-.10000p est affiche.",		\
											\
	"l'adresse %42.42p est affiche.",		\
	"l'adresse %1.42p est affiche.",		\
	"l'adresse %2.42p est affiche.",		\
	"l'adresse %42.1p est affiche.",		\
	"l'adresse %42.2p est affiche.",		\
	"l'adresse %-42.42p est affiche.",		\
	"l'adresse %-1.42p est affiche.",		\
	"l'adresse %-2.42p est affiche.",		\
	"l'adresse %-42.1p est affiche.",		\
	"l'adresse %-42.2p est affiche.",		\
	"l'adresse %-1.2p est affiche.",		\
	"l'adresse %-2.1p est affiche.",		\
	"l'adresse %-0.0p est affiche.",		\
	"l'adresse %042.42p est affiche.",		\
	"l'adresse %01.42p est affiche.",		\
	"l'adresse %02.42p est affiche.",		\
	"l'adresse %042.1p est affiche.",		\
	"l'adresse %042.2p est affiche.",		\
	"l'adresse %01.2p est affiche.",		\
	"l'adresse %02.1p est affiche.",		\
	"l'adresse %-042.42p est affiche.",		\
	"l'adresse %-01.42p est affiche.",		\
	"l'adresse %-02.42p est affiche.",		\
	"l'adresse %-042.1p est affiche.",		\
	"l'adresse %-042.2p est affiche.",		\
	"l'adresse %-01.2p est affiche.",		\
	"l'adresse %-02.1p est affiche.",		\
	"l'adresse %0.0p est affiche.",			\
	"l'adresse %00.0p est affiche.",		\
											\
	"le nombre %-42.42.42p est affiche.",	\
	"le nombre %42-p est affiche.",			\
	"le nombre %--0020.000p est affiche.",/*	\
	"le nombre %99999999999p est affiche."	\
*/	)

TestSuite(one_ptr, .init = cr_redirect_stdout);

TheoryDataPoints(one_ptr, simple) = {
	FORMAT_DATAPOINTS,
	INT_DATAPOINTS,
};

Theory((char *format, void *ptr), one_ptr, simple)
{
	FILE	*ft_printf_output;
	FILE	*printf_output;
	int		ret_printf;
	int		ret_ft_printf;

	printf_output = freopen("printf.output", "a+", stdout);
	ret_printf = printf(format, ptr);
	fclose(printf_output);

	ft_printf_output = freopen("ft_printf.output", "a+", stdout);
	ret_ft_printf = ft_printf(format, ptr);
	fclose(ft_printf_output);

	cr_expect_eq(ret_printf, ret_ft_printf,
		"ft_printf(\"%s\", &ptr = %p) return a wrong value.", format, ptr);
	cr_expect_file_contents_eq(printf_output, ft_printf_output,
		"ft_printf(\"%s\", &ptr = %p) return a wrong output.", format, ptr);

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
