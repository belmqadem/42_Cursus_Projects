/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:50:04 by mchihab           #+#    #+#             */
/*   Updated: 2024/10/09 17:50:06 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	perform_dda_algorithm(t_game *game, t_dda *dda)
{
	char	tile;

	while (dda->hit == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		tile = game->config.map[dda->map_y][dda->map_x];
		if (tile == '1' || tile == 'D')
		{
			dda->hit = 1;
		}
	}
}

t_texture	*select_texture(t_game *game, t_dda *dda)
{
	if (dda->side == 0 && game->ray.ray_dir_x < 0)
		return (valid_texture(game, dda, 2));
	else if (dda->side == 0 && game->ray.ray_dir_x >= 0)
		return (valid_texture(game, dda, 3));
	else if (dda->side == 1 && game->ray.ray_dir_y < 0)
		return (valid_texture(game, dda, 0));
	else
		return (valid_texture(game, dda, 1));
}

void	draw_wall_slice(t_game *game, t_texture *texture, t_dda *dda,
		int screen_column)
{
	int	y;
	int	tex_y;
	int	d;

	y = dda->draw_start;
	while (y < dda->draw_end)
	{
		d = (y * 256 - game->mlx.img_height * 128 + dda->line_height * 128);
		tex_y = ((d * texture->height) / dda->line_height) / 256;
		if (tex_y < 0)
			tex_y = 0;
		else if (tex_y >= texture->height)
			tex_y = texture->height - 1;
		dda->color = texture->img_add[tex_y * texture->width + dda->tex_x];
		put_pixel(&game->mlx, screen_column, y, dda->color);
		y++;
	}
}

void	draw_wall(t_game *game, t_dda *dda, int screen_column)
{
	t_texture	*texture;
	float		wall_x;

	texture = select_texture(game, dda);
	wall_x = calculate_wall_x(game, dda);
	dda->tex_x = calculate_tex_x(game, dda, texture, wall_x);
	calculate_draw_range(game, dda);
	draw_wall_slice(game, texture, dda, screen_column);
}

void	perform_dda(t_game *game, float ray_dir_x, float ray_dir_y,
		int screen_column)
{
	t_dda	*dda;

	dda = &game->dda;
	init_dda(game, dda, ray_dir_x, ray_dir_y);
	calculate_side_distances(game, dda, ray_dir_x, ray_dir_y);
	perform_dda_algorithm(game, dda);
	calculate_perpendicular_wall_distance(game, dda, ray_dir_x, ray_dir_y);
	draw_wall(game, dda, screen_column);
}
