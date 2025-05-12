/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:30:47 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/12 19:28:32 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	helper(char **str, t_stack **a)
{
	t_stack		*node;
	long long	res;
	int			j;

	j = 0;
	res = 0;
	node = NULL;
	while (str[j])
	{
		res = ft_atoi(str[j]);
		check_max_min(res, a, str);
		if (res == -1)
		{
			free_split(str);
			print_error(a);
		}
		node = create_node(res);
		add_back(node, a);
		j++;
	}
	if (check_duplicates(*a) == 0)
	{
		free_split(str);
		print_error(a);
	}
}

void	sort_check(t_stack *a, t_stack *b)
{
	int	res;

	res = 0;
	if (a != NULL)
	{
		res = check_sorted(a);
		if (res == 0 && b == NULL)
			write (1, "OK\n", 3);
		else
			write (1, "KO\n", 3);
	}
}

size_t	ft_strlen1(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
