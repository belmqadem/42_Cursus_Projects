/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:21:07 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/07/26 23:34:42 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	handle_output_redirect(t_tools *tools, t_lexer *token, t_cmds *cmd)
{
	if (cmd->out >= 0)
		close(cmd->out);
	if (token->next == token || token->next->token <= 5)
	{
		print_err_token(token);
		tools->parse_err = true;
		tools->last_exit_status = 2;
		return (0);
	}
	if (tools->ambiguous || tools->not_found)
	{
		tools->quit = true;
		return (0);
	}
	cmd->out = open_file(tools, token->next->content, token->token);
	if (cmd->out == -1)
		return (0);
	return (1);
}

static int	handle_input_redirect(t_tools *tools, t_lexer *token, t_cmds *cmd)
{
	if (cmd->in >= 0)
		close(cmd->in);
	if (token->next == token || token->next->token <= 5)
	{
		print_err_token(token);
		tools->parse_err = true;
		tools->last_exit_status = 2;
		return (0);
	}
	if (token->token == INPUT)
	{
		if (tools->ambiguous || tools->not_found)
		{
			tools->quit = true;
			return (0);
		}
		cmd->in = open_file(tools, token->next->content, INPUT);
	}
	else
		cmd->in = open_heredoc(tools, token->next->content);
	if (cmd->in == -1)
		return (0);
	return (1);
}

static int	process_redirection(t_tools *tools, t_lexer *token, t_cmds *cmd)
{
	if (token->token == TRUNC || token->token == APPEND)
		return (handle_output_redirect(tools, token, cmd));
	else if (token->token == INPUT || token->token == HEREDOC)
		return (handle_input_redirect(tools, token, cmd));
	return (1);
}

int	get_redirect(t_tools *tools, t_lexer *token, t_cmds *cmd)
{
	t_lexer	*tmp;

	tmp = token;
	if (tmp->token != PIPE)
	{
		if (!process_redirection(tools, tmp, cmd))
			return (0);
	}
	tmp = tmp->next;
	while (tmp->token != PIPE && tmp != tools->token)
	{
		if (!process_redirection(tools, tmp, cmd))
			return (1);
		tmp = tmp->next;
	}
	return (1);
}
