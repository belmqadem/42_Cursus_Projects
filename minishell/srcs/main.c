/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 05:34:09 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/20 11:10:36 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_tools	*g_tools;

static void	init_tools(t_tools	*tools)
{
	tools->env = NULL;
	tools->token = NULL;
	tools->cmd = NULL;
	tools->last_exit_status = 0;
	tools->pipefds[0] = 0;
	tools->pipefds[1] = 0;
	tools->num_command = 0;
	tools->sq = false;
	tools->dq = false;
	tools->parse_err = false;
	tools->not_found = false;
	tools->quit = false;
	tools->ambiguous = false;
	tools->hd_count = 0;
	tools->red_err = false;
	tools->var_count = 0;
	tools->handle_no_args_here = 0;
}

static void	exec_and_free(t_tools *tools)
{
	if (!tools->parse_err)
	{
		if (!tools->quit)
			execute_cmds(tools);
		else
		{
			print_error(RED "minishell: ambiguous redirect" RESET);
			tools->last_exit_status = 2;
		}
	}
	free_cmd(&tools->cmd);
	free_token(&tools->token);
}

static void	init_parse(t_tools	*tools)
{
	tools->parse_err = false;
	tools->not_found = false;
	tools->quit = false;
	tools->ambiguous = false;
	tools->hd_count = 0;
	tools->red_err = false;
	tools->var_count = 0;
}

static void	display_prompt(t_tools	*tools)
{
	char	*input;

	input = NULL;
	while (1)
	{
		input = readline(BLUE BOLD PROMPT RESET);
		if (!input)
		{
			ft_putendl_fd("exit", 1);
			free_all(tools, NULL, tools->last_exit_status, NULL);
		}
		if (check_empty(input))
		{
			free(input);
			continue ;
		}
		check_cmd_not_found(tools, input);
		add_history(input);
		init_parse(tools);
		if (!parse_command_line(tools, input))
			continue ;
		exec_and_free(tools);
	}
	rl_clear_history();
}

int	main(int ac, char	**av, char	**envp)
{
	t_tools	tools;

	(void)av;
	if (ac != 1)
	{
		printf(GREEN ERR_ARGS RESET);
		return (0);
	}
	init_tools(&tools);
	g_tools = &tools;
	if (!setup_env(&tools, envp))
	{
		print_error(RED ERR_MALLOC RESET);
		exit(1);
	}
	update_shell_level(&tools);
	handle_signals();
	display_prompt(&tools);
	free_all(&tools, NULL, 0, NULL);
}
