/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:54:39 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/12 19:15:01 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	root_n(int size)
{
	int	i;

	i = 0;
	if (i < size / 2)
	{
		while (i * i <= size)
		{
			if (i * i == size)
				return (i);
			else
				i++;
		}
	}
	return (i - 1);
}

int	log_n(int size)
{
	int	count;

	count = 0;
	while (size > 1)
	{
		size = size / 2;
		count++;
	}
	return (count);
}

int	formula_n(int size)
{
	return ((root_n(size)) + log_n(size));
}

int	get_position(t_stack *b, int value)
{
	int	pos;

	pos = 0;
	while (b)
	{
		if (b->data == value)
			return (pos);
		b = b->next;
		pos++;
	}
	return (-1);
}

int	find_max(t_stack *b)
{
	int	max;

	if (!b)
		return (0);
	max = b->data;
	while (b)
	{
		if (b->data > max)
			max = b->data;
		b = b->next;
	}
	return (max);
}
