/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 04:21:09 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/13 07:01:46 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
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

TestSuite(backslash_zero, .init = init_seed_and_stdout);

Test(backslash_zero, test00)
{
	char	str_pf[GIANT_BUFF];
	char	str_ft[GIANT_BUFF];
	char	format[FMT_BUFF];
	char	c = '\0';

	bzero(str_ft, sizeof(str_ft));
	bzero(str_pf, sizeof(str_pf));
	strcpy((char*)format, "test du %c aka \\0");
	cr_expect_eq(sprintf(str_pf, format, c), ft_printf(format, c),
		"ft_printf(\"%s\", char c = \'\\0\') return a wrong value.", format);
	freopen("/dev/null", "a", stdout);
	setbuf(stdout, str_ft);
	cr_expect_arr_eq(str_pf, str_ft, GIANT_BUFF,
		"ft_printf(\"%s\", char c = \'\\0\') return a wrong output.", format);
}
