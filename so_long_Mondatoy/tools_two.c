/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:56:06 by aennaqad          #+#    #+#             */
/*   Updated: 2024/03/09 16:05:40 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_cor(char **map, int *x, int *y)
{
	t_tool	var;

	var.i = 0;
	var.j = 0;
	while (map[var.i])
	{
		var.j = 0;
		while (map[var.i][var.j])
		{
			if (map[var.i][var.j] == 'P')
			{
				*x = var.i;
				*y = var.j;
			}
			var.j++;
		}
		var.i++;
	}
}

char	**copy_original(char **original, int height, int width)
{
	char		**copy;
	t_tool		var;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	copy[height] = NULL;
	var.i = 0;
	var.j = 0;
	while (var.i < height)
	{
		var.j = 0;
		copy[var.i] = malloc(sizeof(char) * (width + 1));
		if (!copy[var.i])
			return (clear_2d(copy), NULL);
		while (var.j < width)
		{
			copy[var.i][var.j] = original[var.i][var.j];
			var.j++;
		}
		copy[var.i][width] = '\0';
		var.i++;
	}
	return (copy);
}

void	check_only_v_0_1_(char **str)
{
	t_tool	var;

	var.i = 0;
	var.j = 0;
	while (str[var.i])
	{
		var.j = 0;
		while (str[var.i][var.j])
		{
			if (str[var.i][var.j] == 'V' || str[var.i][var.j] == '1'
				|| str[var.i][var.j] == '0' || str[var.i][var.j] == 'E')
				var.j++;
			else
			{
				clear_2d(str);
				write(1, "Impossible to win !!\n", 21);
				exit(1);
			}
		}
		var.i++;
	}
}

void	clear_2d(char **str)
{
	t_tool	var;

	var.i = 0;
	while (str[var.i])
	{
		free(str[var.i]);
		var.i++;
	}
	free(str);
}

void	initialize_var(t_tool *var)
{
	var->var_mlx.c = NULL;
	var->var_mlx.player = NULL;
	var->var_mlx.exite = NULL;
	var->var_mlx.wall = NULL;
	var->var_mlx.floor = NULL;
	var->c = 0;
	var->e = 0;
	var->p = 0;
	var->i = 0;
	var->j = 0;
	var->size_line = 0;
	var->line_number = 0;
	var->fd = 0;
	var->len = 0;
	var->x = 0;
	var->y = 0;
}
