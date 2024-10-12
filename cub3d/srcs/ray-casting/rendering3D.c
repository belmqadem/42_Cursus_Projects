/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering3D.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:50:19 by mchihab           #+#    #+#             */
/*   Updated: 2024/10/09 17:50:20 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_plane(t_game *game)
{
	int	screen_column;

	game->ray.start_angle = atan2(game->player.dir_y, game->player.dir_x) - (FOV
			* M_PI / 180) / 2;
	game->ray.step_angle = (FOV * M_PI / 180) / game->mlx.img_width;
	screen_column = 0;
	while (screen_column < game->mlx.img_width)
	{
		game->ray.ray_dir_x = cos(game->ray.start_angle + screen_column
				* game->ray.step_angle);
		game->ray.ray_dir_y = sin(game->ray.start_angle + screen_column
				* game->ray.step_angle);
		perform_dda(game, game->ray.ray_dir_x, game->ray.ray_dir_y,
			screen_column);
		screen_column++;
	}
}

void	draw_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HG / 2)
	{
		x = 0;
		while (x < WIN_WD)
		{
			put_pixel(&game->mlx, x, y, game->config.ceiling_hex);
			x++;
		}
		y++;
	}
}

void	draw_floor(t_game *game)
{
	int	x;
	int	y;

	y = WIN_HG / 2;
	while (y < WIN_HG)
	{
		x = 0;
		while (x < WIN_WD)
		{
			put_pixel(&game->mlx, x, y, game->config.floor_hex);
			x++;
		}
		y++;
	}
}

void	render_map(t_game *game)
{
	draw_ceiling(game);
	draw_floor(game);
	draw_plane(game);
}

int	render_game(t_game *game)
{
	ft_memset(game->mlx.img_data, 0, game->mlx.img_width * game->mlx.img_height
		* (game->mlx.bpp / 8));
	handle_movement(game);
	render_map(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->mlx.img_ptr, 0, 0);
	if (game->bonus)
	{
		draw_mini_map(game);
		if (!game->animation_playing)
			game->animation_frame = 0;
		render_animation_frame(game);
		update_hand_animation(game);
	}
	return (0);
}
