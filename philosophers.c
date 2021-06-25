/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:16:30 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/06/25 10:50:10 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

void	*routine(void *arg)
{
	t_id	*data;

	data = (t_id*)arg;
	eating(data);
	sleeping(data);
	thinking(data);
	return (NULL);
}

int		main(int arc, char **arv)
{
	int		ret;
	t_data	philo;

	philo.start_time = getcurrenttime();
	if ((ret = coll_data(arc, arv, &philo)))
	{
		printf("Erreur!!\n");
		return (1);
	}
	pthread_mutex_init(&philo.print, NULL);
	philo.threads = malloc(sizeof(pthread_t) * philo.numberofphilos);
	philo.forks = malloc(sizeof(pthread_mutex_t) * philo.numberofphilos);
	ret = -1;
	while (++ret < philo.numberofphilos)
		pthread_mutex_init(&philo.forks[ret], NULL);
	start(&philo);
	free((pthread_t*)philo.threads);
	ret = -1;
	while (++ret < philo.numberofphilos)
		pthread_mutex_destroy(&philo.forks[ret]);
	pthread_mutex_destroy(&philo.print);
	free((pthread_mutex_t*)philo.forks);
	// while (1){};
	return (0);
}
