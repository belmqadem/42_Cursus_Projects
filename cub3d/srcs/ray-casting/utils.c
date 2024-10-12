/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:50:21 by mchihab           #+#    #+#             */
/*   Updated: 2024/10/09 18:20:10 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	toggle_door(t_game *game, int player_x, int player_y)
{
	if (game->config.map[player_y][player_x + 1] == 'D')
		game->config.map[player_y][player_x + 1] = 'O';
	else if (game->config.map[player_y][player_x + 1] == 'O')
		game->config.map[player_y][player_x + 1] = 'D';
	if (game->config.map[player_y][player_x - 1] == 'D')
		game->config.map[player_y][player_x - 1] = 'O';
	else if (game->config.map[player_y][player_x - 1] == 'O')
		game->config.map[player_y][player_x - 1] = 'D';
	if (game->config.map[player_y + 1][player_x] == 'D')
		game->config.map[player_y + 1][player_x] = 'O';
	else if (game->config.map[player_y + 1][player_x] == 'O')
		game->config.map[player_y + 1][player_x] = 'D';
	if (game->config.map[player_y - 1][player_x] == 'D')
		game->config.map[player_y - 1][player_x] = 'O';
	else if (game->config.map[player_y - 1][player_x] == 'O')
		game->config.map[player_y - 1][player_x] = 'D';
}

void	interact_with_door(t_game *game)
{
	int	player_x;
	int	player_y;

	player_x = (int)game->player.pos_x;
	player_y = (int)game->player.pos_y;
	toggle_door(game, player_x, player_y);
}

void	put_pixel(t_mlx *mlx, int x, int y, size_t color)
{
	int	pixel_index;

	if (x >= 0 && x < mlx->img_width && y >= 0 && y < mlx->img_height)
	{
		pixel_index = (y * mlx->line_size) + (x * (mlx->bpp / 8));
		*((unsigned int *)(mlx->img_data + pixel_index)) = color;
	}
}

t_texture	*valid_texture(t_game *game, t_dda *dda, int i)
{
	if (game->bonus)
		if (game->config.map[dda->map_y][dda->map_x] == 'D')
			return (&game->config.textures[4]);
	return (&game->config.textures[i]);
}
