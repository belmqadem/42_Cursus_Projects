/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_analyze.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:32:15 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/09/30 13:32:16 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_walls(t_game *game, char **map, int i, int j)
{
	if (game->config.map_hg <= 2)
		exit_w_error(game, ERR_SMALL);
	check_top_bottom(game, map, 0, 0);
	i = 1;
	while (i < game->config.map_hg - 1)
	{
		j = 0;
		while (ft_isspace(map[i][j]))
			j++;
		if (map[i][j] != '1')
			exit_w_error(game, ERR_WALL);
		j = ft_strlen(map[i]) - 1;
		if (map[i][j] != '1')
			exit_w_error(game, ERR_WALL);
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' && (ft_isspace(map[i - 1][j]) || map[i
					- 1][j] == '\0'))
				exit_w_error(game, ERR_WALL);
			j++;
		}
		i++;
	}
	check_top_bottom(game, map, i, 0);
}

static void	check_elements(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	game->player.direction = '0';
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			while (ft_isspace(map[i][j]))
				j++;
			if (!ft_strchr("NSEW10", map[i][j]))
				exit_w_error(game, INVALID_ELEM);
			if (ft_strchr("NSEW", map[i][j]) && game->player.direction != '0')
				exit_w_error(game, INVALID_NUM);
			if (ft_strchr("NSEW", map[i][j]) && game->player.direction == '0')
				game->player.direction = map[i][j];
			j++;
		}
		i++;
	}
	if (game->player.direction == '0')
		exit_w_error(game, ERR_PLAYER);
}

static void	check_player(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				game->player.pos_x = (double)j + 0.5;
				game->player.pos_y = (double)i + 0.5;
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (position_not_valid(game, map))
		exit_w_error(game, INVALID_POS);
}

static void	check_map_position(t_game *game)
{
	int	i;
	int	j;

	i = game->config.eom;
	while (game->config.all_data[i])
	{
		j = 0;
		while (game->config.all_data[i][j])
		{
			if (!ft_isspace(game->config.all_data[i][j]))
				exit_w_error(game, ERR_LAST);
			j++;
		}
		i++;
	}
}

void	analyze_map(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map || !(*map))
		exit_w_error(game, ERR_NOMAP);
	if (game->bonus)
	{
		check_walls_bonus(game, map, i, j);
		check_elements_bonus(game, map);
	}
	else
	{
		check_walls(game, map, i, j);
		check_elements(game, map);
	}
	check_player(game, map);
	check_map_position(game);
}
