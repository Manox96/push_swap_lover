/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   To_linkedList.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:47:18 by aennaqad          #+#    #+#             */
/*   Updated: 2024/02/03 11:24:12 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_stack	*createnode(int value, int pos)
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

void	add_back(t_stack **head, int value, int pos)
{
	t_stack	*node;
	t_stack	*curr;

	curr = NULL;
	node = createnode(value, pos);
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

t_stack	*to_linkedlist(char **av)
{
	int		i;
	t_stack	*head;

	i = -1;
	head = NULL;
	while (av[++i])
		add_back(&head, my_atoi(av[i]), i + 1);
	freeit(av);
	return (head);
}
