/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_two_paring_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:05:05 by aennaqad          #+#    #+#             */
/*   Updated: 2024/03/02 16:37:55 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_stranger(char **str)
{
	t_tool	var;

	var.i = 0;
	var.j = 0;
	while (str[var.i])
	{
		var.j = 0;
		while (str[var.i][var.j])
		{
			if (str[var.i][var.j] == '0' || str[var.i][var.j] == '1'
				|| str[var.i][var.j] == 'P' || str[var.i][var.j] == 'E'
				|| str[var.i][var.j] == 'C' || str[var.i][var.j] == 'X')
				var.j++;
			else
				printerror();
		}
		var.i++;
	}
}

void	print_stranger_error(int p, int c, int e, int x)
{
	if (p != 1)
		perror("Error\nmust be one player!!");
	if (c < 1)
		perror("Error\nshould a munimum one collectble !!");
	if (e != 1)
		perror("Error\nmust be one exit !!");
	if (x != 1)
		perror("Error\nmust be  one enemy !!");
}

void	check_p_c_e(t_tool p, char **str)
{
	initialize_var(&p);
	while (str[p.i])
	{
		p.j = 0;
		while (str[p.i][p.j])
		{
			if (str[p.i][p.j] == 'P')
				p.p += 1;
			if (str[p.i][p.j] == 'E')
				p.e += 1;
			if (str[p.i][p.j] == 'C')
				p.c += 1;
			if (str[p.i][p.j] == 'X')
				p.enemy += 1;
			p.j++;
		}
		p.i++;
	}
	if (p.p != 1 || p.c == 0 || p.e != 1 || p.enemy != 1)
	{
		print_stranger_error(p.p, p.c, p.e, p.enemy);
		clear_2d(str);
		exit(EXIT_FAILURE);
	}
}

void	collectable(t_tool *var, int x, int y)
{
	if (var->map[y / 64][x / 64] == 'X')
	{
		clear_2d(var->map);
		destory_imgs(var);
		mlx_destroy_window(var->var_mlx.mlx, var->var_mlx.win);
		write(2, "you lose !\n", 11);
		exit(1);
	}
	mlx_put_image_to_window(var->var_mlx.mlx,
		var->var_mlx.win, var->var_mlx.floor,
		x, y);
}

void	chek_wall(t_tool *var)
{
	if (chech_collectble(var->map))
	{
		clear_2d(var->map);
		destory_imgs(var);
		mlx_destroy_window(var->var_mlx.mlx, var->var_mlx.win);
		write(1, "you win congratulations\n", 25);
		exit(EXIT_SUCCESS);
	}
}
