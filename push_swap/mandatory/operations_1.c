/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:04:31 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/22 02:52:16 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack, char *operation, int ok)
{
	t_stack	*tmp;

	if (!*stack || !((*stack)->next))
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	if (ok)
		ft_putendl_fd(operation, 1);
}

void	ss(t_stack **a, t_stack **b, int ok)
{
	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return ;
	swap(a, "sa", 0);
	swap(b, "sb", 0);
	if (ok)
		ft_putendl_fd("ss", 1);
}

void	pa(t_stack **a, t_stack **b, int ok)
{
	t_stack	*top_b;

	if (*b == NULL)
		return ;
	top_b = *b;
	*b = (*b)->next;
	top_b->next = *a;
	*a = top_b;
	if (ok)
		ft_putendl_fd("pa", 1);
}

void	pb(t_stack **b, t_stack **a, int ok)
{
	t_stack	*top_a;

	if (*a == NULL)
		return ;
	top_a = *a;
	*a = (*a)->next;
	top_a->next = *b;
	*b = top_a;
	if (ok)
		ft_putendl_fd("pb", 1);
}
