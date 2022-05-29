# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 14:02:31 by frosa-ma          #+#    #+#              #
#    Updated: 2022/05/29 02:58:22 by frosa-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	= all clean fclean re bonus

NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
INC		= -I. -I libft/
MAKE	= make
LIB		= libft.a
SRCS	= \
	ft_printf.c \
	ft_printf_utils.c \
	dot_disp.c \
	dot_wr.c \
	dot.c \
	minus_disp.c \
	minus_wr.c \
	minus.c \
	space_disp.c \
	space_wr.c \
	space.c \
	zero_disp.c \
	zero_wr.c \
	zero.c \
	sharp.c \
	plus.c

OBJDIR	= obj
OBJS	= ${SRCS:%.c=%.o}

all: ${NAME}

${NAME}: ${OBJS}
	cp libft/${LIB} $@
	ar -rcs $@ $^

${OBJS}: | ${LIB}

.c.o:
	${CC} ${CFLAGS} ${INC} -c $< -o ${<:%.c=%.o}

${LIB}:
	${MAKE} -C libft/

bonus: all

clean:
	${MAKE} fclean -C libft/
	rm -rf *.o

fclean: clean
	rm -rf ${NAME}

re: fclean all
