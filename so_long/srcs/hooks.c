/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:01:52 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/04/27 14:02:14 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	on_keypress(int keysym, t_mlx_data *data)
{
	if (keysym != ESC)
		handle_moves(keysym, data);
	if (keysym == ESC)
	{
		ft_printf(RED GAME_OVER RESET);
		exit_game(data, 1);
	}
	return (0);
}

int	on_destroy(t_mlx_data *data)
{
	ft_printf(RED GAME_OVER RESET);
	exit_game(data, 1);
	return (0);
}

void	handle_moves(int keysym, t_mlx_data *data)
{
	if (keysym == UP || keysym == KEY_W)
		step_up(data);
	else if (keysym == DOWN || keysym == KEY_S)
		step_down(data);
	else if (keysym == RIGHT || keysym == KEY_D)
		step_right(data);
	else if (keysym == LEFT || keysym == KEY_A)
		step_left(data);
}

void	exit_game(t_mlx_data *data, int code)
{
	mlx_destroy_window(data->mlx_connection, data->mlx_window);
	free_arr(data->map.map);
	free(data->mlx_connection);
	exit(code);
}
