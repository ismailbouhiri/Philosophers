/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:16:30 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/07/01 16:53:19 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init(t_data *ph)
{
	int	ret;

	pthread_mutex_init(&ph->print, NULL);
	ph->threads = malloc(sizeof(pthread_t) * ph->nofph);
	ph->last_time_eat = malloc(sizeof(int) * ph->nofph);
	ph->is_eatinng = malloc(sizeof(int) * ph->nofph);
	ph->eating_time = malloc(sizeof(int) * ph->nofph);
	ph->forks = malloc(sizeof(pthread_mutex_t) * ph->nofph);
	ph->dead = malloc(sizeof(pthread_mutex_t) * ph->nofph);
	ret = -1;
	while (++ret < ph->nofph)
	{
		pthread_mutex_init(&ph->forks[ret], NULL);
		pthread_mutex_init(&ph->dead[ret], NULL);
		ph->is_eatinng[ret] = NOTEAT;
		ph->eating_time[ret] = 0;
		ph->last_time_eat[ret] = getcurrenttime();
	}
}

void	ft_destroy(t_data *ph)
{
	int		ret;
	t_id	*data;

	usleep(20000);
	ret = -1;
	data = (t_id *)*(ph->pointer);
	while (++ret < ph->nofph)
		free((int *)data[ret].index);
	free((pthread_t *)ph->threads);
	free((pthread_mutex_t *)ph->forks);
	free((pthread_mutex_t *)ph->dead);
	free((int *)ph->last_time_eat);
	free((int *)ph->eating_time);
	free((int *)ph->is_eatinng);
}

void	*routine(void *arg)
{
	t_id	*data;

	data = (t_id *)arg;
	while (1)
	{
		eating(data);
		sleeping(data);
		thinking(data);
	}
	return (NULL);
}

int	main(int arc, char **arv)
{
	int		ret;
	t_data	philo;

	ret = coll_data(arc, arv, &philo);
	if (ret)
	{
		printf("Erreur!!\n");
		return (1);
	}
	start(&philo);
	ft_destroy(&philo);
	return (0);
}
