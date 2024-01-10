/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_max_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:58:10 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/10 17:22:43 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_five(t_stack **head_a , t_stack **head_b, int pos)
{
	if (pos == 4)
	{
		push_b(head_a,head_b);
		sort_two_and_three(head_a);
		push_a(head_b,head_a);
	}
	else if (pos == 5)
	{
		push_b(head_a,head_b);
		push_b(head_a,head_b);
		sort_two_and_three(head_a);
		push_a(head_b,head_a);
		push_a(head_b,head_a);
		update_index(head_a);
	}
}