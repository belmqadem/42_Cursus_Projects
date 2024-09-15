/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_own_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyass <ilyass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 04:18:52 by samurai0lav       #+#    #+#             */
/*   Updated: 2024/08/19 17:08:46 by ilyass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	print_error_env(t_cmds *cmd, char *str)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(cmd->command[0], 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(RESET, 2);
}

void	my_own_env(t_tools *tools)
{
	t_var	*current;
	t_var	*start;

	if (!tools->env)
		return ;
	if (tools->cmd && tools->cmd->command[1])
	{
		print_error_env(tools->cmd, ": No such file or directory\n");
		tools->last_exit_status = 127;
		return ;
	}
	current = tools->env;
	start = tools->env;
	while (current)
	{
		printf("%s\n", current->str);
		current = current->next;
		if (current == start)
			break ;
	}
}
