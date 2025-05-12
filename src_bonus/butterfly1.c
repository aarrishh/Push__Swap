/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:15:54 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/12 19:39:48 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	butterfly(t_stack **a, t_stack **b, int n)
{
	int	count;

	count = 0;
	while (*a != NULL)
	{
		if ((*a)->index <= count)
		{
			pb(a, b, 1);
			rb(b, 1);
			count++;
		}
		else if ((*a)->index <= count + n)
		{
			pb(a, b, 1);
			count++;
		}
		else
			ra(a, 1);
	}
	while (*b)
		move_b_to_a(a, b);
}

void	move_two_smallest_to_b(int data, int len, t_stack **a, t_stack **b)
{
	int		count;
	t_stack	*tmp;

	tmp = *a;
	count = 1;
	while (data != tmp->data)
	{
		tmp = tmp->next;
		count++;
	}
	if (len / 2 < count)
	{
		while (tmp->next != NULL)
			rra(a, 1);
		rra(a, 1);
		pb(a, b, 1);
	}
	else
	{
		while (--count)
			ra(a, 1);
		pb(a, b, 1);
	}
}

void	indexing(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*current;

	current = *a;
	tmp = *a;
	while (tmp)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
	tmp = (*a)->next;
	while (current)
	{
		while (tmp)
		{
			if (current->data > tmp->data)
				current->index++;
			tmp = tmp->next;
		}
		tmp = *a;
		current = current->next;
	}
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	int	max;
	int	pos;

	while (*b)
	{
		max = find_max(*b);
		pos = get_position(*b, max);
		if (pos <= size_list(*b) / 2)
			while ((*b)->data != max)
				rb(b, 1);
		else
			while ((*b)->data != max)
				rrb(b, 1);
		pa(a, b, 1);
	}
}
