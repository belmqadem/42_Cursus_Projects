/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cd_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:50:58 by ilyass            #+#    #+#             */
/*   Updated: 2024/08/16 16:37:24 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static char	*concat_name_value(const char *name, const char *value)
{
	char	*new_str;
	char	*temp;

	new_str = ft_strjoin(name, "=");
	if (!new_str)
		return (NULL);
	temp = ft_strjoin(new_str, value);
	free(new_str);
	return (temp);
}

static void	update_existing_var(t_var *current, const char *name,
		const char *value)
{
	char	*new_str;

	new_str = concat_name_value(name, value);
	if (!new_str)
		return ;
	free(current->str);
	current->str = new_str;
}

void	add_new_var_cd(t_tools *tools, const char *name, const char *value)
{
	t_var	*new_var;
	char	*new_str;

	new_str = concat_name_value(name, value);
	if (!new_str)
		return ;
	new_var = malloc(sizeof(t_var));
	if (!new_var)
	{
		free(new_str);
		return ;
	}
	new_var->str = new_str;
	new_var->next = tools->env->next;
	tools->env->next = new_var;
}

void	update_env(t_tools *tools, char *name, char *value)
{
	t_var	*current;
	size_t	len;
	t_var	*start;

	len = ft_strlen(name);
	current = tools->env;
	start = tools->env;
	while (current != NULL)
	{
		if (ft_strncmp(current->str, name, len) == 0 \
			&& current->str[len] == '=')
		{
			update_existing_var(current, name, value);
			return ;
		}
		current = current->next;
		if (current == start)
			break ;
	}
	add_new_var_cd(tools, name, value);
}
