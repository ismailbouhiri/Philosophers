/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taks.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 08:57:54 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/06/25 10:57:14 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

void myprint(t_id *data, char *string)
{
	char *number;
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
	// pickup
	pthread_mutex_lock(&data->ph->forks[*(data->index)]);
	myprint(data, " has taken a fork\n");
	pthread_mutex_lock(&data->ph->forks[(*(data->index) + 1) % data->ph->numberofphilos]);
	myprint(data, " has taken a fork\n");
	// horloge countdown
	myprint(data, " is eating\n");
	horloge(data->ph->timetoeat);
	// putdown the forks
	pthread_mutex_unlock(&data->ph->forks[(*(data->index) + 1) % data->ph->numberofphilos]);
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
