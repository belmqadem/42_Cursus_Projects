/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:58:06 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/19 23:18:11 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Checks whether str matches the name of an environment variable defined in env
int	validate_env_var_name(char *str, char *env)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		++i;
	j = -1;
	while (env[++j])
		if (env[j] == '=' && j == i)
			return (i);
	return (0);
}

// Checks if the following characters from an env variable or '$?'
int	find_env_var(char *input, int *i, t_tools *tools)
{
	t_var	*tmp;
	int		len;
	int		key_len;

	if (input[*i + 1] == '?')
		return (2);
	tmp = tools->env;
	len = lstsize(tmp);
	key_len = 0;
	while (len--)
	{
		key_len = validate_env_var_name(&input[*i + 1], tmp->str);
		if (!ft_strncmp(tmp->str, &input[*i + 1], key_len))
		{
			*i += ft_strlen(tmp->str) - ft_strlen(ft_strchr(tmp->str, '=')) + 1;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

// Searching for an environment variable
char	*lookup_env_var(t_var *env, char *key)
{
	t_var	*current;
	int		len;
	int		start;

	if (!key)
		return (NULL);
	current = env;
	len = lstsize(current);
	start = ft_strlen(key);
	while (len--)
	{
		if (!ft_strncmp(current->str, key, start))
		{
			len = 0;
			while (current->str[len])
				if (current->str[len++] == '=')
					break ;
			return (ft_strdup(current->str + len));
		}
		current = current->next;
	}
	return (NULL);
}

// Copies characters from input to variable excluding '$'
char	*extract_var_name(char *input, int size)
{
	char	*dollar;
	int		i;

	dollar = malloc(sizeof(char) * size);
	if (!dollar)
		return (NULL);
	i = 0;
	while (input[++i] && i < size)
		dollar[i - 1] = input[i];
	dollar[i - 1] = '\0';
	return (dollar);
}

size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}
