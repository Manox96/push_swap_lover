/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:57:55 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/27 15:25:56 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	swap_b(t_stack **head, int p)
{
	t_stack	*curr;
	t_stack	*nexto;

	if ((*head == NULL) || ((*head)->next == NULL))
		return ;
	curr = *head;
	nexto = curr->next;
	curr->next = curr->next->next;
	nexto->next = curr;
	*head = nexto;
	if (p == 1)
		write(1, "sb\n", 3);
}

void	push_b(t_stack **head_a, t_stack **head_b, int p)
{
	t_stack	*the_first;
	t_stack	*second;

	if (*head_a == NULL)
		return ;
	the_first = (*head_a);
	second = (*head_a)->next;
	*head_a = second;
	add_front(head_b, the_first);
	if (p == 1)
		write(1, "pb\n", 3);
}

void	rotate_b(t_stack **head, int p)
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
	if (p == 1)
		write(1, "rb\n", 3);
}

void	reverse_rotate_b(t_stack **head, int p)
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
	if (p == 1)
		write(1, "rrb\n", 4);
}
