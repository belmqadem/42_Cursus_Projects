/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_own_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:51:14 by ilyass            #+#    #+#             */
/*   Updated: 2024/08/16 01:39:30 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	exe_cd(char **command, t_tools *tools, char *path, int cd_result)
{
	if (command[1] && command[2])
	{
		print_error(RED CD_ERR RESET);
		tools->last_exit_status = 1;
	}
	else if (command[1])
	{
		path = command[1];
		cd_result = my_own_cd(path, tools);
		cd_result_handle(command, tools, cd_result);
	}
	else
	{
		path = get_env_value(tools, "HOME");
		if (!path)
		{
			print_error_cd(command, ": HOME not set");
			tools->last_exit_status = 1;
			return ;
		}
		else
			my_own_cd(path, tools);
	}
}

void	free_perror(char *oldpwd, char *expanded_path, char *str)
{
	free(oldpwd);
	free(expanded_path);
	if (str)
		perror(str);
}

int	my_own_cd(char *path, t_tools *tools)
{
	char		*expanded_path;
	char		*oldpwd;
	char		cwd[1024];
	struct stat	path_stat;

	oldpwd = getcwd(NULL, 0);
	expanded_path = expand_path(path, tools);
	if (!expanded_path)
		return (free(oldpwd), perror("malloc"), -1);
	if (stat(expanded_path, &path_stat) != 0)
		return (free_perror(oldpwd, expanded_path, NULL), -3);
	if (!S_ISDIR(path_stat.st_mode))
		return (free_perror(oldpwd, expanded_path, NULL), -2);
	if (chdir(expanded_path) == -1)
		return (free_perror(oldpwd, expanded_path, "chdir"), -1);
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (free_perror(oldpwd, expanded_path, "getcwd"), -1);
	update_env(tools, "OLDPWD", oldpwd);
	update_env(tools, "PWD", cwd);
	free_perror(oldpwd, expanded_path, NULL);
	return (0);
}

void	cd_result_handle(char **command, t_tools *tools, int result)
{
	if (result == -3)
	{
		print_error_cd(command, ": No such file or directory");
		tools->last_exit_status = 1;
	}
	else if (result == -2)
	{
		print_error_cd(command, ": Not a directory");
		tools->last_exit_status = 1;
	}
	else if (result == -1)
		tools->last_exit_status = 1;
	else
		tools->last_exit_status = 0;
}

void	excute_cd(t_tools *tools, char **command)
{
	char	*path;
	int		cd_result;

	path = NULL;
	cd_result = 0;
	exe_cd(command, tools, path, cd_result);
}
