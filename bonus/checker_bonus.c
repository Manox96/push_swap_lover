/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:23:33 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/29 16:30:31 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker_bonus.h"
#include "get_next_line/get_next_line.h"

int	is_sorted(t_stack **head_a)
{
	t_stack	*curr_a;
	t_stack	*nexto;

	curr_a = *head_a;
	nexto = curr_a->next;
	while (curr_a->next != NULL)
	{
		if (curr_a->content > nexto->content)
			return (0);
		curr_a = curr_a->next;
		nexto = curr_a->next;
	}
	return (1);
}

void	check_actions(char *actions, t_stack **a, t_stack **b)
{
	if (my_strcmp("sa\n", actions) == 0)
		swap_a(a, 0);
	else if (my_strcmp("sb\n", actions) == 0)
		swap_b(b, 0);
	else if (my_strcmp("pa\n", actions) == 0)
		push_a(b, a, 0);
	else if (my_strcmp("pb\n", actions) == 0)
		push_b(a, b, 0);
	else if (my_strcmp("ra\n", actions) == 0)
		rotate_a(a, 0);
	else if (my_strcmp("rb\n", actions) == 0)
		rotate_b(b, 0);
	else if (my_strcmp("rra\n", actions) == 0)
		reverse_rotate_a(a, 0);
	else if (my_strcmp("rrb\n", actions) == 0)
		reverse_rotate_b(b, 0);
	else if (my_strcmp("rr\n", actions) == 0)
		rr(a, b, 0);
	else if (my_strcmp("rrr\n", actions) == 0)
		rrr(a, b, 0);
	else if (my_strcmp("ss\n", actions) == 0)
		ss(a, b, 0);
	else
		print_err();
}

void	its_ok(t_stack **head_a, t_stack **head_b)
{
	if (*head_b == NULL && is_sorted(head_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	legend(char *actions, t_stack **a, t_stack **b)
{
	while (1)
	{
		actions = get_next_line(0);
		if (!actions)
			break ;
		check_actions(actions, a, b);
		free(actions);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*actions;
	int		i;
	char	**parsed_input;

	a = NULL;
	actions = NULL;
	i = 0;
	if (ac < 2)
		exit(EXIT_FAILURE);
	else
	{
		while (i < ac)
		{
			if (is_empty(av[i]))
				return (0);
			i++;
		}
		parsed_input = parsing(ac, av);
		a = to_linkedlist(parsed_input);
		legend(actions, &a, &b);
		its_ok(&a, &b);
	}
}
