/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:26:20 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/04/25 15:34:42 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	step_up(t_mlx_data *data)
{
	int	y;
	int	x;

	y = -1;
	x = 0;
	if (data->map.map[data->pos.y_p + y][data->pos.x_p + x] == '1')
		return ;
	if (data->map.map[data->pos.y_p + y][data->pos.x_p + x] == 'E')
		return ;
	if (data->elem.c_coll != 0)
	{
		data->map.map[data->pos.y_e][data->pos.x_e] = 'E';
		set_element(data, 'E', data->pos.x_e, data->pos.y_e);
	}
	if (data->map.map[data->pos.y_p][data->pos.x_p] != 'E')
	{
		data->map.map[data->pos.y_p][data->pos.x_p] = '0';
		set_element(data, '0', data->pos.x_p, data->pos.y_p);
	}
	set_player(data, x, y);
}

void	step_down(t_mlx_data *data)
{
	int	y;
	int	x;

	y = 1;
	x = 0;
	if (data->map.map[data->pos.y_p + y][data->pos.x_p + x] == '1')
		return ;
	if (data->map.map[data->pos.y_p + y][data->pos.x_p + x] == 'E')
		return ;
	if (data->elem.c_coll != 0)
	{
		data->map.map[data->pos.y_e][data->pos.x_e] = 'E';
		set_element(data, 'E', data->pos.x_e, data->pos.y_e);
	}
	if (data->map.map[data->pos.y_p][data->pos.x_p] != 'E')
	{
		data->map.map[data->pos.y_p][data->pos.x_p] = '0';
		set_element(data, '0', data->pos.x_p, data->pos.y_p);
	}
	set_player(data, x, y);
}

void	step_right(t_mlx_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 1;
	if (data->map.map[data->pos.y_p + y][data->pos.x_p + x] == '1')
		return ;
	if (data->map.map[data->pos.y_p + y][data->pos.x_p + x] == 'E')
		return ;
	if (data->elem.c_coll != 0)
	{
		data->map.map[data->pos.y_e][data->pos.x_e] = 'E';
		set_element(data, 'E', data->pos.x_e, data->pos.y_e);
	}
	if (data->map.map[data->pos.y_p][data->pos.x_p] != 'E')
	{
		data->map.map[data->pos.y_p][data->pos.x_p] = '0';
		set_element(data, '0', data->pos.x_p, data->pos.y_p);
	}
	set_player(data, x, y);
}

void	step_left(t_mlx_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = -1;
	if (data->map.map[data->pos.y_p + y][data->pos.x_p + x] == '1')
		return ;
	if (data->map.map[data->pos.y_p + y][data->pos.x_p + x] == 'E')
		return ;
	if (data->elem.c_coll != 0)
	{
		data->map.map[data->pos.y_e][data->pos.x_e] = 'E';
		set_element(data, 'E', data->pos.x_e, data->pos.y_e);
	}
	if (data->map.map[data->pos.y_p][data->pos.x_p] != 'E')
	{
		data->map.map[data->pos.y_p][data->pos.x_p] = '0';
		set_element(data, '0', data->pos.x_p, data->pos.y_p);
	}
	set_player(data, x, y);
}
