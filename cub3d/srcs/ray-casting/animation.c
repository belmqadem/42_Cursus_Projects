/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:49:58 by mchihab           #+#    #+#             */
/*   Updated: 2024/10/09 17:50:00 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	render_animation_frame(t_game *game)
{
	int			color;
	t_texture	*texture;
	int			x;
	int			y;

	texture = &game->bonus_textures[game->animation_frame];
	y = 0;
	while (y < texture->height)
	{
		x = 0;
		while (x < texture->width)
		{
			if (y * texture->line_size / 4 + x >= (texture->height
					* texture->line_size / 4))
				return ;
			color = texture->img_add[y * (texture->line_size / 4) + x];
			if (color != (int)0xFF000000)
				put_pixel(&game->mlx, (WIN_WD / 2 + x) - 180, (WIN_HG / 2 + y)
					- 180, color);
			x++;
		}
		y++;
	}
}

void	update_hand_animation(t_game *game)
{
	static int	anim_timer = 0;

	if (game->animation_playing)
	{
		anim_timer++;
		if (anim_timer >= 10)
		{
			game->animation_frame++;
			anim_timer = 0;
			if (game->animation_frame >= game->total_frames)
			{
				game->animation_playing = 0;
				game->animation_frame = 0;
			}
		}
	}
}
