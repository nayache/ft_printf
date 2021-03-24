# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nayache <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 19:34:36 by nayache           #+#    #+#              #
#    Updated: 2019/11/27 15:00:37 by nayache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CFLAGS		= -Wall -Wextra -Werror

SRCS		= ft_printf.c utils.c utils2.c utils3.c utils4.c utils5.c utils6.c	

OBJS		= ${SRCS:.c=.o}

CC			= gcc

RM			= rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) :	${OBJS} 
	ar rc ${NAME} ${OBJS}

all :		${NAME}

clean :
		${RM} ${OBJS}

fclean :	clean
		${RM} ${NAME}

re :		fclean all
