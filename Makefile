# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bycop <bycop@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 11:41:27 by bycop          #+#    #+#              #
#    Updated: 2021/03/12 13:08:02 by bycop         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_write.s \
		ft_read.s \
		ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_strdup.s 

OBJS = ${SRCS:.s=.o}

HEADER = libasm.h

NAME = libasm.a

CC = nasm

RM = rm -f

FLAGS = -f macho64

%.o:	%.s ${HEADER}
	${CC} ${FLAGS} $< -o ${<:.s=.o}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}

main:		${NAME}
			gcc main.c ${NAME} ${HEADER}

all:		${NAME}
			
clean:
			${RM} ${OBJS} ${OBJBONUS}

fclean:		clean
			${RM} ${NAME} a.out

re: fclean all

.PHONY: all clean fclean re