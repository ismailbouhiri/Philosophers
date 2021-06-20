/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:16:32 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/06/19 16:44:50 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
// # define EATING 1
// # define WAITFOR_EATING 2
// # define SLEEP 3
// # define THINKING 4

typedef struct s_philoshopers
{
	pthread_t	thread;
	int			state;
}				t_philo;

struct			s_data
{
	int			numberofphilos;
	int			timetodie;
	int			timetoeat;
	int			timetosleep;
	int			time_must_eat;
	int			arc;
	int			forks;
}				t_d;

t_philo			*philos;

int				ft_atoi(const char *str);
int				coll_data(int arc, char **arv);
void			start(t_philo *philos);
void			*routine();
#endif
