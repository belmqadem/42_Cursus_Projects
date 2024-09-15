/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:30:05 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/16 01:30:54 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	calc_cmd_len(char *input, int *quotes)
{
	int	i;

	i = 0;
	*quotes = 0;
	while (input[i] && !ft_isspace(input[i]) && !is_special_token(input + i))
	{
		if (input[i] == DQ || input[i] == SQ)
		{
			(*quotes)++;
			if (input[i++] == DQ)
				while (input[i] && input[i] != DQ)
					++i;
			else
				while (input[i] && input[i] != SQ)
					++i;
			if (input[i])
				++i;
		}
		if (input[i] && input[i] != DQ && input[i] != SQ
			&& !ft_isspace(input[i]) && !is_special_token(input + i))
			++i;
	}
	return (i);
}

void	copy_token(char *input, int length, char *output, int i)
{
	int	j;

	j = 0;
	while (input[i + j] && i < length)
	{
		if (input[i + j] == SQ && ++j)
		{
			while (input[i + j] != SQ && ++i)
				output[i - 1] = input[i - 1 + j];
			j++;
		}
		else if (input[i + j] == DQ && ++j)
		{
			while (input[i + j] != DQ && ++i)
				output[i - 1] = input[i - 1 + j];
			j++;
		}
		else
		{
			output[i] = input[i + j];
			i++;
		}
	}
	output[i] = '\0';
}

int	add_cmd(t_lexer **token, char **input)
{
	char	*str;
	int		cmd_len;
	int		quotes;
	int		i;

	i = 0;
	cmd_len = calc_cmd_len(*input, &quotes);
	if ((cmd_len - (2 * quotes)) < 0)
		return (1);
	str = ft_calloc((cmd_len + 1) - (2 * quotes), sizeof(char));
	if (!str)
		return (0);
	if ((*token) && (*token)->prev && (*token)->prev->token == HEREDOC)
		if (is_quoted(*input))
			(*token)->quoted_hd = true;
	copy_token(*input, cmd_len - (2 * quotes), str, i);
	if (!append_token(token, str, 0))
		return (free(str), 0);
	if ((*token)->prev == (*token) || (*token)->prev->prev->token == PIPE)
		(*token)->prev->token = CMD;
	else
		(*token)->prev->token = ARG;
	(*input) += cmd_len;
	return (1);
}

int	add_special_token(t_tools *tools, t_lexer **token, char **input)
{
	int	spc;

	spc = set_special_token(*input);
	if (!spc)
		return (0);
	if (spc == INPUT && !append_token(token, ft_strdup("<"), INPUT))
		return (0);
	else if (spc == HEREDOC)
	{
		check_hd_max(tools);
		tools->hd_count++;
		if (!append_token(token, ft_strdup("<<"), HEREDOC))
			return (0);
	}
	else if (spc == TRUNC && !append_token(token, ft_strdup(">"), TRUNC))
		return (0);
	else if (spc == APPEND && !append_token(token, ft_strdup(">>"), APPEND))
		return (0);
	else if (spc == PIPE && !append_token(token, ft_strdup("|"), PIPE))
		return (0);
	if (spc == INPUT || spc == TRUNC || spc == PIPE)
		(*input)++;
	else if (spc == HEREDOC || spc == APPEND)
		(*input) += 2;
	return (1);
}

int	tokenize(t_tools *tools, t_lexer **token, char *input)
{
	(*token) = NULL;
	while (*input)
	{
		while (ft_isspace(*input))
			input++;
		if (*input && !is_special_token(input))
		{
			if (!add_cmd(token, &input))
				if (*token)
					return (0);
		}
		else if (*input && is_special_token(input))
		{
			if (!add_special_token(tools, token, &input))
				if (*token)
					return (0);
		}
	}
	return (1);
}
