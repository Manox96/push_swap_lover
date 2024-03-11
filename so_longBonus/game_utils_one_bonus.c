/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_one_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:12:54 by aennaqad          #+#    #+#             */
/*   Updated: 2024/02/29 09:37:27 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	top_tour(t_tool *var, int x, int y)
{
	if (var->timing == 4000)
	{
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.floor,
			x, y);
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.col_top,
			x, y);
		var->timing = 0;
	}
	else
		var->timing += 1;
	var->timing_food = 1;
}

void	left_tour(t_tool *var, int x, int y)
{
	if (var->timing == 4000)
	{
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.floor,
			x, y);
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.col_left,
			x, y);
		var->timing = 0;
	}
	else
		var->timing += 1;
	var->timing_food = 2;
}

void	bottom_tour(t_tool *var, int x, int y)
{
	if (var->timing == 4000)
	{
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.floor,
			x, y);
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.col_bottom,
			x, y);
		var->timing = 0;
	}
	else
		var->timing += 1;
	var->timing_food = 3;
}

void	right_tour(t_tool *var, int x, int y)
{
	if (var->timing == 4000)
	{
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.floor,
			x, y);
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.col_right,
			x, y);
		var->timing = 0;
	}
	else
		var->timing += 1;
	var->timing_food = 0;
}

void	initial_collec(t_tool *var)
{
	int		img_width;
	int		img_height;

	img_height = 0;
	img_width = 0;
	var->var_mlx.col_top = mlx_xpm_file_to_image(var->var_mlx.mlx,
			"./textures/one.xpm", &img_width, &img_height);
	var->var_mlx.col_left = mlx_xpm_file_to_image(var->var_mlx.mlx,
			"./textures/two.xpm", &img_width, &img_height);
	var->var_mlx.col_bottom = mlx_xpm_file_to_image(var->var_mlx.mlx,
			"./textures/three.xpm", &img_width, &img_height);
	var->var_mlx.col_right = mlx_xpm_file_to_image(var->var_mlx.mlx,
			"./textures/four.xpm", &img_width, &img_height);
	var->var_mlx.col_midd = mlx_xpm_file_to_image(var->var_mlx.mlx,
			"./textures/sex.xpm", &img_width, &img_height);
	var->var_mlx.col_midd_left = mlx_xpm_file_to_image(var->var_mlx.mlx,
			"./textures/seven.xpm", &img_width, &img_height);
	if (!var->var_mlx.col_top || !var->var_mlx.col_left
		|| !var->var_mlx.col_bottom || !var->var_mlx.col_right
		|| !var->var_mlx.col_midd || !var->var_mlx.col_midd_left)
	{
		write(1, "Image Error\n", 13);
		exit(1);
	}
}
