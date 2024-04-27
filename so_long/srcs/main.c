/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:40:37 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/04/27 15:15:07 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_mlx_data	data;

	if (ac != 2 || !file_is_valid(av[1]))
		print_error(RED "Error: You must add a valid file" RESET);
	set_count(&data.elem);
	data.moves = 0;
	data.map.map = parse_map(av[1], &data);
	if (NULL == data.map.map)
		return (1);
	data.mlx_connection = mlx_init();
	data.mlx_window = mlx_new_window(data.mlx_connection,
			data.map.wd * SIZE, data.map.hg * SIZE, "GREED ISLAND");
	if (!data.mlx_connection || !data.mlx_window)
		return (free(data.mlx_connection), 1);
	import_images(&data);
	render_textures(&data);
	mlx_key_hook(data.mlx_window, &on_keypress, &data);
	mlx_hook(data.mlx_window, 17, 1L << 17, &on_destroy, &data);
	mlx_loop(data.mlx_connection);
	print_error(RED "Loop Failed" RESET);
	return (0);
}
