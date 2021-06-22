/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:16:32 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/06/22 16:06:49 by ibouhiri         ###   ########.fr       */
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
	int			state;
}				t_philo;

struct			s_data
{
	int			*forks;
	t_philo		*philos;
	int			numberofphilos;
	int			timetodie;
	int			timetoeat;
	int			timetosleep;
	int			time_must_eat;
	int			arc;
}				t_d;

int				ft_atoi(const char *str);
int				coll_data(int arc, char **arv);
void			start(void);
int				getcurrenttime(void);
int				horloge( int arg_time );
void			*routine(void *arg);

#endif
