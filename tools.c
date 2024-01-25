/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:45:35 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/25 15:50:30 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	update_index(t_stack **head)
{
	t_stack	*curr;
	int		i;

	i = 0;
	curr = *head;
	while (curr != NULL)
	{
		++i;
		curr->pos = i;
		curr = curr->next;
	}
}

void	set_pos_frm_0(t_stack **head)
{
	t_stack	*curr;
	int		i;

	i = -1;
	curr = *head;
	while (curr != NULL)
	{
		++i;
		curr->pos = i;
		curr = curr->next;
	}
}

int	min_node(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*min;
	int		i;

	i = 0;
	tmp = *head;
	min = tmp;
	while (tmp != NULL)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min->pos);
}

t_stack	*min_node_addrs(t_stack **head_a)
{
	t_stack	*curr;
	t_stack	*min;

	curr = *head_a;
	while (curr && curr->is_visited == 1)
		curr = curr->next;
	min = curr;
	while (curr)
	{
		if (curr->is_visited == 0 && curr->content < min->content)
			min = curr;
		curr = curr->next;
	}
	return (min);
}

void	index_from_the_small(t_stack **head_a)
{
	t_stack	*min_node;
	int		rank;

	min_node = min_node_addrs(head_a);
	rank = 0;
	while (min_node != NULL)
	{
		min_node->rank = rank++;
		min_node->is_visited = 1;
		min_node = min_node_addrs(head_a);
	}
}
