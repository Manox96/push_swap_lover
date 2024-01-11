/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:46:37 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/11 16:15:51 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void swap_A(t_stack **head)
{
	t_stack *curr;
	t_stack *nexto;

	if(*head == NULL || (*head)->next == NULL)
		return;
	curr = *head;
	nexto = curr->next;

	curr->next = curr->next->next;
	nexto->next = curr;
	*head = nexto;
	write(1,"sa\n",3);
	// printf("\033[1;33;40msa\n");
}
void retate_A(t_stack **head)
{
	t_stack *curr;
	t_stack *first;
	t_stack *nexto;

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
	write(1,"ra\n",3);
	// printf("\033[1;32;40mra\n");

}

void	reverse_retate(t_stack **head)
{
	t_stack *curr;
	t_stack *last;

	curr = *head;
	while (curr->next->next != NULL)
	{
		curr = curr->next;
	}
	last = curr->next;
	curr->next = NULL;
	last->next = *head;
	*head = last;
	write(1,"rra\n",4);
	// printf("\033[1;36;40mrra\n");

}

void push_b(t_stack **head_a,t_stack **head_b)
{
	//enjoy bb
	t_stack	*the_first;
	t_stack	*curr_a;
	int	min_Node_pos;
	int	size;

	if (*head_a == NULL)
		return;

	to_top_of_node(head_a);

	the_first = (*head_a);
	curr_a = (*head_a)->next;
	*head_a = curr_a;
	add_front(head_b,the_first);
	update_index(head_a);
	write(1,"pb\n",3);
	// printf("\033[1;36;40mpb\n");
}
void push_a(t_stack **head_b,t_stack **head_a)
{
	t_stack	*ptr_to_last_b;
	t_stack	*ptr_to_first_b;

	ptr_to_last_b = (*head_b)->next;
	ptr_to_first_b = (*head_b);

	ptr_to_first_b->next = (*head_a);
	(*head_a) = ptr_to_first_b;
	(*head_b) = ptr_to_last_b;
	write(1,"pa\n",3);
	// printf("\033[1;36;40mpa\n");
}