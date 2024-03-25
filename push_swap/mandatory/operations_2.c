/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:01:23 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/17 15:04:14 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack **stack, char *operation, int ok)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	*stack = ft_lstlast(*stack);
	(*stack)->next = last;
	*stack = last->next;
	last->next = NULL;
	if (ok)
		ft_putendl_fd(operation, 1);
}

void	rr(t_stack **a, t_stack **b, int ok)
{
	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return ;
	rotate(a, "ra", 0);
	rotate(b, "rb", 0);
	if (ok)
		ft_putendl_fd("rr", 1);
}

void	reverse_rotate(t_stack **stack, char *operation, int ok)
{
	t_stack	*last;
	int		i;

	if (!*stack || !(*stack)->next)
		return ;
	i = 0;
	last = *stack;
	while ((*stack)->next)
	{
		i++;
		*stack = (*stack)->next;
	}
	(*stack)->next = last;
	while (i > 1)
	{
		last = last->next;
		i--;
	}
	last->next = NULL;
	if (ok)
		ft_putendl_fd(operation, 1);
}

void	rrr(t_stack **a, t_stack **b, int ok)
{
	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return ;
	reverse_rotate(a, "rra", 0);
	reverse_rotate(b, "rrb", 0);
	if (ok)
		ft_putendl_fd("rrr", 1);
}
