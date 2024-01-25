/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:57:55 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/25 15:59:46 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack **head_a, t_stack **head_b)
{
	t_stack	*the_first;
	t_stack	*second;

	if (*head_a == NULL)
		return ;
	the_first = (*head_a);
	second = (*head_a)->next;
	*head_a = second;
	add_front(head_b, the_first);
	write(1, "pb\n", 3);
}

void	retate_b(t_stack **head)
{
	t_stack	*curr;
	t_stack	*first;
	t_stack	*nexto;

	if ((*head == NULL) || ((*head)->next == NULL))
		return ;
	first = *head;
	nexto = (*head)->next;
	*head = nexto;
	curr = *head;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	reverse_retate_b(t_stack **head)
{
	t_stack	*curr;
	t_stack	*last;

	if ((*head == NULL) || ((*head)->next == NULL))
		return ;
	curr = *head;
	while (curr->next->next != NULL)
	{
		curr = curr->next;
	}
	last = curr->next;
	curr->next = NULL;
	last->next = *head;
	*head = last;
	write(1, "rrb\n", 4);
}
