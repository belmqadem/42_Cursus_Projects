/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:40:01 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/14 03:51:15 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	check_empty(char *input)
{
	while (*input && ft_isspace(*input))
		input++;
	if (*input == '\0')
		return (true);
	return (false);
}

void	print_error(char *err)
{
	if (err)
		ft_putendl_fd(err, 2);
}

void	close_pipefds(t_tools *tools)
{
	if (tools->pipefds[0] > 0)
		close(tools->pipefds[0]);
	if (tools->pipefds[1] > 0)
		close(tools->pipefds[1]);
}

void	close_fds(t_cmds *cmd)
{
	if (cmd->in > 0)
		close(cmd->in);
	cmd->in = -2;
	if (cmd->out > 0)
		close(cmd->out);
	cmd->out = -2;
}

int	numbr_command(t_tools *tools)
{
	t_cmds	*tmp;
	int		count;

	if (!tools->cmd)
		return (0);
	count = 0;
	tmp = tools->cmd;
	while (tmp->next != tools->cmd)
	{
		count++;
		tmp = tmp->next;
	}
	count++;
	return (count);
}
