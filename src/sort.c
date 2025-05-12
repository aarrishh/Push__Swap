/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:30:47 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/12 19:25:05 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_line_len(char *s, t_stack **a)
{
	int	len;

	len = ft_strlen1(s);
	if (len > 11)
		print_error(a);
}

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
		check_line_len(str[j], a);
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
