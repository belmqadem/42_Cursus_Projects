/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:05:32 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/19 15:11:42 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	int		i;
	int		size;

	size = ft_lstsize(*a);
	if (size == 2)
		swap(a, "sa", 1);
	else
	{
		sort_stack_b(a, b);
		sort_stack_a(a, b);
		i = get_index(*a, find_min(*a));
		if (i < size - i)
		{
			while ((*a)->data != find_min(*a))
				rotate(a, "ra", 1);
		}
		else
		{
			while ((*a)->data != find_min(*a))
				reverse_rotate(a, "rra", 1);
		}
	}
}

void	sort_stack_b(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) > 3)
		pb(b, a, 1);
	if (ft_lstsize(*a) > 3)
		pb(b, a, 1);
	while (ft_lstsize(*a) > 3)
		push_to_b(a, b);
	sort_three(a);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		nbr;
	int		i;

	tmp = *a;
	i = calculate_operation_b(*a, *b);
	while (i >= 0)
	{
		nbr = tmp->data;
		if (i == case_rr_b(*a, *b, nbr))
			i = exec_rr_b(a, b, nbr);
		else if (i == case_rrr_b(*a, *b, nbr))
			i = exec_rrr_b(a, b, nbr);
		else if (i == case_ra_rrb_b(*a, *b, nbr))
			i = exec_ra_rrb_b(a, b, nbr);
		else if (i == case_rra_rb_b(*a, *b, nbr))
			i = exec_rra_rb_b(a, b, nbr);
		else
			tmp = tmp->next;
	}
}

void	sort_stack_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		nbr;
	int		i;

	while (*b)
	{
		tmp = *b;
		i = calculate_operation_a(*a, *b);
		while (i >= 0)
		{
			nbr = tmp->data;
			if (i == case_rr_a(*a, *b, nbr))
				i = exec_rr_a(a, b, nbr);
			else if (i == case_rrr_a(*a, *b, nbr))
				i = exec_rrr_a(a, b, nbr);
			else if (i == case_ra_rrb_a(*a, *b, nbr))
				i = exec_ra_rrb_a(a, b, nbr);
			else if (i == case_rra_rb_a(*a, *b, nbr))
				i = exec_rra_rb_a(a, b, nbr);
			else
				tmp = tmp->next;
		}
	}
}

void	sort_three(t_stack **a)
{
	if (find_min(*a) == (*a)->data)
	{
		if (!stack_is_sorted(*a))
		{
			reverse_rotate(a, "rra", 1);
			swap(a, "sa", 1);
		}
	}
	else if (find_max(*a) == (*a)->data)
	{
		rotate(a, "ra", 1);
		if (!stack_is_sorted(*a))
			swap(a, "sa", 1);
	}
	else
	{
		if (get_index(*a, find_max(*a)) == 1)
			reverse_rotate(a, "rra", 1);
		else
			swap(a, "sa", 1);
	}
}
