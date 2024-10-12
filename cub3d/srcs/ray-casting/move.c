/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:50:16 by mchihab           #+#    #+#             */
/*   Updated: 2024/10/11 14:55:00 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_hit_wall(t_game *game, float new_x, float new_y)
{
	if (game->config.map[(int)new_y][(int)(new_x + PLAYER_OFFSET)] == '1'
		|| game->config.map[(int)new_y][(int)(new_x - PLAYER_OFFSET)] == '1'
		|| game->config.map[(int)(new_y + PLAYER_OFFSET)][(int)new_x] == '1'
		|| game->config.map[(int)(new_y - PLAYER_OFFSET)][(int)new_x] == '1')
		return (0);
	if (game->config.map[(int)(new_y + PLAYER_OFFSET)][(int)(new_x
			+ PLAYER_OFFSET)] == '1' || game->config.map[(int)(new_y
			- PLAYER_OFFSET)][(int)(new_x + PLAYER_OFFSET)] == '1'
		|| game->config.map[(int)(new_y + PLAYER_OFFSET)][(int)(new_x
			- PLAYER_OFFSET)] == '1' || game->config.map[(int)(new_y
			- PLAYER_OFFSET)][(int)(new_x - PLAYER_OFFSET)] == '1')
		return (0);
	return (1);
}

int	check_hit_door(t_game *game, float new_x, float new_y)
{
	if (game->config.map[(int)new_y][(int)(new_x + DOOR_OFFSET)] == 'D'
		|| game->config.map[(int)new_y][(int)(new_x - DOOR_OFFSET)] == 'D'
		|| game->config.map[(int)(new_y + DOOR_OFFSET)][(int)new_x] == 'D'
		|| game->config.map[(int)(new_y - DOOR_OFFSET)][(int)new_x] == 'D')
		return (0);
	if (game->config.map[(int)(new_y + DOOR_OFFSET)][(int)(new_x
			+ DOOR_OFFSET)] == 'D' || game->config.map[(int)(new_y
			- DOOR_OFFSET)][(int)(new_x + DOOR_OFFSET)] == 'D'
		|| game->config.map[(int)(new_y + DOOR_OFFSET)][(int)(new_x
			- DOOR_OFFSET)] == 'D' || game->config.map[(int)(new_y
			- DOOR_OFFSET)][(int)(new_x - DOOR_OFFSET)] == 'D')
		return (0);
	return (1);
}

int	check_collision(t_game *game, float new_x, float new_y)
{
	if ((int)new_x >= 0 && (int)new_x < game->config.map_wd && (int)new_y >= 0
		&& (int)new_y < game->config.map_hg)
	{
		if (game->config.map[(int)new_y][(int)new_x] == '1'
			|| game->config.map[(int)new_y][(int)new_x] == 'D')
			return (0);
		if (!check_hit_wall(game, new_x, new_y) || !check_hit_door(game, new_x,
				new_y))
			return (0);
		return (1);
	}
	return (0);
}

void	handle_movement(t_game *game)
{
	if (game->keys[XK_Escape])
		exit_w_success(game);
	if (game->keys[XK_w])
		move_forward(game);
	if (game->keys[XK_s])
		move_backward(game);
	if (game->keys[XK_d])
		move_left(game);
	if (game->keys[XK_a])
		move_right(game);
	if (game->keys[XK_Left])
		rotate_player(game, -game->player.rot_speed);
	if (game->keys[XK_Right])
		rotate_player(game, game->player.rot_speed);
}
