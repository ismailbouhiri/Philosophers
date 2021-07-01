/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminette.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:35:22 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/07/01 16:49:44 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	horloge(int arg_time)
{
	int	start;

	start = getcurrenttime();
	usleep((arg_time - 20) * 1000);
	while ((getcurrenttime() - start) < arg_time)
		continue ;
	return (1);
}

int	arg_check(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (!(ptr[i] >= '0' && ptr[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	coll_data(int arc, char **arv, t_data *philo)
{
	if (arc < 5 || arc > 6)
		return (1);
	philo->arc = arc;
	philo->nofph = -1;
	if (arg_check(arv[1]))
		philo->nofph = atoi(arv[1]);
	philo->timetodie = -1;
	if (arg_check(arv[2]))
		philo->timetodie = atoi(arv[2]);
	philo->timetoeat = -1;
	if (arg_check(arv[3]))
		philo->timetoeat = atoi(arv[3]);
	philo->timetosleep = -1;
	if (arg_check(arv[4]))
		philo->timetosleep = atoi(arv[4]);
	philo->time_must_eat = -1;
	if (arc == 6 && arg_check(arv[5]))
		philo->time_must_eat = atoi(arv[5]);
	if (philo->nofph < 1 || philo->timetodie < 1
		|| philo->timetoeat < 1 || philo->timetosleep < 1)
		return (1);
	if (arc == 6 && philo->time_must_eat < 1)
		return (1);
	return (0);
}

void	start(t_data *philo)
{
	int		count;
	t_id	*data;

	count = 0;
	philo->start_time = getcurrenttime();
	data = malloc(sizeof(t_id) * philo->nofph);
	philo->pointer = (void *)&data;
	ft_init(philo);
	create_threads(0, philo, data);
	ft_death(philo);
}

int 	getcurrenttime(void)
{
	struct timeval	current_time;
	int				time;

	gettimeofday(&current_time, NULL);
	time = ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
	return (time);
}
