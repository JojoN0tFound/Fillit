# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/07 00:53:31 by mmousson          #+#    #+#              #
#    Updated: 2018/11/15 17:28:51 by jquivogn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a
FLAGS = -c -Wall -Wextra -Werror

SRC =	ft_memset.c \
		ft_isalpha.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_memalloc.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstpush.c \
		ft_lstnew.c \
		ft_memdel.c \
		ft_bzero.c \
		ft_memcpy.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libft.h
	$(CC) $(FLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
