/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 08:57:54 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/07/01 17:08:03 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	deadprint(t_data *data, int id)
{
	char	*number;

	number = ft_itoa(id + 1);
	pthread_mutex_lock(&data->print);
	ft_putnbr_fd(getcurrenttime() - data->start_time, 1);
	write(1, " ", 1);
	write(1, number, ft_strlen(number));
	write(1, " died\n", ft_strlen(" died\n"));
	free(number);
}

void	myprint(t_id *data, char *string)
{
	char	*number;

	number = ft_itoa(*(data->index) + 1);
	pthread_mutex_lock(&data->ph->print);
	ft_putnbr_fd(getcurrenttime() - data->ph->start_time, 1);
	write(1, " ", 1);
	write(1, number, ft_strlen(number));
	write(1, string, ft_strlen(string));
	pthread_mutex_unlock(&data->ph->print);
	free(number);
}

void	eating(t_id *data)
{
	pthread_mutex_lock(&data->ph->forks[*(data->index)]);
	myprint(data, " has taken a fork\n");
	pthread_mutex_lock(&data->ph->forks[(*(data->index) + 1)
		% data->ph->nofph]);
	myprint(data, " has taken a fork\n");
	pthread_mutex_lock(&data->ph->dead[*data->index]);
	data->ph->is_eatinng[*(data->index)] = ISEAT;
	data->ph->eating_time[*(data->index)]
		= data->ph->eating_time[*(data->index)] + 1;
	myprint(data, " is eating\n");
	data->ph->last_time_eat[*(data->index)] = getcurrenttime();
	horloge(data->ph->timetoeat);
	data->ph->is_eatinng[*(data->index)] = NOTEAT;
	pthread_mutex_unlock(&data->ph->dead[*data->index]);
	pthread_mutex_unlock(&data->ph->forks[(*(data->index) + 1)
		% data->ph->nofph]);
	pthread_mutex_unlock(&data->ph->forks[*(data->index)]);
}

void	sleeping(t_id *data)
{
	myprint(data, " is sleeping\n");
	horloge(data->ph->timetosleep);
}

void	thinking(t_id *data)
{
	myprint(data, " is thinking\n");
}
