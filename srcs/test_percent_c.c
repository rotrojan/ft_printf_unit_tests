/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 04:21:09 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/13 17:55:02 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_ft_printf.h"
#define CHAR_DATAPOINTS DataPoints(char, 0,	\
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,	\
	13, 14, 15, 16, 17, 18, 19, 20, 21, 22,	\
	23, 24, 25, 26, 27, 28, 29, 30, 31, 32,	\
	33, 34, 35, 36, 37, 38, 39, 40, 41, 42,	\
	43, 44, 45, 46, 47, 48, 49, 50, 51, 52,	\
	53, 54, 55, 56, 57, 58, 59, 60, 61, 62,	\
	63, 64, 65, 66, 67, 68, 69, 70, 71, 72,	\
	73, 74, 75, 76, 77, 78, 79, 80, 81, 82,	\
	83, 84, 85, 86, 87, 88, 89, 90, 91, 92,	\
	93, 94, 95, 96, 97, 98, 99, 100, 101,	\
	102, 103, 104, 105, 106, 107, 108, 109,	\
	112, 111, 112, 113, 114, 115, 116, 117,	\
	118, 119, 120, 121, 122, 123, 124, 125,	\
	126, 127, 128, 129, 130, 131, 132, 133,	\
	134, 135, 136, 137, 138, 139, 140, 141,	\
	142, 143, 144, 145, 146, 147, 148, 149,	\
	150, 151, 152, 153, 154, 155, 156, 157,	\
	158, 159, 160, 161, 162, 163, 164, 165,	\
	166, 167, 168, 169, 170, 171, 172, 173,	\
	174, 175, 176, 177, 178, 179, 180, 181,	\
	182, 183, 184, 185, 186, 187, 188, 189,	\
	190, 191, 192, 193, 194, 195, 196, 197,	\
	198, 199, 200, 201, 202, 203, 204, 205,	\
	206, 207, 208, 209, 210, 211, 212, 213,	\
	214, 215, 216, 217, 218, 219, 220, 221,	\
	222, 223, 224, 225, 226, 227, 228, 229,	\
	230, 231, 232, 233, 234, 235, 236, 237,	\
	238, 239, 240, 241, 242, 243, 244, 245,	\
	246, 247, 248, 249, 250, 251, 252, 253,	\
	254, 255)
#define FORMAT_DATAPOINTS DataPoints(char*,	\
	"le char %c est affiche.",			\
											\
	"le char %42c est affiche.",			\
	"le char %1c est affiche.",			\
	"le char %10000c est affiche.",		\
											\
	"le char %0c est affiche.",			\
	"le char %042c est affiche.",			\
	"le char %01c est affiche.",			\
	"le char %02c est affiche.",			\
	"le char %010000c est affiche.",		\
											\
	"le char %-c est affiche.",			\
	"le char %-42c est affiche.",			\
	"le char %-1c est affiche.",			\
	"le char %-2c est affiche.",			\
	"le char %-10000c est affiche.",		\
											\
	"le char %-0c est affiche.",			\
	"le char %-042c est affiche.",		\
	"le char %-01c est affiche.",			\
	"le char %-02c est affiche.",			\
	"le char %-010000c est affiche.",		\
											\
	"le char %0-c est affiche.",			\
	"le char %0-42c est affiche.",		\
	"le char %0-1c est affiche.",			\
	"le char %0-2c est affiche.",			\
	"le char %0-10000c est affiche.",		\
											\
	"le char %.c est affiche.",			\
	"le char %.42c est affiche.",			\
	"le char %.1c est affiche.",			\
	"le char %.2c est affiche.",			\
	"le char %.0c est affiche.",			\
	"le char %.10000c est affiche.",		\
											\
	"le char %0.c est affiche.",			\
	"le char %0.42c est affiche.",		\
	"le char %0.1c est affiche.",			\
	"le char %0.2c est affiche.",			\
	"le char %0.0c est affiche.",			\
	"le char %0.10000c est affiche.",		\
											\
	"le char %-.c est affiche.",			\
	"le char %-.42c est affiche.",		\
	"le char %-.1c est affiche.",			\
	"le char %-.2c est affiche.",			\
	"le char %-0.0c est affiche.",		\
	"le char %-.10000c est affiche.",		\
											\
	"le char %42.42c est affiche.",		\
	"le char %1.42c est affiche.",		\
	"le char %2.42c est affiche.",		\
	"le char %42.1c est affiche.",		\
	"le char %42.2c est affiche.",		\
	"le char %-42.42c est affiche.",		\
	"le char %-1.42c est affiche.",		\
	"le char %-2.42c est affiche.",		\
	"le char %-42.1c est affiche.",		\
	"le char %-42.2c est affiche.",		\
	"le char %-1.2c est affiche.",		\
	"le char %-2.1c est affiche.",		\
	"le char %-0.0c est affiche.",		\
	"le char %042.42c est affiche.",		\
	"le char %01.42c est affiche.",		\
	"le char %02.42c est affiche.",		\
	"le char %042.1c est affiche.",		\
	"le char %042.2c est affiche.",		\
	"le char %01.2c est affiche.",		\
	"le char %02.1c est affiche.",		\
	"le char %-042.42c est affiche.",		\
	"le char %-01.42c est affiche.",		\
	"le char %-02.42c est affiche.",		\
	"le char %-042.1c est affiche.",		\
	"le char %-042.2c est affiche.",		\
	"le char %-01.2c est affiche.",		\
	"le char %-02.1c est affiche.",		\
	"le char %0.0c est affiche.",			\
	"le char %00.0c est affiche.",		\
											\
	"le char %-42.42.42c est affiche.",	\
	"le char %42-c est affiche.",			\
	"le char %--0020.000c est affiche.",/*	\
	"le char %99999999999c est affiche."	\
*/	)

TestSuite(one_char, .init = cr_redirect_stdout);

TheoryDataPoints(one_char, simple) = {
	FORMAT_DATAPOINTS,
	CHAR_DATAPOINTS,
};

Theory((char *format, char c), one_char, simple)
{
	FILE	*ft_printf_output;
	FILE	*printf_output;
	int		ret_printf;
	int		ret_ft_printf;

	printf_output = freopen("printf.output", "a+", stdout);
	ret_printf = printf(format, c);
	fclose(printf_output);

	ft_printf_output = freopen("ft_printf.output", "a+", stdout);
	ret_ft_printf = ft_printf(format, c);
	fclose(ft_printf_output);

	cr_expect_eq(ret_printf, ret_ft_printf,
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	cr_expect_file_contents_eq(printf_output, ft_printf_output,
		"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);

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
	char	*format = "le char %-*.*c est un arobase";
	char	*format = "le char %0*.-*c est un arobase";
	char	*format = "le char %*-.*c est un arobase";
	char	*format = "le char %c est un arobase et le %c est random aussi.";
*/
