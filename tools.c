/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:34:24 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/07/01 14:36:35 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

int		ft_atoi(const char *str)
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

int		ft_death(t_data *ph)
{
	int i;
	
	ph->is_dead = 0;
	while (!ph->is_dead)
	{
		i = 0;
		while (i < ph->nofph)
		{
			if (ph->is_eatinng[i] == ISEAT)
			{
				i++;
				continue;
			}
			pthread_mutex_lock(&ph->dead[i]);
		 	if (getcurrenttime() - ph->last_time_eat[i] > ph->timetodie)
			{
				ph->is_dead = 1;
				deadprint(ph, i);
				break;
			}
			pthread_mutex_unlock(&ph->dead[i]);
			i++;
		}
		usleep(800);
	}
	return (1);
}

void	start(t_data *philo)
{
	int		count;
	t_id	*data;
	// void	*arg;
	
	count = 0;
	philo->start_time = getcurrenttime();
	data = malloc(sizeof(t_id) * philo->nofph);
	philo->pointer = (void *)&data;
	ft_init(philo);
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
	ft_death(philo);
}

int 	getcurrenttime(void)
{
	struct timeval current_time;
	int time;
	
	gettimeofday(&current_time, NULL);
	time = ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
	return (time);
}

int 	horloge(int arg_time)
{
	int start;

	start = getcurrenttime();
	usleep((arg_time  - 20) * 1000);
	while ((getcurrenttime() - start) < arg_time)
		continue;
	return (1);
}

int		arg_check(char *ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		if (!(ptr[i] >= '0' && ptr[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int		coll_data(int arc, char **arv, t_data *philo)
{
	if (arc < 5 || arc > 6)
		return (1);
	philo->arc = arc;
	philo->nofph = (arg_check(arv[1])) ? atoi(arv[1]) : -1;
	philo->timetodie = (arg_check(arv[2])) ? atoi(arv[2]) : -1;
	philo->timetoeat = (arg_check(arv[3])) ? atoi(arv[3]) : -1;
	philo->timetosleep = (arg_check(arv[4])) ? atoi(arv[4]) : -1;
	philo->time_must_eat = (arc == 6 && arg_check(arv[5])) ? atoi(arv[5]) : 0;
	if (philo->nofph < 1 || philo->timetodie < 1
	|| philo->timetoeat < 1 || philo->timetosleep < 1)
		return (1);
	if (arc == 6 && philo->time_must_eat < 1)
		return (1);
	return (0);
}
