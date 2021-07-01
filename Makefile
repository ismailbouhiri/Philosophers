# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 15:16:28 by ibouhiri          #+#    #+#              #
#    Updated: 2021/07/01 16:38:09 by ibouhiri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	philosophers.c \
		tools.c \
		forks.c \
		tasks.c \
		norminette.c

CC = gcc -Wall -Wextra -Werror

# CC = gcc -Wall -Wextra -Werror -fsanitize=address

PROG = philo

all: $(PROG)

$(PROG) : $(SRC)
	$(CC) $(SRC) -o $(PROG)

clean:
	rm -rf $(PROG)

fclean: clean

re : clean all
