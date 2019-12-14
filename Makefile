# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 07:02:44 by rotrojan          #+#    #+#              #
#    Updated: 2019/12/14 05:21:13 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF_DIR		=		../rendu/ft_printf00/

SRCS				=		test_percent_c.c
OBJS				=		${SRCS:.c=.o}
NAME				=		ft_printf_unit_tests

INC_CRITERION		=		-lcriterion
INC_FT_PRINTF		=		-L ${FT_PRINTF_DIR} -lftprintf

CC					=		clang
CFLAGS				=		-Wall -Wextra -Werror
MAKE				=		make
NORMINETTE			=		norminette

RM					=		rm -f

all					:		${NAME}

${NAME}				:		${OBJS}
	${NORMINETTE} ${FT_PRINTF_DIR}
	${MAKE} -C ${FT_PRINTF_DIR}
	${CC} ${CFLAGS} $< -o $@ ${INC_FT_PRINTF} ${INC_CRITERION}

%.o					:		%.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

tests				:
	./${NAME}

clean				:
	${MAKE} clean -C ${FT_PRINTF_DIR}
	${RM} ${OBJS}

fclean				:		clean
	${MAKE} fclean -C ${FT_PRINTF_DIR}
	${RM} ${NAME}

re					:		fclean all

.PHONY : all tests clean fclean re
