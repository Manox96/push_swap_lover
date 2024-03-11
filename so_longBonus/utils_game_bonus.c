/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:56:29 by aennaqad          #+#    #+#             */
/*   Updated: 2024/02/27 16:54:08 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	chech_collectble(char **str)
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
			if (str[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	swap_to_top(t_tool *var)
{
	int	x;
	int	y;

	get_pos_player(var);
	y = var->var_mlx.x;
	x = var->var_mlx.y;
	if (var->map[y - 1][x] == 'E')
		chek_wall(var);
	if (var->map[y - 1][x] != '1' && var->map[y - 1][x] != 'E')
	{
		var->moves += 1;
		if (var->map[y - 1][x] == 'C' || var->map[y - 1][x] == 'X')
			collectable(var, x * 64, (y - 1) * 64);
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.player_top,
			x * 64, (y - 1) * 64);
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.floor,
			x * 64, y * 64);
		var->map[y - 1][x] = 'P';
		var->map[y][x] = '0';
	}
}

void	swap_to_bottom(t_tool *var)
{
	int	x;
	int	y;

	get_pos_player(var);
	y = var->var_mlx.x;
	x = var->var_mlx.y;
	if (var->map[y + 1][x] == 'E')
		chek_wall(var);
	if (var->map[y + 1][x] != '1' && var->map[y + 1][x] != 'E')
	{
		if (var->map[y + 1][x] == 'C' || var->map[y + 1][x] == 'X')
			collectable(var, x * 64, (y + 1) * 64);
		var->moves += 1;
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.player,
			x * 64, (y + 1) * 64);
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.floor,
			x * 64, (y) * 64);
		var->map[y + 1][x] = 'P' ;
		var->map[y][x] = '0';
	}
}

void	swap_to_left(t_tool *var)
{
	int	x;
	int	y;

	get_pos_player(var);
	y = var->var_mlx.x;
	x = var->var_mlx.y;
	if (var->map[y][x - 1] == 'E')
		chek_wall(var);
	if (var->map[y][x - 1] != '1' && var->map[y][x - 1] != 'E')
	{
		if (var->map[y][x - 1] == 'C' || var->map[y][x - 1] == 'X')
			collectable(var, (x - 1) * 64, (y) * 64);
		var->moves += 1;
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.player_left,
			(x - 1) * 64, (y) * 64);
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.floor,
			x * 64, (y) * 64);
		var->map[y][x - 1] = 'P';
		var->map[y][x] = '0';
	}
}

void	swap_to_right(t_tool *var)
{
	int	x;
	int	y;

	get_pos_player(var);
	y = var->var_mlx.x;
	x = var->var_mlx.y;
	if (var->map[y][x + 1] == 'E')
		chek_wall(var);
	if (var->map[y][x + 1] != '1' && var->map[y][x + 1] != 'E' )
	{
		if (var->map[y][x + 1] == 'C' || var->map[y][x + 1] == 'X')
			collectable(var, (x + 1) * 64, y * 64);
		var->moves += 1;
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.player_right,
			(x + 1) * 64, (y) * 64);
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.floor,
			x * 64, (y) * 64);
		var->map[y][x + 1] = 'P';
		var->map[y][x] = '0';
	}
}
