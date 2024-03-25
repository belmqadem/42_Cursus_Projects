/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rotation_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:44:52 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/17 14:45:05 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	exec_rr_a(t_stack **a, t_stack **b, int nbr)
{
	while ((*b)->data != nbr && find_place_a(*a, nbr) > 0)
		rr(a, b, 1);
	while ((*b)->data != nbr)
		rotate(b, "rb", 1);
	while (find_place_a(*a, nbr) > 0)
		rotate(a, "ra", 1);
	pa(a, b, 1);
	return (-1);
}

int	exec_rrr_a(t_stack **a, t_stack **b, int nbr)
{
	while ((*b)->data != nbr && find_place_a(*a, nbr) > 0)
		rrr(a, b, 1);
	while ((*b)->data != nbr)
		reverse_rotate(b, "rrb", 1);
	while (find_place_a(*a, nbr) > 0)
		reverse_rotate(a, "rra", 1);
	pa(a, b, 1);
	return (-1);
}

int	exec_rra_rb_a(t_stack **a, t_stack **b, int nbr)
{
	while (find_place_a(*a, nbr) > 0)
		reverse_rotate(a, "rra", 1);
	while ((*b)->data != nbr)
		rotate(b, "rb", 1);
	pa(a, b, 1);
	return (-1);
}

int	exec_ra_rrb_a(t_stack **a, t_stack **b, int nbr)
{
	while (find_place_a(*a, nbr) > 0)
		rotate(a, "ra", 1);
	while ((*b)->data != nbr)
		reverse_rotate(b, "rrb", 1);
	pa(a, b, 1);
	return (-1);
}
