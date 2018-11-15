# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 22:53:22 by jquivogn          #+#    #+#              #
#    Updated: 2018/11/13 23:11:06 by jquivogn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =	./grid_management.c \
		./main.c \
		./read.c \
		./solve.c \
		./annex.c

OBJS = $(SRCS:.c=.o)

FLAG = -Wextra -Wall -Werror

all : $(NAME)

$(NAME) : $(OBJS) fillit.h
	$(MAKE) -C libft/
	gcc -c $(FLAG) $(SRCS)
	gcc $(OBJS) -o $(NAME) libft/libft.a

clean :
	rm -rf $(OBJS)
	$(MAKE) -C libft/ clean

fclean : clean
	rm -rf $(NAME)
	$(MAKE) -C libft/ fclean

re : fclean all

.PHONY : all clean fclean re