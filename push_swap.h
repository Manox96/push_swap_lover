/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:05:12 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/15 17:28:13 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>


typedef struct s_stack
{
	// struct s_stack		*prev;
	int				content;
	int				pos;
	struct s_stack		*next;
}	t_stack;

//*--- this is the G.O.A.T ----*
void	print_err();

//***-------filter input------****

char	**parsing(int ac, char **av);
size_t	ft_strlen(const char *s);
int	ft_isdigit(int c);
long	my_atoi(const char *str);
char	**ft_split(char const *s, char c);

//*--------LinkedList magic -------*
t_stack	*to_LinkedList(char **av);
void	print_linkedList(t_stack *a);
t_stack	*createNode(int value, int pos);
char	*joined_arg(int ac, char **av);


//tools
int	min_node(t_stack **head);
int	size_list(t_stack **head);
void	to_top_of_node(t_stack **head);
void	add_back(t_stack **head, int value, int pos);
void	add_front(t_stack **head_b, t_stack *node);
void print_linkedList_two(t_stack *a);
void	update_index(t_stack **head);
void	set_index_frm_0(t_stack **head);

//action :
void	swap_a(t_stack **head);
void	retate_b(t_stack **head);
void	retate_a(t_stack **head);
void	reverse_retate_a(t_stack **head);
void	reverse_retate_b(t_stack **head);
void push_b(t_stack **head_a, t_stack **head_b);
void push_a(t_stack **head_b, t_stack **head_a);
void rr(t_stack **head_a,t_stack **head_b);

//algo
void	sort_two_and_three(t_stack **head);
void	sort_five(t_stack **head_a ,t_stack **head_b,int pos);
void	sort_hundred(t_stack **head_a, t_stack **head_b);
#endif