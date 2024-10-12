/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:50:54 by mchihab           #+#    #+#             */
/*   Updated: 2024/10/11 14:54:53 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_forward(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player.pos_x + game->player.dir_x * game->player.move_speed;
	new_y = game->player.pos_y + game->player.dir_y * game->player.move_speed;
	if (check_collision(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (check_collision(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

void	move_backward(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player.pos_x - game->player.dir_x * game->player.move_speed;
	new_y = game->player.pos_y - game->player.dir_y * game->player.move_speed;
	if (check_collision(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (check_collision(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

void	move_left(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player.pos_x - game->player.dir_y * game->player.move_speed;
	new_y = game->player.pos_y + game->player.dir_x * game->player.move_speed;
	if (check_collision(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (check_collision(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

void	move_right(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player.pos_x + game->player.dir_y * game->player.move_speed;
	new_y = game->player.pos_y - game->player.dir_x * game->player.move_speed;
	if (check_collision(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (check_collision(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

void	rotate_player(t_game *game, float angle)
{
	float	old_dir_x;
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos_angle - game->player.dir_y
		* sin_angle;
	game->player.dir_y = old_dir_x * sin_angle + game->player.dir_y * cos_angle;
}
