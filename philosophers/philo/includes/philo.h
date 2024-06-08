/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:58:37 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/06/02 22:48:14 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// **** Header files **** //
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

// **** Colors **** //
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[0m"

// **** Error messages **** //
# define ERR_ARGS "Error: Invalid set of arguments\n  \
Try: ./philo NBR T2D T2E T2S [NBR OF MEAL]"
# define ERR_ZERO_PHILOS "Error: Try with one philosopher or more"
# define ERR_INT_MAX "Error: The input is way bigger than INT_MAX"

// **** Log State **** //
# define TOOK "has taken a fork 🍴"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died ☠️"
# define FINISH "Each philosopher ate %d time(s)\n"

// **** Structs **** //
typedef struct s_arguments
{
	int				nb_of_philos;
	int				time_2_die;
	int				time_2_eat;
	int				time_2_sleep;
	int				count_meal;
}	t_arguments;

typedef struct s_shared_data
{
	long int		start;
	int				stop;
	int				nb_philos_finished;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	time_eat_mutex;
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t	dead_mutex;
}	t_shared_data;

typedef struct s_philosopher
{
	int				id;
	long int		last_meal_time;
	int				nb_of_meal;
	int				finished;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	left_fork;
	pthread_t		th_id;
	pthread_t		monitor_th_id;
	t_arguments		*args;
	t_shared_data	*data;
}	t_philosopher;

typedef struct s_param
{
	t_philosopher	*philo;
	t_arguments		args;
	t_shared_data	data;
}	t_param;

// **** Utils Functions **** //
int			print_error(char *msg);
void		ft_usleep(long int time_in_ms);
long int	actual_time(void);
void		print_state(char *state, t_philosopher *philo);

// **** Main Functions **** //
int			parse_arguments(int ac, char **av, t_param *data);
void		setup_simulation(t_param *sim);
void		run_dining_simulation(t_param *sim);
int			check_life_status(t_philosopher *philo, int flag);
int			dining_behavior(t_philosopher *philo);
void		cleanup_simulation(t_param *sim);

#endif
