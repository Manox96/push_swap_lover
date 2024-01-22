/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:42:33 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/22 13:46:43 by aennaqad         ###   ########.fr       */
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
        {
            *second_max_node = current;
        }
        current = current->next;
    }
}



void	push_to_b(t_stack **head_a, t_stack **head_b)
{
	t_stack *second_max_node;
	t_stack *max_node;
	int	size;

	search_max_and_second_max(head_b, &max_node, &second_max_node);
	set_pos_frm_0(head_b);
	// enjoy bb


}

void sort_hundred(t_stack **head_a, t_stack **head_b)
{
	index_from_the_small(head_a);
	int chunk = size_list(head_a) / 5;
	int step = size_list(head_a) / 5;

	int c;
	c = 0;
	while (*head_a)
	{
		c = 0;
		while (c <= step)
		{
			c++;
			if ((*head_a) && (*head_a)->rank < (chunk))
			{
				if ((*head_a)->rank < (chunk - (chunk / 2)))
					push_b(head_a, head_b);
				else if ((*head_a) && (*head_a)->rank >= (chunk - (chunk / 2)) && (*head_a)->rank < (chunk))
				{
					push_b(head_a, head_b);
					retate_b(head_b);
				}
			}
			else
				retate_a(head_a);
		}
		chunk+=chunk;
	}

   //  int b_size = size_list(head_b);
   //  while (b_size > 1)
   //  {
	while (*head_b)
      push_to_b(head_a, head_b);
   //      b_size = size_list(head_b);
   //  }
   //  if (b_size == 1)
   //      push_a(head_b, head_a);
}