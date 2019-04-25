# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 17:04:52 by cdimitro          #+#    #+#              #
#    Updated: 2019/04/25 16:16:31 by cdimitro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = fillit.c validation.c coordinates.c mapping.c solve.c placement.c
OBJS = fillit.o validation.o coordinates.o mapping.o solve.o placement.o

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) -I ../libft/ -c $(SRCS)
	$(CC) -o $(TARGET) $(OBJS) -L ../libft -lft

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
