/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:36:13 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/05/28 11:05:00 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	destroy_mutexes(t_param *sim)
{
	int	i;

	pthread_mutex_destroy(&sim->data.write_mutex);
	pthread_mutex_destroy(&sim->data.dead_mutex);
	pthread_mutex_destroy(&sim->data.time_eat_mutex);
	pthread_mutex_destroy(&sim->data.finish_mutex);
	i = -1;
	while (++i < sim->args.nb_of_philos)
		pthread_mutex_destroy(&sim->philo[i].left_fork);
}

void	cleanup_simulation(t_param *sim)
{
	destroy_mutexes(sim);
	if (sim->data.stop == 2)
		printf(GREEN FINISH RESET, sim->args.count_meal);
	free(sim->philo);
}
