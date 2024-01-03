/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:04:57 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/03 18:21:22 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>


// no other input than integers (ok)
// no duplicates  (ok)
// it should be able to read bash ./push_swap 2 3 "1 4  "  (ok)
// Else, it should exit the program with "Error\n" in the error output.

int	only_digit(char *str)
{
	int i = 0;
	while (str[i])
	{
		// i == 0 to we need - or + at the beginning of number
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
		{
			if (ft_isdigit(str[i++]))
					return (0);
		}
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
int	check_double_and_max_min_int(char **av)
{
	int i = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) >= INT_MAX || ft_atoi(av[i]) <= INT_MIN)
			return (0);
		i++;
	}
	i = 0;
	int j = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
char **parsing(int ac, char **av)
{
	char	**splited_arg;
	int i;

	i = 0;
	splited_arg = NULL;

	splited_arg = ft_split(joined_arg(ac, av + 1),' ');   //[" '---' '---' '---' '---' ""]
	while (splited_arg[i])
	{
		if (!(only_digit(splited_arg[i])))
			print_err();
		i++;
	}
	if (!check_double_and_max_min_int(splited_arg))
		print_err();
	return (splited_arg);
}

