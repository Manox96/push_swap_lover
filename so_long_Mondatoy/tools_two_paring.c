/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_two_paring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:05:05 by aennaqad          #+#    #+#             */
/*   Updated: 2024/02/26 21:24:53 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				|| str[var.i][var.j] == 'C')
				var.j++;
			else
			{
				perror("Error\na stranger at the map :(");
				exit(1);
			}
		}
		var.i++;
	}
}

void	print_stranger_error(int p, int c, int e)
{
	if (p != 1)
		perror("Error\nmust be one player!!");
	if (c < 1)
		perror("Error\nshould a munimum one collectble !!");
	if (e != 1)
		perror("Error\nmust be one exit !!");
	exit(EXIT_FAILURE);
}

void	check_p_c_e(char **str)
{
	t_tool	p;

	initialize_var(&p);
	check_stranger(str);
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
			p.j++;
		}
		p.i++;
	}
	if (p.p != 1 || p.c == 0 || p.e != 1)
		print_stranger_error(p.p, p.c, p.e);
}

void	collectable(t_tool *var, int x, int y)
{
	mlx_put_image_to_window(var->var_mlx.mlx,
		var->var_mlx.win, var->var_mlx.floor,
		x, y);
}

void	chek_wall(t_tool *var)
{
	if (chech_collectble(var->map))
	{
		destory_imgs(var);
		clear_2d(var->map);
		mlx_destroy_window(var->var_mlx.mlx, var->var_mlx.win);
		write(1, "MBROUUUUUUUUUK !!\n", 18);
		exit(EXIT_SUCCESS);
	}
}
