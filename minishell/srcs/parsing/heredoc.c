/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:22:56 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/20 00:57:54 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	print_err_hd(char *lim)
{
	ft_putstr_fd(RED HD_ERR, 2);
	ft_putstr_fd(lim, 2);
	ft_putendl_fd("')" RESET, 2);
}

static int	handle_input_lines(t_tools *tools, int fd, char *lim)
{
	char	*line;

	tools->last_exit_status = 0;
	rl_catch_signals = 0;
	rl_event_hook = event_hook;
	while (1)
	{
		line = readline("heredoc> ");
		if (!line)
		{
			print_err_hd(lim);
			break ;
		}
		if (g_tools->g_sigint_received)
		{
			g_tools->g_sigint_received = 0;
			tools->last_exit_status = 130;
			return (close_free(line, fd));
		}
		if (!ft_strncmp(lim, line, INT_MAX))
			break ;
		hd_expansion(tools, line, fd);
	}
	return (close_free(line, fd));
}

int	read_from_stdin(t_tools *tools, int fd, char *lim)
{
	struct sigaction	old_sa_int;
	struct sigaction	old_sa_quit;
	int					result;

	setup_signal_handling(&old_sa_int, &old_sa_quit);
	result = handle_input_lines(tools, fd, lim);
	restore_signal_handling(&old_sa_int, &old_sa_quit);
	return (result);
}

int	open_heredoc(t_tools *tools, char *lim)
{
	char	*name;
	int		fd;

	name = generate_rand_name(0, NULL);
	if (!name)
		return (-1);
	fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		return (free(name), -1);
	if (!read_from_stdin(tools, fd, lim))
	{
		unlink(name);
		return (free(name), -1);
	}
	fd = open(name, O_RDONLY);
	if (fd > 0)
		unlink(name);
	generate_rand_name(-3, NULL);
	free(name);
	return (fd);
}
