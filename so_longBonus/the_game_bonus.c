/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:26:58 by aennaqad          #+#    #+#             */
/*   Updated: 2024/02/28 19:12:09 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdio.h>
#include <stdlib.h>

void	initial_img(t_tool *var)
{
	int		img_width;
	int		img_height;

	img_height = 0;
	img_width = 0;
	var->var_mlx.floor = mlx_xpm_file_to_image(var->var_mlx.mlx,
			"./textures/floor.xpm", &img_width, &img_height);
	var->var_mlx.enemy = mlx_xpm_file_to_image(var->var_mlx.mlx,
			"./textures/enemy.xpm", &img_width, &img_height);
	var->var_mlx.player = mlx_xpm_file_to_image(var->var_mlx.mlx,
			"./textures/bottom.xpm", &img_width, &img_height);
	var->var_mlx.wall = mlx_xpm_file_to_image(var->var_mlx.mlx,
			"./textures/wall.xpm", &img_width, &img_height);
	var->var_mlx.c = mlx_xpm_file_to_image(var->var_mlx.mlx,
			"./textures/C.xpm", &img_width, &img_height);
	var->var_mlx.exite = mlx_xpm_file_to_image(var->var_mlx.mlx,
			"./textures/door.xpm", &img_width, &img_height);
	if ((!var->var_mlx.floor || !var->var_mlx.player
			|| !var->var_mlx.wall || !var->var_mlx.c
			|| !var->var_mlx.exite || !var->var_mlx.enemy))
	{
		write(1, "Image Error\n", 13);
		exit(1);
	}
}

void	which_img(t_tool *var, int i, int j)
{
	if (var->map[i][j] == '1')
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.wall,
			var->var_mlx.x_img, var->var_mlx.y_img);
	if (var->map[i][j] == 'P')
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.player,
			var->var_mlx.x_img, var->var_mlx.y_img);
	if (var->map[i][j] == 'E')
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.exite,
			var->var_mlx.x_img, var->var_mlx.y_img);
	if (var->map[i][j] == 'X')
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.enemy,
			var->var_mlx.x_img, var->var_mlx.y_img);
	if (var->map[i][j] == 'C')
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.col_top,
			var->var_mlx.x_img, var->var_mlx.y_img);
	if (var->map[i][j] == '0')
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.floor,
			var->var_mlx.x_img, var->var_mlx.y_img);
}

int	key_handler(int keycode, t_tool *var)
{
	if (keycode == 53)
		close_win(var);
	else if (keycode == 13 || keycode == 126)
		to_top(var);
	else if (keycode == 0 || keycode == 123)
		to_left(var);
	else if (keycode == 2 || keycode == 124)
		to_right(var);
	else if (keycode == 1 || keycode == 125)
		to_bottom(var);
	return (0);
}

void	event_handle(t_tool *var)
{
	mlx_hook(var->var_mlx.win, 17, 0, close_win, var);
	mlx_hook(var->var_mlx.win, 2, 0, key_handler, var);
}

void	main_game(t_tool *var)
{
	char	*move;

	var->var_mlx.mlx = mlx_init();
	if (!var->var_mlx.mlx)
	{
		clear_2d(var->map);
		perror("Error\nmlx fail :(");
		exit(1);
	}
	var->var_mlx.win = mlx_new_window(var->var_mlx.mlx,
			var->size_line * 64, var->line_number * 64, "so_long_bonus");
	check_if_fail(var);
	initial_img(var);
	initial_img_direction(var);
	initial_collec(var);
	set_background(var);
	moves_enemy(var);
	put_the_images(var);
	move = ft_itoa(var->moves);
	mlx_string_put(var->var_mlx.mlx, var->var_mlx.win,
		50, 32, 0x000000, move);
	free(move);
	event_handle(var);
	mlx_loop(var->var_mlx.mlx);
}
