/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:16:32 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/06/25 11:10:29 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	int				numberofphilos;
	int				timetodie;
	int				timetoeat;
	int				timetosleep;
	int				time_must_eat;
	int				arc;
	pthread_mutex_t	print;
	long			start_time;
}					t_data;
typedef struct s_index
{
	int				*index;
	t_data			*ph;
}					t_id;
//////////////// libft tools //////////////
int				ft_atoi(const char *str);
int				ft_check(int n);
char			*ft_itoa(int n);
int				ft_strlen(char *ptr);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
///////////////////////////////////////////
int				coll_data(int arc, char **arv, t_data *philo);
void			start(t_data *philo);
int				getcurrenttime(void);
int				horloge(int arg_time);
void			eating(t_id *data);
void			sleeping(t_id *data);
void			thinking(t_id *data);
void			*routine(void *arg);

#endif
