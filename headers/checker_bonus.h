/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:56:27 by aennaqad          #+#    #+#             */
/*   Updated: 2024/02/03 11:24:47 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <unistd.h>
# include <stdlib.h>

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
char	**ft_split(char *s, char c);
void	ft_lstclear(t_stack **lst);
char	**freeit(char **s);

//*--------LinkedList magic -------*
t_stack	*to_linkedlist(char **av);
void	print_linkedlist(t_stack *a);
t_stack	*createnode(int value, int pos);
char	*joined_arg(int ac, char **av);

//actions
void	swap_a(t_stack **head, int p);
void	push_a(t_stack **head_b, t_stack **head_a, int p);
void	reverse_rotate_a(t_stack **head, int p);
void	rotate_a(t_stack **head, int p);
void	swap_b(t_stack **head, int p);
void	push_b(t_stack **head_a, t_stack **head_b, int p);
void	rotate_b(t_stack **head, int p);
void	reverse_rotate_b(t_stack **head, int p);
void	rrr(t_stack **head_a, t_stack **head_b, int p);
void	rr(t_stack **head_a, t_stack **head_b, int p);
void	ss(t_stack **head_a, t_stack **head_b, int p);

//tools
int		check_is_sorted(t_stack	**head_a);
int		is_empty(char *str);
void	add_back(t_stack **head, int value, int pos);
void	add_front(t_stack **head_b, t_stack *node);
int		my_strcmp(const char *s1, const char *s2);

#endif