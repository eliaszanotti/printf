# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 18:13:50 by ezanotti          #+#    #+#              #
#    Updated: 2022/11/21 19:09:57 by ezanotti         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_printf_utils.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
AR		= ar rcs

all :		${NAME}

%.o: %.c	ft_printf.h Makefile
			${CC} ${CFLAGS} -I . -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME}

re :		fclean all
