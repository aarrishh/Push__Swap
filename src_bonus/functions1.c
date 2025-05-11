/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:56:38 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/07 21:45:39 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_white_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else
			return (-1);
	}
	return (1);
}

int	check_duplicates(t_stack *a)
{
	t_stack	*tmp;

	while (a != NULL)
	{
		tmp = a->next;
		while (tmp != NULL)
		{
			if (a->data != tmp->data)
				tmp = tmp->next;
			else
				return (0);
		}
		a = a->next;
	}
	return (1);
}

void	check_max_min(long long num, t_stack **a, char **str)
{
	if ((num > INT_MAX || num < INT_MIN) || (num > LONG_MAX || num < LONG_MIN)
		|| (num > LLONG_MAX || num < LLONG_MIN))
	{
		free_split(str);
		print_error(a);
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack);
	while (stack && *stack)
	{
		tmp = tmp ->next;
		free(*stack);
		*stack = tmp;
	}
}

void	print_error(t_stack **a)
{
	if (*a && a)
		free_stack(a);
	write (2, "Error\n", 6);
	exit(1);
}
