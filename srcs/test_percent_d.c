/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 09:52:05 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/23 01:10:33 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_ft_printf.h"

TestSuite(one_int, .init = init_seed_and_stdout);

Test(one_int, test00)
{
	char	*str;
	char	*format = "le nombre %d est affiche.";
	int		d = 2147483647;

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
	char	*format = "le nombre %d est affiche.";
	int		d = -2147483648;

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
	char	*format = "le nombre %d est affiche.";
	int		d = 0;

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
	char	*format = "le nombre %d est affiche.";
	int		d = RAND_POS_INT;

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
	char	*format = "le nombre %d est affiche.";
	int		d = RAND_NEG_INT;

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
	char	*format = "le nombre %.15d est affiche.";
	int		d = 0;

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
	char	*format = "le nombre %.15d est affiche.";
	int		d = 2147483647;

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
	char	*format = "le nombre %.15d est affiche.";
	int		d = -2147483648;

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
	char	*format = "le nombre %.15d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test09)
{
	char	*str;
	char	*format = "le nombre %.15d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test10)
{
	char	*str;
	char	*format = "le nombre %.1d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test11)
{
	char	*str;
	char	*format = "le nombre %.1d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test12)
{
	char	*str;
	char	*format = "le nombre %.1d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test13)
{
	char	*str;
	char	*format = "le nombre %.1d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test14)
{
	char	*str;
	char	*format = "le nombre %.1d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test15)
{
	char	*str;
	char	*format = "le nombre %15.1d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test16)
{
	char	*str;
	char	*format = "le nombre %15.1d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test17)
{
	char	*str;
	char	*format = "le nombre %15.1d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test18)
{
	char	*str;
	char	*format = "le nombre %15.1d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test19)
{
	char	*str;
	char	*format = "le nombre %15.1d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test20)
{
	char	*str;
	char	*format = "le nombre %1.51d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test21)
{
	char	*str;
	char	*format = "le nombre %5.51d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test22)
{
	char	*str;
	char	*format = "le nombre %5.51d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test23)
{
	char	*str;
	char	*format = "le nombre %1.51d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test24)
{
	char	*str;
	char	*format = "le nombre %1.51d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test25)
{
	char	*str;
	char	*format = "le nombre %0.0d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test26)
{
	char	*str;
	char	*format = "le nombre %0.0d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test27)
{
	char	*str;
	char	*format = "le nombre %0.0d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test28)
{
	char	*str;
	char	*format = "le nombre %0.0d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test29)
{
	char	*str;
	char	*format = "le nombre %0.0d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}


Test(one_int, test30)
{
	char	*str;
	char	*format = "le nombre %015d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test31)
{
	char	*str;
	char	*format = "le nombre %015d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test32)
{
	char	*str;
	char	*format = "le nombre %015d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}
Test(one_int, test33)
{
	char	*str;
	char	*format = "le nombre %015d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test34)
{
	char	*str;
	char	*format = "le nombre %015d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test35)
{
	char	*str;
	char	*format = "le nombre %0-14.6d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test36)
{
	char	*str;
	char	*format = "le nombre %0-14.6d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test37)
{
	char	*str;
	char	*format = "le nombre %0-14.6d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test38)
{
	char	*str;
	char	*format = "le nombre %0-14.6d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test39)
{
	char	*str;
	char	*format = "le nombre %0-14.6d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test40)
{
	char	*str;
	char	*format = "le nombre %-14d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test41)
{
	char	*str;
	char	*format = "le nombre %-14d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test42)
{
	char	*str;
	char	*format = "le nombre %-14d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test43)
{
	char	*str;
	char	*format = "le nombre %-14d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test44)
{
	char	*str;
	char	*format = "le nombre %-14d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test45)
{
	char	*str;
	char	*format = "le nombre %-14d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test46)
{
	char	*str;
	char	*format = "le nombre %-14d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test47)
{
	char	*str;
	char	*format = "le nombre %-14d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test48)
{
	char	*str;
	char	*format = "le nombre %-14d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test49)
{
	char	*str;
	char	*format = "le nombre %-14d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test50)
{
	char	*str;
	char	*format = "le nombre %0-14.6d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test51)
{
	char	*str;
	char	*format = "le nombre %0-14.6d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test52)
{
	char	*str;
	char	*format = "le nombre %0-14.6d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test53)
{
	char	*str;
	char	*format = "le nombre %0-14.6d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test54)
{
	char	*str;
	char	*format = "le nombre %0-14.6d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test55)
{
	char	*str;
	char	*format = "le nombre %-15.0d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test56)
{
	char	*str;
	char	*format = "le nombre %-15.0d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test57)
{
	char	*str;
	char	*format = "le nombre %-15.0d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test58)
{
	char	*str;
	char	*format = "le nombre %-15.0d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test59)
{
	char	*str;
	char	*format = "le nombre %-15.0d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test60)
{
	char	*str;
	char	*format = "le nombre %05000.d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test61)
{
	char	*str;
	char	*format = "le nombre %05000.d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test62)
{
	char	*str;
	char	*format = "le nombre %05000.d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test63)
{
	char	*str;
	char	*format = "le nombre %05000.d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_int, test64)
{
	char	*str;
	char	*format = "le nombre %05000.d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, d), ft_printf(format, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

TestSuite(one_asterisk, init_seed_and_stdout);

Test(one_asterisk, test00)
{
	char	*str;
	char	*format = "le nombre %*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test01)
{
	char	*str;
	char	*format = "le nombre %*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test02)
{
	char	*str;
	char	*format = "le nombre %*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test03)
{
	char	*str;
	char	*format = "le nombre %*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test04)
{
	char	*str;
	char	*format = "le nombre %*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test05)
{
	char	*str;
	char	*format = "le nombre %*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test06)
{
	char	*str;
	char	*format = "le nombre %*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test07)
{
	char	*str;
	char	*format = "le nombre %*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test08)
{
	char	*str;
	char	*format = "le nombre %*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test09)
{
	char	*str;
	char	*format = "le nombre %*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test10)
{
	char	*str;
	char	*format = "le nombre %*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test11)
{
	char	*str;
	char	*format = "le nombre %*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test12)
{
	char	*str;
	char	*format = "le nombre %*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test13)
{
	char	*str;
	char	*format = "le nombre %*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test14)
{
	char	*str;
	char	*format = "le nombre %*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test15)
{
	char	*str;
	char	*format = "le nombre %.*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test16)
{
	char	*str;
	char	*format = "le nombre %.*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test17)
{
	char	*str;
	char	*format = "le nombre %.*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test18)
{
	char	*str;
	char	*format = "le nombre %.*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test19)
{
	char	*str;
	char	*format = "le nombre %.*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test20)
{
	char	*str;
	char	*format = "le nombre %.*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test21)
{
	char	*str;
	char	*format = "le nombre %.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test22)
{
	char	*str;
	char	*format = "le nombre %.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test23)
{
	char	*str;
	char	*format = "le nombre %.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test24)
{
	char	*str;
	char	*format = "le nombre %.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test25)
{
	char	*str;
	char	*format = "le nombre %.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test26)
{
	char	*str;
	char	*format = "le nombre %.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test27)
{
	char	*str;
	char	*format = "le nombre %.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test28)
{
	char	*str;
	char	*format = "le nombre %.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test29)
{
	char	*str;
	char	*format = "le nombre %.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test30)
{
	char	*str;
	char	*format = "le nombre %-*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test31)
{
	char	*str;
	char	*format = "le nombre %-*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test32)
{
	char	*str;
	char	*format = "le nombre %-*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test33)
{
	char	*str;
	char	*format = "le nombre %-*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test34)
{
	char	*str;
	char	*format = "le nombre %-*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test35)
{
	char	*str;
	char	*format = "le nombre %-*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test36)
{
	char	*str;
	char	*format = "le nombre %-*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test37)
{
	char	*str;
	char	*format = "le nombre %-*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test38)
{
	char	*str;
	char	*format = "le nombre %-*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test39)
{
	char	*str;
	char	*format = "le nombre %-*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test40)
{
	char	*str;
	char	*format = "le nombre %-*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test41)
{
	char	*str;
	char	*format = "le nombre %-*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test42)
{
	char	*str;
	char	*format = "le nombre %-*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test43)
{
	char	*str;
	char	*format = "le nombre %-*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test44)
{
	char	*str;
	char	*format = "le nombre %-*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test45)
{
	char	*str;
	char	*format = "le nombre %0*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test46)
{
	char	*str;
	char	*format = "le nombre %0*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test47)
{
	char	*str;
	char	*format = "le nombre %0*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test48)
{
	char	*str;
	char	*format = "le nombre %0*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test49)
{
	char	*str;
	char	*format = "le nombre %0*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test50)
{
	char	*str;
	char	*format = "le nombre %0*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test51)
{
	char	*str;
	char	*format = "le nombre %0*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test52)
{
	char	*str;
	char	*format = "le nombre %0*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test53)
{
	char	*str;
	char	*format = "le nombre %0*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test54)
{
	char	*str;
	char	*format = "le nombre %0*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test55)
{
	char	*str;
	char	*format = "le nombre %0*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test56)
{
	char	*str;
	char	*format = "le nombre %0*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test57)
{
	char	*str;
	char	*format = "le nombre %0*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test58)
{
	char	*str;
	char	*format = "le nombre %0*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test59)
{
	char	*str;
	char	*format = "le nombre %0*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test60)
{
	char	*str;
	char	*format = "le nombre %-0*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test61)
{
	char	*str;
	char	*format = "le nombre %-0*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test62)
{
	char	*str;
	char	*format = "le nombre %-0*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test63)
{
	char	*str;
	char	*format = "le nombre %-0*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test64)
{
	char	*str;
	char	*format = "le nombre %-0*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test65)
{
	char	*str;
	char	*format = "le nombre %-0*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test66)
{
	char	*str;
	char	*format = "le nombre %-0*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test67)
{
	char	*str;
	char	*format = "le nombre %-0*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test68)
{
	char	*str;
	char	*format = "le nombre %-0*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test69)
{
	char	*str;
	char	*format = "le nombre %-0*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test70)
{
	char	*str;
	char	*format = "le nombre %-0*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test71)
{
	char	*str;
	char	*format = "le nombre %-0*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test72)
{
	char	*str;
	char	*format = "le nombre %-0*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test73)
{
	char	*str;
	char	*format = "le nombre %-0*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test74)
{
	char	*str;
	char	*format = "le nombre %-0*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test75)
{
	char	*str;
	char	*format = "le nombre %0.*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test76)
{
	char	*str;
	char	*format = "le nombre %0.*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test77)
{
	char	*str;
	char	*format = "le nombre %0.*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test78)
{
	char	*str;
	char	*format = "le nombre %0.*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test79)
{
	char	*str;
	char	*format = "le nombre %0.*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test80)
{
	char	*str;
	char	*format = "le nombre %0.*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test81)
{
	char	*str;
	char	*format = "le nombre %0.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test82)
{
	char	*str;
	char	*format = "le nombre %0.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test83)
{
	char	*str;
	char	*format = "le nombre %0.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test84)
{
	char	*str;
	char	*format = "le nombre %0.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test85)
{
	char	*str;
	char	*format = "le nombre %0.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test86)
{
	char	*str;
	char	*format = "le nombre %0.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test87)
{
	char	*str;
	char	*format = "le nombre %0.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test88)
{
	char	*str;
	char	*format = "le nombre %0.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test89)
{
	char	*str;
	char	*format = "le nombre %0.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test90)
{
	char	*str;
	char	*format = "le nombre %-0.*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test91)
{
	char	*str;
	char	*format = "le nombre %-0.*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test92)
{
	char	*str;
	char	*format = "le nombre %-0.*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test93)
{
	char	*str;
	char	*format = "le nombre %-0.*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test94)
{
	char	*str;
	char	*format = "le nombre %-0.*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test95)
{
	char	*str;
	char	*format = "le nombre %-0.*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test96)
{
	char	*str;
	char	*format = "le nombre %-0.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test97)
{
	char	*str;
	char	*format = "le nombre %-0.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test98)
{
	char	*str;
	char	*format = "le nombre %-0.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test99)
{
	char	*str;
	char	*format = "le nombre %-0.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test100)
{
	char	*str;
	char	*format = "le nombre %-0.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test101)
{
	char	*str;
	char	*format = "le nombre %-0.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test102)
{
	char	*str;
	char	*format = "le nombre %-0.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test103)
{
	char	*str;
	char	*format = "le nombre %-0.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test104)
{
	char	*str;
	char	*format = "le nombre %-0.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test105)
{
	char	*str;
	char	*format = "le nombre %-.*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test106)
{
	char	*str;
	char	*format = "le nombre %-.*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test107)
{
	char	*str;
	char	*format = "le nombre %-.*d est affiche.";
	int		d = RAND_NEG_INT;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test108)
{
	char	*str;
	char	*format = "le nombre %-.*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test109)
{
	char	*str;
	char	*format = "le nombre %-.*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test110)
{
	char	*str;
	char	*format = "le nombre %-.*d est affiche.";
	int		d = RAND_POS_INT;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test111)
{
	char	*str;
	char	*format = "le nombre %-.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test112)
{
	char	*str;
	char	*format = "le nombre %-.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test113)
{
	char	*str;
	char	*format = "le nombre %-.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test114)
{
	char	*str;
	char	*format = "le nombre %-.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test115)
{
	char	*str;
	char	*format = "le nombre %-.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test116)
{
	char	*str;
	char	*format = "le nombre %-.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test117)
{
	char	*str;
	char	*format = "le nombre %-.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 15, d), ft_printf(format, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test118)
{
	char	*str;
	char	*format = "le nombre %-.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, -15, d), ft_printf(format, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test119)
{
	char	*str;
	char	*format = "le nombre %-.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 0, d), ft_printf(format, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test120)
{
	char	*str;
	char	*format = "le nombre %*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 5000, d), ft_printf(format, 5000, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test121)
{
	char	*str;
	char	*format = "le nombre %.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 5000, d), ft_printf(format, 5000, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test122)
{
	char	*str;
	char	*format = "le nombre %*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, -5000, d), ft_printf(format, -5000, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test123)
{
	char	*str;
	char	*format = "le nombre %.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, -5000, d), ft_printf(format, -5000, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test124)
{
	char	*str;
	char	*format = "le nombre %*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 5000, d), ft_printf(format, 5000, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test125)
{
	char	*str;
	char	*format = "le nombre %.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 5000, d), ft_printf(format, 5000, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test126)
{
	char	*str;
	char	*format = "le nombre %*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, -5000, d), ft_printf(format, -5000, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(one_asterisk, test127)
{
	char	*str;
	char	*format = "le nombre %.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, -5000, d), ft_printf(format, -5000, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

TestSuite(two_asterisks, .init = init_seed_and_stdout);

Test(two_asterisks, test00)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 15, 15, d), ft_printf(format, 15, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test01)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, -15, 15, d), ft_printf(format, -15, 15 , d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test02)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 15, -15, d), ft_printf(format, 15, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test03)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 0, 15, d), ft_printf(format, 0, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test04)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 15, 0, d), ft_printf(format, 15, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test05)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 0, -15, d), ft_printf(format, 0, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test06)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, -15, 0, d), ft_printf(format, -15, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test07)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, 150000, 15000, d), ft_printf(format, 150000, 15000, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test08)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = 2147483647;

	cr_expect_eq(asprintf(&str, format, -15000, -15000000, d), ft_printf(format, -15000, -15000000, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test09)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 15, 15, d), ft_printf(format, 15, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test10)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, -15, 15, d), ft_printf(format, -15, 15 , d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test11)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 15, -15, d), ft_printf(format, 15, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test12)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 0, 15, d), ft_printf(format, 0, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test13)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 15, 0, d), ft_printf(format, 15, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test14)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 0, -15, d), ft_printf(format, 0, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test15)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, -15, 0, d), ft_printf(format, -15, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test16)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = -2147483648;

	cr_expect_eq(asprintf(&str, format, 8000000, 15000, d), ft_printf(format, 8000000, 15000, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test17)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, -15000, -15000000, d), ft_printf(format, -15000, -15000000, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}
Test(two_asterisks, test18)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 15, 15, d), ft_printf(format, 15, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test19)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, -15, 15, d), ft_printf(format, -15, 15 , d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test20)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 15, -15, d), ft_printf(format, 15, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test21)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 0, 15, d), ft_printf(format, 0, 15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test22)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 15, 0, d), ft_printf(format, 15, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test23)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 0, -15, d), ft_printf(format, 0, -15, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test24)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, -15, 0, d), ft_printf(format, -15, 0, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test25)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, 150000, 15000, d), ft_printf(format, 150000, 15000, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}

Test(two_asterisks, test26)
{
	char	*str;
	char	*format = "le nombre %*.*d est affiche.";
	int		d = 0;

	cr_expect_eq(asprintf(&str, format, -15000, -15000000, d), ft_printf(format, -15000, -15000000, d),
		"ft_printf(\"%s\", int = \'%d\') return a wrong value.", format, d);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", int = \'%d\') return a wrong output.", format, d);
	free(str);
}
