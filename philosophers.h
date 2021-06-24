/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:16:32 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/06/24 11:20:38 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philoshopers
{
	pthread_t	thread;
}				t_philo;

struct				s_data
{
	pthread_mutex_t	*forks;
	t_philo			*philos;
	int				numberofphilos;
	int				timetodie;
	int				timetoeat;
	int				timetosleep;
	int				time_must_eat;
	int				arc;
}					t_d;
pthread_mutex_t		print;
//////////////// libft tools //////////////
int				ft_atoi(const char *str);
int				ft_check(int n);
char			*ft_itoa(int n);
int				ft_strlen(char *ptr);
long 			g_time;
///////////////////////////////////////////
void			ft_putnbr_fd(int n, int fd);
int				coll_data(int arc, char **arv);
void			start(void);
int				getcurrenttime(void);
int				horloge(int arg_time);
void			eating(int id);
void			sleeping(int id);
void			thinking(int id);
void			*routine(void *arg);

#endif
