/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:46:27 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/29 16:29:54 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	size_list(t_stack **head)
{
	int		c;
	t_stack	*curr;

	c = 0;
	curr = *head;
	while (curr != NULL)
	{
		c++;
		curr = curr->next;
	}
	return (c);
}

void	to_top_of_node(t_stack **head)
{
	int		min_node_pos;
	int		size;

	min_node_pos = min_node(head);
	size = size_list(head);
	if (min_node_pos == (size / 2))
		rotate_a(head, 1);
	else if (min_node_pos > (size / 2))
	{
		while ((*head)->pos != min_node_pos)
			reverse_rotate_a(head, 1);
	}
}

void	add_front(t_stack **head_b, t_stack *node)
{
	t_stack	*curr;

	if (!head_b || !node)
		return ;
	curr = *head_b;
	node->next = curr;
	*head_b = node;
}
