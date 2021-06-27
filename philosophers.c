/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:16:30 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/06/27 15:02:48 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

void	ft_init(t_data *ph)
{
	int ret;

	pthread_mutex_init(&ph->print, NULL);
	ph->threads = malloc(sizeof(pthread_t) * ph->nofph);
	ph->last_time_eat = malloc(sizeof(int) * ph->nofph);
	ph->forks = malloc(sizeof(pthread_mutex_t) * ph->nofph);
	ret = -1;
	while (++ret < ph->nofph)
		pthread_mutex_init(&ph->forks[ret], NULL);
}

void	ft_destroy(t_data *ph)
{
	int ret;

	ret = -1;
	while (++ret < ph->nofph)
		pthread_mutex_destroy(&ph->forks[ret]);
	pthread_mutex_destroy(&ph->print);
	// free 
	free((pthread_t*)ph->threads);
	free((pthread_mutex_t*)ph->forks);
	free((int*)ph->last_time_eat);
}

void	*routine(void *arg)
{
	t_id	*data;

	data = (t_id*)arg;
	while (1)
	{
		eating(data);
		sleeping(data);
		thinking(data);
	}
	free(data->index);
	free((t_id*)data);
	return (NULL);
}

int		main(int arc, char **arv)
{
	int		ret;
	t_data	philo;

	if ((ret = coll_data(arc, arv, &philo)))
	{
		printf("Erreur!!\n");
		return (1);
	}
	ft_init(&philo);
	start(&philo);
	ft_destroy(&philo);
	return (0);
}
