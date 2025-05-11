/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:59:36 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/11 15:37:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && (s1[i] == s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	line_by_line(char *input, t_stack **a, t_stack **b)
{
	if (ft_strcmp(input, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp(input, "sb\n") == 0)
		sb(b, 0);
	else if (ft_strcmp(input, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(input, "pb\n") == 0)
		pb(a, b, 0);
	else if (ft_strcmp(input, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp(input, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp(input, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(input, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp(input, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp(input, "rrr\n") == 0)
		rrr(a, b, 0);
	else
		print_error(a);
}

void	helper_bonus(char **str, t_stack **a)
{
	long long	res;
	int			j;

	j = 0;
	res = 0;
	while (str[j])
	{
		res = ft_atoi(str[j]);
		check_max_min(res, a, str);
		if (res == -1)
		{
			free_split(str);
			print_error(a);
		}
		j++;
	}
}

void	gnl_call(t_stack **a, t_stack **b)
{
	char	*gnl;

	gnl = NULL;
	gnl = get_next_line(0);
	while (gnl != NULL)
	{
		line_by_line(gnl, a, b);
		free(gnl);
		gnl = get_next_line(0);
	}
	sort_check(*a, *b);
	free_stack(a);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	int			i;
	char		**str;
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	str = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	if (argc >= 2)
	{
		while (argv[i])
		{
			if (check_white_spaces(argv[i]) == 1)
				print_error(&a);
			str = ft_split(argv[i]);
			helper(str, &a);
			free_split(str);
			i++;
		}
		gnl_call(&a, &b);
	}
	return (0);
}
