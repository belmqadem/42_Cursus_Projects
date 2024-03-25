/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:58:53 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/18 21:58:50 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_stack *stack)
{
	int	nbr;

	nbr = stack->data;
	while (stack)
	{
		if (stack->data < nbr)
			nbr = stack->data;
		stack = stack->next;
	}
	return (nbr);
}

int	find_max(t_stack *stack)
{
	int	nbr;

	nbr = stack->data;
	while (stack)
	{
		if (stack->data > nbr)
			nbr = stack->data;
		stack = stack->next;
	}
	return (nbr);
}

int	stack_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// return index that nbr will get after pushing it to B
int	find_place_b(t_stack *b, int nbr)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	if (nbr > b->data && nbr < ft_lstlast(b)->data)
		i = 0;
	else if (nbr > find_max(b) || nbr < find_min(b))
		i = get_index(b, find_max(b));
	else
	{
		tmp = b->next;
		while (b->data < nbr || tmp->data > nbr)
		{
			b = b->next;
			tmp = b->next;
			i++;
		}
	}
	return (i);
}

// return index that nbr will get after pushing it to A
int	find_place_a(t_stack *a, int nbr)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	if (nbr < a->data && nbr > ft_lstlast(a)->data)
		i = 0;
	else if (nbr > find_max(a) || nbr < find_min(a))
		i = get_index(a, find_min(a));
	else
	{
		tmp = a->next;
		while (a->data > nbr || tmp->data < nbr)
		{
			a = a->next;
			tmp = a->next;
			i++;
		}
	}
	return (i);
}
