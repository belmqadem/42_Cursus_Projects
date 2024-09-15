/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd_exist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:51:59 by ilyass            #+#    #+#             */
/*   Updated: 2024/08/20 01:20:20 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	is_dir(char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) == -1)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

int	check_direct_command(char *command, char **path)
{
	*path = ft_strdup(command);
	if (!*path)
		return (0);
	if (access(*path, F_OK) == 0)
	{
		if (access(*path, X_OK) == 0 && !is_dir(*path))
			return (1);
		else if (is_dir(*path))
			return (5);
		else
			return (2);
	}
	return (3);
}

int	search_command_in_path(char **paths, char *command, char **path)
{
	int		i;
	char	*temp;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			return (0);
		*path = ft_strjoin(temp, command);
		free(temp);
		if (!*path)
			return (0);
		if (access(*path, F_OK) == 0)
		{
			if (access(*path, X_OK) == 0)
				return (1);
			else
				return (2);
		}
		free(*path);
		i++;
	}
	return (4);
}

int	is_cmd_exist(t_tools *tools, t_cmds *cmd, char **path)
{
	char	**paths;
	int		result;
	char	*env_path;

	if (cmd->skip_cmd)
		return (1);
	if (cmd->command[0] == NULL)
		return (1);
	if (ft_strchr(cmd->command[0], '/'))
		return (check_direct_command(cmd->command[0], path));
	if (cmd->command[0][0] == '.' && cmd->command[0][1] == '\0')
		return (5);
	env_path = get_env_value(tools, "PATH");
	if (!env_path)
	{
		tools->last_exit_status = 127;
		return (0);
	}
	paths = ft_split(env_path, ':');
	if (!paths)
		return (0);
	result = search_command_in_path(paths, cmd->command[0], path);
	free_arr(paths);
	return (result);
}
