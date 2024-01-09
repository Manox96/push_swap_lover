/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:05:19 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/09 19:53:06 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
void print_linkedList(t_stack *a)
{
		t_stack *curr = a;
		printf("\033[0;103m{head}\033[0m\n");
				printf("\033[1;94m  |   \n");
		while (curr != NULL)
		{
			printf("\033[0;47m(%d)\033[0m\033[1;32m[%d]--",curr->pos,curr->content);
			curr = curr->next;
		}
		printf("\033[0;103m|<---tail}\033[0m");
		printf("\033[0;94m  | a linkedList created by aymane\n");
}
int main(int ac, char **av)
{
	t_stack	*a;
	int		i;
	char		**parsed_input;

	a = NULL;
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
		a = to_LinkedList(parsed_input);
		sort_two_and_three(&a);
		print_linkedList(a);
	}
}
