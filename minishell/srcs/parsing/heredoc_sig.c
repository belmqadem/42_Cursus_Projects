/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_sig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 23:22:18 by iouhssei          #+#    #+#             */
/*   Updated: 2024/08/20 00:00:02 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_sigint_here(int sig)
{
	(void)sig;
	g_tools->g_sigint_received = 1;
	g_tools->last_exit_status = 130;
	rl_done = 1;
}

int	event_hook(void)
{
	if (g_tools->g_sigint_received)
		rl_done = 1;
	return (0);
}

int	close_free(char *line, int fd)
{
	free(line);
	close(fd);
	return (1);
}

void	setup_signal_handling(struct sigaction *old_sa_int,
		struct sigaction *old_sa_quit)
{
	struct sigaction	sa_int;
	struct sigaction	sa_quit;

	g_tools->g_sigint_received = 0;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = 0;
	sa_int.sa_handler = handle_sigint_here;
	sigaction(SIGINT, &sa_int, old_sa_int);
	sigemptyset(&sa_quit.sa_mask);
	sa_quit.sa_flags = 0;
	sa_quit.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa_quit, old_sa_quit);
}

void	restore_signal_handling(struct sigaction *old_sa_int,
		struct sigaction *old_sa_quit)
{
	sigaction(SIGINT, old_sa_int, NULL);
	sigaction(SIGQUIT, old_sa_quit, NULL);
}
