/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:32:17 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/09/30 13:32:18 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_walls_bonus(t_game *game, char **map, int i, int j)
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
			if ((map[i][j] == '0' || map[i][j] == 'D') && (ft_isspace(map[i
						- 1][j]) || map[i - 1][j] == '\0'))
				exit_w_error(game, ERR_WALL);
			j++;
		}
		i++;
	}
	check_top_bottom(game, map, i, 0);
}

void	check_valid_door(t_game *game, char **map, int i, int j)
{
	if (map[i][j - 1] == '1' && map[i][j + 1] == '1')
		return ;
	if (map[i - 1][j] == '1' && map[i + 1][j] == '1')
		return ;
	exit_w_error(game, INVALID_D_POS);
}

void	check_elements_bonus(t_game *game, char **map)
{
	int	i;
	int	j;

	i = -1;
	game->player.direction = '0';
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			while (ft_isspace(map[i][j]))
				j++;
			if (!ft_strchr("DNSEW10", map[i][j]))
				exit_w_error(game, INVALID_ELEM);
			if (ft_strchr("NSEW", map[i][j]) && game->player.direction != '0')
				exit_w_error(game, INVALID_NUM);
			if (ft_strchr("NSEW", map[i][j]) && game->player.direction == '0')
				game->player.direction = map[i][j];
			if (map[i][j] == 'D')
				check_valid_door(game, map, i, j);
			j++;
		}
	}
	if (game->player.direction == '0')
		exit_w_error(game, ERR_PLAYER);
}
