/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_two_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:02:13 by aennaqad          #+#    #+#             */
/*   Updated: 2024/03/09 16:54:58 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = n * -1 ;
	}
	else
		nb = n;
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
}

int	countnum(int n)
{
	int	c;

	c = 0;
	if (n == 0)
		c = 1;
	while (n != 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int			sizen;
	char		*ptr;
	int			t;
	long long	newn;

	t = 0;
	newn = n;
	if (newn < 0)
	{
		t = 1;
		newn = -newn;
	}
	sizen = countnum(n) + t;
	ptr = malloc(sizen * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	ptr[sizen] = '\0';
	if (t == 1)
		ptr[0] = '-';
	while (--sizen >= t)
	{
		ptr[sizen] = (newn % 10) + '0';
		newn = newn / 10;
	}
	return (ptr);
}

void	flood_fill(char **cpy, int x, int y)
{
	if (x < 0 || cpy[x][y] == '1' || cpy[x][y] == 'V' || cpy[x][y] == 'E')
		return ;
	cpy[x][y] = 'V';
	flood_fill(cpy, x + 1, y);
	flood_fill(cpy, x - 1, y);
	flood_fill(cpy, x, y + 1);
	flood_fill(cpy, x, y - 1);
}
