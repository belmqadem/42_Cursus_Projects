/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:39:45 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/18 15:59:00 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*parse_input(int ac, char **av)
{
	t_stack	*a;
	int		i;

	a = NULL;
	if (ac < 2)
		exit(0);
	if (is_empty(ac, av) || is_error(ac, av))
		handle_err();
	check_int(ac, av);
	i = 1;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
			ft_lstadd_back(&a, process_split(av[i]));
		else
			ft_lstadd_back(&a, process_direct(av[i]));
		i++;
	}
	return (a);
}

t_stack	*process_split(char *av)
{
	char	**split_args;
	t_stack	*a;
	int		i;
	int		data;

	a = NULL;
	split_args = ft_split(av, ' ');
	i = 0;
	while (split_args[i])
	{
		data = ft_atoi(split_args[i]);
		ft_lstadd_back(&a, ft_lstnew(data));
		i++;
	}
	free_arr(split_args);
	return (a);
}

t_stack	*process_direct(char *av)
{
	int		data;
	t_stack	*a;

	a = NULL;
	data = ft_atoi(av);
	ft_lstadd_back(&a, ft_lstnew(data));
	return (a);
}
