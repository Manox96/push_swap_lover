/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:24:31 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/29 16:30:31 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker_bonus.h"

void	rrr(t_stack **head_a, t_stack **head_b, int p)
{
	rotate_a(head_a, 0);
	rotate_b(head_b, 0);
	if (p == 1)
		write(1, "rrr\n", 4);
}

void	rr(t_stack **head_a, t_stack **head_b, int p)
{
	rotate_a(head_a, 0);
	rotate_b(head_b, 0);
	if (p == 1)
		write(1, "rr\n", 3);
}

void	ss(t_stack **head_a, t_stack **head_b, int p)
{
	swap_a(head_a, 0);
	swap_b(head_b, 0);
	if (p == 1)
		write(1, "ss\n", 3);
}

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	print_err(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
