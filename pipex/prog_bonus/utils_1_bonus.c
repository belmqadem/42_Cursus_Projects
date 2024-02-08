/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:01:50 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/02/06 18:59:49 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*bring_the_path(char *cmd, char **envp)
{
	char	**full_path;
	char	*path;
	char	*final_path;
	int		i;

	while (*envp && ft_strnstr(*envp, "PATH", 4) == 0)
		envp++;
	if (!*envp)
		return (NULL);
	full_path = ft_split(*envp + 5, ':');
	i = -1;
	while (full_path[++i])
	{
		path = ft_strjoin(full_path[i], "/");
		final_path = ft_strjoin(path, cmd);
		free (path);
		if (access(final_path, F_OK | X_OK) == 0)
		{
			free_arr(full_path);
			return (final_path);
		}
		free(final_path);
	}
	free_arr(full_path);
	return (NULL);
}

int	f_open(char *file, int mode, int code)
{
	int	fd;

	fd = 0;
	if (mode == 0)
		fd = open(file, O_RDONLY, 0644);
	else if (mode == 1)
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (mode == 2)
		fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
		handle_error("open", code);
	return (fd);
}

void	handle_error(char *msg, int code)
{
	perror(msg);
	if (code == 0)
		exit(0);
	else if (code == 1)
		exit(1);
}

void	free_arr(char **arr)
{
	size_t	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
