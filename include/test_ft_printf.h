/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 11:44:51 by rotrojan          #+#    #+#             */
/*   Updated: 2019/12/18 10:16:41 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_FT_PRINTF_H
# define TEST_FT_PRINTF_H
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include "../rendu/ft_printf00/include/ft_printf.h"
#define MIN_CHAR 1
#define MAX_CHAR 127
#define RAND_INT (rand() % (MAX_INT - MIN_INT + 1)) + MIN_INT
#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define RAND_CHAR (rand() % (MAX_CHAR - MIN_CHAR + 1)) + MIN_CHAR
#define GIANT_BUFF	6384
#define FMT_BUFF	512

void	init_seed_and_stdout(void);

#endif
