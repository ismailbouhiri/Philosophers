/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:16:30 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/06/22 16:07:00 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

// #define LEFT (philo_num + 1 % totalphilos)
// #define right philo_num

pthread_mutex_t mut;

void	*routine(void *arg)
{
	int count;

	count = *(int*)arg;
	pthread_mutex_lock(&mut);
	pickup();
	horloge(t_d.timetoeat);
	pickdown();
	pthread_mutex_unlock(&mut);
	return (NULL);
}

int		main(int arc, char **arv)
{
	int		ret;
	pthread_mutex_init(&mut, NULL);
	if ((ret = coll_data(arc, arv)))
	{
		printf("Erreur!!\n");
		return (1);
	}
	t_d.philos = malloc(sizeof(t_philo) * t_d.numberofphilos);
	t_d.firks = malloc(sizeof(t_philo) * t_d.numberofphilos);
	start();
	free((t_philo*)t_d.philos);
	pthread_mutex_destroy(&mut);
	return (0);
}
