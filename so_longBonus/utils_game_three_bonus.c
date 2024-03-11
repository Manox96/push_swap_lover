/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game_three_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:52:43 by aennaqad          #+#    #+#             */
/*   Updated: 2024/03/09 16:54:41 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_size(t_tool *var)
{
	clear_2d(var->map);
	write(1, "window so long\n", 16);
	exit(1);
}

void	find_cor_enemy(t_tool *vr, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (vr->map[i])
	{
		j = 0;
		while (vr->map[i][j])
		{
			if (vr->map[i][j] == 'X')
			{
				*x = i;
				*y = j;
			}
			j++;
		}
		i++;
	}
}

void	destory_imgs(t_tool *var)
{
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.floor);
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.col_bottom);
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.col_left);
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.col_right);
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.col_top);
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.wall);
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.exite);
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.c);
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.player_left);
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.player_right);
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.player_top);
}

void	initial_img_direction(t_tool *var)
{
	int		img_width;
	int		img_height;

	img_height = 0;
	img_width = 0;
	var->var_mlx.player_left = mlx_xpm_file_to_image(var->var_mlx.mlx,
			"./textures/left.xpm", &img_width, &img_height);
	var->var_mlx.player_right = mlx_xpm_file_to_image(var->var_mlx.mlx,
			"./textures/right.xpm", &img_width, &img_height);
	var->var_mlx.player_top = mlx_xpm_file_to_image(var->var_mlx.mlx,
			"./textures/top.xpm", &img_width, &img_height);
	if (!var->var_mlx.player_top || !var->var_mlx.player_left
		|| !var->var_mlx.player_right)
	{
		write(1, "Image Error\n", 13);
		clear_2d(var->map);
		exit(1);
	}
}

void	flood_fill_bns_e(char **cpy, int x, int y)
{
	if (x < 0 || cpy[x][y] == '1' || cpy[x][y] == 'V')
		return ;
	cpy[x][y] = 'V';
	flood_fill_bns_e(cpy, x + 1, y);
	flood_fill_bns_e(cpy, x - 1, y);
	flood_fill_bns_e(cpy, x, y + 1);
	flood_fill_bns_e(cpy, x, y - 1);
}
