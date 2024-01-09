/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:46:37 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/09 19:55:57 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	// write(1,"sa\n",3);
	printf("\033[1;33;40msa\n");
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
	// write(1,"ra\n",3);
	printf("\033[1;32;40mra\n");

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
	// write(1,"rr\n",3);
	printf("\033[1;36;40mrra\n");

}

void push_b(t_stack **head_a,t_stack **head_b)
{
	//enjoy bb
}



int main()
{
	t_stack *head_a = NULL;
	t_stack *head_b = NULL;

	add_back(&head_a,1,1);
	add_back(&head_a,2,2);
	add_back(&head_a,3,3);
	add_back(&head_a,4,4);
	add_back(&head_a,5,5);
	add_back(&head_a,6,6);


	print_linkedList_two(head_b);

	printf("\n\n");
	// print_linkedList(head_b);

}