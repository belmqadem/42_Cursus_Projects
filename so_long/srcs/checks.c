/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:05:47 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/04/27 19:55:51 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_walls(char **map, int wd, int hg, char *map_read)
{
	int	i;

	i = 0;
	while (map[0][i] || map[hg - 1][i])
	{
		if (map[0][i] != '1' || map[hg - 1][i] != '1')
		{
			free_arr(map);
			free(map_read);
			print_error(RED ERR_BORDER RESET);
		}
		i++;
	}
	i = 1;
	while (i < hg - 1)
	{
		if (map[i][0] != '1' || map[i][wd - 1] != '1')
		{
			free_arr(map);
			free(map_read);
			print_error(RED ERR_BORDER RESET);
		}
		i++;
	}
}

void	check_elem_count(char **map, t_mlx_data *data, char *map_read)
{
	int	i;
	int	j;

	i = 0;
	while (++i < data->map.hg - 1)
	{
		j = 0;
		while (j < data->map.wd - 1)
		{
			if (map[i][j] == 'P')
				(data->elem.c_player)++;
			else if (map[i][j] == 'C')
				(data->elem.c_coll)++;
			else if (map[i][j] == 'E')
				(data->elem.c_exit)++;
			j++;
		}
	}
	if (data->elem.c_player != 1 || data->elem.c_exit != 1
		|| data->elem.c_coll < 1)
	{
		free_arr(map);
		free(map_read);
		print_error(RED ERR_CHARS RESET);
	}
}

void	check_valid_path(char **map_cp, char **map, char *map_r)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	get_position(map_cp, &x, &y);
	fill_path(map_cp, x, y);
	if (!is_path_valid(map_cp))
	{
		free_arr(map_cp);
		free_arr(map);
		free(map_r);
		print_error(RED ERR_PATH RESET);
	}
}

void	fill_path(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'e';
		return ;
	}
	map[y][x] = '1';
	fill_path(map, x, y + 1);
	fill_path(map, x, y - 1);
	fill_path(map, x + 1, y);
	fill_path(map, x - 1, y);
}

int	is_path_valid(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != 'e'
				&& map[y][x] != '0')
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
