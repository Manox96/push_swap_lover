/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_argsJoin_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:47:05 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/27 16:48:02 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	total_argslen(int ac, char **av)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (i < ac - 1)
	{
		size += ft_strlen(av[i]);
		i++;
	}
	size += ac - 2;
	return (size);
}

char	*joined_arg(int ac, char **av)
{
	char	*joined;
	int		i;
	size_t	j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	joined = malloc((total_argslen(ac, av) + 1) * sizeof(char));
	while (i < ac - 1)
	{
		j = 0;
		while (j < ft_strlen(av[i]))
		{
			joined[k] = av[i][j];
			j++;
			k++;
		}
		if (!(i == ac - 2))
			joined[k++] = ' ';
		i++;
	}
	joined[k] = '\0';
	return (joined);
}
