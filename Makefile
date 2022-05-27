# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 14:02:31 by frosa-ma          #+#    #+#              #
#    Updated: 2022/05/27 19:06:47 by frosa-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	= all clean fclean re bonus

NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
INC		= -I. -I libft/
MAKE	= make -s
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

OBJS	= ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${LIB} ${OBJS}
	@mv libft/${LIB} $@
	@ar -rcs $@ ${OBJS}
.c.o:
	@${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o} 

${LIB}:
	@${MAKE} -C libft/ && ${MAKE} clean -C libft/

bonus: all

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf ${NAME}

re: fclean all
