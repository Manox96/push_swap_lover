/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:42:33 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/25 16:34:09 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_chunk(t_stack **head_a, int chunk)
{
	t_stack	*curr;

	curr = *head_a;
	while (curr != NULL)
	{
		if (curr->rank < chunk)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	go_to_b(t_stack **head_a, t_stack **head_b, int chunk, int step)
{
	int	c;

	while ((*head_a))
	{
		c = 0;
		while (c < 1)
		{
			if ((*head_a) && (*head_a)->rank < (chunk))
			{
				if ((*head_a)->rank <= (chunk - (step / 2)))
					push_b(head_a, head_b);
				else
				{
					push_b(head_a, head_b);
					retate_b(head_b);
				}
			}
			else if (((*head_a) && (*head_a)->rank >= (chunk)))
				retate_a(head_a);
			c++;
		}
		if (check_chunk(head_a, chunk))
			chunk += step;
	}
}

void	come_back_to_a(t_stack **head_a, t_stack **head_b)
{
	t_stack	*max_node;
	t_stack	*second_max_node;
	int		size;

	search(head_b, &max_node, &second_max_node);
	set_pos_frm_0(head_b);
	size = size_list(head_b);
	if (check_where_in_stack(max_node->pos, second_max_node->pos, size))
	{
		max_to_top_of_b(head_b, max_node);
		push_a(head_b, head_a);
	}
	else
	{
		second_max_to_top_of_b(head_b, second_max_node);
		push_a(head_b, head_a);
		max_to_top_of_b(head_b, max_node);
		push_a(head_b, head_a);
		swap_a(head_a);
	}
}

void	which_chunk(t_stack **head_a, int *chunk, int *step)
{
	int	size;

	size = size_list(head_a);
	if (size <= 200)
	{
		*chunk = size_list(head_a) / 5;
		*step = size_list(head_a) / 5;
	}
	else
	{
		*chunk = size_list(head_a) / 10;
		*step = size_list(head_a) / 10;
	}
}

void	sort_hundred(t_stack **head_a, t_stack **head_b)
{
	int	chunk;
	int	step;
	int	size_b;

	index_from_the_small(head_a);
	if (check_is_sorted(head_a))
		return ;
	which_chunk(head_a, &chunk, &step);
	go_to_b(head_a, head_b, chunk, step);
	size_b = size_list(head_b);
	while (size_b > 1)
	{
		come_back_to_a(head_a, head_b);
		size_b = size_list(head_b);
	}
	if (size_b == 1 && (*head_b))
		push_a(head_b, head_b);
}
