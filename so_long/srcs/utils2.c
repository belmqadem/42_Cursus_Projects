/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:52:17 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/04/27 14:04:07 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_count(t_count *elem)
{
	elem->c_coll = 0;
	elem->c_exit = 0;
	elem->c_player = 0;
}

int	calc_width(char *str)
{
	int	width;

	width = 0;
	while (str[width] && str[width] != '\n')
		width++;
	return (width);
}

char	**ft_strdup_double(char **str, int hg)
{
	char	**cpy;
	int		i;

	cpy = (char **)malloc((hg + 1) * sizeof(char *));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < hg)
	{
		cpy[i] = ft_strdup(str[i]);
		if (!cpy[i])
		{
			while (--i > 0)
				free(cpy[i]);
			free(cpy);
			return (NULL);
		}
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

void	get_position(char **map, int *x, int *y)
{
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}
