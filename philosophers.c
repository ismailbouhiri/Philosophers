/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:16:30 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/06/23 12:37:28 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

// #define LEFT (philo_num + 1 % totalphilos)
// #define right philo_num

void	*routine(void *arg)
{
	int count;

	count = *(int*)arg;
	pickup(count);
	horloge(t_d.timetoeat);
	while (1)
	{}
	putdown(count);
	return (NULL);
}

int		main(int arc, char **arv)
{
	int		ret;
	if ((ret = coll_data(arc, arv)))
	{
		printf("Erreur!!\n");
		return (1);
	}
	pthread_mutex_init(&print, NULL);
	t_d.philos = malloc(sizeof(t_philo) * t_d.numberofphilos);
	t_d.forks = malloc(sizeof(pthread_mutex_t) * t_d.numberofphilos);
	ret = -1;
	while (++ret < t_d.numberofphilos)
		pthread_mutex_init(&t_d.forks[ret], NULL);
	start();
	free((t_philo*)t_d.philos);
	ret = -1;
	while (++ret < t_d.numberofphilos)
		pthread_mutex_destroy(&t_d.forks[ret]);
	pthread_mutex_destroy(&print);
	free((pthread_mutex_t*)t_d.forks);
	return (0);
}
