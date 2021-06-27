# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 15:16:28 by ibouhiri          #+#    #+#              #
#    Updated: 2021/06/27 15:40:03 by ibouhiri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	philosophers.c \
		tools.c \
		forks.c \
		taks.c

CC = gcc -Wall -Wextra -Werror

PROG = philo

all: $(PROG)

$(PROG) : $(SRC)
	$(CC) $(SRC) -o $(PROG)

clean:
	rm -rf $(PROG)

fclean: clean

re : clean all
