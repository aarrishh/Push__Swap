/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:57:31 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/11 17:50:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main() {
	
// }

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
		check(&a, &b);
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}
