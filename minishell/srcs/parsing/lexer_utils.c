/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 04:51:32 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/09 11:49:41 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	is_special_token(char *str)
{
	if (str && *str && ft_strlen(str) >= 2)
	{
		if (!ft_strncmp(str, "<<", 2) || !ft_strncmp(str, ">>", 2))
			return (true);
	}
	if (*str && ft_strlen(str) >= 1)
	{
		if (!ft_strncmp(str, "<", 1) || !ft_strncmp(str, ">", 1)
			|| !ft_strncmp(str, "|", 1))
			return (true);
	}
	return (false);
}

t_lexer	*token_new(char *str, int type)
{
	t_lexer	*new_token;

	if (!str)
		return (NULL);
	new_token = (t_lexer *)malloc(sizeof(t_lexer));
	if (!new_token)
		return (NULL);
	new_token->content = str;
	new_token->token = type;
	new_token->next = NULL;
	new_token->prev = NULL;
	return (new_token);
}

int	append_token(t_lexer **token, char *str, int type)
{
	t_lexer	*new;

	new = token_new(str, type);
	if (!new)
		return (0);
	if (!(*token))
	{
		(*token) = new;
		(*token)->next = *token;
		(*token)->prev = *token;
	}
	else
	{
		new->prev = (*token)->prev;
		new->next = (*token);
		(*token)->prev->next = new;
		(*token)->prev = new;
	}
	return (1);
}

int	set_special_token(char *str)
{
	if (str && *str && ft_strlen(str) >= 2)
	{
		if (!ft_strncmp(str, "<<", 2))
			return (HEREDOC);
		if (!ft_strncmp(str, ">>", 2))
			return (APPEND);
	}
	if (*str && ft_strlen(str) >= 1)
	{
		if (!ft_strncmp(str, "<", 1))
			return (INPUT);
		if (!ft_strncmp(str, ">", 1))
			return (TRUNC);
		if (!ft_strncmp(str, "|", 1))
			return (PIPE);
	}
	return (0);
}

bool	is_quoted(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == SQ || str[i] == DQ)
			return (true);
	}
	return (false);
}
