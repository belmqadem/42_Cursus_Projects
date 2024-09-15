/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:51:11 by ilyass            #+#    #+#             */
/*   Updated: 2024/08/20 00:28:11 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

void	add_new_var(t_tools *tools, char *var_name, char *value)
{
	char	*new_entry;
	char	*temp;

	temp = NULL;
	new_entry = ft_strjoin(var_name, "=");
	if (value)
	{
		temp = ft_strjoin(new_entry, value);
		free(new_entry);
		new_entry = temp;
	}
	lstadd_back_mine(&tools->env, new_entry);
	free(temp);
}

void	print_error_export(char *command)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("minishell: export: `", STDERR_FILENO);
	ft_putstr_fd(command, STDERR_FILENO);
	ft_putstr_fd(NAI, STDERR_FILENO);
	ft_putstr_fd(RESET, 2);
}

int	is_valid_var_name(const char *var_name)
{
	int	i;

	if (!ft_isalpha(var_name[0]) && var_name[0] != '_')
		return (0);
	i = 1;
	while (var_name[i])
	{
		if (!ft_isalnum(var_name[i]) && var_name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	add_quotes(t_var **undefined)
{
	t_var	*current;
	t_var	*start;
	char	*new_str;
	char	*equals_sign;

	current = *undefined;
	if (!current)
		return ;
	start = current;
	while (1)
	{
		equals_sign = strchr(current->str, '=');
		if (equals_sign)
		{
			new_str = malloc(strlen(current->str) + 3);
			if (!new_str)
				return ;
			add_quote_helper(new_str, current, equals_sign);
			current->str = new_str;
		}
		current = current->next;
		if (current == start)
			break ;
	}
}

void	add_quote_helper(char *new_str, t_var *current, char *equals_sign)
{
	ft_strncpy(new_str, current->str, equals_sign - current->str + 1);
	new_str[equals_sign - current->str + 1] = '\0';
	ft_strcat(new_str, "\"");
	ft_strcat(new_str, equals_sign + 1);
	ft_strcat(new_str, "\"");
	free(current->str);
}
