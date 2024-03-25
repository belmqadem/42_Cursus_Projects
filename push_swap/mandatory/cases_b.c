/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:14:13 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/17 14:44:29 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Amount of rotation for the 'ra+rb' case
int	case_rr_b(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = find_place_b(b, nbr);
	if (i < get_index(a, nbr))
		i = get_index(a, nbr);
	return (i);
}

// Amount of rotation for the 'rra+rrb' case
int	case_rrr_b(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (find_place_b(b, nbr))
		i = ft_lstsize(b) - find_place_b(b, nbr);
	if ((i < (ft_lstsize(a) - get_index(a, nbr))) && get_index(a, nbr))
		i = ft_lstsize(a) - get_index(a, nbr);
	return (i);
}

// Amount of rotation for the 'rra+rb' case
int	case_rra_rb_b(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (get_index(a, nbr))
		i = ft_lstsize(a) - get_index(a, nbr);
	i = find_place_b(b, nbr) + i;
	return (i);
}

// Amount of rotation for the 'ra+rrb' case
int	case_ra_rrb_b(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (find_place_b(b, nbr))
		i = ft_lstsize(b) - find_place_b(b, nbr);
	i = get_index(a, nbr) + i;
	return (i);
}
