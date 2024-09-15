/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 00:54:24 by iouhssei          #+#    #+#             */
/*   Updated: 2024/08/20 00:56:34 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	update_shell_level(t_tools *tools)
{
	t_var	*current;
	int		shlvl;
	char	*new_shlvl_str;
	char	*shlvl_str;

	if (!tools->env)
		return ;
	shlvl = 0;
	shlvl_str = NULL;
	new_shlvl_str = NULL;
	current = tools->env;
	while (1)
	{
		if (ft_strncmp(current->str, "SHLVL=", 6) == 0)
		{
			shlvl_helper2(new_shlvl_str, current, shlvl_str, shlvl);
			return ;
		}
		current = current->next;
		if (current == tools->env)
			break ;
	}
	shlvl_helper(tools);
}

void	shlvl_helper2(char *new, t_var *curr, char *str, int lvl)
{
	str = curr->str + 6;
	lvl = ft_atoi(str);
	if (str[0] != '-' && lvl == 0 && ft_strncmp(str, "0", 2) != 0)
		lvl = 1;
	else
		lvl++;
	if (lvl < 0 || lvl > 999)
		lvl = 0;
	new = ft_itoa(lvl);
	free(curr->str);
	curr->str = ft_strjoin("SHLVL=", new);
	free(new);
}

void	shlvl_helper(t_tools *tools)
{
	t_var	*new_var;
	t_var	*last;

	new_var = malloc(sizeof(t_var));
	if (!new_var)
		return ;
	new_var->str = ft_strdup("SHLVL=1");
	if (!new_var->str)
		return (free(new_var));
	if (!tools->env)
	{
		tools->env = new_var;
		new_var->next = new_var;
		new_var->prev = new_var;
	}
	else
	{
		last = tools->env->prev;
		new_var->next = tools->env;
		new_var->prev = last;
		tools->env->prev = new_var;
		last->next = new_var;
		tools->env = new_var;
	}
}
