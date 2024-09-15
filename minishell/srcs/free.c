/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:50:58 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/20 11:19:20 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr && arr[++i])
		free(arr[i]);
	if (arr)
		free(arr);
}

void	free_cmd(t_cmds **cmd)
{
	t_cmds	*current;
	t_cmds	*tmp;

	if (!(*cmd))
		return ;
	current = *cmd;
	while (current && current->next != *cmd)
	{
		tmp = current;
		current = current->next;
		free_arr(tmp->command);
		close_fds(tmp);
		free(tmp);
	}
	if (current)
	{
		free_arr(current->command);
		close_fds(current);
		free(current);
	}
	*cmd = NULL;
}

void	free_token(t_lexer **list)
{
	t_lexer	*tmp;
	t_lexer	*current;

	if (!(*list))
		return ;
	current = *list;
	while (current && current->next != *list)
	{
		tmp = current;
		current = current->next;
		free(tmp->content);
		free(tmp);
	}
	if (current)
	{
		free(current->content);
		free(current);
	}
	*list = NULL;
}

void	free_list(t_var **list)
{
	t_var	*tmp;
	t_var	*current;

	if (!list || !(*list))
		return ;
	current = *list;
	while (current && current->next != *list)
	{
		tmp = current;
		current = current->next;
		free(tmp->str);
		free(tmp);
	}
	if (current)
	{
		free(current->str);
		free(current);
	}
	*list = NULL;
}

void	free_all(t_tools *tools, char *err, int status, char *str)
{
	if (str != NULL)
		free(str);
	if (tools->token != NULL)
		free_token(&tools->token);
	if (tools->cmd != NULL)
		free_cmd(&tools->cmd);
	if (tools->env != NULL)
		free_list(&tools->env);
	if (err)
		print_error(err);
	rl_clear_history();
	if (status != -1)
		exit(status);
}
