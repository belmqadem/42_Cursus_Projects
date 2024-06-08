/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:24:14 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/06/02 15:23:43 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_param	simulation;
	int		size;

	if (!parse_arguments(ac, av, &simulation))
		return (1);
	size = sizeof(t_philosopher);
	simulation.philo = malloc(simulation.args.nb_of_philos * size);
	if (!simulation.philo)
		return (1);
	setup_simulation(&simulation);
	run_dining_simulation(&simulation);
	cleanup_simulation(&simulation);
	return (0);
}
