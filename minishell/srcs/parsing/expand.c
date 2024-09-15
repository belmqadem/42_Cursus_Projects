/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyass <ilyass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 03:29:01 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/19 17:04:44 by ilyass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	expand_env_var(t_tools *tools, char *input, int size, char **output)
{
	char	*tmp;
	char	*variable;
	char	*value;

	variable = extract_var_name(input, size);
	value = lookup_env_var(tools->env, variable);
	if (variable)
		free(variable);
	if (check_ambig(value) && !tools->dq)
		tools->ambiguous = true;
	tmp = ft_strjoin(*output, value);
	if (value)
		free(value);
	free(*output);
	if (!tmp)
		return (0);
	*output = tmp;
	return (1);
}

int	expand_exit_status(t_tools *tools, char **output)
{
	char	*tmp;
	char	*ext_stt;

	tmp = ft_itoa(tools->last_exit_status);
	if (!tmp)
		return (0);
	ext_stt = ft_strjoin(*output, tmp);
	free(tmp);
	free(*output);
	if (!ext_stt)
		return (0);
	*output = ext_stt;
	return (1);
}

int	handle_dollar(char *input, int *i, char **output, t_tools *tools)
{
	int		control;
	int		start;

	start = *i;
	control = find_env_var(input, i, tools);
	if (control == 1)
	{
		tools->var_count++;
		if (!expand_env_var(tools, &input[start], *i - start, output))
			return (0);
	}
	else if (control == 2)
	{
		(*i) += 2;
		if (!expand_exit_status(tools, output))
			return (0);
	}
	else
	{
		check_ambiguous(tools);
		++(*i);
		while (input[*i] && (ft_isalnum(input[*i]) || input[*i] == '_'))
			++(*i);
	}
	return (1);
}

int	append_char(char *c, char **str, t_tools *tools, int *i)
{
	char	char_str[2];
	char	*tmp;
	int		j;

	j = 0;
	tmp = NULL;
	if (c[j] == '$' && !tools->sq && find_env_var(c, &j, tools))
		return (1);
	char_str[0] = *c;
	char_str[1] = '\0';
	(*i)++;
	tmp = ft_strjoin(*str, char_str);
	free(*str);
	if (!tmp)
		return (0);
	*str = tmp;
	return (1);
}

int	expansion(t_tools *tools, char **input)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup("");
	while ((*input)[i])
	{
		update_quote_state(&tools->dq, &tools->sq, (*input)[i]);
		if ((*input)[i] && (*input)[i + 1] && (*input)[i] == '$' &&
			!tools->sq && ((*input)[i + 1] != SQ && (*input)[i + 1] != DQ) &&
			(ft_isalpha((*input)[i + 1]) || (*input)[i + 1] == '_'
			|| (*input)[i + 1] == '?'))
		{
			if (!handle_dollar((*input), &i, &str, tools))
				return (free(str), 0);
		}
		else
		{
			if (!append_char(&(*input)[i], &str, tools, &i))
				return (free(str), 0);
		}
	}
	free(*input);
	*input = str;
	return (1);
}
