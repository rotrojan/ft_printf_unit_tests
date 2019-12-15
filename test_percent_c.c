/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 04:21:09 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/14 21:28:29 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include "../rendu/ft_printf00/include/ft_printf.h"
#define MIN_CHAR 1
#define MAX_CHAR 127
#define RAND (rand() % (MAX_CHAR - MIN_CHAR + 1)) + MIN_CHAR
#define GIANT_BUFF	6384
#define FMT_BUFF	512

void	init_seed_and_stdout(void)
{
	srand(time(NULL));
	cr_redirect_stdout();
}

TestSuite(one_char, .init = init_seed_and_stdout);

Test(one_char, test00)
{
	char	*str;
	char	*format = "le char %c est un arobase";
	char	c = RAND;

	cr_expect_eq(asprintf(&str, format, c), ft_printf(format, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}

Test(one_char, test01)
{
	char	*str;
	char	*format = "le char %14c est un arobase";
	char	c = RAND;

	cr_expect_eq(asprintf(&str, format, c), ft_printf(format, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}

Test(one_char, test02)
{
	char	*str;
	char	*format = "le char %-23c est un arobase";
	char	c = RAND;

	cr_expect_eq(asprintf(&str, format, c), ft_printf(format, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}

Test(one_char, test03)
{
	char	*str;
	char	*format = "le char %027c est un arobase";
	char	c = RAND;

	cr_expect_eq(asprintf(&str, format, c), ft_printf(format, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}

Test(one_char, test04)
{
	char	*str;
	char	*format = "le char %052-c est un arobase";
	char	c = RAND;

	cr_expect_eq(asprintf(&str, format, c), ft_printf(format, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}

Test(one_char, test05)
{
	char	*str;
	char	*format = "le char %05000c est un arobase";
	char	c = RAND;

	cr_expect_eq(asprintf(&str, format, c), ft_printf(format, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}

TestSuite(backslash_zero);

int		test_backslash_zero	(char *format, char **pf_buf, char **ft_buf, int *ret_pf)
{
	int		stdout_bk; //is fd for stdout backup
	int		pipefd[2];
	char	c = '\0';
	int		ret_ft;

	*ret_pf = asprintf(pf_buf, format, c);
	*ft_buf = (char*)malloc(sizeof(char) * (*ret_pf + 1));
	bzero(*ft_buf, *ret_pf + 1);
	stdout_bk = dup(fileno(stdout));
	pipe(pipefd);
	dup2(pipefd[1], fileno(stdout));
	ret_ft = ft_printf(format, c);
	fflush(stdout);//flushall();
	close(pipefd[1]);
	dup2(stdout_bk, fileno(stdout));//restore
	read(pipefd[0], *ft_buf, *ret_pf);
	return (ret_ft);
}

Test(backslash_zero, test00)
{
	char	*pf_buf, *ft_buf;
	int		ret_pf, ret_ft;
	char	*format = "le char %c est un \\0";

	ret_ft = test_backslash_zero(format, &pf_buf, &ft_buf, &ret_pf);
	cr_expect_eq(ret_pf, ret_ft,"ft_printf(\"%s\", char c = \'\\0\') return a wrong value.", format);
	cr_expect_arr_eq(pf_buf, ft_buf, ret_pf, "ft_printf(\"%s\", char c = \'\\0\') return a wrong output.", format);
	free(pf_buf);
	free(ft_buf);
}

Test(backslash_zero, test01)
{
	char	*pf_buf, *ft_buf;
	int		ret_pf, ret_ft;
	char	*format = "le char %14c est un \\0";

	ret_ft = test_backslash_zero(format, &pf_buf, &ft_buf, &ret_pf);
	cr_expect_eq(ret_pf, ret_ft,"ft_printf(\"%s\", char c = \'\\0\') return a wrong value.", format);
	cr_expect_arr_eq(pf_buf, ft_buf, ret_pf, "ft_printf(\"%s\", char c = \'\\0\') return a wrong output.", format);
	free(pf_buf);
	free(ft_buf);
}

Test(backslash_zero, test02)
{
	char	*pf_buf, *ft_buf;
	int		ret_pf, ret_ft;
	char	*format = "le char %-54c est un \\0";

	ret_ft = test_backslash_zero(format, &pf_buf, &ft_buf, &ret_pf);
	cr_expect_eq(ret_pf, ret_ft,"ft_printf(\"%s\", char c = \'\\0\') return a wrong value.", format);
	cr_expect_arr_eq(pf_buf, ft_buf, ret_pf, "ft_printf(\"%s\", char c = \'\\0\') return a wrong output.", format);
	free(pf_buf);
	free(ft_buf);
}

Test(backslash_zero, test03)
{
	char	*pf_buf, *ft_buf;
	int		ret_pf, ret_ft;
	char	*format = "le char %065c est un \\0";

	ret_ft = test_backslash_zero(format, &pf_buf, &ft_buf, &ret_pf);
	cr_expect_eq(ret_pf, ret_ft,"ft_printf(\"%s\", char c = \'\\0\') return a wrong value.", format);
	cr_expect_arr_eq(pf_buf, ft_buf, ret_pf, "ft_printf(\"%s\", char c = \'\\0\') return a wrong output.", format);
	free(pf_buf);
	free(ft_buf);
}

Test(backslash_zero, test04)
{
	char	*pf_buf, *ft_buf;
	int		ret_pf, ret_ft;
	char	*format = "le char %065-c est un \\0";

	ret_ft = test_backslash_zero(format, &pf_buf, &ft_buf, &ret_pf);
	cr_expect_eq(ret_pf, ret_ft,"ft_printf(\"%s\", char c = \'\\0\') return a wrong value.", format);
	cr_expect_arr_eq(pf_buf, ft_buf, ret_pf, "ft_printf(\"%s\", char c = \'\\0\') return a wrong output.", format);
	free(pf_buf);
	free(ft_buf);
}

Test(backslash_zero, test05)
{
	char	*pf_buf, *ft_buf;
	int		ret_pf, ret_ft;
	char	*format = "le char %5000c est un \\0";

	ret_ft = test_backslash_zero(format, &pf_buf, &ft_buf, &ret_pf);
	cr_expect_eq(ret_pf, ret_ft,"ft_printf(\"%s\", char c = \'\\0\') return a wrong value.", format);
	cr_expect_arr_eq(pf_buf, ft_buf, ret_pf, "ft_printf(\"%s\", char c = \'\\0\') return a wrong output.", format);
	free(pf_buf);
	free(ft_buf);
}

Test(backslash_zero, test06)
{
	char	*pf_buf, *ft_buf;
	int		ret_pf, ret_ft;
	char	*format = "le char %12.890c est un \\0";

	ret_ft = test_backslash_zero(format, &pf_buf, &ft_buf, &ret_pf);
	cr_expect_eq(ret_pf, ret_ft,"ft_printf(\"%s\", char c = \'\\0\') return a wrong value.", format);
	cr_expect_arr_eq(pf_buf, ft_buf, ret_pf, "ft_printf(\"%s\", char c = \'\\0\') return a wrong output.", format);
	free(pf_buf);
	free(ft_buf);
}

Test(backslash_zero, test08)
{
	char	*pf_buf, *ft_buf;
	int		ret_pf, ret_ft;
	char	*format = "le char %-05000.76c est un \\0";

	ret_ft = test_backslash_zero(format, &pf_buf, &ft_buf, &ret_pf);
	ft_buf[12] = 'Y';
	cr_expect_eq(ret_pf, ret_ft,"ft_printf(\"%s\", char c = \'\\0\') return a wrong value.", format);
	cr_expect_arr_eq(pf_buf, ft_buf, ret_pf, "ft_printf(\"%s\", char c = \'\\0\') return a wrong output.", format);
	free(pf_buf);
	free(ft_buf);
}

Test(backslash_zero, test09)
{
	char	*pf_buf, *ft_buf;
	int		ret_pf, ret_ft;
	char	*format = "%c";

	ret_ft = test_backslash_zero(format, &pf_buf, &ft_buf, &ret_pf);
	cr_expect_eq(ret_pf, ret_ft,"ft_printf(\"%s\", char c = \'\\0\') return a wrong value.", format);
	cr_expect_arr_eq(pf_buf, ft_buf, ret_pf, "ft_printf(\"%s\", char c = \'\\0\') return a wrong output.", format);
	free(pf_buf);
	free(ft_buf);
}
/*
TestSuite(one_asterik);

Test(one_asterik, test00)
{
	char	*str;
	char	*format = "le char %c est un arobase";
	char	c = RAND;

	cr_expect_eq(asprintf(&str, format, c), ft_printf(format, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}
*/
