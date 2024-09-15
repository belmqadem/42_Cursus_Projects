/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_own_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyass <ilyass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:56:23 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/19 17:10:21 by ilyass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	is_matching_env_var(t_var *var, const char *env_var, int var_len)
{
	if (!var->str || !env_var)
		return (0);
	return (ft_strncmp(var->str, env_var, var_len) == 0
		&& (var->str[var_len] == '=' || var->str[var_len] == '\0'));
}

void	update_env_links(t_tools *tools, t_var *to_remove)
{
	if (!tools || !to_remove || !tools->env)
		return ;
	if (to_remove->next == to_remove)
	{
		tools->env = NULL;
		return ;
	}
	to_remove->next->prev = to_remove->prev;
	to_remove->prev->next = to_remove->next;
	if (tools->env == to_remove)
		tools->env = to_remove->next;
}

void	find_and_remove_var(t_tools *tools, char *var_name)
{
	t_var	*current;
	size_t	var_len;
	t_var	*next;

	if (!tools || !tools->env || !var_name)
		return ;
	current = tools->env;
	var_len = ft_strlen(var_name);
	while (1)
	{
		next = current->next;
		if (is_matching_env_var(current, var_name, var_len))
		{
			update_env_links(tools, current);
			free(current->str);
			free(current);
			if (!tools->env)
				break ;
		}
		current = next;
		if (current == tools->env)
			break ;
	}
}

void	my_own_unset(t_tools *tools, char **command)
{
	int	i;

	if (!tools->env)
		return ;
	i = 1;
	while (command[i])
	{
		find_and_remove_var(tools, command[i]);
		i++;
	}
}
