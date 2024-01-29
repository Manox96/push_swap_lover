/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:46:37 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/29 17:49:10 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker_bonus.h"

void	swap_a(t_stack **head, int p)
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
		write(1, "sa\n", 3);
}

void	rotate_a(t_stack **head, int p)
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
		write(1, "ra\n", 3);
}

void	push_a(t_stack **head_b, t_stack **head_a, int p)
{
	t_stack	*the_first;
	t_stack	*second;

	if (*head_b == NULL)
		return ;
	the_first = (*head_b);
	second = (*head_b)->next;
	*head_b = second;
	add_front(head_a, the_first);
	if (p == 1)
		write(1, "pa\n", 3);
}

void	reverse_rotate_a(t_stack **head, int p)
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
		write(1, "rra\n", 4);
}
