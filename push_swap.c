/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:05:19 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/22 13:07:52 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>


void	print_err()
{
	write(2,"Error\n",6);
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
void	print_linkedList(t_stack *a)
{
		t_stack *curr = a;
		printf("\033[0;103m{head}\033[0m\n");
				printf("\033[1;94m  |   \n");
		while (curr != NULL)
		{
			printf("\033[0;20m(%d)\033[0m\033[1;32m[%d]--",curr->rank,curr->content);
			curr = curr->next;
		}
		printf("\033[0;103m|<---tail}\033[0m\n");
}
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*curr_a;
	int	i;
	char		**parsed_input;

	a = NULL;
	b = NULL;
	i = 0;

	if (ac < 2)
		exit(EXIT_FAILURE);
	if (ac >= 2)
	{
		while (i < ac)
		{
			if (is_empty(av[i]))
				print_err();
			i++;
		}
		parsed_input = parsing(ac, av);
		a = to_LinkedList(parsed_input);
		curr_a = a;
		while (curr_a->next != NULL)
			curr_a = curr_a->next;
		if (curr_a->pos <= 3)
		{
			sort_two_and_three(&a);
			return 0;
		}
		if (curr_a->pos <= 5)
		{
			sort_five(&a, &b, curr_a->pos);
			return (0);
		}
		if (curr_a->pos > 5)
		{
			index_from_the_small(&a);
			sort_hundred(&a,&b);
			// print_linkedList(a);
  		}
	}
}
