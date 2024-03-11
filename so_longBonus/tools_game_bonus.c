/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:09:42 by aennaqad          #+#    #+#             */
/*   Updated: 2024/02/24 15:59:07 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_pos_player(t_tool *var);

void	to_top(t_tool *var)
{
	swap_to_top(var);
	printmoves(var);
}

void	to_bottom(t_tool *var)
{
	swap_to_bottom(var);
	printmoves(var);
}

void	to_left(t_tool *var)
{
	swap_to_left(var);
	printmoves(var);
}

void	to_right(t_tool *var)
{
	swap_to_right(var);
	printmoves(var);
}

void	get_pos_player(t_tool *var)
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
			if (var->map[i][j] == 'P')
			{
				var->var_mlx.x = i;
				var->var_mlx.y = j;
			}
			j++;
		}
		i++;
	}
}
