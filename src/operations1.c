/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:48:32 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/06 22:30:35 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack **b, int i)
{
	t_stack	*tmp;
	t_stack	*idk;

	if ((*b)->next != NULL)
	{
		idk = *b;
		tmp = *b;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*b) = (*b)->next;
		idk->next = NULL;
		tmp->next = idk;
	}
	if (i == 1)
		write (1, "rb\n", 3);
}

void	rra(t_stack **a, int i)
{
	t_stack	*tmp;
	t_stack	*idk;

	tmp = *a;
	idk = tmp;
	if ((*a)->next != NULL)
	{
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		while (idk->next != NULL)
			idk = idk->next;
		tmp->next = NULL;
		idk->next = *a;
		*a = idk;
	}
	if (i == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int i)
{
	t_stack	*tmp;
	t_stack	*idk;

	tmp = *b;
	idk = tmp;
	if ((*b)->next != NULL)
	{
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		while (idk->next != NULL)
			idk = idk->next;
		tmp->next = NULL;
		idk->next = *b;
		*b = idk;
	}
	if (i == 1)
		write (1, "rrb\n", 4);
}

void	rr(t_stack **a, t_stack **b, int i)
{
	if (i == 1)
	{
		ra(a, 1);
		rb(b, 1);
	}
	else
	{
		ra(a, 0);
		rb(b, 0);
	}
}

void	rrr(t_stack **a, t_stack **b, int i)
{
	if (i == 1)
	{
		rra(a, 1);
		rrb(b, 1);
	}
	else
	{
		rra(a, 0);
		rrb(b, 0);
	}
}
