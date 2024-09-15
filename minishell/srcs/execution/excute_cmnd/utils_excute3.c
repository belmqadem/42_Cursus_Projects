/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_excute3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:52:10 by ilyass            #+#    #+#             */
/*   Updated: 2024/08/14 03:47:42 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_cmds	*find_last_command(t_cmds *cmd)
{
	t_cmds	*last_cmd;

	last_cmd = cmd;
	while (last_cmd->next != cmd)
		last_cmd = last_cmd->next;
	return (last_cmd);
}

t_cmds	*find_command_by_pid(t_cmds *cmd, int pid)
{
	while (cmd && cmd->pid_fork != pid)
		cmd = cmd->next;
	return (cmd);
}

int	handle_waitpid_error(void)
{
	if (errno == EINTR)
		return (1);
	if (errno == ECHILD)
		return (-1);
	perror("waitpid");
	return (-1);
}

void	process_command_status(t_tools *tools, t_cmds *cmd, int status,
		t_cmds *last_cmd)
{
	int	last_command_status;

	last_command_status = 0;
	if (WIFEXITED(status))
		last_command_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		last_command_status = 128 + WTERMSIG(status);
	if (cmd == last_cmd)
		tools->last_exit_status = last_command_status;
	close_file(cmd);
}

void	dup_and_close(t_execute_info ex_info, t_tools *tools)
{
	if (!ex_info.is_first_cmd)
		dup2(ex_info.prev_pipe, STDIN_FILENO);
	if (!ex_info.is_last_cmd)
		dup2(tools->pipefds[1], STDOUT_FILENO);
	if (ex_info.prev_pipe != -1)
		close(ex_info.prev_pipe);
	if (!ex_info.is_last_cmd)
		close_pipefds(tools);
}
