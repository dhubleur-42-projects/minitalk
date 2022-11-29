# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 09:41:48 by dhubleur          #+#    #+#              #
#    Updated: 2021/12/12 12:53:59 by dhubleur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 			=	ft_printf.c \
					conversions/convert_char.c \
					conversions/convert_str.c \
					conversions/convert_ptr.c \
					conversions/convert_dbl.c \
					conversions/convert_int.c \
					conversions/convert_uint.c \
					conversions/convert_hex.c \
					conversions/convert_hex_cap.c \
					conversions/convert.c \
					put_functions/put_nbr.c \
					put_functions/put_strs.c \
					flags/flags_util.c

OBJS		=	${SRCS:.c=.o}
INCL		=	./.

NAME		=	libftprintf.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

.c.o:
				${CC} ${CFLAGS} -I ${INCL} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS}
				ar rc ${NAME} ${OBJS}
				ranlib ${NAME}

clean:
				rm -f ${OBJS}

fclean:		clean
				rm -f ${NAME}

re:			fclean all

.PHONY:			all clean fclean re
			