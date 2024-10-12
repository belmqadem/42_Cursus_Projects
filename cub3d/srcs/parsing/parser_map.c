/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:32:41 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/09/30 13:32:42 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	count_map_hg(t_game *game, char **data, int i)
{
	int	index;
	int	j;

	index = i;
	while (data[i])
	{
		j = 0;
		while (ft_isspace(data[i][j]))
			j++;
		if (data[i][j] != '1' && data[i][j] != '0' && data[i][j] != ' ')
			break ;
		i++;
	}
	game->config.eom = i;
	return (i - index);
}

static size_t	count_map_wd(t_config *config, int i)
{
	size_t	major_len;

	major_len = ft_strlen(config->all_data[i]);
	while (config->all_data[i])
	{
		if (ft_strlen(config->all_data[i]) > major_len)
			major_len = ft_strlen(config->all_data[i]);
		i++;
	}
	return (major_len);
}

static void	extract_map_array(t_game *game, char **map, int ind)
{
	int	i;
	int	j;

	game->config.map_wd = count_map_wd(&game->config, ind);
	i = 0;
	while (i < game->config.map_hg)
	{
		map[i] = ft_calloc((game->config.map_wd + 1), sizeof(char));
		if (!map[i])
			exit_w_error(game, ERR_MALLOC);
		j = 0;
		while (game->config.all_data[ind][j]
			&& game->config.all_data[ind][j] != '\n')
		{
			map[i][j] = game->config.all_data[ind][j];
			j++;
		}
		i++;
		ind++;
	}
}

static void	replace_spaces_w_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (ft_isspace(map[i][j]))
			j++;
		while (map[i][++j])
		{
			if (map[i][j] == ' ' && j != map[i][ft_strlen(map[i]) - 1])
				map[i][j] = '1';
		}
		i++;
	}
}

void	parse_map(t_game *game, char **data, int i)
{
	game->config.map_hg = count_map_hg(game, data, i);
	game->config.map = ft_calloc((game->config.map_hg + 1), sizeof(char *));
	if (!game->config.map)
		exit_w_error(game, ERR_MALLOC);
	track_malloc_array(game->manager, game->config.map);
	extract_map_array(game, game->config.map, i);
	replace_spaces_w_wall(game->config.map);
}
