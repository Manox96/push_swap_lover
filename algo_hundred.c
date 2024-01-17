/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:42:33 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/17 15:46:02 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h> // for rand() function
#include <time.h>

void	update_pvs(t_stack **head_a, int *last_piv, int *pivot1, int *pivot2)
{
	*last_piv = *pivot1;
	*pivot1 += size_list(head_a) / 3;
	*pivot2 = size_list(head_a) / 6 + *pivot1;
}

int last_node(t_stack **head)
{
	t_stack *curr;

	curr = *head;
	while(curr->next != NULL)
	{
		curr = curr->next;
	}
	return curr->pos;

}


void	sort_hundred(t_stack **head_a, t_stack **head_b)
{
	set_index_frm_0(head_a);
	int	lastPiv;
	int	pivot1;
	int	pivot2;

	pivot1 = size_list(head_a) / 3;
	pivot2 = size_list(head_a) / 6;
	lastPiv = -1;
	while (size_list(head_a) > 3)
	{
		if (size_list(head_b) > 1
			&& ((*head_a)->pos) > pivot1
			&& (((*head_b)->pos) > lastPiv && ((*head_b)->pos) < pivot2))
			rr(head_a,head_b);
		else if ((size_list(head_b) > 1)
			&& (((*head_b)->pos) > lastPiv && ((*head_b)->pos) < pivot2))
			retate_b(head_b);
		if (((*head_a)->pos) < pivot1)
			push_b(head_a,head_b);
		else
			retate_a(head_a);
		if (size_list(head_a) >= pivot1)
			update_pvs(head_a ,&lastPiv, &pivot1, &pivot2);
	}
}



// int main()
// {
// 	t_stack *head_a;
// 	t_stack *head_b;

// 	head_a = NULL;
// 	head_b = NULL;

// 	int i = 100;
// 	int c = 0;
// 	while (i--)
// 	{
// 		add_back(&head_a ,i+1,c);
// 		c++;
// 	}

// 	// sort_hundred(&head_a,&head_b);
// 	printf("\n\t stack a :");
// 	print_linkedList(head_a);
// 	printf("\n\t stack b :");
// 	print_linkedList(head_b);
// }