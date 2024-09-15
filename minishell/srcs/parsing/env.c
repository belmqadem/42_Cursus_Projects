/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:50:11 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/19 23:17:27 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	lstsize(t_var *list)
{
	t_var	*tmp;
	size_t	count;

	if (!list)
		return (0);
	count = 1;
	tmp = list;
	while (tmp->next != list)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

t_var	*lstnew(char *str)
{
	t_var	*new;

	new = (t_var *)malloc(sizeof(t_var));
	if (!new)
		return (NULL);
	new->str = str;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	lstadd_back(t_var **list, char *str)
{
	t_var	*new;

	new = lstnew(str);
	if (!new)
		return (0);
	if (!(*list))
	{
		(*list) = new;
		(*list)->next = *list;
		(*list)->prev = *list;
	}
	else
	{
		new->prev = (*list)->prev;
		new->next = (*list);
		(*list)->prev->next = new;
		(*list)->prev = new;
	}
	return (1);
}

int	set_env_backup(t_tools *tools)
{
	char	path[PATH_MAX];
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	if (!getcwd(path, PATH_MAX))
		free_all(tools, ERR_MALLOC, 1, NULL);
	tmp = ft_strjoin("PWD=", path);
	if (!tmp || !lstadd_back(&(tools->env), tmp))
		free_all(tools, ERR_MALLOC, 1, NULL);
	tmp2 = ft_strdup("SHLVL=1");
	if (! tmp2 || !lstadd_back(&(tools->env), tmp2))
		free_all(tools, ERR_MALLOC, 1, tmp);
	tmp3 = ft_strdup("_=/usr/bin/env");
	if (!tmp3 || !lstadd_back(&(tools->env), tmp3))
	{
		free(tmp2);
		free_all(tools, ERR_MALLOC, 1, tmp);
	}
	return (1);
}

int	setup_env(t_tools *tools, char **envp)
{
	t_var	*env;
	int		i;
	char	*tmp;

	if (!(*envp))
		return (set_env_backup(tools));
	env = NULL;
	tmp = NULL;
	i = -1;
	while (envp[++i])
	{
		tmp = ft_strdup(envp[i]);
		if (!tmp)
			return (free_list(&tools->env), 0);
		if (!lstadd_back(&env, tmp))
		{
			free_list(&tools->env);
			return (free(tmp), 0);
		}
	}
	tools->env = env;
	return (1);
}
