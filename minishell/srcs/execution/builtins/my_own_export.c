/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_own_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:51:30 by ilyass            #+#    #+#             */
/*   Updated: 2024/08/20 11:12:23 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static t_var_info	*parse_var_info(char *command, t_tools *tools)
{
	t_var_info	*info;
	char		*equal_sign;

	info = (t_var_info *)malloc(sizeof(t_var_info));
	if (!info)
		return (NULL);
	info->var_name = extract_var_name_export(command, &equal_sign,
			&info->is_append);
	if (!info->var_name || !is_valid_var_name(info->var_name))
	{
		free(info->var_name);
		free(info);
		tools->last_exit_status = 1;
		print_error_export(command);
		return (NULL);
	}
	info->value = NULL;
	if (equal_sign)
	{
		if (info->is_append && *(equal_sign + 1) == '=')
			info->value = equal_sign + 2;
		else if (!info->is_append && *equal_sign == '=')
			info->value = equal_sign + 1;
	}
	return (info);
}

static t_var	*find_existing_var(t_var *env, const char *var_name)
{
	t_var	*current;
	size_t	current_var_len;
	char	*current_equal_sign;

	if (!env)
		return (NULL);
	current = env;
	while (1)
	{
		current_equal_sign = ft_strchr(current->str, '=');
		if (current_equal_sign)
			current_var_len = (size_t)(current_equal_sign - current->str);
		else
			current_var_len = ft_strlen(current->str);
		if (ft_strncmp(current->str, var_name, current_var_len) == 0
			&& ft_strlen(var_name) == current_var_len)
			return (current);
		current = current->next;
		if (current == env)
			break ;
	}
	return (NULL);
}

static void	update_var(t_var *current, char *var_name, char *value,
		int is_append)
{
	char	*new_value;
	char	*existing_value;
	char	*equal_sign;
	char	*var_name_with_eq;

	existing_value = NULL;
	if (is_append && value)
	{
		equal_sign = ft_strchr(current->str, '=');
		if (equal_sign)
			existing_value = ft_strdup(equal_sign + 1);
		else
			existing_value = ft_strdup("");
		new_value = ft_strjoin(existing_value, value);
		free(existing_value);
	}
	else
		i_run_out_of_names(&value, &new_value);
	free(current->str);
	var_name_with_eq = ft_strjoin(var_name, "=");
	current->str = ft_strjoin(var_name_with_eq, new_value);
	free(new_value);
	free(var_name_with_eq);
}

static void	handle_var_update(t_tools *tools, t_var_info *info)
{
	t_var	*current;

	current = find_existing_var(tools->env, info->var_name);
	if (info->value == NULL)
		return ;
	else if (current != NULL)
		update_var(current, info->var_name, info->value, info->is_append);
	else
		add_new_var(tools, info->var_name, info->value);
}

void	my_own_export(t_tools *tools, char **command)
{
	t_var_info	*info;
	int			i;

	if (command[1] == NULL)
		return (handle_no_args(tools));
	i = 1;
	while (command[i])
	{
		info = parse_var_info(command[i], tools);
		if (!info)
		{
			i++;
			continue ;
		}
		handle_var_update(tools, info);
		i++;
		free(info->var_name);
		free(info);
	}
}
