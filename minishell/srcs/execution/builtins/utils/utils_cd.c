/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:51:02 by ilyass            #+#    #+#             */
/*   Updated: 2024/08/20 01:36:58 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

void	print_error_cd(char **command, char *str)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command[0], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(command[1], 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd(RESET, 2);
}

char	*get_env_value(t_tools *tools, char *name)
{
	t_var	*current;
	size_t	len;

	if (!tools->env)
		return (NULL);
	len = ft_strlen(name);
	current = tools->env;
	while (current->next != tools->env)
	{
		if (ft_strncmp(current->str, name, len) == 0 \
			&& current->str[len] == '=')
		{
			return (current->str + len + 1);
		}
		current = current->next;
	}
	if (ft_strncmp(current->str, name, len) == 0 \
		&& current->str[len] == '=')
	{
		return (current->str + len + 1);
	}
	return (NULL);
}

char	*expand_path(char *path, t_tools *tools)
{
	char	*home;
	char	*oldpwd;

	if (ft_strcmp(path, "~") == 0 || ft_strncmp(path, "~/", 2) == 0)
	{
		home = get_env_value(tools, "HOME");
		if (home)
			return (ft_strjoin(home, path + 1));
		ft_putstr_fd(RED, 2);
		ft_putendl_fd("minishell: cd: HOME not set", 2);
		ft_putstr_fd(RESET, 2);
		return (ft_strdup("."));
	}
	else if (ft_strcmp(path, "-") == 0)
	{
		oldpwd = get_env_value(tools, "OLDPWD");
		if (oldpwd)
			return (ft_strdup(oldpwd));
		ft_putstr_fd(RED, 2);
		ft_putendl_fd("minishell: cd: OLDPWD not set", 2);
		ft_putstr_fd(RESET, 2);
		return (ft_strdup("."));
	}
	return (ft_strdup(path));
}
