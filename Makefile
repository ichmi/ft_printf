# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 14:02:31 by frosa-ma          #+#    #+#              #
#    Updated: 2022/05/25 21:45:50 by frosa-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	= all clean fclean re bonus

NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
MAKE	= make -s
LIB		= libft.a
M_SRCS	= \
		ft_printf.c

B_SRCS	= \
		ft_printf_bonus.c \
		ft_printf_utils_bonus.c \
		dot_bonus.c \
		dot_dispatcher_bonus.c \
		dot_spec_bonus.c \
		minus_bonus.c \
		minus_dispatcher_bonus.c \
		minus_spec_bonus.c \
		space_bonus.c \
		space_dispatcher_bonus.c \
		space_spec_bonus.c \
		zero_bonus.c \
		zero_dispatcher_bonus.c \
		zero_spec_bonus.c \
		sharp_bonus.c \
		plus_bonus.c

M_OBJS	= ${M_SRCS:.c=.o}
B_OBJS	= ${B_SRCS:.c=.o}

all: ${NAME}

${NAME}: ${LIB} ${M_OBJS}
	@cp inc/libft/$< $@ && rm inc/libft/$<
	@ar -rcs $@ ${M_OBJS}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I inc/ -I inc/libft/

${LIB}:
	@${MAKE} -C inc/libft/ && ${MAKE} clean -C inc/libft/

bonus: ${LIB} ${B_OBJS}
	@cp inc/libft/${LIB} ${NAME} && rm inc/libft/${LIB}
	@ar -rcs ${NAME} ${B_OBJS}

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf ${NAME}

re: fclean all
