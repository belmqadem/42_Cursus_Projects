/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:43:01 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/19 00:19:04 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	handle_err(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	get_index(t_stack *stack, int value)
{
	int	index;

	index = 0;
	while (stack->data != value)
	{
		index++;
		stack = stack->next;
	}
	return (index);
}

void	check_int(int ac, char **av)
{
	int		i;
	int		j;
	char	**s_int;

	i = 0;
	while (++i < ac)
	{
		if (ft_strchr(av[i], ' '))
		{
			s_int = ft_split(av[i], ' ');
			j = -1;
			while (s_int[++j])
			{
				if (ft_atoi(s_int[j]) > INT_MAX || ft_atoi(s_int[j]) < INT_MIN)
				{
					free_arr(s_int);
					handle_err();
				}
			}
			free_arr(s_int);
		}
		else
			if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
				handle_err();
	}
}
