/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_excute2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyass <ilyass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:52:07 by ilyass            #+#    #+#             */
/*   Updated: 2024/08/19 20:21:47 by ilyass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	wait_all(t_tools *tools)
{
	int		status;
	int		pid;
	int		num_cmds;
	t_cmds	*tmp;
	t_cmds	*last_cmd;

	tmp = tools->cmd;
	num_cmds = len_cmd(tmp);
	last_cmd = find_last_command(tmp);
	while (num_cmds > 0)
	{
		ignore_sigint();
		pid = waitpid(-1, &status, 0);
		restore_sigint();
		if (pid == -1 && handle_waitpid_error() != 0)
			break ;
		tools->cmd = find_command_by_pid(tools->cmd, pid);
		if (tools->cmd)
			process_command_status(tools, tools->cmd, status, last_cmd);
		num_cmds--;
	}
}

int	find_env(t_tools *tools, char *name)
{
	t_var	*current;
	size_t	len;

	len = ft_strlen(name);
	current = tools->env;
	if (current == NULL)
		return (0);
	while (1)
	{
		if (ft_strncmp(current->str, name, len) == 0
			&& current->str[len] == '=')
			return (1);
		current = current->next;
		if (current == tools->env)
			break ;
	}
	return (0);
}

int	is_builtin(char *cmd)
{
	char	*builtin[8];
	int		i;

	builtin[0] = "echo";
	builtin[1] = "cd";
	builtin[2] = "pwd";
	builtin[3] = "export";
	builtin[4] = "unset";
	builtin[5] = "env";
	builtin[6] = "exit";
	builtin[7] = NULL;
	i = -1;
	while (builtin[++i])
		if (ft_strcmp(builtin[i], cmd) == 0)
			return (1);
	return (0);
}

void	close_file(t_cmds *cmd)
{
	if (cmd->in >= 0)
		close(cmd->in);
	if (cmd->out >= 0)
		close(cmd->out);
}

size_t	len_cmd(t_cmds *list)
{
	t_cmds	*tmp;
	size_t	i;

	if ((list))
	{
		tmp = list;
		i = 1;
		while (tmp->next != list)
		{
			++i;
			tmp = tmp->next;
		}
		return (i);
	}
	return (0);
}
