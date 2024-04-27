/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:32:18 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/04/27 14:15:02 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_player(t_mlx_data *data, int x, int y)
{
	play_game(data, x, y);
	data->pos.x_p += x;
	data->pos.y_p += y;
	data->map.map[data->pos.y_p][data->pos.x_p] = 'P';
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
		data->img.player, data->pos.x_p * SIZE, data->pos.y_p * SIZE);
	(data->moves)++;
	if (data->moves == 1)
		write (1, "\n", 1);
	ft_printf(">> " MAGENTA "Move n°: " RESET "%d\n", data->moves);
}

void	play_game(t_mlx_data *data, int x, int y)
{
	if (data->map.map[data->pos.y_p + y][data->pos.x_p + x] == 'C')
	{
		data->elem.c_coll -= 1;
		if (data->elem.c_coll == 1)
			ft_printf(">> " CYAN "One card added to book\n" RESET
				">> " CYAN "Still one more\n" RESET);
		else if (data->elem.c_coll == 0)
			ft_printf(">> " CYAN "Last card added to book\n" RESET
				">> " CYAN "Ready to go\n" RESET);
		else
			ft_printf(">> " CYAN "One card added to book\n" RESET
				">> " CYAN "Still '%d' cards\n" RESET, data->elem.c_coll);
	}
	if (data->elem.c_coll == 0)
	{
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
			data->img.exit_1, data->pos.x_e * SIZE, data->pos.y_e * SIZE);
		data->map.map[data->pos.y_e][data->pos.x_e] = 'e';
	}
	if (data->map.map[data->pos.y_p + y][data->pos.x_p + x] == 'e')
	{
		data->elem.c_exit -= 1;
		ft_printf(GREEN WIN_MSG RESET, data->moves);
		exit_game(data, 0);
	}
}
