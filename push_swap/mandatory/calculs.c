/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:03:01 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/19 14:40:38 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calculate_operation_b(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	i = INT_MAX;
	while (tmp)
	{
		if (i > case_rr_b(a, b, tmp->data))
			i = case_rr_b(a, b, tmp->data);
		if (i > case_rrr_b(a, b, tmp->data))
			i = case_rrr_b(a, b, tmp->data);
		if (i > case_ra_rrb_b(a, b, tmp->data))
			i = case_ra_rrb_b(a, b, tmp->data);
		if (i > case_rra_rb_b(a, b, tmp->data))
			i = case_rra_rb_b(a, b, tmp->data);
		tmp = tmp->next;
	}
	return (i);
}

int	calculate_operation_a(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	int		i;

	tmp = b;
	i = INT_MAX;
	while (tmp)
	{
		if (i > case_rr_a(a, b, tmp->data))
			i = case_rr_a(a, b, tmp->data);
		if (i > case_rrr_a(a, b, tmp->data))
			i = case_rrr_a(a, b, tmp->data);
		if (i > case_ra_rrb_a(a, b, tmp->data))
			i = case_ra_rrb_a(a, b, tmp->data);
		if (i > case_rra_rb_a(a, b, tmp->data))
			i = case_rra_rb_a(a, b, tmp->data);
		tmp = tmp->next;
	}
	return (i);
}
