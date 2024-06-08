/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:03:27 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/06/01 04:57:49 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	print_error(char *msg)
{
	while (*msg)
		write (2, msg++, 1);
	write (2, "\n", 1);
	return (0);
}

void	ft_usleep(long int time_in_ms)
{
	usleep(time_in_ms * 1000);
}

long int	actual_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print_state(char *state, t_philosopher *philo)
{
	long int	time;

	time = actual_time() - philo->data->start;
	if (time >= 0 && time <= INT_MAX && !check_life_status(philo, 0))
		printf("[ %ld ] -- Philo %d %s\n", time, philo->id, state);
}
