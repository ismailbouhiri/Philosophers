/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:34:24 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/07/01 16:41:24 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		if (res > 2147483648 && sign == -1)
			return (0);
		if (res > 2147483647 && sign == 1)
			return (-1);
		i++;
	}
	return (res * sign);
}

int	eatingtime(t_data *ph)
{
	int	i;

	i = 0;
	if (ph->arc != 6)
		return (0);
	while (i < ph->nofph)
	{
		if (ph->eating_time[i] < ph->time_must_eat)
			return (0);
		i++;
	}
	return (1);
}

int	ft_norminette(int *i, t_data *ph)
{
	if (ph->is_eatinng[(*i)] == ISEAT)
	{
		(*i)++;
		return (0);
	}
	pthread_mutex_lock(&ph->dead[(*i)]);
	if (getcurrenttime() - ph->last_time_eat[(*i)] > ph->timetodie)
	{
		ph->is_dead = 1;
		deadprint(ph, (*i));
		return (1);
	}
	pthread_mutex_unlock(&ph->dead[(*i)]);
	(*i)++;
	return (0);
}

int	ft_death(t_data *ph)
{
	int	i;

	ph->is_dead = 0;
	while (!ph->is_dead)
	{
		i = 0;
		if (eatingtime(ph))
			break ;
		while (i < ph->nofph)
			if (ft_norminette(&i, ph))
				break ;
		usleep(800);
	}
	return (1);
}

void	create_threads(int count, t_data *philo, t_id *data)
{
	while (count < philo->nofph)
	{
		data[count].index = malloc(sizeof(int));
		*(data[count].index) = count;
		data[count].ph = philo;
		pthread_create(&philo->threads[count], NULL, &routine, &data[count]);
		count += 2;
	}
	usleep(philo->nofph * 100);
	count = 1;
	while (count < philo->nofph)
	{
		data[count].index = malloc(sizeof(int));
		*(data[count].index) = count;
		data[count].ph = philo;
		pthread_create(&philo->threads[count], NULL, &routine, &data[count]);
		count += 2;
	}
}
