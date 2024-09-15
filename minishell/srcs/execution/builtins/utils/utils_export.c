/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:51:09 by ilyass            #+#    #+#             */
/*   Updated: 2024/08/20 11:17:28 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

void	lstadd_back_mine(t_var **env, char *new_var)
{
	t_var	*new_node;
	t_var	*last;

	new_node = malloc(sizeof(t_var));
	if (!new_node)
		return ;
	new_node->str = ft_strdup(new_var);
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!(*env))
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*env = new_node;
	}
	else
	{
		last = (*env)->prev;
		last->next = new_node;
		new_node->prev = last;
		new_node->next = *env;
		(*env)->prev = new_node;
	}
}

void	sort_env(t_var **env)
{
	t_var	*current;
	t_var	*index;
	t_var	*start;

	start = *env;
	if (!start)
		return ;
	while (1)
	{
		current = start;
		index = start->next;
		while (index != start)
		{
			if (ft_strcmp(current->str, index->str) < 0)
				swap(current, index);
			index = index->next;
		}
		start = start->next;
		if (start == *env)
			break ;
	}
}

void	handle_no_args(t_tools *tools)
{
	t_var	*current;
	t_var	*start;

	if (tools->handle_no_args_here == 0)
		sort_env(&tools->env);
	current = tools->env;
	if (current)
	{
		start = current;
		printf("declare -x %s\n", current->str);
		current = current->next;
		while (current != start)
		{
			printf("declare -x %s\n", current->str);
			current = current->next;
		}
	}
	tools->handle_no_args_here = 1;
}

void	i_run_out_of_names(char **value, char **new_value)
{
	if (*value)
		*new_value = ft_strdup(*value);
	else
		*new_value = ft_strdup("");
}

char	*extract_var_name_export(char *new_var, char **equal_sign,
		int *is_append)
{
	size_t	var_name_len;

	*equal_sign = ft_strchr(new_var, '=');
	*is_append = 0;
	if (*equal_sign != NULL && *equal_sign > new_var && *(*equal_sign \
		- 1) == '+')
	{
		*is_append = 1;
		*equal_sign = *equal_sign - 1;
	}
	if (*equal_sign)
		var_name_len = (size_t)(*equal_sign - new_var);
	else
		var_name_len = ft_strlen(new_var);
	return (ft_substr(new_var, 0, var_name_len));
}
