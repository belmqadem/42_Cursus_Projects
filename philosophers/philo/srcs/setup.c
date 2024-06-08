/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:09:23 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/06/02 18:48:25 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	init_mutexes(t_param *sim)
{
	pthread_mutex_init(&sim->data.write_mutex, NULL);
	pthread_mutex_init(&sim->data.time_eat_mutex, NULL);
	pthread_mutex_init(&sim->data.finish_mutex, NULL);
	pthread_mutex_init(&sim->data.dead_mutex, NULL);
}

void	setup_simulation(t_param *sim)
{
	int	i;

	sim->data.start = actual_time();
	sim->data.stop = 0;
	sim->data.nb_philos_finished = 0;
	init_mutexes(sim);
	i = -1;
	while (++i < sim->args.nb_of_philos)
	{
		sim->philo[i].id = i + 1;
		sim->philo[i].last_meal_time = sim->data.start;
		sim->philo[i].nb_of_meal = 0;
		sim->philo[i].finished = 0;
		sim->philo[i].right_fork = NULL;
		pthread_mutex_init(&sim->philo[i].left_fork, NULL);
		if (sim->args.nb_of_philos == 1)
			return ;
		if (i == sim->args.nb_of_philos - 1)
			sim->philo[i].right_fork = &sim->philo[0].left_fork;
		else
			sim->philo[i].right_fork = &sim->philo[i + 1].left_fork;
	}
}
