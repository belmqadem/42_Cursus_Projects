/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:32:54 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/09/30 13:32:55 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	count_char(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

int	check_valid_arg(int ac, char **av)
{
	int	i;

	if (ac != 2)
		exit_w_error(NULL, INVALID_ARG);
	i = ft_strlen(av[1]) - 1;
	if (count_char(av[1], '.') > 1)
		return (0);
	if ((av[1][i] == 'b') && (av[1][i - 1] == 'u') && (av[1][i - 2] == 'c')
		&& (av[1][i - 3] == '.') && ft_isprint(av[1][i - 4]))
		return (1);
	return (0);
}
