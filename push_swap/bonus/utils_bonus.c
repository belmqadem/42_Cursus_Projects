/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:10:35 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/22 16:33:32 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	is_valid(t_stack **a, t_stack **b, char *line)
{
	if (ft_strnstr(line, "sa\n", 3))
		swap(a, "sa", 0);
	else if (ft_strnstr(line, "sb\n", 3))
		swap(b, "sb", 0);
	else if (ft_strnstr(line, "ss\n", 3))
		ss(a, b, 0);
	else if (ft_strnstr(line, "pa\n", 3))
		pa(a, b, 0);
	else if (ft_strnstr(line, "pb\n", 3))
		pb(b, a, 0);
	else if (ft_strnstr(line, "ra\n", 3))
		rotate(a, "ra", 0);
	else if (ft_strnstr(line, "rb\n", 3))
		rotate(b, "rb", 0);
	else if (ft_strnstr(line, "rr\n", 3))
		rr(a, b, 0);
	else if (ft_strnstr(line, "rra\n", 4))
		reverse_rotate(a, "rra", 0);
	else if (ft_strnstr(line, "rrb\n", 4))
		reverse_rotate(b, "rrb", 0);
	else if (ft_strnstr(line, "rrr\n", 4))
		rrr(a, b, 0);
	else
		handle_err();
}

void	read_instructions(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		is_valid(a, b, line);
		free(line);
	}
	if (*b)
		ft_putendl_fd("KO", 1);
	else if (!stack_is_sorted(*a))
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
}
