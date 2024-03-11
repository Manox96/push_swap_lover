/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:09:42 by aennaqad          #+#    #+#             */
/*   Updated: 2024/03/09 16:15:45 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_pos_player(t_tool *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (var->map[i])
	{
		j = 0;
		while (var->map[i][j])
		{
			if (var->map[i][j] == 'P')
			{
				var->var_mlx.x = i;
				var->var_mlx.y = j;
			}
			j++;
		}
		i++;
	}
}

void	get_exit_pos(char **str, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'E')
			{
				*x = i;
				*y = j;
			}
			j++;
		}
		i++;
	}
}
