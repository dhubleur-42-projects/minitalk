# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 14:17:16 by dhubleur          #+#    #+#              #
#    Updated: 2021/12/05 20:48:54 by dhubleur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	+= 	$(addprefix list_functions/, \
						ft_lstadd_back.c \
						ft_lstadd_front.c \
						ft_lstclear.c \
						ft_lstdelone.c \
						ft_lstiter.c \
						ft_lstlast.c \
						ft_lstmap.c \
						ft_lstnew.c \
						ft_lstsize.c)
SRCS	+=	$(addprefix mem_functions/, \
						ft_bzero.c \
						ft_calloc.c \
						ft_memchr.c \
						ft_memcpy.c \
						ft_memmove.c \
						ft_memset.c)
SRCS	+=	$(addprefix put_functions/, \
						ft_putchar_fd.c \
						ft_putendl_fd.c \
						ft_putnbr_fd.c \
						ft_putstr_fd.c \
						ft_putnbr_hexa_fd.c)
SRCS	+=	$(addprefix str_functions/, \
						$(addprefix char_functions/, \
									ft_isalnum.c \
									ft_isalpha.c \
									ft_isascii.c \
									ft_isdigit.c \
									ft_isprint.c \
									ft_tolower.c \
									ft_toupper.c) \
						ft_atoi.c \
						ft_itoa.c \
						ft_split.c \
						ft_strchr.c \
						ft_strdup.c \
						ft_striteri.c \
						ft_strjoin.c \
						ft_strlcat.c \
						ft_strlcpy.c \
						ft_strlen.c \
						ft_strmapi.c \
						ft_strncmp.c \
						ft_strnstr.c \
						ft_strrchr.c \
						ft_strtrim.c \
						ft_substr.c)
SRCS	+=	get_next_line/get_next_line.c

OBJS	=	${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o:
				${CC} ${CFLAGS} -I . -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS}
				ar rc ${NAME} ${OBJS}
				ranlib ${NAME}

clean:
				rm -f ${OBJS}

fclean:		clean
				rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re 