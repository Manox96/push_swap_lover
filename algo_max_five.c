/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_max_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:58:10 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/17 21:29:38 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	check_is_sorted(t_stack	**head_a)
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

void	sort_five(t_stack **head_a ,t_stack **head_b, int pos)
{
	if (check_is_sorted(head_a))
		return;
	if (pos == 4)
	{
		to_top_of_node(head_a);
		push_b(head_a, head_b);
		sort_two_and_three(head_a);
		push_a(head_b, head_a);
	}
	else if (pos == 5)
	{
		to_top_of_node(head_a);
		push_b(head_a, head_b);
		update_index(head_a); // this is important
		to_top_of_node(head_a);
		push_b(head_a, head_b);
		sort_two_and_three(head_a);
		push_a(head_b, head_a);
		push_a(head_b, head_a);
	}
} 