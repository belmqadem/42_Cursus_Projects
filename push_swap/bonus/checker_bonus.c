/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:10:38 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/24 03:53:29 by abel-mqa         ###   ########.fr       */
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
	read_instructions(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
