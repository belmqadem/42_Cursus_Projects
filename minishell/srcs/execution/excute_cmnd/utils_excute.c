/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_excute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:52:03 by ilyass            #+#    #+#             */
/*   Updated: 2024/08/20 10:55:15 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**lst_to_arr(t_var *env)
{
	t_var	*lst;
	char	**dest;
	int		i;

	if (!env)
		return (NULL);
	dest = NULL;
	i = 0;
	lst = env;
	dest = (char **)malloc(sizeof(char *) * (lstsize(lst) + 1));
	if (!dest)
		return (NULL);
	dest[i] = (lst->str);
	lst = lst->next;
	i++;
	while (lst != env)
	{
		dest[i] = (lst->str);
		lst = lst->next;
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

void	stdout_backup_function(int stdout_backup)
{
	if (stdout_backup != -1)
	{
		dup2(stdout_backup, STDOUT_FILENO);
		close(stdout_backup);
	}
}

void	handle_builtin(t_tools *tools, t_cmds *cmd, int input_fd, int output_fd)
{
	int	stdout_backup;

	stdout_backup = -1;
	if (input_fd != -1)
	{
		dup2(input_fd, STDIN_FILENO);
		close(input_fd);
	}
	if (cmd->out >= 0)
	{
		stdout_backup = dup(STDOUT_FILENO);
		dup2(cmd->out, STDOUT_FILENO);
	}
	else if (output_fd != -1)
	{
		stdout_backup = dup(STDOUT_FILENO);
		dup2(output_fd, STDOUT_FILENO);
	}
	execute_builtin(tools, cmd, output_fd);
	stdout_backup_function(stdout_backup);
	if (output_fd != -1)
		close(output_fd);
}

void	handle_child_error(int cmd_status, t_tools *tools, t_cmds *cmd)
{
	if (cmd_status == 2)
	{
		tools->last_exit_status = 1;
		print_error_ex(cmd->command, NPERM);
	}
	else if (cmd_status == 4)
	{
		tools->last_exit_status = 127;
		print_error_ex(cmd->command, NCMD);
	}
	else if (cmd_status == 5)
	{
		tools->last_exit_status = 126;
		print_error_ex(cmd->command, NDIR);
	}
	else
	{
		tools->last_exit_status = 1;
		print_error_ex(cmd->command, NSFD);
	}
	free_all(tools, NULL, -1, NULL);
}

void	handle_child_in_out(int input_fd, int output_fd, t_cmds *cmd)
{
	if (cmd->in >= 0)
		dup2(cmd->in, STDIN_FILENO);
	else if (input_fd != -1)
		dup2(input_fd, STDIN_FILENO);
	if (cmd->out >= 0)
		dup2(cmd->out, STDOUT_FILENO);
	else if (output_fd != -1)
		dup2(output_fd, STDOUT_FILENO);
	if (input_fd != -1)
		close(input_fd);
	if (output_fd != -1)
		close(output_fd);
}
