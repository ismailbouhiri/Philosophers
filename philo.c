/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:16:30 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/06/19 17:32:07 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t mut;

int horloge( int arg_time )
{
	int _time;
	
	_time = arg_time - 20;
	struct timeval current_time;
	
	gettimeofday(&current_time, NULL);
	printf("seconds : [ %ld ] -- micro seconds : [ %d ]\n", current_time.tv_sec, current_time.tv_usec);
	usleep;
	gettimeofday(&current_time, NULL);
	printf("seconds : [ %ld ] -- micro seconds : [ %d ]\n", current_time.tv_sec, current_time.tv_usec);
	for(int = 0;)
	return (1);
}

// void	eating( void )
// {
// 	usleep(t_d.timetoeat * 1000);
// }

// void	sleeping()
// {
		
//
void	*routine(void *arg)
{
	int count;

	count = *(int*)arg;
	pthread_mutex_lock(&mut);
	horloge(1000);
	pthread_mutex_unlock(&mut);
	return (NULL);
}

void	start(t_philo *philos)
{
	int count;
	int *id;

	count = 0;
	while (count < t_d.numberofphilos)
	{
		id = malloc(sizeof(int));
		
		if (count % 2 != 0)
		{
			pthread_create(&philos[count].thread, NULL, &routine, &count);
			t_d.forks += 1;
		}
		else
		{
			pthread_create(&philos[count].thread, NULL, &routine, &count);
		}
		count++;
	}
	count = 0;
	while (count < t_d.numberofphilos)
	{
		pthread_join(philos[count].thread, NULL);
		// printf("stateof philos:[ %d ]\n", count);
		count++;
	}
}

int		coll_data(int arc, char **arv)
{
	t_d.arc = arc;
	if (arc < 5 || arc > 6)
		return (1);
	t_d.numberofphilos = atoi(arv[1]);
	t_d.timetodie = atoi(arv[2]);
	t_d.timetoeat = atoi(arv[3]);
	t_d.timetosleep = atoi(arv[4]);
	t_d.time_must_eat = (arc == 6) ? atoi(arv[5]) : 0;
	if (t_d.numberofphilos < 1 || t_d.timetodie < 1 || t_d.timetoeat < 1
	|| t_d.timetosleep < 1)
		return (1);
	if (arc == 6 && t_d.time_must_eat < 1)
		return (1);
	return (0);
}

int		main(int arc, char **arv)
{
	int		ret;
	t_philo	*philos;
	pthread_mutex_init(&mut, NULL);
	if ((ret = coll_data(arc, arv)))
	{
		printf("Erreur!!\n");
		return (1);
	}
	philos = malloc(sizeof(t_philo) * t_d.numberofphilos);
	start(philos);
	free((t_philo*)philos);
	pthread_mutex_destroy(&mut);
	return (0);
}
