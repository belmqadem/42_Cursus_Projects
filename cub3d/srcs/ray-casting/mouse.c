/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:50:13 by mchihab           #+#    #+#             */
/*   Updated: 2024/10/09 17:50:14 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	mouse_click(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		game->mouse_locked = !game->mouse_locked;
		if (game->mouse_locked)
			mlx_mouse_move(game->mlx.mlx_ptr, game->mlx.win_ptr,
				game->mlx.img_width / 2, game->mlx.img_height / 2);
		else
			mlx_mouse_show(game->mlx.mlx_ptr, game->mlx.win_ptr);
	}
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{
	int	center_x;
	int	delta_x;

	(void)y;
	if (!game->mouse_locked)
		return (0);
	center_x = game->mlx.img_width / 2;
	delta_x = x - center_x;
	rotate_player(game, delta_x * game->player.rot_speed);
	mlx_mouse_move(game->mlx.mlx_ptr, game->mlx.win_ptr, center_x,
		game->mlx.img_height / 2);
	return (0);
}
