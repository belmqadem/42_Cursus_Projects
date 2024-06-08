/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:36:03 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/06/02 22:48:41 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	took_both_forks(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&philo->data->write_mutex);
	print_state(CYAN TOOK RESET, philo);
	pthread_mutex_unlock(&philo->data->write_mutex);
	if (!philo->right_fork)
	{
		pthread_mutex_unlock(&philo->left_fork);
		ft_usleep(philo->args->time_2_die * 2);
		return (-1);
	}
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->data->write_mutex);
	print_state(CYAN TOOK RESET, philo);
	pthread_mutex_unlock(&philo->data->write_mutex);
	return (0);
}

static void	start_eating(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->write_mutex);
	print_state(CYAN EAT RESET, philo);
	pthread_mutex_unlock(&philo->data->write_mutex);
	pthread_mutex_lock(&philo->data->time_eat_mutex);
	philo->last_meal_time = actual_time();
	pthread_mutex_unlock(&philo->data->time_eat_mutex);
	ft_usleep(philo->args->time_2_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}

static void	sleep_and_think(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->write_mutex);
	print_state(CYAN SLEEP RESET, philo);
	pthread_mutex_unlock(&philo->data->write_mutex);
	ft_usleep(philo->args->time_2_sleep);
	pthread_mutex_lock(&philo->data->write_mutex);
	print_state(CYAN THINK RESET, philo);
	pthread_mutex_unlock(&philo->data->write_mutex);
}

int	dining_behavior(t_philosopher *philo)
{
	if (took_both_forks(philo) == -1)
		return (-1);
	start_eating(philo);
	sleep_and_think(philo);
	return (0);
}
