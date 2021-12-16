# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 18:58:29 by nlenoch           #+#    #+#              #
#    Updated: 2021/12/16 23:44:27 by nlenoch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ft_split.c push_swap.c stack.c check.c tinyutils.c utils.c algorithm.c operations.c sort.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ := $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): 
	$(CC) -c $(CLFAGS) $(SRC)
	$(CC) $(CLFAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all