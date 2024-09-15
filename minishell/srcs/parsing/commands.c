/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:09:04 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/15 17:32:11 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	add_to_cmd_param(char **cmd_param, int *i, char *str)
{
	cmd_param[*i] = ft_strdup(str);
	if (!cmd_param[*i])
		return (0);
	(*i)++;
	return (1);
}

char	**set_cmd_param(t_tools *tools, t_lexer *token)
{
	char	**cmd_param;
	int		i;
	t_lexer	*tmp;
	int		count;

	count = calc_args(tools, token);
	cmd_param = ft_calloc((count + 1), sizeof(char *));
	if (!cmd_param)
		return (NULL);
	i = 0;
	tmp = token;
	if (tmp->token != PIPE && (tmp->token == CMD || (tmp->token == ARG \
		&& tmp->prev != tools->token->prev && !is_redirect(tmp->prev->token))))
		if (!add_to_cmd_param(cmd_param, &i, tmp->content))
			return (free_arr(cmd_param), NULL);
	tmp = tmp->next;
	while (tmp != tools->token && tmp->token != PIPE)
	{
		if ((tmp->token == CMD || (tmp->token == ARG && \
			tmp->prev != tools->token->prev && !is_redirect(tmp->prev->token))))
			if (!add_to_cmd_param(cmd_param, &i, tmp->content))
				return (free_arr(cmd_param), NULL);
		tmp = tmp->next;
	}
	return (cmd_param);
}

int	configure_cmd(t_tools *tools, t_lexer *token)
{
	if (!get_redirect(tools, token, tools->cmd->prev) \
		&& (tools->cmd->prev->in != -1 || tools->cmd->prev->out != -1))
		return (0);
	if (tools->cmd->prev->in == -1)
	{
		tools->cmd->prev->skip_cmd = true;
		tools->cmd->prev->out = -1;
		return (1);
	}
	if (tools->cmd->prev->out == -1)
	{
		if (tools->cmd->prev->in >= 0)
			close (tools->cmd->prev->in);
		tools->cmd->prev->skip_cmd = true;
		tools->cmd->prev->in = -1;
		return (1);
	}
	tools->cmd->prev->command = set_cmd_param(tools, token);
	if (!tools->cmd->prev->command)
		free_all(tools, ERR_MALLOC, 1, NULL);
	return (1);
}

int	create_command_list(t_tools *tools)
{
	t_lexer	*current;

	current = tools->token;
	if (!cmdadd_back(&tools->cmd, -2, -2, NULL))
		free_all(tools, ERR_MALLOC, 1, NULL);
	if (!configure_cmd(tools, current))
		return (0);
	current = current->next;
	while (current != tools->token)
	{
		if (current->prev->token == PIPE)
		{
			if (current->token == PIPE)
				return (or_err(tools));
			if (!cmdadd_back(&tools->cmd, -2, -2, NULL))
				free_all(tools, ERR_MALLOC, 1, NULL);
			if (!configure_cmd(tools, current))
				return (0);
		}
		current = current->next;
	}
	return (1);
}
