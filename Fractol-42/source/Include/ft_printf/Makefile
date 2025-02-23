# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akella <akella@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 06:39:48 by akella            #+#    #+#              #
#    Updated: 2025/02/16 10:55:36 by akella           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = \
    ft_printf.c \
    disy.c \
    handle_char.c \
    handle_string.c \
    handle_integer.c \
    handle_unsigned.c \
    handle_hex.c \
    handle_percent.c \
    pointer.c \
    ft_strlen.c \
    ft_putchar.c \
    ft_putstr.c \
    ft_putnbr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
