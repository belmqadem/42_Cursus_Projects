/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:54:22 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/04/30 23:28:26 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	import_images(t_mlx_data *data)
{
	data->img.floor = mlx_xpm_file_to_image(data->mlx_connection,
			"./textures/floor.xpm", &data->img.img_w, &data->img.img_h);
	data->img.obj = mlx_xpm_file_to_image(data->mlx_connection,
			"./textures/collectible.xpm", &data->img.img_w, &data->img.img_h);
	data->img.exit_1 = mlx_xpm_file_to_image(data->mlx_connection,
			"./textures/exit_1.xpm", &data->img.img_w, &data->img.img_h);
	data->img.exit_0 = mlx_xpm_file_to_image(data->mlx_connection,
			"./textures/exit_0.xpm", &data->img.img_w, &data->img.img_h);
	data->img.wall = mlx_xpm_file_to_image(data->mlx_connection,
			"./textures/wall.xpm", &data->img.img_w, &data->img.img_h);
	data->img.player = mlx_xpm_file_to_image(data->mlx_connection,
			"./textures/player.xpm", &data->img.img_w, &data->img.img_h);
	if (!data->img.floor || !data->img.obj || !data->img.exit_1
		|| !data->img.exit_0 || !data->img.wall || !data->img.player)
	{
		free_arr(data->map.map);
		print_error(RED "**OOH OOH! Failed to Load images**" RESET);
	}
}

void	render_textures(t_mlx_data *data)
{
	int	col;
	int	row;

	row = 0;
	set_floor(data);
	while ((data->map.map)[row])
	{
		col = 0;
		while ((data->map.map)[row][col])
		{
			set_element(data, (data->map.map)[row][col], col, row);
			col++;
		}
		row++;
	}
}

void	set_floor(t_mlx_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.hg + 1)
	{
		x = 0;
		while (x < data->map.wd)
		{
			mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
				data->img.floor, x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
}

void	set_element(t_mlx_data *data, char elem, int x, int y)
{
	if (elem == '0')
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
			data->img.floor, x * SIZE, y * SIZE);
	else if (elem == '1')
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
			data->img.wall, x * SIZE, y * SIZE);
	else if (elem == 'C')
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
			data->img.obj, x * SIZE, y * SIZE);
	else if (elem == 'P')
	{
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
			data->img.player, x * SIZE, y * SIZE);
		data->pos.x_p = x;
		data->pos.y_p = y;
	}
	else if (elem == 'E')
	{
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
			data->img.exit_0, x * SIZE, y * SIZE);
		data->pos.x_e = x;
		data->pos.y_e = y;
	}
}
