/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 04:21:09 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/12 06:12:36 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "../rendu/ft_printf00/include/ft_printf.h"
#define DECLARATIONS			\
	int		ret_printf;			\
	int		ret_ft_printf;		\
	char	format[512];		\
	char	*str_printf;

TestSuite(percent_c);

void	test_one_char(char *str)
{
	DECLARATIONS
	char	c;

	strcpy(format, str);
	ret_printf = asprintf(&str_printf, format, c);
	ret_ft_printf = ft_printf(format, c);
	fflush(stdout);
	cr_assert_stdout_eq_str(str_printf,
		"The output of your printf is wrong.");
	cr_assert(ret_ft_printf == ret_ft_printf,
		"Your printf does not return a good value.");
	free(str_printf);
}

Test(percent_c, test00, .init = cr_redirect_stdout)
{
	test_one_char("le char %-14c est (ou pas) un arobase");
}

Test(percent_c, test01, .init = cr_redirect_stdout)
{
	test_one_char("le char %043c est (ou pas) un arobase");
}

Test(percent_c, test02, .init = cr_redirect_stdout)
{
	test_one_char("le char %14-0c est (ou pas) un arobase");
}

Test(percent_c, test03, .init = cr_redirect_stdout)
{
	test_one_char("le char %06.12c est (ou pas) un arobase");
}

TestSuite(percent_c_with_asterisk);

void	test_one_char_with_one_asterisk(char *str)
{
	DECLARATIONS
	char	c;
	int		ast;

	c = (rand() % (127 - 0 + 1)) + 0;
	ast = (rand() % (1000 - 0 + 1)) + 0;
	strcpy(format, str);
	ret_printf = asprintf(&str_printf, format, ast, c);
	ret_ft_printf = ft_printf(format, ast, c);
	fflush(stdout);
	cr_assert_stdout_eq_str(str_printf,
		"The output of your printf is wrong.");
	cr_assert(ret_ft_printf == ret_ft_printf,
		"Your printf does not return a good value.");
	free(str_printf);
}

Test(test_one_char_with_one_asterisk, test00)
{

}
