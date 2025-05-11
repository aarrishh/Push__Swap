/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:03:34 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/11 20:32:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check(t_stack **a, t_stack **b)
{
	if (check_sorted(*a) == 1)
	{
		if (check_duplicates(*a) == 0)
			print_error(a);
		if (size_list(*a) == 1)
			return ;
		else if (size_list(*a) == 2)
			sa(a, 1);
		else if (size_list(*a) == 3)
			sort_3(a);
		else if (size_list(*a) == 4 || size_list(*a) == 5)
			sort_5(a, b);
		else
		{
			indexing(a);
			// printf("tes-?%d\n", size_list(*a));
			butterfly(a, b, formula_n(size_list(*a)));
		}
	}
}

int	check_sorted(t_stack *a)
{
	if (a == NULL)
		return (0);
	while (a->next != NULL)
	{
		if (a->data < a->next->data)
			a = a->next;
		else
			return (1);
	}
	return (0);
}

void	add_back(t_stack *node, t_stack **a)
{
	t_stack	*tmp;

	if (*a == NULL)
	{
		*a = node;
		return ;
	}
	tmp = *a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
}

t_stack	*create_node(int res)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	new_node->data = res;
	new_node->next = NULL;
	return (new_node);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free (str);
	str = NULL;
}
