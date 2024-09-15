/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:53:47 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/18 17:29:13 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parse_error(t_tools *tools, char *err, char *input)
{
	print_error(err);
	tools->last_exit_status = 2;
	tools->parse_err = true;
	free(input);
	return (2);
}

bool	check_dir(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == '/')
		i++;
	if (str[i] == '\0')
		return (true);
	return (false);
}

bool	check_tokens(const char *input)
{
	int	i;

	i = -1;
	while (input[++i])
		if (!ft_strchr("<>|&;", (int)input[i]))
			return (false);
	return (true);
}

int	err_dir(char *input, t_tools *tools)
{
	ft_putstr_fd(RED "minishell: ", 2);
	ft_putstr_fd(input, 2);
	ft_putendl_fd(": Is a directory" RESET, 2);
	tools->last_exit_status = 126;
	tools->parse_err = true;
	free(input);
	return (0);
}

int	err_first_char(t_tools *tools, char *input)
{
	ft_putstr_fd(RED ERR_TOKEN, 2);
	ft_putchar_fd(input[0], 2);
	ft_putendl_fd("'" RESET, 2);
	tools->last_exit_status = 2;
	tools->parse_err = true;
	free(input);
	return (0);
}
