/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 09:52:05 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/19 20:53:38 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_ft_printf.h"

TestSuite(one_int, .init = cr_redirect_stdout);

Test(one_int, test00)
{
	char	*str;
	char	*format = "le nombre %d est afiche.";
	int		d = RAND_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test01)
{
	char	*str;
	char	*format = "le nombre %14d est afiche.";
	int		d = RAND_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test02)
{
	char	*str;
	char	*format = "le nombre %d est afiche.";
	int		d = RAND_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test03)
{
	char	*str;
	char	*format = "le nombre %.12d est afiche.";
	int		d = RAND_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test04)
{
	char	*str;
	char	*format = "le nombre %6.14d est afiche.";
	int		d = RAND_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test05)
{
	char	*str;
	char	*format = "le nombre %14.6d est afiche.";
	int		d = RAND_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test06)
{
	char	*str;
	char	*format = "le nombre %014d est afiche.";
	int		d = RAND_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test07)
{
	char	*str;
	char	*format = "le nombre %-14d est afiche.";
	int		d = RAND_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test08)
{
	char	*str;
	char	*format = "le nombre %0-14.6d est afiche.";
	int		d = RAND_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}
/*
Test(one_int, test08)
{
	char	*str;
	char	*format = "le nombre %d est afiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test08)
{
	char	*str;
	char	*format = "le nombre %0-14.6d est afiche.";
	int		d = RAND_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test08)
{
	char	*str;
	char	*format = "le nombre %0-14.6d est afiche.";
	int		d = RAND_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test08)
{
	char	*str;
	char	*format = "le nombre %0-14.6d est afiche.";
	int		d = RAND_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test08)
{
	char	*str;
	char	*format = "le nombre %0-14.6d est afiche.";
	int		d = RAND_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}
*/
