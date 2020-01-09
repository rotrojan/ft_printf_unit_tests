/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 04:21:09 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/09 02:29:13 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_ft_printf.h"
TestSuite(one_cha, .init = cr_redirect_stdout);

ParameterizedTestParameters(one_percent, simple) {
	char	*formats[50] = {
		"le symbole %% est affiche.",

		"le symbole %42% est affiche.",
		"le symbole %1% est affiche.",
		"le symbole %10000% est affiche.",
										
		"le symbole %0% est affiche.",
		"le symbole %042% est affiche.",
		"le symbole %01% est affiche.",
		"le symbole %010000% est affiche.",
									
		"le symbole %-% est affiche.",
		"le symbole %-42% est affiche.",
		"le symbole %-1% est affiche.",
		"le symbole %-10000% est affiche.",

		"le symbole %-0% est affiche.",
		"le symbole %-042% est affiche.",
		"le symbole %-01% est affiche.",
		"le symbole %-010000% est affiche.",

		"le symbole %0-% est affiche.",
		"le symbole %0-42% est affiche.",
		"le symbole %0-1% est affiche.",
		"le symbole %0-10000% est affiche.",

		"le symbole %.% est affiche.",
		"le symbole %.42% est affiche.",
		"le symbole %.1% est affiche.",
		"le symbole %.0% est affiche.",
		"le symbole %.10000% est affiche.",

		"le symbole %0.% est affiche.",
		"le symbole %0.42% est affiche.",
		"le symbole %0.1% est affiche.",
		"le symbole %0.0% est affiche.",
		"le symbole %0.10000% est affiche.",

		"le symbole %-.% est affiche.",
		"le symbole %-.42% est affiche.",
		"le symbole %-.1% est affiche.",
		"le symbole %-0.0% est affiche.",
		"le symbole %-.10000% est affiche.",

		"le symbole %42.42% est affiche.",
		"le symbole %1.42% est affiche.",
		"le symbole %42.1% est affiche.",
		"le symbole %-42.42% est affiche.",
		"le symbole %-1.42% est affiche.",
		"le symbole %-42.1% est affiche.",
		"le symbole %-0.0% est affiche.",
		"le symbole %042.42% est affiche.",
		"le symbole %01.42% est affiche.",
		"le symbole %042.1% est affiche.",
		"le symbole %-042.42% est affiche.",
		"le symbole %-01.42% est affiche.",
		"le symbole %-042.1% est affiche.",
		"le symbole %0.0% est affiche.",
		"le symbole %00.0% est affiche."/*,			\
												\
		"le symbole %-42.42.42% est affiche.",		\
		"le symbole %42-% est affiche.",			\
		"le symbole %--0020.000% est affiche.",	\
		"le symbole %99999999999% est affiche."	\
*/	
    };

    size_t nb_formats = sizeof(formats) / sizeof(char*);
    return (cr_make_param_array(char*, formats, nb_formats));
}

ParameterizedTest(char *formats[], one_percent, simple)
{
	FILE	*ft_printf_output;
	FILE	*printf_output;
	int		ret_printf;
	int		ret_ft_printf;

	printf_output = freopen("printf.output", "a+", stdout);
	ret_printf = printf(*formats);
	fclose(printf_output);

	ft_printf_output = freopen("ft_printf.output", "a+", stdout);
	ret_ft_printf = ft_printf(*formats);
	fclose(ft_printf_output);

	cr_expect_eq(ret_printf, ret_ft_printf,
		"ft_printf(\"%s\", char c = %%) return a wrong value.", *formats);
	cr_expect_file_contents_eq(printf_output, ft_printf_output,
		"ft_printf(\"%s\", char c = %%) return a wrong output.", *formats);

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
