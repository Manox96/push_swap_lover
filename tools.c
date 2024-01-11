#include "push_swap.h"
#include <stdio.h>

void print_linkedList_two(t_stack *a)
{
		t_stack *curr = a;
		printf("\033[0;103m{head}\033[0m\n");
				printf("\033[1;94m  |   \n");
		while (curr != NULL)
		{
			printf("\033[0;47m(%d)\033[0m\033[1;32m[%d]--",curr->pos,curr->content);
			curr = curr->next;
		}
		printf("\033[0;103m|<---tail}\033[0m");
		printf("\033[0;94m  | a linkedList created by aymane\n");
}
void	update_index(t_stack **head)
{
	t_stack	*curr;
	int	i;

	i = 0;
	curr = *head;
	while (curr != NULL)
	{
		++i;
		curr->pos = i;
		curr = curr->next;
	}
}

void	to_top_of_node(t_stack **head)
{
	// not forget to handle case if pos not in linkedList
	int min_Node_pos = min_node(head);
	int size = size_list(head);

	if (min_Node_pos == size / 2)
		retate_A(head);
	else if (min_Node_pos > size / 2)
	{
		while ((*head)->pos != min_Node_pos)
			reverse_retate(head);
	}

}

int	min_node(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = *head;
	min = tmp;
	while (tmp != NULL)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	// int x = min->pos;
	return min->pos;
}

int	size_list(t_stack **head)
{
	int	c;
	t_stack *curr;

	c = 0;
	curr = *head;
	while (curr != NULL)
	{
		c++;
		curr = curr->next;
	}
	return (c);

}
void	add_front(t_stack **head_b,t_stack *node)
{
	t_stack *curr;

	if (!head_b || !node)
		return;
	curr = *head_b;
	node->next = curr;
	*head_b = node;
}
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