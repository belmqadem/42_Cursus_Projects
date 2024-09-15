/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:38:36 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/20 01:49:56 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_child(t_tools *tools, t_cmds *cmd, int input_fd, int output_fd)
{
	char	*path;
	char	**env;
	int		cmd_status;

	handle_child_in_out(input_fd, output_fd, cmd);
	path = NULL;
	cmd_status = is_cmd_exist(tools, cmd, &path);
	if (cmd_status == 1)
	{
		env = lst_to_arr(tools->env);
		if (!env)
			free_all(tools, ERR_MALLOC, 1, NULL);
		if (execve(path, cmd->command, env) == -1)
		{
			free_all(tools, NULL, -1, path);
			exit(tools->last_exit_status);
		}
	}
	else
	{
		handle_child_error(cmd_status, tools, cmd);
		exit(tools->last_exit_status);
	}
}

void	child_excute(t_execute_info ex_info, t_tools *tools, t_cmds *cmd)
{
	dup_and_close(ex_info, tools);
	if (cmd && !cmd->skip_cmd && cmd->command[0] && is_builtin(cmd->command[0]))
		builtins(ex_info, tools, cmd);
	else
		child(tools, ex_info, cmd);
}

void	my_last_breath(t_tools *tools, t_cmds *current, t_execute_info ex_info)
{
	if (!ex_info.is_last_cmd && pipe(tools->pipefds) == -1)
		return (perror("pipe"));
	current->pid_fork = fork();
	if (current->pid_fork == -1)
		return (perror("fork"));
	else if (current->pid_fork == 0)
	{
		signal(SIGINT, SIG_DFL);
		child_excute(ex_info, tools, current);
		tools->cmd->pid = current->pid_fork;
	}
}

void	init_idk_bruh(t_execute_info *ex_info, t_cmds *current, t_tools *tools)
{
	ex_info->is_last_cmd = (current->next == tools->cmd);
	ex_info->is_first_cmd = (current == tools->cmd);
}

int	execute_cmds(t_tools *tools)
{
	t_cmds			*current;
	t_execute_info	ex_info;

	current = tools->cmd;
	if (current->next == current)
		return (execute_single_command(tools, current));
	ex_info.prev_pipe = -1;
	while (current)
	{
		init_idk_bruh(&ex_info, current, tools);
		my_last_breath(tools, current, ex_info);
		tools->cmd->pid = current->pid_fork;
		if (ex_info.prev_pipe != -1)
			close(ex_info.prev_pipe);
		if (!ex_info.is_last_cmd)
		{
			close(tools->pipefds[1]);
			ex_info.prev_pipe = tools->pipefds[0];
		}
		current = current->next;
		if (ex_info.is_last_cmd)
			break ;
	}
	wait_all(tools);
	return (1);
}
