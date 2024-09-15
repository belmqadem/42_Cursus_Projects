/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_excute4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyass <ilyass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:52:13 by ilyass            #+#    #+#             */
/*   Updated: 2024/08/19 21:06:02 by ilyass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	execute_builtin(t_tools *tools, t_cmds *cmd, int fd)
{
	if (ft_strncmp(cmd->command[0], "cd", 3) == 0)
		excute_cd(tools, cmd->command);
	else if (ft_strncmp(cmd->command[0], "env", 4) == 0)
		my_own_env(tools);
	else if (ft_strncmp(cmd->command[0], "echo", 5) == 0)
		my_own_echo(cmd->command, tools);
	else if (ft_strncmp(cmd->command[0], "pwd", 4) == 0)
		my_own_pwd(tools, cmd->command);
	else if (ft_strncmp(cmd->command[0], "export", 7) == 0)
		my_own_export(tools, cmd->command);
	else if (ft_strncmp(cmd->command[0], "unset", 6) == 0)
		my_own_unset(tools, cmd->command);
	else if (ft_strncmp(cmd->command[0], "exit", 5) == 0)
	{
		if (cmd->out >= 0)
		{
			dup2(fd, STDOUT_FILENO);
			close(fd);
		}
		my_own_exit(tools, cmd->command);
	}
}

int	builtin_single_cmd(t_cmds *cmd, t_tools *tools)
{
	int	stdout_original;

	stdout_original = -1;
	if (cmd->out >= 0)
	{
		stdout_original = dup(STDOUT_FILENO);
		dup2(cmd->out, STDOUT_FILENO);
	}
	execute_builtin(tools, cmd, stdout_original);
	if (cmd->out >= 0)
	{
		dup2(stdout_original, STDOUT_FILENO);
		close(stdout_original);
	}
	return (1);
}

int	execute_single_command(t_tools *tools, t_cmds *cmd)
{
	int		status;
	pid_t	pid;

	if (cmd && !cmd->skip_cmd && cmd->command[0] && is_builtin(cmd->command[0]))
		return (builtin_single_cmd(cmd, tools));
	pid = fork();
	if (pid == -1)
		return (perror("fork"), 0);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		handle_child(tools, cmd, -1, -1);
	}
	ignore_sigint();
	waitpid(pid, &status, 0);
	restore_sigint();
	if (WIFEXITED(status))
		tools->last_exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		tools->last_exit_status = 128 + WTERMSIG(status);
	return (1);
}

void	builtins(t_execute_info ex_info, t_tools *tools, t_cmds *cmd)
{
	int	fd_out;

	fd_out = -1;
	if (ex_info.is_last_cmd)
		fd_out = -1;
	else
		fd_out = tools->pipefds[1];
	handle_builtin(tools, cmd, ex_info.prev_pipe, fd_out);
	exit(tools->last_exit_status);
}

void	child(t_tools *tools, t_execute_info ex_info, t_cmds *cmd)
{
	int	fd_out;

	if (ex_info.is_last_cmd)
		fd_out = -1;
	else
		fd_out = tools->pipefds[1];
	handle_child(tools, cmd, ex_info.prev_pipe, fd_out);
}
