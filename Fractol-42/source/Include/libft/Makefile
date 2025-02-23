# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akella <akella@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 15:08:11 by akella            #+#    #+#              #
#    Updated: 2025/02/16 10:54:23 by akella           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
APPEND = ar rsc
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC =           ft_isalpha.c             \
				ft_isdigit.c             \
				ft_isalnum.c             \
				ft_isascii.c             \
				ft_isprint.c             \
				ft_strlen.c              \
				ft_memset.c              \
				ft_bzero.c               \
				ft_memcpy.c              \
				ft_memmove.c             \
				ft_strlcpy.c             \
				ft_strlcat.c             \
				ft_toupper.c             \
				ft_tolower.c             \
				ft_strchr.c              \
				ft_strrchr.c             \
				ft_strncmp.c             \
				ft_memchr.c              \
				ft_memcmp.c              \
				ft_strnstr.c             \
				ft_atoi.c                \
				ft_calloc.c              \
				ft_strdup.c              \
				ft_substr.c              \
				ft_strjoin.c             \
				ft_strtrim.c             \
				ft_split.c               \
				ft_itoa.c                \
				ft_strmapi.c             \
				ft_striteri.c            \
				ft_putchar_fd.c          \
				ft_putstr_fd.c           \
				ft_putendl_fd.c          \
				ft_putnbr_fd.c

BONUS_SRC =     ft_lstnew_bonus.c        \
				ft_lstadd_front_bonus.c  \
				ft_lstsize_bonus.c       \
				ft_lstlast_bonus.c       \
				ft_lstadd_back_bonus.c   \
				ft_lstdelone_bonus.c     \
				ft_lstclear_bonus.c      \
				ft_lstiter_bonus.c       \
				ft_lstmap_bonus.c

OBJ = ${SRC:.c=.o}
BONUS_OBJ = ${BONUS_SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	@${APPEND} ${NAME} ${OBJ}

bonus: ${BONUS_OBJ}
	@${APPEND} ${NAME} ${BONUS_OBJ}

%.o: %.c libft.h
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -f ${OBJ} ${BONUS_OBJ}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: clean fclean all bonus re
