/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:57:38 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/02/06 19:02:05 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

int	check_empty(int ac, char **av)
{
	int	i;
	int	check;

	i = 2;
	while (i < ac - 1)
	{
		check = is_empty(av[i]);
		if (check == 1)
			return (1);
		i++;
	}
	return (check);
}

void	multiple_pipe(char **av)
{
	int	infd;

	infd = f_open(av[1], 0, 0);
	if (dup2(infd, 0) == -1)
	{
		handle_error("dup2", 1);
	}
}

void	read_from_stdin(char **av, int *pipefd)
{
	char	*line;

	close(pipefd[0]);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, av[2], ft_strlen(line + 1)) == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, pipefd[1]);
		free(line);
	}
}
