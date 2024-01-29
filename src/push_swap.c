/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:05:19 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/29 16:47:32 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include <stdlib.h>

void	print_err(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	sort(t_stack **a, t_stack **b)
{
	int	size;

	size = size_list(a);
	if (size <= 3)
		sort_two_and_three(a);
	else if (size >= 4 && size <= 5)
		sort_five(a, b, size);
	else if (size >= 6)
		sort_hundred(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	char	**parsed_input;

	a = NULL;
	b = NULL;
	i = 0;
	if (ac < 2)
		exit(EXIT_SUCCESS);
	if (ac >= 2)
	{
		while (i < ac)
		{
			if (is_empty(av[i]))
				print_err();
			i++;
		}
		parsed_input = parsing(ac, av);
		a = to_linkedlist(parsed_input);
		sort(&a, &b);
	}
}
