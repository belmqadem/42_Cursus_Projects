/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:52:04 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/16 14:00:54 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	open_file(t_tools *tools, char *name, int type)
{
	int	fd;

	fd = -2;
	if (type == INPUT)
		fd = open(name, O_RDONLY, 0644);
	else if (type == TRUNC)
		fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (type == APPEND)
		fd = open(name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
	{
		ft_putstr_fd(RED "minishell: ", 2);
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": ", 2);
		perror(NULL);
		ft_putstr_fd(RESET, 2);
		tools->last_exit_status = 1;
		tools->red_err = true;
	}
	return (fd);
}

bool	is_redirect(int token)
{
	if (token == INPUT)
		return (true);
	if (token == TRUNC)
		return (true);
	if (token == APPEND)
		return (true);
	if (token == HEREDOC)
		return (true);
	return (false);
}
