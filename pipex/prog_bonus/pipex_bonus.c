/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:01:34 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/02/06 19:01:13 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

static void	execute(int ac, char **av, char **envp, int fd)
{
	if (dup2(fd, 1) == -1)
		handle_error("dup2", 1);
	execute_cmd(av[ac - 2], envp);
}

static void	do_pipe(char *cmd, char **envp)
{
	pid_t	id;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		handle_error("pipe", 1);
	id = fork();
	if (id == -1)
		handle_error("fork", 1);
	else if (id == 0)
	{
		close(pipefd[0]);
		if (dup2(pipefd[1], 1) == -1)
			handle_error("dup2", 1);
		execute_cmd(cmd, envp);
	}
	else
	{
		close(pipefd[1]);
		if (dup2(pipefd[0], 0) == -1)
			handle_error("dup2", 1);
		wait(NULL);
	}
}

static void	here_doc(char **av)
{
	pid_t	id;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		handle_error("pipe", 1);
	id = fork();
	if (id == -1)
		handle_error("fork", 1);
	else if (id == 0)
		read_from_stdin(av, pipefd);
	else
	{
		close(pipefd[1]);
		if (dup2(pipefd[0], 0) == -1)
			handle_error("dup2", 1);
		wait(NULL);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	cmd_index;
	int	outfd;

	if (ac < 5)
		return (ft_putendl_fd("Error: Invalid number of arguments", 2), 1);
	if (check_empty(ac, av))
		return (ft_putendl_fd("Error: Please enter a command", 2), 1);
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		if (ac < 6)
			return (ft_putendl_fd("Error: invalid number of arguments", 2), 1);
		cmd_index = 3;
		outfd = f_open(av[ac - 1], 2, 1);
		here_doc(av);
	}
	else
	{
		cmd_index = 2;
		outfd = f_open(av[ac - 1], 1, 1);
		multiple_pipe(av);
	}
	while (cmd_index < ac - 2)
		do_pipe(av[cmd_index++], envp);
	execute(ac, av, envp, outfd);
	return (0);
}
