/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:33:19 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/06 19:05:20 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_ft_printf.h"
#define STR_DATAPOINTS DataPoints(char*,		\
	"chaine non vide et non nulle",				\
	"",											\
	NULL										\
	)
#define FORMAT_DATAPOINTS DataPoints(char*,		\
	"la string\"%s\" est affiche.",				\
												\
	"la string\"%42s\" est affiche.",			\
	"la string\"%1s\" est affiche.",			\
	"la string\"%10000s\" est affiche.",		\
												\
	"la string\"%0s\" est affiche.",			\
	"la string\"%042s\" est affiche.",			\
	"la string\"%01s\" est affiche.",			\
	"la string\"%010000s\" est affiche.",		\
												\
	"la string\"%-s\" est affiche.",			\
	"la string\"%-42s\" est affiche.",			\
	"la string\"%-1s\" est affiche.",			\
	"la string\"%-10000s\" est affiche.",		\
												\
	"la string\"%-0s\" est affiche.",			\
	"la string\"%-042s\" est affiche.",			\
	"la string\"%-01s\" est affiche.",			\
	"la string\"%-010000s\" est affiche.",		\
												\
	"la string\"%0-s\" est affiche.",			\
	"la string\"%0-42s\" est affiche.",			\
	"la string\"%0-1s\" est affiche.",			\
	"la string\"%0-10000s\" est affiche.",		\
												\
	"la string\"%.s\" est affiche.",			\
	"la string\"%.42s\" est affiche.",			\
	"la string\"%.1s\" est affiche.",			\
	"la string\"%.0s\" est affiche.",			\
	"la string\"%.10000s\" est affiche.",		\
												\
	"la string\"%0.s\" est affiche.",			\
	"la string\"%0.42s\" est affiche.",			\
	"la string\"%0.1s\" est affiche.",			\
	"la string\"%0.0s\" est affiche.",			\
	"la string\"%0.10000s\" est affiche.",		\
												\
	"la string\"%-.s\" est affiche.",			\
	"la string\"%-.42s\" est affiche.",			\
	"la string\"%-.1s\" est affiche.",			\
	"la string\"%-0.0s\" est affiche.",			\
	"la string\"%-.10000s\" est affiche.",		\
												\
	"la string\"%42.42s\" est affiche.",		\
	"la string\"%1.42s\" est affiche.",			\
	"la string\"%42.1s\" est affiche.",			\
	"la string\"%-42.42s\" est affiche.",		\
	"la string\"%-1.42s\" est affiche.",		\
	"la string\"%-42.1s\" est affiche.",		\
	"la string\"%-0.0s\" est affiche.",			\
	"la string\"%042.42s\" est affiche.",		\
	"la string\"%01.42s\" est affiche.",		\
	"la string\"%042.1s\" est affiche.",		\
	"la string\"%-042.42s\" est affiche.",		\
	"la string\"%-01.42s\" est affiche.",		\
	"la string\"%-042.1s\" est affiche.",		\
	"la string\"%0.0s\" est affiche.",			\
	"la string\"%00.0s\" est affiche."/*,			\
												\
	"la string\"%-42.42.42s\" est affiche.",	\
	"la string\"%42-s\" est affiche.",			\
	"la string\"%--0020.000s\" est affiche]",	\
	"la string\"%99999999999s\" est affiche."	\
*/	)

TestSuite(one_str, .init = cr_redirect_stdout);

TheoryDataPoints(one_str, simple) = {
	FORMAT_DATAPOINTS,
	STR_DATAPOINTS,
};

Theory((char *format, char *str), one_str, simple)
{
	FILE	*ft_printf_output;
	FILE	*printf_output;
	int		ret_printf;
	int		ret_ft_printf;

	printf_output = freopen("printf.output", "a+", stdout);
	ret_printf = printf(format, str);
	fclose(printf_output);

	ft_printf_output = freopen("ft_printf.output", "a+", stdout);
	ret_ft_printf = ft_printf(format, str);
	fclose(ft_printf_output);

	cr_expect_eq(ret_printf, ret_ft_printf,
		"ft_printf(\"%s\", char *str = \"%s\") return a wrong value.", format, str);
	cr_expect_file_contents_eq(printf_output, ft_printf_output,
		"ft_printf(\"%s\", char *str = \"%s\") return a wrong output.", format, str);

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
*/
