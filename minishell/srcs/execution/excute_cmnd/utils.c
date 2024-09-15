/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:57:07 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/20 00:54:45 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	print_error_ex(char **command, char *str)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command[0], 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(RESET, 2);
}

char	*extract_path_env(t_tools *tools)
{
	t_var	*current;
	size_t	path_len;

	if (!tools->env)
		return (NULL);
	path_len = ft_strlen("PATH=");
	current = tools->env;
	while (current != tools->env)
	{
		if (ft_strncmp(current->str, "PATH=", path_len) == 0)
			return (ft_strdup(current->str + path_len));
		current = current->next;
	}
	return (NULL);
}

char	**splitted_path(char *str)
{
	char	**path;

	while (ft_strchr(str, '='))
		str++;
	path = ft_split(str, ':');
	if (!path)
	{
		perror("malloc");
		exit(1);
		return (NULL);
	}
	return (path);
}

int	check_is_path(char *cmd)
{
	if (ft_strchr(cmd, '/'))
		return (1);
	return (0);
}

char	*search_path(char *cmd, char **path)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(tmp2, F_OK && X_OK) == 0)
		{
			return (tmp2);
		}
		i++;
		free(tmp2);
	}
	return (NULL);
}
