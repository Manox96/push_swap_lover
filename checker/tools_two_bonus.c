/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_two_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:46:27 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/27 18:34:20 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	size_list(t_stack **head)
{
	int		c;
	t_stack	*curr;

	c = 0;
	curr = *head;
	while (curr != NULL)
	{
		c++;
		curr = curr->next;
	}
	return (c);
}

void	add_front(t_stack **head, t_stack *node)
{
	t_stack	*curr;

	if (!head || !node)
		return ;
	curr = *head;
	node->next = curr;
	*head = node;
}
