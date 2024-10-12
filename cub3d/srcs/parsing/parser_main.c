/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:32:38 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/09/30 13:32:39 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	extract_lines(t_game *game, char *file)
{
	char	*line;
	int		x;

	x = 0;
	game->config.fd = open_file(game, file);
	while (1)
	{
		line = get_next_line(game->config.fd);
		if (!line)
			break ;
		game->config.all_data[x] = ft_strdup(line);
		if (!game->config.all_data[x])
			exit_w_error(game, ERR_MALLOC);
		x++;
		free(line);
	}
	close(game->config.fd);
}

static int	parse_data(t_game *game, char **data, int i, int j)
{
	while (ft_isspace(data[i][j]) || data[i][j] == '\n')
		j++;
	if (is_print(data[i][j]) && !ft_isdigit(data[i][j]))
	{
		if (data[i][j + 1] && is_print(data[i][j + 1])
			&& !ft_isdigit(data[i][j]))
		{
			parse_textures(game, data[i], j);
			return (0);
		}
		else
		{
			parse_colors(game, data[i], j);
			return (0);
		}
	}
	else if (ft_isdigit(data[i][j]))
	{
		parse_map(game, data, i);
		return (1);
	}
	return (2);
}

static void	extract_data(t_game *game, char **data)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (data[i])
	{
		j = 0;
		while (data[i][j])
		{
			ret = parse_data(game, data, i, j);
			if (ret == 0)
				break ;
			else if (ret == 1)
				return ;
			j++;
		}
		i++;
	}
}

void	parsing(t_game *game, char *file)
{
	game->config.fd = open_file(game, file);
	game->config.lines = count_lines(game->config.fd);
	game->config.all_data = ft_calloc((game->config.lines + 1), sizeof(char *));
	if (!game->config.all_data)
		exit_w_error(game, ERR_MALLOC);
	track_malloc_array(game->manager, game->config.all_data);
	extract_lines(game, file);
	extract_data(game, game->config.all_data);
	analyze_map(game, game->config.map);
	check_infos(game, &game->config);
}
