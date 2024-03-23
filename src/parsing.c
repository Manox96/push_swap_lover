/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:04:57 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/30 10:34:58 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			if (ft_isdigit(str[i++]))
				return (0);
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_double(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (my_atoi(av[i]) == my_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**parsing(int ac, char **av)
{
	char	**splited_arg;
	int		i;

	i = 0;
	splited_arg = NULL;
	splited_arg = ft_split(joined_arg(ac, av + 1), ' ');
	while (splited_arg[i])
	{
		if (!(only_digit(splited_arg[i])))
			print_err();
		i++;
	}
	if (!check_double(splited_arg))
		print_err();
	return (splited_arg);
}
