/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:19:57 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/06/03 00:05:15 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_life_status(t_philosopher *philo, int flag)
{
	pthread_mutex_lock(&philo->data->dead_mutex);
	if (flag != 0)
		philo->data->stop = flag;
	if (philo->data->stop != 0)
	{
		pthread_mutex_unlock(&philo->data->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead_mutex);
	return (0);
}

static void	process_meal_completion(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->finish_mutex);
	philo->finished = 1;
	philo->data->nb_philos_finished += 1;
	if (philo->data->nb_philos_finished == philo->args->nb_of_philos)
	{
		pthread_mutex_unlock(&philo->data->finish_mutex);
		check_life_status(philo, 2);
	}
	pthread_mutex_unlock(&philo->data->finish_mutex);
}

static void	*starvation_guard(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	ft_usleep(philo->args->time_2_die);
	pthread_mutex_lock(&philo->data->time_eat_mutex);
	pthread_mutex_lock(&philo->data->finish_mutex);
	if (!check_life_status(philo, 0) && !philo->finished && \
		((actual_time() - philo->last_meal_time) >= \
		(long)(philo->args->time_2_die)))
	{
		pthread_mutex_lock(&philo->data->write_mutex);
		print_state(RED DEAD RESET, philo);
		pthread_mutex_unlock(&philo->data->write_mutex);
		check_life_status(philo, 1);
	}
	pthread_mutex_unlock(&philo->data->time_eat_mutex);
	pthread_mutex_unlock(&philo->data->finish_mutex);
	return (NULL);
}

static void	*life_cycle(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	if (philo->id % 2 == 0)
		ft_usleep(philo->args->time_2_eat);
	pthread_create(&philo->monitor_th_id, NULL, starvation_guard, data);
	while (!check_life_status(philo, 0))
	{
		if (dining_behavior(philo) != -1)
			philo->nb_of_meal++;
		if (philo->nb_of_meal == philo->args->count_meal)
		{
			process_meal_completion(philo);
			break ;
		}
	}
	pthread_join(philo->monitor_th_id, NULL);
	return (NULL);
}

void	run_dining_simulation(t_param *sim)
{
	int	i;

	i = 0;
	while (i < sim->args.nb_of_philos)
	{
		sim->philo[i].args = &sim->args;
		sim->philo[i].data = &sim->data;
		pthread_create(&sim->philo[i].th_id, NULL, life_cycle, &sim->philo[i]);
		i++;
	}
	i = 0;
	while (i < sim->args.nb_of_philos)
	{
		pthread_join(sim->philo[i].th_id, NULL);
		i++;
	}
}
