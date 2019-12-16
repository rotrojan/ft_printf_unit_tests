/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:33:19 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/16 14:52:49 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_ft_printf.h"

TestSuite(one_str, .init = init_seed_and_stdout);

Test(one_str, test00)
{
	char	*str;
	char	*format = "la string str : %s ...";
	char	*s = "maxi yolooooo ! :)";

	cr_expect_eq(asprintf(&str, format, s), ft_printf(format, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str, test01)
{
	char	*str;
	char	*format = "la string str : %14s ...";
	char	*s = "maxi yolooooo ! :)";

	cr_expect_eq(asprintf(&str, format, s), ft_printf(format, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str, test02)
{
	char	*str;
	char	*format = "la string str : %-23s ...";
	char	*s = "maxi yolooooo ! :)";

	cr_expect_eq(asprintf(&str, format, s), ft_printf(format, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str, test03)
{
	char	*str;
	char	*format = "la string str : %027s ...";
	char	*s = "maxi yolooooo ! :)";

	cr_expect_eq(asprintf(&str, format, s), ft_printf(format, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str, test04)
{
	char	*str;
	char	*format = "la string str : %052-s ...";
	char	*s = "maxi yolooooo ! :)";

	cr_expect_eq(asprintf(&str, format, s), ft_printf(format, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str, test05)
{
	char	*str;
	char	*format = "la string str : %05000s ...";
	char	*s = "maxi yolooooo ! :)";

	cr_expect_eq(asprintf(&str, format, s), ft_printf(format, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str, test06)
{
	char	*str;
	char	*format = "la string str : %05000.s ...";
	char	*s = "maxi yolooooo ! :)";

	cr_expect_eq(asprintf(&str, format, s), ft_printf(format, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str, test07)
{
	char	*str;
	char	*format = "la string str : %0-.s ...";
	char	*s = "maxi yolooooo ! :)";

	cr_expect_eq(asprintf(&str, format, s), ft_printf(format, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str, test08)
{
	char	*str;
	char	*format = "la string str : %.3s ...";
	char	*s = "maxi yolooooo ! :)";

	cr_expect_eq(asprintf(&str, format, s), ft_printf(format, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str, test09)
{
	char	*str;
	char	*format = "la string str : %.0s ...";
	char	*s = "maxi yolooooo ! :)";

	cr_expect_eq(asprintf(&str, format, s), ft_printf(format, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str, test10)
{
	char	*str;
	char	*format = "la string str : %.5000s ...";
	char	*s = "maxi yolooooo ! :)";

	cr_expect_eq(asprintf(&str, format, s), ft_printf(format, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

TestSuite(one_str_one_asterisks, .init = init_seed_and_stdout);

Test(one_str_one_asterisks, test00)
{
	char	*str;
	char	*format = "le char %*s est un arobase";
	char	*s = "pour un max de yolo XD";
	int		ast = 42;

	cr_expect_eq(asprintf(&str, format, ast, s), ft_printf(format, ast, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str_one_asterisks, test01)
{
	char	*str;
	char	*format = "le char %*s est un arobase";
	char	*s = "pour un max de yolo XD";
	int		ast = -42;

	cr_expect_eq(asprintf(&str, format, ast, s), ft_printf(format, ast, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str_one_asterisks, test02)
{
	char	*str;
	char	*format = "le char %*s est un arobase";
	char	*s = "pour un max de yolo XD";
	int		ast = 0;

	cr_expect_eq(asprintf(&str, format, ast, s), ft_printf(format, ast, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str_one_asterisks, test03)
{
	char	*str;
	char	*format = "le char %.*s est un arobase";
	char	*s = "pour un max de yolo XD";
	int		ast = 42;

	cr_expect_eq(asprintf(&str, format, ast, s), ft_printf(format, ast, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str_one_asterisks, test04)
{
	char	*str;
	char	*format = "le char %.*s est un arobase";
	char	*s = "pour un max de yolo XD";
	int		ast = -42;

	cr_expect_eq(asprintf(&str, format, ast, s), ft_printf(format, ast, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str_one_asterisks, test05)
{
	char	*str;
	char	*format = "le char %.*s est un arobase";
	char	*s = "pour un max de yolo XD";
	int		ast = 0;

	cr_expect_eq(asprintf(&str, format, ast, s), ft_printf(format, ast, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str_one_asterisks, test06)
{
	char	*str;
	char	*format = "le char %-.*s est un arobase";
	char	*s = "pour un max de yolo XD";
	int		ast = 21;

	cr_expect_eq(asprintf(&str, format, ast, s), ft_printf(format, ast, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str_one_asterisks, test07)
{
	char	*str;
	char	*format = "le char %0*s est un arobase";
	char	*s = "pour un max de yolo XD";
	int		ast = 60;

	cr_expect_eq(asprintf(&str, format, ast, s), ft_printf(format, ast, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str_one_asterisks, test08)
{
	char	*str;
	char	*format = "le char %0-*c est un arobase";
	char	*s = "pour un max de yolo XD";
	int		ast = 0;

	cr_expect_eq(asprintf(&str, format, ast, s), ft_printf(format, ast, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

TestSuite(one_str_two_asterisks, .init = init_seed_and_stdout);

Test(one_str_two_asterisks, test00)
{
	char	*str;
	char	*format = "le char %*.*s est un arobase";
	char	*s = "pour un max de yolo XD";
	int		ast1 = 10;
	int		ast2 = 20;

	cr_expect_eq(asprintf(&str, format, ast1, ast2, s), ft_printf(format, ast1, ast2, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str_two_asterisks, test01)
{
	char	*str;
	char	*format = "le char %*.*s est un arobase";
	char	*s = "pour un max de yolo XD";
	int		ast1 = -10;
	int		ast2 = -20;

	cr_expect_eq(asprintf(&str, format, ast1, ast2, s), ft_printf(format, ast1, ast2, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str_two_asterisks, test02)
{
	char	*str;
	char	*format = "le char %-*.*s est un arobase";
	char	*s = "pour un max de yolo XD";
	int		ast1 = -10;
	int		ast2 = 20;

	cr_expect_eq(asprintf(&str, format, ast1, ast2, s), ft_printf(format, ast1, ast2, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str_two_asterisks, test03)
{
	char	*str;
	char	*format = "le char %0*.-*s est un arobase";
	char	*s = "pour un max de yolo XD";
	int		ast1 = 0;
	int		ast2 = 0;

	cr_expect_eq(asprintf(&str, format, ast1, ast2, s), ft_printf(format, ast1, ast2, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

Test(one_str_two_asterisks, test04)
{
	char	*str;
	char	*format = "le char %*-.*s est un arobase";
	char	*s = "pour un max de yolo XD";
	int		ast1 = -10;
	int		ast2 = -20;

	cr_expect_eq(asprintf(&str, format, ast1, ast2, s), ft_printf(format, ast1, ast2, s),
		"ft_printf(\"%s\", str = \'%s\') return a wrong value.", format, s);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", str = \'%s\') return a wrong output.", format, s);
	free(str);
}

TestSuite(two_str, .init = init_seed_and_stdout);

Test(two_str, test00)
{
	char	*str;
	char	*format = "le char %s est un arobase et le %s est random aussi.";
	char	*s1 = "yolo";
	char	*s2 = "swag";

	cr_expect_eq(asprintf(&str, format, s1, s2), ft_printf(format, s1, s2),
		"ft_printf(\"%s\", char s1 = \'%s\' char s2 = \'%s\') return a wrong value.", format, s1, s2);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char s1 = \'%s\', char s2 = \'%s\') return a wrong output.", format, s1, s2);
	free(str);
}

Test(two_str, test01)
{
	char	*str;
	char	*format = "le char %14s est un arobase et le %.34s est random aussi.";
	char	*s1 = "yolo";
	char	*s2 = "swag";

	cr_expect_eq(asprintf(&str, format, s1, s2), ft_printf(format, s1, s2),
		"ft_printf(\"%s\", char s1 = \'%s\' char s2 = \'%s\') return a wrong value.", format, s1, s2);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char s1 = \'%s\', char s2 = \'%s\') return a wrong output.", format, s1, s2);
	free(str);
}

Test(two_str, test02)
{
	char	*str;
	char	*format = "le char %032s est un arobase et le %7654-s est random aussi.";
	char	*s1 = "yolo";
	char	*s2 = "swag";

	cr_expect_eq(asprintf(&str, format, s1, s2), ft_printf(format, s1, s2),
		"ft_printf(\"%s\", char s1 = \'%s\' char s2 = \'%s\') return a wrong value.", format, s1, s2);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char s1 = \'%s\', char s2 = \'%s\') return a wrong output.", format, s1, s2);
	free(str);
}

Test(two_str, test03)
{
	char	*str;
	char	*format = "le char %s est un arobase et le %s est random aussi.";
	char	*s1 = "yolo";
	char	*s2 = "swag";

	cr_expect_eq(asprintf(&str, format, s1, s2), ft_printf(format, s1, s2),
		"ft_printf(\"%s\", char s1 = \'%s\' char s2 = \'%s\') return a wrong value.", format, s1, s2);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char s1 = \'%s\', char s2 = \'%s\') return a wrong output.", format, s1, s2);
	free(str);
}

Test(two_str, test04)
{
	char	*str;
	char	*format = "le char %-0.s est un arobase et le %-54s est random aussi.";
	char	*s1 = "yolo";
	char	*s2 = "swag";

	cr_expect_eq(asprintf(&str, format, s1, s2), ft_printf(format, s1, s2),
		"ft_printf(\"%s\", char s1 = \'%s\' char s2 = \'%s\') return a wrong value.", format, s1, s2);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char s1 = \'%s\', char s2 = \'%s\') return a wrong output.", format, s1, s2);
	free(str);
}

Test(two_str, test05)
{
	char	*str;
	char	*format = "le char %*s est un arobase et le %*s est random aussi.";
	char	*s1 = "yolo";
	char	*s2 = "swag";

	cr_expect_eq(asprintf(&str, format, -32, s1, -43, s2), ft_printf(format, -32, s1, -43, s2),
		"ft_printf(\"%s\", char s1 = \'%s\' char s2 = \'%s\') return a wrong value.", format, s1, s2);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char s1 = \'%s\', char s2 = \'%s\') return a wrong output.", format, s1, s2);
	free(str);
}

Test(two_str, test06)
{
	char	*str;
	char	*format = "le char %*.*s est un arobase et le %*.*s est random aussi.";
	char	*s1 = "yolo";
	char	*s2 = "swag";

	cr_expect_eq(asprintf(&str, format, 32, 65, s1, 12, 32, s2), ft_printf(format, 32, 65, s1, 12, 32, s2),
		"ft_printf(\"%s\", char s1 = \'%s\' char s2 = \'%s\') return a wrong value.", format, s1, s2);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char s1 = \'%s\', char s2 = \'%s\') return a wrong output.", format, s1, s2);
	free(str);
}
