/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:08:57 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/18 17:28:05 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmds	*cmd_new(int in, int out, char **param)
{
	t_cmds	*new_cmd;

	new_cmd = (t_cmds *)malloc(sizeof(t_cmds));
	if (!new_cmd)
		return (NULL);
	new_cmd->command = param;
	new_cmd->in = in;
	new_cmd->out = out;
	new_cmd->skip_cmd = false;
	new_cmd->next = NULL;
	new_cmd->prev = NULL;
	return (new_cmd);
}

int	cmdadd_back(t_cmds **cmd, int in, int out, char **param)
{
	t_cmds	*new;

	new = cmd_new(in, out, param);
	if (!new)
		return (0);
	if (!(*cmd))
	{
		(*cmd) = new;
		(*cmd)->prev = *cmd;
		(*cmd)->next = *cmd;
	}
	else
	{
		new->prev = (*cmd)->prev;
		new->next = (*cmd);
		(*cmd)->prev->next = new;
		(*cmd)->prev = new;
	}
	return (1);
}

int	calc_args(t_tools *tools, t_lexer *token)
{
	t_lexer	*tmp;
	int		c;

	c = 0;
	tmp = token;
	if (tmp->token == CMD || (tmp->token == ARG \
		&& tmp->prev != tools->token->prev && tmp->prev->token > 5))
		c++;
	tmp = tmp->next;
	while (tmp != tools->token && tmp->token != PIPE)
	{
		if (tmp->token == CMD || (tmp->token == ARG \
			&& tmp->prev != tools->token->prev && tmp->prev->token > 5))
			c++;
		tmp = tmp->next;
	}
	return (c);
}

void	print_err_token(t_lexer *token)
{
	ft_putstr_fd(RED ERR_TOKEN, 2);
	ft_putstr_fd(token->next->content, 2);
	ft_putendl_fd("'" RESET, 2);
}

int	or_err(t_tools *tools)
{
	tools->parse_err = true;
	tools->last_exit_status = 2;
	print_error(RED OR_ERR RESET);
	return (0);
}
