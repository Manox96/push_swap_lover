/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:05:12 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/25 16:39:24 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				rank;
	int				is_visited;
	int				pos;
	struct s_stack	*next;
}	t_stack;

//*--- this is the G.O.A.T ----*
void	print_err(void);

//***-------filter input------****

char	**parsing(int ac, char **av);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
long	my_atoi(const char *str);
char	**ft_split(char const *s, char c);

//*--------LinkedList magic -------*
t_stack	*to_linkedlist(char **av);
void	print_linkedlist(t_stack *a);
t_stack	*createnode(int value, int pos);
char	*joined_arg(int ac, char **av);

//tools
int		min_node(t_stack **head);
int		size_list(t_stack **head);
void	index_from_the_small(t_stack **head_a);
void	to_top_of_node(t_stack **head);
t_stack	*min_node_addrs(t_stack **head_a);
void	add_back(t_stack **head, int value, int pos);
void	add_front(t_stack **head_b, t_stack *node);
void	print_linkedList_two(t_stack *a);
void	update_index(t_stack **head);
void	set_pos_frm_0(t_stack **head);
int		check_is_sorted(t_stack	**head_a);
void	sort(t_stack **a, t_stack **b);

//tools algo hundred and over
void	search(t_stack **head, t_stack **max_node, t_stack **second_max_node);
void	max_to_top_of_b(t_stack **head_b, t_stack *max_node);
void	second_max_to_top_of_b(t_stack **head_b, t_stack *second_node);
int		check_where_in_stack(int larg, int second_larg, int size_list);

//action :
void	swap_a(t_stack **head);
void	retate_b(t_stack **head);
void	retate_a(t_stack **head);
void	reverse_retate_a(t_stack **head);
void	reverse_retate_b(t_stack **head);
void	push_b(t_stack **head_a, t_stack **head_b);
void	push_a(t_stack **head_b, t_stack **head_a);
void	rr(t_stack **head_a, t_stack **head_b);

//algo
void	sort_hundred(t_stack **head_a, t_stack **head_b);
void	sort_two_and_three(t_stack **head);
void	sort_five(t_stack **head_a, t_stack **head_b, int pos);
#endif