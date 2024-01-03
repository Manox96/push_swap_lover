/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:05:19 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/03 18:22:05 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void	print_err()
{
	write(2,"Error\n",6);
	exit(EXIT_FAILURE);
}
int	is_empty(char *str)
{
	int i = 0;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int main(int ac,char **av)
{
	my_stack	*a;
	my_stack	*b;
	int		i;
	char		**parsed_input;

	a = NULL;
	b = NULL;
	i = 0;

	if (ac < 2)
		print_err();
	if (ac >= 2)
	{
		while (i < ac)
		{
			if (is_empty(av[i]))
				print_err();
			i++;
		}
		parsed_input = parsing(ac, av);
	}
}