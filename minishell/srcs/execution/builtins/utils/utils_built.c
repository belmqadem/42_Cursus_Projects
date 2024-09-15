/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_built.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyass <ilyass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:50:55 by ilyass            #+#    #+#             */
/*   Updated: 2024/08/14 00:50:56 by ilyass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

static int	ft_update_existing_env(t_var *env, const char *name,
		char *new_env_var)
{
	while (env)
	{
		if (ft_strncmp(env->str, name, ft_strlen(name)) == 0
			&& env->str[ft_strlen(name)] == '=')
		{
			free(env->str);
			env->str = new_env_var;
			return (1);
		}
		env = env->next;
	}
	return (0);
}

static int	ft_add_new_env(t_var **env, char *new_env_var)
{
	t_var	*new_var;

	new_var = malloc(sizeof(t_var));
	if (!new_var)
		return (-1);
	new_var->str = new_env_var;
	new_var->next = *env;
	new_var->prev = NULL;
	if (*env)
		(*env)->prev = new_var;
	*env = new_var;
	return (0);
}

int	ft_setenv(t_var **env, const char *name, const char *value)
{
	char	*tmp;
	char	*new_env_var;

	tmp = ft_strjoin(name, "=");
	new_env_var = ft_strjoin(tmp, value);
	free(tmp);
	if (ft_update_existing_env(*env, name, new_env_var))
		return (0);
	return (ft_add_new_env(env, new_env_var));
}

void	swap(t_var *a, t_var *b)
{
	char	*temp;

	temp = a->str;
	a->str = b->str;
	b->str = temp;
}
