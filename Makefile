# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 07:02:44 by rotrojan          #+#    #+#              #
#    Updated: 2019/12/13 08:04:29 by rotrojan         ###   ########.fr        #
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

RM					=		rm -f

all					:		${NAME}

${NAME}				:		${OBJS}
	${CC} ${CFLAGS} $< -o $@ ${INC_FT_PRINTF} ${INC_CRITERION}

%.o					:		%.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

tests				:
	./${NAME}

clean				:
	${RM} ${OBJS}

fclean				:		clean
	${RM} ${NAME}

re					:		fclean all

.PHONY : all tests clean fclean re
