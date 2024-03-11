/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_coin_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:25:17 by aennaqad          #+#    #+#             */
/*   Updated: 2024/03/04 16:22:13 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	tour(t_tool *var, int x, int y)
{
	if (var->timing_food == 0)
		top_tour(var, x, y);
	if (var->timing_food == 1)
		left_tour(var, x, y);
	if (var->timing_food == 2)
		bottom_tour(var, x, y);
	if (var->timing_food == 3)
		right_tour(var, x, y);
}

void	animation_col(t_tool *var)
{
	t_tool	inc;

	inc.i = 0;
	inc.j = 0;
	inc.x = 0;
	inc.y = 0;
	while (var->map[inc.i])
	{
		inc.j = 0;
		inc.x = 0;
		while (var->map[inc.i][inc.j])
		{
			if (var->map[inc.i][inc.j] == 'C')
				tour(var, inc.x, inc.y);
			inc.j++;
			inc.x += 64;
		}
		inc.i++;
		inc.y += 64;
	}
}

void	check_if_fail(t_tool *var)
{
	if (!var->var_mlx.win)
	{
		clear_2d(var->map);
		perror("error\nmlx_win fail !!");
		exit(0);
	}
}

void	destory_animation(t_tool *var)
{
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.col_bottom);
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.col_left);
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.col_right);
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.col_top);
}

void	get_exit_pos(t_tool *var, int *x, int *y)
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
			if (var->map[i][j] == 'E')
			{
				*x = i;
				*y = j;
			}
			j++;
		}
		i++;
	}
}
