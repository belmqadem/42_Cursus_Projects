/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 02:07:36 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/02/05 17:11:55 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	close_all_fds(int fd, ...)
{
	va_list	ap;
	int		current_fd;

	va_start(ap, fd);
	current_fd = fd;
	while (current_fd != -1)
	{
		close(current_fd);
		current_fd = va_arg(ap, int);
	}
	va_end(ap);
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
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	is_empty(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
