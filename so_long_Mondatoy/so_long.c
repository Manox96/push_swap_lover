/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:34:37 by aennaqad          #+#    #+#             */
/*   Updated: 2024/03/09 17:05:24 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	its_ok(int ac, char **av)
{
	char	*the_file_name;
	int		check;
	int		fd;

	if (ac != 2)
	{
		perror("Error\nplease follow this : ./so_long <file.ber> ");
		exit(1);
	}
	the_file_name = av[1];
	check = check_extention(the_file_name);
	if (!check)
	{
		perror("Error\nextention error the extention should be '.ber'");
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nthis file do not existe");
		exit(1);
	}
	return (fd);
}

char	*alloconeline(char *str, int size_line)
{
	t_tool	var;
	char	*line;

	var.i = 0;
	var.len = strlen_nl(str);
	if (size_line != var.len)
	{
		write(2, "Error\n", 6);
		write(2, "lines is not the same !\n", 25);
		exit(EXIT_FAILURE);
	}
	line = malloc(sizeof(char) * (var.len + 1));
	if (!line)
		return (NULL);
	line[var.len] = '\0';
	while (var.i < var.len)
	{
		line[var.i] = str[var.i];
		var.i++;
	}
	return (line);
}

char	**fill_2d_array(char *line, t_tool *var)
{
	int		i;
	char	**array2d;

	i = 0;
	array2d = malloc((var->line_number + 1) * (sizeof(char *)));
	if (!array2d)
		return (NULL);
	array2d[var->line_number] = NULL;
	while (i < var->line_number)
	{
		array2d[i] = alloconeline(line, var->size_line);
		if (!array2d[i])
			return (clear_2d(array2d), NULL);
		if (i == var->line_number - 1)
			check_last_line(i, line, var, array2d);
		free(line);
		line = get_next_line(var->fd);
		i++;
	}
	return (array2d);
}

void	check_its_pos_win(t_tool *var)
{
	int		x;
	int		y;
	char	**cpy;

	cpy = copy_original(var->map, var->line_number, var->size_line);
	flood_fill(cpy, var->x, var->y);
	check_only_v_0_1_(cpy);
	clear_2d(cpy);
	get_exit_pos(var->map, &x, &y);
	cpy = copy_original(var->map, var->line_number, var->size_line);
	flood_fill_e(cpy, x, y);
	check_only_v_0_1_(cpy);
	clear_2d(cpy);
}

int	main(int ac, char **av)
{
	t_tool	var;

	var.fd = its_ok(ac, av);
	var.line_number = coun_line(var.fd);
	var.fd = open(av[1], O_RDONLY);
	if (var.fd == -1)
		printerror();
	var.line = get_next_line(var.fd);
	var.size_line = strlen_nl(var.line);
	var.map = fill_2d_array(var.line, &var);
	close(var.fd);
	if (!var.map)
	{
		perror("nothing allocated !!");
		exit(0);
	}
	check_ones(var.map, var.line_number, var.size_line);
	check_p_c_e(var.map);
	find_cor(var.map, &var.x, &var.y);
	check_its_pos_win(&var);
	main_game(&var);
}
