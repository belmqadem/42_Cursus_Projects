/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:59:10 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/22 02:41:53 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_empty(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] && (av[i][j] == ' ' || av[i][j] == '\t'))
			j++;
		if (av[i][j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	is_error(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != '-'
				&& av[i][j] != '+' && av[i][j] != ' ')
				return (1);
			if (av[i][j] == '-' && (av[i][j + 1] == '+' || av[i][j + 1] == '-'
				|| av[i][j + 1] == '\0' || av[i][j + 1] == ' '))
				return (1);
			if (av[i][j] == '+' && (av[i][j + 1] == '+' || av[i][j + 1] == '-'
				|| av[i][j + 1] == '\0' || av[i][j + 1] == ' '))
				return (1);
			if ((av[i][j] == '-' || av[i][j] == '+') &&
				ft_isdigit(av[i][j - 1]))
				return (1);
			j++;
		}
	}
	return (0);
}

int	check_dup(t_stack *stack)
{
	t_stack	*tmp;

	while (stack != NULL)
	{
		tmp = stack->next;
		while (tmp != NULL)
		{
			if (stack->data == tmp->data)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}
