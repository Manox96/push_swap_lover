/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   To_linkedList.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:47:18 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/11 14:18:29 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_stack	*createNode(int value ,int pos)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->content = value;
	node->pos = pos;
	node->next = NULL;
	return (node);
}
void	add_back(t_stack **head,int value,int pos)
{
	t_stack	*node;
	t_stack	*curr;

	curr = NULL;
	node = createNode(value,pos);
	if (*head == NULL)
		*head = node;
	else
	{
		curr = *head;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = node;
	}
}

t_stack *to_LinkedList(char **av)
{
	int i;
	t_stack	*head;

	i = 0;
	head = NULL;

	while (av[i])
	{
		add_back(&head,my_atoi(av[i]),i + 1);
		i++;
	}
	return (head);
}
void	to_top_three(t_stack **head)
{
	// not forget to handle case if pos not in linkedList
	int min_Node_pos = min_node(head);
	int size = size_list(head);

	// while (!((*head)->pos == min_Node_pos))
	// 	retate_A(head); old code

	if (min_Node_pos <= size)
	{
		retate_A(head);
	}
	else if (min_Node_pos > size)
	{
		while ((*head)->pos != min_Node_pos)
			reverse_retate(head);
		// update_index(head);
	}

}

