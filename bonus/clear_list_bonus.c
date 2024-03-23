/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:48:59 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/30 11:40:53 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker_bonus.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*nextnode;

	if (!lst)
		return ;
	nextnode = *lst;
	while (nextnode != NULL)
	{
		nextnode = (*lst)->next;
		free(*lst);
		*lst = nextnode;
	}
	*lst = NULL;
}
