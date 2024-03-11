/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_solong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:44:11 by aennaqad          #+#    #+#             */
/*   Updated: 2024/03/11 11:00:56 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	destory_imgs(t_tool *var)
{
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.floor);
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.player);
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.wall);
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.exite);
	mlx_destroy_image(var->var_mlx.mlx, var->var_mlx.c);
}

void	check_last_line(int i, char *line, t_tool *var, char **array2d)
{
	if (i == var->line_number - 1)
	{
		if (line[var->size_line] == '\n')
		{
			clear_2d(array2d);
			perror("Error\nu add empty line !!");
			exit(EXIT_FAILURE);
		}
	}
}

void	check_size(t_tool *var)
{
	clear_2d(var->map);
	write(1, "window so long\n", 16);
	exit(1);
}

void	flood_fill_e(char **cpy, int x, int y)
{
	if (x < 0 || cpy[x][y] == '1' || cpy[x][y] == 'V')
		return ;
	cpy[x][y] = 'V';
	flood_fill_e(cpy, x + 1, y);
	flood_fill_e(cpy, x - 1, y);
	flood_fill_e(cpy, x, y + 1);
	flood_fill_e(cpy, x, y - 1);
}
