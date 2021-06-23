/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:51:22 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/06/23 10:55:00 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

int ft_strlen(char *ptr)
{
	int i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

int		ft_check(int n)
{
	int				i;
	unsigned int	res;

	i = 1;
	res = n;
	if (n < 0)
	{
		i++;
		res *= -1;
	}
	while (res > 9)
	{
		res = res / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int				i;
	unsigned char	*str;
	unsigned int	res;

	res = n;
	i = ft_check(n);
	str = (unsigned char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		res *= -1;
	}
	str[i] = '\0';
	while (--i && res >= 10)
	{
		str[i] = (res % 10) + 48;
		res = res / 10;
	}
	if (res < 10)
		str[i] = res % 10 + 48;
	return ((char*)str);
}

void myprint(int id)
{
	char *number;
	
	number = ft_itoa(id + 1);
	pthread_mutex_lock(&print);
	write(1, number, ft_strlen(number));
	write(1, " has taken a fork\n", 18);
	pthread_mutex_unlock(&print);
	free(number);
}

void	pickup(int id)
{
	// printf("left = ")
	pthread_mutex_lock(&t_d.forks[id]);
	myprint(id);
	pthread_mutex_lock(&t_d.forks[(id + 1) % t_d.numberofphilos]);
	myprint(id);
}

void	putdown(int id)
{
	pthread_mutex_unlock(&t_d.forks[id]);
	pthread_mutex_unlock(&t_d.forks[(id + 1) % t_d.numberofphilos]);
}
