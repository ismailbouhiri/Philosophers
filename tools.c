/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:34:24 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/06/23 12:40:26 by ibouhiri         ###   ########.fr       */
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

void	start(void)
{
	int count;
	int *id;

	count = 0;
	id = malloc(sizeof(int) * t_d.numberofphilos);
	// while (count < t_d.numberofphilos)
	// {
	// 	id[count] = count;
	// 	if (count % 2 != 0)
	// 		pthread_create(&t_d.philos[count].thread, NULL, &routine, &id[count]);
	// 	else
	// 		pthread_create(&t_d.philos[count].thread, NULL, &routine, &id[count]);
	// 	count++;
	// }
	// ////////
	count = 0;
	while (count < t_d.numberofphilos)
	{
		id[count] = count;
		if (count % 2 != 0)
			pthread_create(&t_d.philos[count].thread, NULL, &routine, &id[count]);
		count++;
	}
	count = 0;
	usleep(t_d.numberofphilos * 2);
	while (count < t_d.numberofphilos)
	{
		if (count % 2 == 0)
			pthread_create(&t_d.philos[count].thread, NULL, &routine, &id[count]);
		count++;
	}
	// ///////
	count = 0;
	while (count < t_d.numberofphilos)
	{
		pthread_join(t_d.philos[count].thread, NULL);
		count++;
	}
	free(id);
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
	int time;
	int start;

	time = 20;
	usleep((arg_time  - 20) * 1000);
	start = getcurrenttime();
	while ((getcurrenttime() - start) < time)
		continue;
	return (1);
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
