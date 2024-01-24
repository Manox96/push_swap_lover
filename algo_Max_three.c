/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_Max_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:47:36 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/24 21:21:27 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **head)
{
	int a;
	int b;
	int c;

	if (check_is_sorted(head))
		return;
	a = (*head)->content;
	b = (*head)->next->content;
	c = (*head)->next->next->content;
	if (a > b && b < c && c > a)
		swap_a(head);
	else if (a > b && b > c)
	{
		swap_a(head);
		reverse_retate_a(head);
	}
	else if (a < b && b > c && c > a)
	{
		swap_a(head);
		retate_a(head);
	}
	else if (a > b && b < c && c < a)
		retate_a(head);
	else if (a < b && b > c && c < a)
		reverse_retate_a(head);
}

void	sort_two(t_stack **head)
{
	t_stack *curr;
	int a;
	int b;

	curr = *head;
	a = curr->content;
	b = curr->next->content;
	if (a > b)
		swap_a(head);
}
void sort_two_and_three(t_stack **head)
{
	t_stack	*curr;
	int		c;

	c = 0;
	curr = *head;
	while (curr != NULL)
	{
		c++;
		curr = curr->next;
	}
	if (c == 1)
		return;
	else if (c == 2)
		sort_two(head);
	else if(c >= 3 && c <= 5)
		sort_three(head);
}
