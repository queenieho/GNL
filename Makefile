# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qho <qho@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/10 00:39:38 by qho               #+#    #+#              #
#    Updated: 2016/12/10 00:52:07 by qho              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror

NAME = test_gnl

INCLUDES = libft/includes

OBJ = get_next_line.o \
		main.o

.PHONY: clean

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I $(INCLUDES) -o get_next_line.o -c get_next_line.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -o main.o -c main.c
	$(CC) -o $(NAME) $(OBJ) -I $(INCLUDES) -L libft/ -lft

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
	