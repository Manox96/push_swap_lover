/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_one_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:04:30 by aennaqad          #+#    #+#             */
/*   Updated: 2024/02/27 14:05:58 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	printerror(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	check_extention(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.'
			&& str[i + 1] == 'b'
			&& str[i + 2] == 'e'
			&& str[i + 3] == 'r'
			&& str[i + 4] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	strlen_nl(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

int	coun_line(int fd)
{
	char	*row;
	int		line_number;

	line_number = 0;
	row = get_next_line(fd);
	while (row != NULL)
	{
		free(row);
		row = get_next_line(fd);
		line_number++;
	}
	close(fd);
	return (line_number);
}

void	direction(t_tool *var, int y, int x)
{
	if (var->direction == 0)
		enemy_to_left(var, y, x);
	if (var->direction == 1)
		enemy_to_right(var, y, x);
}
