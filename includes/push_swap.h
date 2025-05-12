/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:46:12 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/12 19:26:12 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				index;
	int				index_b;
	int				data;
	struct s_stack	*next;
}	t_stack;

// libft_functions
int			is_white_space(char c);
long long	ft_atoi(const char *str);
char		**ft_split(char const *s);
size_t		ft_strlen1(const char *str);

// operations
void		sa(t_stack **a, int i);
void		sb(t_stack **b, int i);
void		ra(t_stack **a, int i);
void		rb(t_stack **b, int i);
void		rra(t_stack **a, int i);
void		rrb(t_stack **b, int i);
void		rr(t_stack **a, t_stack **b, int i);
void		pb(t_stack **a, t_stack **b, int i);
void		pa(t_stack **a, t_stack **b, int i);
void		rrr(t_stack **a, t_stack **b, int i);

// sort_functions
void		sort_3(t_stack **a);
void		sort_5(t_stack **a, t_stack **b);
void		move_two_smallest_to_b(int data, int len, t_stack **a, t_stack **b);

// free_functions
void		free_split(char **str);
void		free_stack(t_stack **stack);

// butterfly_functions
int			log_n(int size);
int			formula_n(int size);
int			find_max(t_stack *b);
void		indexing(t_stack **a);
int			get_position(t_stack *b, int value);
void		move_b_to_a(t_stack **a, t_stack **b);
void		butterfly(t_stack **a, t_stack **b, int n);

// check_functions
int			check_sorted(t_stack *a);
int			check_duplicates(t_stack *a);
int			check_white_spaces(char *str);
void		check(t_stack **a, t_stack **b);
void		sort_check(t_stack *a, t_stack *b);
void		check_line_len(char *s, t_stack **a);
void		check_max_min(long long num, t_stack **a, char **str);

// create_stack_functions
t_stack		*create_node(int res);
int			size_list(t_stack *a);
void		helper(char **str, t_stack **a);
void		add_back(t_stack *node, t_stack **a);

// bonus_functions
void		line_by_line(char *input, t_stack **a, t_stack **b);

// print_functions
void		print_error(t_stack **stack);

#endif