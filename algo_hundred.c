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

	// int chunk;
	int step;
	int chunk;

	// chunk = size_list(head_a) / 5;
	step = size_list(head_a) / 5;
	chunk = size_list(head_a) / 5;
	
	while (size_list(head_a) != 0)
	{
		while ( *head_a != NULL && (*head_a)->pos < step)
		{
			if ((*head_a)->pos < step - (chunk / 2))
				push_b(head_a,head_b);
			else
			{
				push_b(head_a,head_b);
				retate_b(head_b);
			}
		}
		step+=chunk;
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
// 	// print_linkedList(head_a);
// 	printf("\n\t stack b :");
// 	print_linkedList(head_b);
// }