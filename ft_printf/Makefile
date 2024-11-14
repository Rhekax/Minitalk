# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 16:55:25 by mdursun           #+#    #+#              #
#    Updated: 2024/10/24 12:48:28 by mdursun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS =	-Wall	-Wextra	-Werror
AR = ar	rc
SRC = ft_printf.c ft_printf_utils.c
OBJ = ${SRC:%.c=%.o}

all : ${NAME}

${NAME}: ${OBJ}
	@${AR}	${NAME}	${OBJ}
	@echo	"${NAME} created"

%.o: %.c
	@${CC}	${CFLAGS}	-c	$<	-o	$@
	@echo	"$@ created"

clean:
	@rm	-rf	${OBJ}
	@echo	"clean done"

fclean: clean
	@rm	-rf	${NAME}
	@echo	"fclean done"

re: fclean all

.PHONY: all clean fclean re
