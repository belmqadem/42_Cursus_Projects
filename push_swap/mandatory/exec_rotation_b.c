/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rotation_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:44:52 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/17 14:45:17 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	exec_rr_b(t_stack **a, t_stack **b, int nbr)
{
	while ((*a)->data != nbr && find_place_b(*b, nbr) > 0)
		rr(a, b, 1);
	while ((*a)->data != nbr)
		rotate(a, "ra", 1);
	while (find_place_b(*b, nbr) > 0)
		rotate(b, "rb", 1);
	pb(b, a, 1);
	return (-1);
}

int	exec_rrr_b(t_stack **a, t_stack **b, int nbr)
{
	while ((*a)->data != nbr && find_place_b(*b, nbr) > 0)
		rrr(a, b, 1);
	while ((*a)->data != nbr)
		reverse_rotate(a, "rra", 1);
	while (find_place_b(*b, nbr) > 0)
		reverse_rotate(b, "rrb", 1);
	pb(b, a, 1);
	return (-1);
}

int	exec_rra_rb_b(t_stack **a, t_stack **b, int nbr)
{
	while ((*a)->data != nbr)
		reverse_rotate(a, "rra", 1);
	while (find_place_b(*b, nbr) > 0)
		rotate(b, "rb", 1);
	pb(b, a, 1);
	return (-1);
}

int	exec_ra_rrb_b(t_stack **a, t_stack **b, int nbr)
{
	while ((*a)->data != nbr)
		rotate(a, "ra", 1);
	while (find_place_b(*b, nbr) > 0)
		reverse_rotate(b, "rrb", 1);
	pb(b, a, 1);
	return (-1);
}
