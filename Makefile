# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 10:05:58 by dhubleur          #+#    #+#              #
#    Updated: 2022/01/05 10:30:02 by dhubleur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_SRCS	=	$(addprefix srcs_client/, \
					client_main.c)
CLIENT_OBJS	=	${CLIENT_SRCS:.c=.o}

SERVER_SRCS	=	$(addprefix srcs_server/, \
					server_main.c \
					utils.c \
					dynamic_buffer.c)
SERVER_OBJS	=	${SERVER_SRCS:.c=.o}

INCL	=	-I./includes -I./libft -I./ft_printf 

CLIENT_NAME	=	client
SERVER_NAME	=	server

CC		=	gcc
CFLAGS	=	-g3
CFLAGS += -Wall -Wextra -Werror
#CFLAGS += -fsanitize=address

RM		=	rm -f

LIBFT		=	libft/libft.a
FT_PRINTF	=	ft_printf/libftprintf.a

.c.o:
				${CC} ${CFLAGS} ${INCL} -c $< -o ${<:.c=.o}

bonus:		all
all:		${CLIENT_NAME} ${SERVER_NAME}

$(CLIENT_NAME):	${CLIENT_OBJS} ${LIBFT} ${FT_PRINTF}
				${CC} -o ${CLIENT_NAME} ${CLIENT_OBJS} ${LIBFT} ${FT_PRINTF}

$(SERVER_NAME):	${SERVER_OBJS} ${LIBFT} ${FT_PRINTF}
				${CC} -o ${SERVER_NAME} ${SERVER_OBJS} ${LIBFT} ${FT_PRINTF}

$(LIBFT):
				$(MAKE) -C libft all
$(FT_PRINTF):
				$(MAKE) -C ft_printf all

clean:
				${RM} ${CLIENT_OBJS} ${SERVER_OBJS}

fclean:		clean
				${RM} ${CLIENT_NAME} ${SERVER_NAME}

fcleanlib:	fclean
				$(MAKE) -C libft fclean
				$(MAKE) -C ft_printf fclean

re:			fclean all

.PHONY:		all clean fclean re fcleanlib
