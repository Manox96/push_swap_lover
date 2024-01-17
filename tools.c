#include "push_swap.h"
#include <stdio.h>

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
void	set_index_frm_0(t_stack **head)
{
	t_stack	*curr;
	int	i;

	i = -1;
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
	int min_Node_pos;
	int size;

	min_Node_pos = min_node(head);
	size= size_list(head);
	if (min_Node_pos == (size / 2))
		retate_a(head);
	else if (min_Node_pos > (size / 2))
	{
		while ((*head)->pos != min_Node_pos)
			reverse_retate_a(head);
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
	return (min->pos);
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