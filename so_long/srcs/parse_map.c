/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:54:16 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/04/27 15:13:57 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**parse_map(char *av, t_mlx_data *data)
{
	int		fd;
	char	**map;
	char	**map_copy;
	char	*map_read;

	fd = open_file(av);
	map_read = read_map(fd, data);
	if (!map_read)
		return (NULL);
	map = ft_split(map_read, '\n');
	if (!map)
		return (free(map_read), NULL);
	check_walls(map, data->map.wd, data->map.hg, map_read);
	check_elem_count(map, data, map_read);
	map_copy = ft_strdup_double(map, data->map.hg);
	if (!map_copy)
	{
		free_arr(map);
		return (free(map_read), NULL);
	}
	check_valid_path(map_copy, map, map_read);
	close(fd);
	free(map_read);
	free_arr(map_copy);
	return (map);
}

char	*read_map(int fd, t_mlx_data *data)
{
	char	*line;
	char	*map;
	char	*map_dup;

	line = get_line_dimension(fd, data);
	if (!line)
		return (NULL);
	map = ft_strdup(line);
	if (!map)
		return (free(line), NULL);
	while (1)
	{
		free (line);
		line = get_next_line(fd);
		if (NULL == line)
			break ;
		check_elements(map, line, data->map.wd);
		map_dup = ft_strjoin(map, line);
		free(map);
		if (!map_dup)
			return (free(line), NULL);
		map = map_dup;
		data->map.hg += 1;
	}
	return (free(line), map);
}

char	*get_line_dimension(int fd, t_mlx_data *data)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	data->map.wd = calc_width(line);
	data->map.hg = 1;
	return (line);
}

int	check_elements(char *map, char *line, int wd)
{
	int	i;

	i = 0;
	while (i < wd)
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
			&& line[i] != 'P' && line[i] != 'E')
		{
			free(map);
			free(line);
			print_error(RED ERR_CHARS RESET);
		}
		i++;
	}
	if (calc_width(line) != wd)
	{
		free(map);
		free(line);
		print_error(RED ERR_RECT RESET);
	}
	return (1);
}
