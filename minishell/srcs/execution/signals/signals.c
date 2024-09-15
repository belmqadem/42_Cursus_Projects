/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyass <ilyass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:52:24 by ilyass            #+#    #+#             */
/*   Updated: 2024/08/19 17:18:12 by ilyass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_sigint(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
	g_tools->last_exit_status = 130;
}

void	setup_terminal(void)
{
	struct termios	term;

	if (tcgetattr(STDIN_FILENO, &term) == -1)
	{
		perror("tcgetattr");
		exit(1);
	}
	term.c_lflag &= ~ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) == -1)
	{
		perror("tcsetattr");
		exit(1);
	}
}

void	handle_sigquit(int sig)
{
	(void)sig;
	if (g_tools->cmd && g_tools->cmd->pid > 0)
	{
		kill(g_tools->cmd->pid, SIGQUIT);
		write(STDERR_FILENO, "^\\Quit (core dumped)\n", 22);
		g_tools->last_exit_status = 131;
	}
	else
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	handle_signals(void)
{
	struct sigaction	sa_int;

	setup_terminal();
	sa_int.sa_handler = handle_sigint;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = 0;
	if (sigaction(SIGINT, &sa_int, NULL) == -1)
	{
		perror("sigaction");
		exit(1);
	}
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, SIG_IGN);
}
