/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two_game_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:45:22 by aennaqad          #+#    #+#             */
/*   Updated: 2024/02/28 19:05:16 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_pos(t_tool *var, int *x, int *y)
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
			if (var->map[i][j] == 'X')
			{
				*x = i;
				*y = j;
			}
			j++;
		}
		i++;
	}
}

void	enemy_to_right(t_tool *var, int y, int x)
{
	if (var->map[y][x + 1] == 'E' || var->map[y][x + 1] == 'C'
		|| var->map[y][x + 1] == '1')
	{
		var->direction = 0;
		return ;
	}
	mlx_put_image_to_window(var->var_mlx.mlx,
		var->var_mlx.win, var->var_mlx.enemy,
		(x + 1) * 64, (y) * 64);
	mlx_put_image_to_window(var->var_mlx.mlx,
		var->var_mlx.win, var->var_mlx.floor,
		x * 64, (y) * 64);
	if (var->map[y][x + 1] == 'P')
	{
		mlx_destroy_window(var->var_mlx.mlx, var->var_mlx.win);
		write(1, "you lose !\n", 12);
		exit(1);
	}
	var->map[y][x + 1] = 'X';
	var->map[y][x] = '0';
}

void	enemy_to_left(t_tool *var, int y, int x)
{
	if (var->map[y][x - 1] == 'E' || var->map[y][x - 1] == 'C'
		|| var->map[y][x - 1] == '1')
	{
		var->direction = 1;
		return ;
	}
	mlx_put_image_to_window(var->var_mlx.mlx,
		var->var_mlx.win, var->var_mlx.enemy,
		(x - 1) * 64, (y) * 64);
	mlx_put_image_to_window(var->var_mlx.mlx,
		var->var_mlx.win, var->var_mlx.floor,
		x * 64, (y) * 64);
	if (var->map[y][x - 1] == 'P')
	{
		mlx_destroy_window(var->var_mlx.mlx, var->var_mlx.win);
		write(1, "you lose !\n", 12);
		exit(1);
	}
	var->map[y][x - 1] = 'X';
	var->map[y][x] = '0';
}

int	event_enemy(t_tool *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	enemy_pos(var, &x, &y);
	animation_col(var);
	if (var->timing == 4000)
	{
		direction(var, x, y);
		var->timing = 0;
	}
	else
		var->timing += 1;
	return (0);
}

void	moves_enemy(t_tool *var)
{
	mlx_loop_hook(var->var_mlx.mlx, event_enemy, var);
}
