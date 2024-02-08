/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:08:30 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/02/06 15:51:57 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute_cmd(char *cmd, char **envp)
{
	char	**command;
	char	*path_exec;

	command = ft_split(cmd, ' ');
	if (command[0][0] == '/')
	{
		if (access(command[0], F_OK | X_OK) == 0)
			path_exec = command[0];
	}
	else
	{
		path_exec = bring_the_path(command[0], envp);
		if (path_exec == NULL)
		{
			free_arr(command);
			ft_putendl_fd("Error: Command not found", 2);
			exit(1);
		}
	}
	if (execve(path_exec, command, envp) == -1)
	{
		free_arr(command);
		handle_error("execve", 1);
	}
}

static void	first_process(char **av, int *pipefd, char **envp)
{
	int	fd;

	fd = open(av[1], O_RDONLY, 0644);
	if (fd == -1)
		handle_error("open", 0);
	if (dup2(fd, 0) == -1)
	{
		close(fd);
		handle_error("dup2", 1);
	}
	if (dup2(pipefd[1], 1) == -1)
	{
		close(fd);
		handle_error("dup2", 1);
	}
	close_all_fds(fd, pipefd[0], pipefd[1], -1);
	execute_cmd(av[2], envp);
}

static void	second_process(char **av, int *pipefd, char **envp)
{
	int	fd;

	fd = open(av[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
		handle_error("open", 1);
	if (dup2(pipefd[0], 0) == -1)
	{
		close(fd);
		handle_error("dup2", 1);
	}
	if (dup2(fd, 1) == -1)
	{
		close(fd);
		handle_error("dup2", 1);
	}
	close_all_fds(fd, pipefd[0], pipefd[1], -1);
	execute_cmd(av[3], envp);
}

static void	do_pipe(char **av, char **envp)
{
	int		pipefd[2];
	pid_t	id1;
	pid_t	id2;

	if (pipe(pipefd) == -1)
		handle_error("pipe", 1);
	id1 = fork();
	if (id1 == -1)
		handle_error("fork", 1);
	else if (id1 == 0)
		first_process(av, pipefd, envp);
	id2 = fork();
	if (id2 == -1)
		handle_error("fork", 1);
	if (id2 == 0)
		second_process(av, pipefd, envp);
	close_all_fds(pipefd[0], pipefd[1], -1);
	waitpid(id1, NULL, 0);
	waitpid(id2, NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	if (ac != 5)
	{
		ft_putendl_fd("Error: Invalid number of arguments", 2);
		return (1);
	}
	if (is_empty(av[2]) || is_empty(av[3]))
	{
		ft_putendl_fd("Error: Please enter a command", 2);
		return (1);
	}
	do_pipe(av, envp);
	return (0);
}
