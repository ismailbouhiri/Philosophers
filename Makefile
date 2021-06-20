# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 15:16:28 by ibouhiri          #+#    #+#              #
#    Updated: 2021/06/17 16:13:45 by ibouhiri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = philo.c
CC = gcc -Wall -Wextra -Werror
PROG = philo

all: $(PROG)

RUN :
	$(CC) $(SRC) -o $(PROG)

clean:
	rm -rf $(PROG)

fclean: clean

re : clean all
