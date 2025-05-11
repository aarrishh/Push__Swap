/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:47:41 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/06 22:21:57 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int i)
{
	int	num;

	if (!a || !(*a) || (*a)->next == NULL)
		return ;
	num = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = num;
	if (i == 1)
		write (1, "sa\n", 3);
}

void	sb(t_stack **b, int i)
{
	int	num;

	if (!b || !(*b) || (*b)->next == NULL)
		return ;
	num = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = num;
	if (i == 1)
		write (1, "sb\n", 3);
}

void	pb(t_stack **a, t_stack **b, int i)
{
	t_stack	*tmp;

	if ((*a) != NULL)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		if (!(*b))
			*b = tmp;
		else
		{
			tmp->next = *b;
			*b = tmp;
		}
	}
	if (i == 1)
		write (1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b, int i)
{
	t_stack	*tmp;

	if ((*b) != NULL)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = NULL;
		if (!(*a))
			*a = tmp;
		else
		{
			tmp->next = *a;
			*a = tmp;
		}
	}
	if (i == 1)
		write (1, "pa\n", 3);
}

void	ra(t_stack **a, int i)
{
	t_stack	*tmp;
	t_stack	*idk;

	if ((*a)->next != NULL)
	{
		idk = *a;
		tmp = *a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*a) = (*a)->next;
		idk->next = NULL;
		tmp->next = idk;
	}
	if (i == 1)
		write (1, "ra\n", 3);
}
