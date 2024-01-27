/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_algo_hundred.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:09:18 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/27 14:46:03 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search(t_stack **head, t_stack **max_node, t_stack **second_max_node)
{
	t_stack	*curr_h;

	*max_node = NULL;
	*second_max_node = NULL;
	curr_h = *head;
	while (curr_h != NULL)
	{
		if (*max_node == NULL || curr_h->content > (*max_node)->content)
		{
			*second_max_node = *max_node;
			*max_node = curr_h;
		}
		else if (*second_max_node == NULL
			|| (curr_h->content > (*second_max_node)->content))
			*second_max_node = curr_h;
		curr_h = curr_h->next;
	}
}

void	max_to_top_of_b(t_stack **head_b, t_stack *max_node)
{
	int	size;

	size = size_list(head_b);
	set_pos_frm_0(head_b);
	if (max_node->pos < size / 2)
		while ((*head_b) != max_node)
			rotate_b(head_b, 1);
	else
		while ((*head_b) != max_node)
			reverse_rotate_b(head_b, 1);
}

void	second_max_to_top_of_b(t_stack **head_b, t_stack *second_node)
{
	int	size;

	size = size_list(head_b);
	set_pos_frm_0(head_b);
	if (second_node->pos < size / 2)
		while ((*head_b) != second_node)
			rotate_b(head_b, 1);
	else
		while ((*head_b) != second_node)
			reverse_rotate_b(head_b, 1);
}

int	check_where_in_stack(int larg, int second_larg, int size_list)
{
	int	x;
	int	y;

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
