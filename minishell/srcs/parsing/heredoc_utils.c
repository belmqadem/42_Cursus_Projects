/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:58:41 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/19 23:35:48 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	expand_heredoc(t_tools *tools, char **input)
{
	int		i;
	char	*str;

	i = 0;
	tools->dq = false;
	tools->sq = false;
	str = ft_strdup("");
	while ((*input)[i])
	{
		update_quote_state(&tools->dq, &tools->sq, (*input)[i]);
		if ((*input)[i] && (*input)[i + 1] && (*input)[i] == '$' && ((*input)[i
				+ 1] != SQ && (*input)[i + 1] != DQ) && (ft_isalpha((*input)[i
					+ 1]) || (*input)[i + 1] == '_' || (*input)[i + 1] == '?'))
			if (!handle_dollar((*input), &i, &str, tools))
				return (0);
		if ((*input)[i])
			if (!append_char(&(*input)[i], &str, tools, &i))
				return (0);
	}
	free(*input);
	*input = str;
	return (1);
}

int	dont_expand(char **input)
{
	int		i;
	char	*str;
	char	char_str[2];
	char	*tmp;

	i = 0;
	str = ft_strdup("");
	if (!str)
		return (0);
	while ((*input)[i])
	{
		char_str[0] = (*input)[i];
		char_str[1] = '\0';
		i++;
		tmp = ft_strjoin(str, char_str);
		free(str);
		if (!tmp)
			return (0);
		str = tmp;
	}
	free(*input);
	*input = str;
	return (1);
}

void	hd_expansion(t_tools *tools, char *line, int fd)
{
	if (!tools->token->quoted_hd && !expand_heredoc(tools, &line))
		free_all(tools, ERR_MALLOC, 1, line);
	if (tools->token->quoted_hd && !dont_expand(&line))
		free_all(tools, ERR_MALLOC, 1, line);
	ft_putendl_fd(line, fd);
	free(line);
}
