/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:50:10 by mchihab           #+#    #+#             */
/*   Updated: 2024/10/11 14:51:39 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_rectangle(t_game *game, int x, int y, size_t color)
{
	int	i;
	int	j;
	int	width;
	int	height;

	if (color == 0xFF0000)
	{
		width = 8;
		height = 8;
	}
	else
	{
		width = MINI_MAP_SCALE;
		height = MINI_MAP_SCALE;
	}
	i = -1;
	while (++i < width)
	{
		j = -1;
		while (++j < height)
			put_pixel(&game->mlx, x + i, y + j, color);
	}
}

void	init_mini_map(t_mini_map *mini_map)
{
	mini_map->start_x = 50;
	mini_map->start_y = 50;
	mini_map->mini_map_width = 10;
	mini_map->mini_map_height = 10;
}

void	check_and_draw_tile(t_game *game, t_mini_map *m_map)
{
	if (game->config.map[m_map->tile_y][m_map->tile_x] == '1')
		m_map->color = 0xFFFFFF;
	else if (game->config.map[m_map->tile_y][m_map->tile_x] == '0')
		m_map->color = 0x888888;
	else if (game->config.map[m_map->tile_y][m_map->tile_x] == 'D')
		m_map->color = 0x8B4513;
	else if (game->config.map[m_map->tile_y][m_map->tile_x] == 'O')
		m_map->color = 0xFDF5EF;
	else
		m_map->color = 0x888888;
	draw_rectangle(game, m_map->start_x + (m_map->map_x + m_map->mini_map_width
			/ 2) * MINI_MAP_SCALE, m_map->start_y + (m_map->map_y
			+ m_map->mini_map_height / 2) * MINI_MAP_SCALE, m_map->color);
}

void	set_mini_map(t_game *game, t_mini_map m_map)
{
	while (m_map.map_y <= m_map.mini_map_height / 2)
	{
		m_map.map_x = -m_map.mini_map_width / 2;
		while (m_map.map_x <= m_map.mini_map_width / 2)
		{
			m_map.tile_x = (int)(game->player.pos_x + m_map.map_x);
			m_map.tile_y = (int)(game->player.pos_y + m_map.map_y);
			if (m_map.tile_x >= 0 && m_map.tile_x < game->config.map_wd
				&& m_map.tile_y >= 0 && m_map.tile_y < game->config.map_hg)
				check_and_draw_tile(game, &m_map);
			m_map.map_x++;
		}
		m_map.map_y++;
	}
}

void	draw_mini_map(t_game *game)
{
	t_mini_map		m_map;
	t_mini_helper	helper;

	init_mini_map(&m_map);
	m_map.map_y = -m_map.mini_map_height / 2;
	set_mini_map(game, m_map);
	helper.player_rect_x = m_map.start_x + (m_map.mini_map_width / 2)
		* MINI_MAP_SCALE;
	helper.player_rect_y = m_map.start_y + (m_map.mini_map_height / 2)
		* MINI_MAP_SCALE;
	draw_rectangle(game, helper.player_rect_x, helper.player_rect_y, 0xFF0000);
	helper.ray_end_x = helper.player_rect_x + (int)(game->player.dir_x
			* MINI_MAP_SCALE * 2);
	helper.ray_end_y = helper.player_rect_y + (int)(game->player.dir_y
			* MINI_MAP_SCALE * 2);
	draw_line(game, &helper);
}
