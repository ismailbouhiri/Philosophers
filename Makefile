# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 15:16:28 by ibouhiri          #+#    #+#              #
#    Updated: 2021/06/22 16:05:36 by ibouhiri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	philosophers.c \
		tools.c \
		forks.c

CC = gcc -Wall -Wextra -Werror

PROG = philo

all: $(PROG)

$(PROG) : $(SRC)
	$(CC) $(SRC) -o $(PROG)

clean:
	rm -rf $(PROG)

fclean: clean

re : clean all
