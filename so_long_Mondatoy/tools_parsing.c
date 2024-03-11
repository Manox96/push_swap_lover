/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:06:18 by aennaqad          #+#    #+#             */
/*   Updated: 2024/02/29 09:34:06 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	top_bottom(char **str, char *top, char *bottom)
{
	int	j;

	j = 0;
	while (top[j])
	{
		if (top[j] != '1')
		{
			perror("Error\nthe line in the top should contain only one !!");
			clear_2d(str);
			exit(EXIT_FAILURE);
		}
		j++;
	}
	j = 0;
	while (bottom[j])
	{
		if (bottom[j] != '1')
		{
			perror("Error\nthe line in the bottom should contain only one !!");
			clear_2d(str);
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

void	left_right(char **str, int line_number, int size_line)
{
	int	j;

	j = 0;
	while (j < line_number)
	{
		if (str[j][size_line - 1] != '1')
		{
			perror("Error\nthe line in the right should contain only one !!");
			clear_2d(str);
			exit(EXIT_FAILURE);
		}
		j++;
	}
	j = 0;
	while (j < line_number)
	{
		if (str[j][0] != '1')
		{
			perror("Error\nthe line in the left should contain only one !!");
			clear_2d(str);
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

void	check_ones(char **str, int line_number, int size_line)
{
	char	*top;
	char	*bottom;

	if (!(*str))
	{
		perror("Error\nnothing in the map please check !!");
		exit(EXIT_FAILURE);
	}
	top = str[0];
	bottom = str[line_number - 1];
	left_right(str, line_number, size_line);
	top_bottom(str, top, bottom);
}
