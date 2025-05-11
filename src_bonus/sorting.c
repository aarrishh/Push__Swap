/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:50:01 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/06 22:25:15 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	small_value(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*start;

	start = *a;
	tmp = (*a)->next;
	while (start != NULL && tmp != NULL)
	{
		if (start->data < tmp->data)
			tmp = tmp->next;
		else
		{
			start = tmp;
			tmp = tmp->next;
		}
	}
	return (start->data);
}

void	sort_3(t_stack **a)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = (*a)->data;
	a2 = (*a)->next->data;
	a3 = (*a)->next->next->data;
	if (a1 < a2 && a2 < a3)
		return ;
	else if (a1 > a2 && a2 > a3 && a3 < a1)
	{
		ra(a, 1);
		sa(a, 1);
	}
	else if (a1 < a2 && a2 > a3 && a3 > a1)
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if (a1 > a2 && a2 < a3 && a3 > a1)
		sa(a, 1);
	else if (a1 > a2 && a2 < a3 && a3 < a1)
		ra(a, 1);
	else if (a1 < a2 && a2 > a3 && a3 < a1)
		rra(a, 1);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int		len;
	int		data;
	int		count;

	count = 0;
	while (count < 2)
	{
		data = small_value(a);
		len = size_list(*a);
		if (len == 3)
			count++;
		else
			move_two_smallest_to_b(data, len, a, b);
		count++;
	}
	sort_3(a);
	pa(a, b, 1);
	pa(a, b, 1);
}
