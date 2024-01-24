/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:42:33 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/24 21:39:17 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


void search_max_and_second_max(t_stack **head, t_stack **max_node, t_stack **second_max_node)
{
    *max_node = NULL;
    *second_max_node = NULL;
    t_stack *current = *head;
    while (current != NULL)
    {
        if (*max_node == NULL || current->content > (*max_node)->content)
        {
            *second_max_node = *max_node;
            *max_node = current;
        }
        else if (*second_max_node == NULL || current->content > (*second_max_node)->content)
            *second_max_node = current;
        current = current->next;
    }
}
void	max_to_top_of_b(t_stack **head_b , t_stack *max_node)
{
	int	size;

	size = size_list(head_b);
	set_pos_frm_0(head_b);

	if (max_node->pos < size / 2)
		while ((*head_b) != max_node)
			retate_b(head_b);
	else
		while ((*head_b) != max_node)
			reverse_retate_b(head_b);

}
void	second_max_to_top_of_b(t_stack **head_b , t_stack *second_node)
{
	int	size;
	size = size_list(head_b);
	set_pos_frm_0(head_b);

	if (second_node->pos < size / 2)
		while ((*head_b) != second_node)
			retate_b(head_b);
	else
		while ((*head_b) != second_node)
			reverse_retate_b(head_b);

}

int check_where_in_stack(int larg, int second_larg, int size_list)
{
	int x = 0;
	int y = 0;
	if (larg < size_list / 2)
		x = larg;
	else
		x = size_list - larg + 1;

	if (second_larg < size_list / 2)
		y = second_larg;
	else
		y = size_list - second_larg + 1;

	if (y >= x)
		return (1);
	else
		return (0);
}
void come_back_to_a(t_stack **head_a, t_stack **head_b)
{
	t_stack	*max_node;
	t_stack	*second_max_node;
	int	size;

	search_max_and_second_max(head_b, &max_node, &second_max_node);
	set_pos_frm_0(head_b);
	// print_linkedList(*head_b);

	size = size_list(head_b);

	if (check_where_in_stack(max_node->pos, second_max_node->pos, size))
	{
		max_to_top_of_b(head_b,max_node);
		push_a(head_b, head_a);
	}
	else
	{
		second_max_to_top_of_b(head_b,second_max_node);
		push_a(head_b, head_a);
		max_to_top_of_b(head_b,max_node);
		push_a(head_b, head_a);
		swap_a(head_a);
	}
}


int	check_chunk(t_stack **head_a, int chunk)
{
	t_stack *curr;

	curr = *head_a;
	while (curr != NULL)
	{
		if (curr->rank < chunk)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void sort_hundred(t_stack **head_a, t_stack **head_b)
{
	index_from_the_small(head_a);
	int chunk;
	int step;
	int size = size_list(head_a);

	if (check_is_sorted(head_a))
		return;
	if (size <= 200)
	{
		chunk = size_list(head_a) / 5;
		step = size_list(head_a) / 5;
	}
	else
	{
		chunk = size_list(head_a) / 10;
		step = size_list(head_a) / 10;
	}
	int c;
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
			chunk+=step;
	}
	int b = size_list(head_b);
	while (b > 1)
	{
		come_back_to_a(head_a, head_b);
		b = size_list(head_b);
	}
	if (b == 1 && (*head_b))
		push_a(head_b, head_b);


}