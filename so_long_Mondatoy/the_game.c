/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:26:58 by aennaqad          #+#    #+#             */
/*   Updated: 2024/03/02 12:49:18 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initial_img(t_tool *var)
{
	int		img_width;
	int		img_height;

	var->var_mlx.floor = mlx_xpm_file_to_image(var->var_mlx.mlx,
			"./textures/floor.xpm", &img_width, &img_height);
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
			|| !var->var_mlx.exite))
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
	if (var->map[i][j] == 'C')
		mlx_put_image_to_window(var->var_mlx.mlx,
			var->var_mlx.win, var->var_mlx.c,
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
		swap_to_top(var);
	else if (keycode == 0 || keycode == 123)
		swap_to_left(var);
	else if (keycode == 2 || keycode == 124)
		swap_to_right(var);
	else if (keycode == 1 || keycode == 125)
		swap_to_bottom(var);
	return (0);
}

void	event_handle(t_tool *var)
{
	mlx_hook(var->var_mlx.win, 17, 0, close_win, var);
	mlx_hook(var->var_mlx.win, 2, 0, key_handler, var);
}

void	main_game(t_tool *var)
{
	if ((var->size_line * 64) > 3200 || ((var->line_number) * 64) > 1800)
		check_size(var);
	var->var_mlx.mlx = mlx_init();
	if (!var->var_mlx.mlx)
	{
		clear_2d(var->map);
		perror("mlx fail :(");
		exit(1);
	}
	var->var_mlx.win = mlx_new_window(var->var_mlx.mlx,
			var->size_line * 64, var->line_number * 64, "so_long");
	if (!var->var_mlx.win)
	{
		clear_2d(var->map);
		perror("Error\nmlx open win fail !!");
		exit(1);
	}
	initial_img(var);
	set_background(var);
	put_the_images(var);
	event_handle(var);
	mlx_loop(var->var_mlx.mlx);
}
