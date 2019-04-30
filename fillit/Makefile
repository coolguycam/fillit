# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 17:04:52 by cdimitro          #+#    #+#              #
#    Updated: 2019/04/29 12:42:51 by cdimitro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = fillit.c validation.c coordinates.c mapping.c solve.c placement.c
OBJS = fillit.o validation.o coordinates.o mapping.o solve.o placement.o

all: $(NAME)

$(NAME):
	make -C ../libft/ fclean && make -C ../libft/
	$(CC) $(CFLAGS) -I ../libft/ -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS) -L ../libft -lft

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
