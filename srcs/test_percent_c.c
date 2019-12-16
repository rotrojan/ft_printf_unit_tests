/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 04:21:09 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/16 11:46:36 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_ft_printf.h"

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
	char	c = RAND_CHAR;

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
	char	c = RAND_CHAR;

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
	char	c = RAND_CHAR;

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
	char	c = RAND_CHAR;

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
	char	c = RAND_CHAR;

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
	char	c = RAND_CHAR;

	cr_expect_eq(asprintf(&str, format, c), ft_printf(format, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}

Test(one_char, test06)
{
	char	*str;
	char	*format = "le char %05000.c est un arobase";
	char	c = RAND_CHAR;

	cr_expect_eq(asprintf(&str, format, c), ft_printf(format, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}

Test(one_char, test07)
{
	char	*str;
	char	*format = "le char %0-.c est un arobase";
	char	c = RAND_CHAR;

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
	cr_expect_eq(ret_pf, ret_ft,
		"ft_printf(\"%s\", char c = \'\\0\') return a wrong value.", format);
	cr_expect_arr_eq(pf_buf, ft_buf, ret_pf,
		"ft_printf(\"%s\", char c = \'\\0\') return a wrong output.", format);
	free(pf_buf);
	free(ft_buf);
}

TestSuite(one_char_one_asterisk, .init = init_seed_and_stdout);

Test(one_char_one_asterisk, test00)
{
	char	*str;
	char	*format = "le char %*c est un arobase";
	char	c = RAND_CHAR;
	int		ast = 42;

	cr_expect_eq(asprintf(&str, format, ast, c), ft_printf(format, ast, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}

Test(one_char_one_asterisk, test01)
{
	char	*str;
	char	*format = "le char %*c est un arobase";
	char	c = RAND_CHAR;
	int		ast = -42;

	cr_expect_eq(asprintf(&str, format, ast, c), ft_printf(format, ast, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}

Test(one_char_one_asterisk, test02)
{
	char	*str;
	char	*format = "le char %*c est un arobase";
	char	c = RAND_CHAR;
	int		ast = 0;

	cr_expect_eq(asprintf(&str, format, ast, c), ft_printf(format, ast, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}

Test(one_char_one_asterisk, test03)
{
	char	*str;
	char	*format = "le char %-.*c est un arobase";
	char	c = RAND_CHAR;
	int		ast = 21;

	cr_expect_eq(asprintf(&str, format, ast, c), ft_printf(format, ast, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}

Test(one_char_one_asterisk, test04)
{
	char	*str;
	char	*format = "le char %0*c est un arobase";
	char	c = RAND_CHAR;
	int		ast = 60;

	cr_expect_eq(asprintf(&str, format, ast, c), ft_printf(format, ast, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}

Test(one_char_one_asterisk, test05)
{
	char	*str;
	char	*format = "le char %0-*c est un arobase";
	char	c = RAND_CHAR;
	int		ast = 0;

	cr_expect_eq(asprintf(&str, format, ast, c), ft_printf(format, ast, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}

TestSuite(one_char_two_asterisks, .init = init_seed_and_stdout);

Test(one_char_two_asterisks, test00)
{
	char	*str;
	char	*format = "le char %*.*c est un arobase";
	char	c = RAND_CHAR;
	int		ast1 = 10;
	int		ast2 = 20;

	cr_expect_eq(asprintf(&str, format, ast1, ast2, c), ft_printf(format, ast1, ast2, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}

Test(one_char_two_asterisks, test01)
{
	char	*str;
	char	*format = "le char %*.*c est un arobase";
	char	c = RAND_CHAR;
	int		ast1 = -10;
	int		ast2 = -20;

	cr_expect_eq(asprintf(&str, format, ast1, ast2, c), ft_printf(format, ast1, ast2, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}

Test(one_char_two_asterisks, test02)
{
	char	*str;
	char	*format = "le char %-*.*c est un arobase";
	char	c = RAND_CHAR;
	int		ast1 = -10;
	int		ast2 = 20;

	cr_expect_eq(asprintf(&str, format, ast1, ast2, c), ft_printf(format, ast1, ast2, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}

Test(one_char_two_asterisks, test03)
{
	char	*str;
	char	*format = "le char %0*.-*c est un arobase";
	char	c = RAND_CHAR;
	int		ast1 = 0;
	int		ast2 = 0;

	cr_expect_eq(asprintf(&str, format, ast1, ast2, c), ft_printf(format, ast1, ast2, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}

Test(one_char_two_asterisks, test04)
{
	char	*str;
	char	*format = "le char %*-.*c est un arobase";
	char	c = RAND_CHAR;
	int		ast1 = -10;
	int		ast2 = -20;

	cr_expect_eq(asprintf(&str, format, ast1, ast2, c), ft_printf(format, ast1, ast2, c),
		"ft_printf(\"%s\", char c = \'%c\') return a wrong value.", format, c);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
	"ft_printf(\"%s\", char c = \'%c\') return a wrong output.", format, c);
	free(str);
}

TestSuite(two_chars, .init = init_seed_and_stdout);

Test(two_chars, test00)
{
	char	*str;
	char	*format = "le char %c est un arobase et le %c est random aussi.";
	char	c1 = RAND_CHAR;
	char	c2 = RAND_CHAR;

	cr_expect_eq(asprintf(&str, format, c1, c2), ft_printf(format, c1, c2),
		"ft_printf(\"%s\", char c1 = \'%c\' char c2 = \'%c\') return a wrong value.", format, c1, c2);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char c1 = \'%c\', char c2 = \'%c\') return a wrong output.", format, c1, c2);
	free(str);
}

Test(two_chars, test01)
{
	char	*str;
	char	*format = "le char %14c est un arobase et le %.34c est random aussi.";
	char	c1 = RAND_CHAR;
	char	c2 = RAND_CHAR;

	cr_expect_eq(asprintf(&str, format, c1, c2), ft_printf(format, c1, c2),
		"ft_printf(\"%s\", char c1 = \'%c\' char c2 = \'%c\') return a wrong value.", format, c1, c2);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char c1 = \'%c\', char c2 = \'%c\') return a wrong output.", format, c1, c2);
	free(str);
}

Test(two_chars, test02)
{
	char	*str;
	char	*format = "le char %032c est un arobase et le %7654-c est random aussi.";
	char	c1 = RAND_CHAR;
	char	c2 = RAND_CHAR;

	cr_expect_eq(asprintf(&str, format, c1, c2), ft_printf(format, c1, c2),
		"ft_printf(\"%s\", char c1 = \'%c\' char c2 = \'%c\') return a wrong value.", format, c1, c2);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char c1 = \'%c\', char c2 = \'%c\') return a wrong output.", format, c1, c2);
	free(str);
}

Test(two_chars, test03)
{
	char	*str;
	char	*format = "le char %c est un arobase et le %c est random aussi.";
	char	c1 = RAND_CHAR;
	char	c2 = RAND_CHAR;

	cr_expect_eq(asprintf(&str, format, c1, c2), ft_printf(format, c1, c2),
		"ft_printf(\"%s\", char c1 = \'%c\' char c2 = \'%c\') return a wrong value.", format, c1, c2);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char c1 = \'%c\', char c2 = \'%c\') return a wrong output.", format, c1, c2);
	free(str);
}

Test(two_chars, test04)
{
	char	*str;
	char	*format = "le char %-0.c est un arobase et le %-54c est random aussi.";
	char	c1 = RAND_CHAR;
	char	c2 = RAND_CHAR;

	cr_expect_eq(asprintf(&str, format, c1, c2), ft_printf(format, c1, c2),
		"ft_printf(\"%s\", char c1 = \'%c\' char c2 = \'%c\') return a wrong value.", format, c1, c2);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char c1 = \'%c\', char c2 = \'%c\') return a wrong output.", format, c1, c2);
	free(str);
}

Test(two_chars, test05)
{
	char	*str;
	char	*format = "le char %*c est un arobase et le %*c est random aussi.";
	char	c1 = RAND_CHAR;
	char	c2 = RAND_CHAR;

	cr_expect_eq(asprintf(&str, format, -32, c1, -43, c2), ft_printf(format, -32, c1, -43, c2),
		"ft_printf(\"%s\", char c1 = \'%c\' char c2 = \'%c\') return a wrong value.", format, c1, c2);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char c1 = \'%c\', char c2 = \'%c\') return a wrong output.", format, c1, c2);
	free(str);
}

Test(two_chars, test06)
{
	char	*str;
	char	*format = "le char %*.*c est un arobase et le %*.*c est random aussi.";
	char	c1 = RAND_CHAR;
	char	c2 = RAND_CHAR;

	cr_expect_eq(asprintf(&str, format, 32, 65, c1, 12, 32, c2), ft_printf(format, 32, 65, c1, 12, 32, c2),
		"ft_printf(\"%s\", char c1 = \'%c\' char c2 = \'%c\') return a wrong value.", format, c1, c2);
	fflush(stdout);
	cr_expect_stdout_eq_str(str,
		"ft_printf(\"%s\", char c1 = \'%c\', char c2 = \'%c\') return a wrong output.", format, c1, c2);
	free(str);
}
