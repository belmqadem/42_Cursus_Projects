/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_own_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:51:24 by ilyass            #+#    #+#             */
/*   Updated: 2024/08/16 13:57:24 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static long long	process_exit_argument(char *arg, t_tools *tools)
{
	long long	exit_status;

	exit_status = 0;
	if (ft_isnumeric(arg))
	{
		if (check_overflow(arg))
		{
			ft_putendl_fd("exit", 1);
			print_error_exit(arg);
			free_all(tools, NULL, 2, arg);
		}
		exit_status = ft_atoi(arg);
		if (exit_status < 0)
			exit_status = 256 + (exit_status % 256);
		else
			exit_status = exit_status % 256;
	}
	else
	{
		ft_putendl_fd("exit", 1);
		print_error_exit(arg);
		free_all(tools, NULL, 2, arg);
	}
	return (exit_status);
}

static void	handle_multiple_arguments(void)
{
	ft_putendl_fd("exit", 1);
	ft_putstr_fd(RED "minishell: exit", 2);
	ft_putstr_fd(TMMA RESET, 2);
}

static void	perform_exit(t_tools *tools, long long exit_status)
{
	rl_clear_history();
	free_all(tools, NULL, (int)exit_status, NULL);
}

void	my_own_exit(t_tools *tools, char **str)
{
	long long	exit_status;
	char		**command;
	char		*arg;
	int			count;

	count = numbr_command(tools);
	command = str;
	exit_status = tools->last_exit_status;
	if (command[1])
	{
		arg = ft_strtrim(command[1], "'\"");
		exit_status = process_exit_argument(arg, tools);
		if (command[2])
		{
			handle_multiple_arguments();
			tools->last_exit_status = 1;
			free(arg);
			return ;
		}
		free(arg);
	}
	if (count == 1)
		ft_putendl_fd("exit", 1);
	perform_exit(tools, exit_status);
}
