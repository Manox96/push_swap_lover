/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_game_three_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:01:03 by aennaqad          #+#    #+#             */
/*   Updated: 2024/03/02 12:49:02 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_c(char **str)
{
	t_tool	p;

	p.i = 0;
	p.j = 0;
	p.c = 0;
	while (str[p.i])
	{
		p.j = 0;
		while (str[p.i][p.j])
		{
			if (str[p.i][p.j] == 'C')
				return (0);
			p.j++;
		}
		p.i++;
	}
	return (1);
}

void	set_background(t_tool *var)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	while (var->map[i])
	{
		j = 0;
		x = 0;
		while (var->map[i][j])
		{
			mlx_put_image_to_window(var->var_mlx.mlx,
				var->var_mlx.win, var->var_mlx.floor, x, y);
			j++;
			x += 64;
		}
		i++;
		y += 64;
	}
}

int	close_win(t_tool *var)
{
	destory_imgs(var);
	mlx_destroy_window(var->var_mlx.mlx, var->var_mlx.win);
	exit(0);
}

void	put_the_images(t_tool *var)
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
			var->var_mlx.x_img = inc.x;
			which_img(var, inc.i, inc.j);
			inc.j++;
			inc.x += 64;
		}
		inc.i++;
		inc.y += 64;
		var->var_mlx.y_img = inc.y;
	}
}

void	check_last_line(int i, char *line, t_tool *var, char **array2d)
{
	if (i == var->line_number - 1)
	{
		if (line[var->size_line] == '\n')
		{
			clear_2d(array2d);
			perror("u add empty line !!");
			exit(EXIT_FAILURE);
		}
	}
}
