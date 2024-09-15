/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_own_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 04:19:22 by samurai0lav       #+#    #+#             */
/*   Updated: 2024/08/16 16:32:24 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char	**check_n_option(char **str, int *new_line)
{
	int	i;

	*new_line = 1;
	while (*str && ft_strncmp(*str, "-n", 2) == 0)
	{
		i = 2;
		while ((*str)[i] == 'n')
			i++;
		if ((*str)[i] == '\0')
		{
			*new_line = 0;
			str++;
		}
		else
			break ;
	}
	return (str);
}

static void	print_arguments(char **str)
{
	while (*str)
	{
		printf("%s", *str);
		if (*(str + 1))
			printf(" ");
		str++;
	}
}

void	my_own_echo(char **str, t_tools *tools)
{
	int	new_line;

	str++;
	str = check_n_option(str, &new_line);
	print_arguments(str);
	if (new_line)
		printf("\n");
	tools->last_exit_status = 0;
}
