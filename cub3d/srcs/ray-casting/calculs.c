/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:50:01 by mchihab           #+#    #+#             */
/*   Updated: 2024/10/09 17:50:03 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	calculate_side_distances(t_game *game, t_dda *dda, float ray_dir_x,
		float ray_dir_y)
{
	if (ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (game->player.pos_x - dda->map_x)
			* dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - game->player.pos_x)
			* dda->delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (game->player.pos_y - dda->map_y)
			* dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - game->player.pos_y)
			* dda->delta_dist_y;
	}
}

void	calculate_perpendicular_wall_distance(t_game *game, t_dda *dda,
		float ray_dir_x, float ray_dir_y)
{
	float	ray_angle;
	float	player_angle;

	if (dda->side == 0)
		dda->perp_wall_dist = (dda->map_x - game->player.pos_x + (1
					- dda->step_x) / 2) / ray_dir_x;
	else
		dda->perp_wall_dist = (dda->map_y - game->player.pos_y + (1
					- dda->step_y) / 2) / ray_dir_y;
	ray_angle = atan2(ray_dir_y, ray_dir_x);
	player_angle = atan2(game->player.dir_y, game->player.dir_x);
	dda->perp_wall_dist = dda->perp_wall_dist * cos(player_angle - ray_angle);
}

int	calculate_tex_x(t_game *game, t_dda *dda, t_texture *texture, float wall_x)
{
	int	tex_x;

	tex_x = (int)(wall_x * (float)texture->width);
	if (dda->side == 0 && game->ray.ray_dir_x > 0)
		tex_x = texture->width - tex_x - 1;
	if (dda->side == 1 && game->ray.ray_dir_y < 0)
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

float	calculate_wall_x(t_game *game, t_dda *dda)
{
	float	wall_x;

	if (dda->side == 0)
		wall_x = game->player.pos_y + dda->perp_wall_dist * game->ray.ray_dir_y;
	else
		wall_x = game->player.pos_x + dda->perp_wall_dist * game->ray.ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

void	calculate_draw_range(t_game *game, t_dda *dda)
{
	dda->line_height = (int)(game->mlx.img_height / dda->perp_wall_dist);
	dda->draw_start = -dda->line_height / 2 + game->mlx.img_height / 2;
	if (dda->draw_start < 0)
		dda->draw_start = 0;
	dda->draw_end = dda->line_height / 2 + game->mlx.img_height / 2;
	if (dda->draw_end >= game->mlx.img_height)
		dda->draw_end = game->mlx.img_height - 1;
}
