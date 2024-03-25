/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:35:26 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/24 03:37:56 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = parse_input(ac, av);
	b = NULL;
	if (!a || check_dup(a))
	{
		free_stack(&a);
		handle_err();
	}
	if (stack_is_sorted(a))
	{
		free_stack(&b);
		exit(0);
	}
	sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}
