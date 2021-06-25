/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:51:22 by ibouhiri          #+#    #+#             */
/*   Updated: 2021/06/25 08:59:08 by ibouhiri         ###   ########.fr       */
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
