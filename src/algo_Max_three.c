/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_Max_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:47:36 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/30 09:48:44 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_three(t_stack **head)
{
	t_stack	*max;
	t_stack	*middle;

	set_pos_frm_0(head);
	search(head, &max, &middle);
	if (max->pos == 0)
	{
		rotate_a(head, 1);
		if ((*head)->content > (*head)->next->content)
			swap_a(head, 1);
	}
	else if (max->pos == 1)
		reverse_rotate_a(head, 1);
	if ((*head)->content > (*head)->next->content)
		swap_a(head, 1);
}

void	sort_two(t_stack **head)
{
	t_stack	*curr;
	int		a;
	int		b;

	curr = *head;
	a = curr->content;
	b = curr->next->content;
	if (a > b)
		swap_a(head, 1);
}

void	sort_two_and_three(t_stack **head)
{
	int		size;

	size = size_list(head);
	if (size == 1)
		return ;
	else if (size == 2)
		sort_two(head);
	else if (size >= 3 && size <= 5)
		sort_three(head);
}
