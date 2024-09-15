/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:14:44 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/20 11:25:41 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	err_last(t_tools *tools)
{
	print_error(RED ERR_OR RESET);
	free_token(&tools->token);
	tools->last_exit_status = 2;
	return (0);
}

int	parsed_commands(t_tools *tools)
{
	if (tools->token && tools->token->prev->token == PIPE)
		return (err_last(tools));
	if (!tools->token || !create_command_list(tools))
	{
		free_token(&tools->token);
		return (free_cmd(&tools->cmd), 0);
	}
	if (!tools->quit && tools->token && tools->token->prev->token < 5)
	{
		print_error(RED ERR_NL RESET);
		free_token(&tools->token);
		free_cmd(&tools->cmd);
		tools->last_exit_status = 2;
		return (0);
	}
	if (tools->token->token == PIPE)
	{
		print_error(RED ERR_OR RESET);
		free_token(&tools->token);
		free_cmd(&tools->cmd);
		tools->last_exit_status = 2;
		return (0);
	}
	return (1);
}

int	parse_command_line(t_tools *tools, char *input)
{
	if (*input && check_dir(input))
		return (err_dir(input, tools));
	if (*input && check_tokens(input))
		return (err_first_char(tools, input));
	if (open_quotes(tools, input))
		return (free(input), 0);
	if (!expansion(tools, &input))
		free_all(tools, ERR_MALLOC, 1, input);
	if (!tokenize(tools, &tools->token, input))
		free_all(tools, ERR_MALLOC, 1, input);
	free(input);
	return (parsed_commands(tools));
}
