/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:07:16 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/06/02 18:30:34 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	is_integer(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+')
				j++;
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
	}
	return (1);
}

static long double	ft_atopi(char const *str)
{
	long double	nbr;

	nbr = 0;
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - 48);
		str++;
	}
	if (nbr > INT_MAX)
		return (-2);
	return (nbr);
}

int	parse_arguments(int ac, char **av, t_param *data)
{
	if (ac < 5 || ac > 6 || !is_integer(av))
		return (print_error(RED ERR_ARGS RESET));
	data->args.nb_of_philos = ft_atopi(av[1]);
	if (data->args.nb_of_philos == 0)
		return (print_error(RED ERR_ZERO_PHILOS RESET));
	data->args.time_2_die = ft_atopi(av[2]);
	data->args.time_2_eat = ft_atopi(av[3]);
	data->args.time_2_sleep = ft_atopi(av[4]);
	data->args.count_meal = -1;
	if (ac == 6)
	{
		data->args.count_meal = ft_atopi(av[5]);
		if (data->args.count_meal == 0)
			return (0);
	}
	if (data->args.nb_of_philos == -2 || data->args.time_2_die == -2 || \
		data->args.time_2_eat == -2 || data->args.time_2_sleep == -2 || \
		data->args.count_meal == -2)
		return (print_error(RED ERR_INT_MAX RESET));
	return (1);
}
