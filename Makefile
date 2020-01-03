# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 07:02:44 by rotrojan          #+#    #+#              #
#    Updated: 2019/12/22 16:05:22 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF_DIR		=		../ft_printf/
FT_PRINTF_INC_DIR		=	../ft_printf/include

_SRCS				=		test_percent_s.c	\
							test_percent_c.c	\
							test_percent_d.c	\
							test_percent_i.c
SRCS_DIR			=		./srcs/
SRCS				=		$(addprefix ${SRCS_DIR}, ${_SRCS})
OBJS				=		${SRCS:.c=.o}
NAME				=		ft_printf_unit_tests

INC_CRITERION		=		-lcriterion
INC_FT_PRINTF		=		-I${FT_PRINTF_INC_DIR} -L${FT_PRINTF_DIR} -lftprintf
INC_DIR				=       ./include/
INC					=		-I${INC_DIR}

CFLAGS				=		-Wall -Wextra -Werror

CC					=		clang
NORMINETTE			=		norminette
RM					=		rm -f

all					:		${NAME}

${NAME}				:		${OBJS} | build
	${CC} ${CFLAGS} $^ ${INC_FT_PRINTF} ${INC_CRITERION} -o $@

%.o					:		%.c
	${CC} ${CFLAGS} -D_GNU_SOURCE ${INC} -I${FT_PRINTF_INC_DIR} -c $< -o ${<:.c=.o}

build				:
	@${MAKE} -C ${FT_PRINTF_DIR}

test				:	all
	./${NAME}

details				: ${NAME} build
	./${NAME} --verbose

norm				:
	${NORMINETTE} ${FT_PRINTF_DIR}

clean				:
	@${MAKE} clean -C ${FT_PRINTF_DIR}
	${RM} ${OBJS}

fclean				:		clean
	@${MAKE} fclean -C ${FT_PRINTF_DIR}
	${RM} ${NAME}

re					:		fclean all

.PHONY : all test clean fclean re build norm
