# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 14:02:31 by frosa-ma          #+#    #+#              #
#    Updated: 2022/05/18 17:01:58 by frosa-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	= all clean fclean re

NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
MAKE	= make -s
LIB		= libft.a

all: ${NAME}

${NAME}: ${LIB} ft_printf.o
	@cp libft/$< $@ && rm libft/$<
	@ar -rc $@ ft_printf.o

.c.o:
	@${CC} ${CFLAGS} -c ft_printf.c

${LIB}:
	@${MAKE} -C libft/ && ${MAKE} clean -C libft/

clean:
	@rm *.o

fclean: clean
	@rm ${NAME}

re: fclean all
