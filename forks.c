/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:51:22 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/06/24 17:01:52 by ibouhiri         ###   ########.fr       */
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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void			ft_putnbr_fd(int n, int fd)
{
	long res;

	res = n;
	if (n < 0)
	{
		res = -res;
		ft_putchar_fd('-', fd);
	}
	if (res > 9)
	{
		ft_putnbr_fd(res / 10, fd);
		ft_putchar_fd('0' + res % 10, fd);
	}
	else
		ft_putchar_fd(res + 48, fd);
}

void myprint(int id, char *string)
{
	char *number;
	
	number = ft_itoa(id + 1);
	pthread_mutex_lock(&print);
	ft_putnbr_fd(getcurrenttime() - g_time, 1);
	write(1, " ", 1);	
	write(1, number, ft_strlen(number));
	write(1, string, ft_strlen(string));
	pthread_mutex_unlock(&print);
	free(number);
}

void	eating(int id)
{
	// pickup
	pthread_mutex_lock(&t_d.forks[id]);
	myprint(id, " has taken a fork\n");
	pthread_mutex_lock(&t_d.forks[(id + 1) % t_d.numberofphilos]);
	myprint(id, " has taken a fork\n");
	// horloge countdown
	myprint(id, " is eating\n");
	horloge(t_d.timetoeat);
	// putdown the forks
	pthread_mutex_unlock(&t_d.forks[(id + 1) % t_d.numberofphilos]);
	pthread_mutex_unlock(&t_d.forks[id]);
}

void	sleeping(int id)
{
	myprint(id, " is sleeping\n");
	horloge(t_d.timetosleep);
}

void	thinking(int id)
{
	myprint(id, " is thinking\n");
}
