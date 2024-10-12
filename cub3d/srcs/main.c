/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:17:53 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/10/08 10:44:34 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (!check_valid_arg(ac, av))
		exit_w_error(NULL, INVALID_EXTS);
	init_before_parse(&game);
	if (!ft_strncmp(av[0], "./cub3D_bonus", 13))
		game.bonus = true;
	parsing(&game, av[1]);
	init_game(&game);
	mlx_hook(game.mlx.win_ptr, KeyPress, KeyPressMask, key_press, &game);
	mlx_hook(game.mlx.win_ptr, KeyRelease, KeyReleaseMask, key_release, &game);
	if (game.bonus)
	{
		mlx_mouse_move(game.mlx.mlx_ptr, game.mlx.win_ptr, game.mlx.img_width
			/ 2, game.mlx.img_height / 2);
		mlx_hook(game.mlx.win_ptr, ButtonPress, ButtonPressMask, mouse_click,
			&game);
		mlx_hook(game.mlx.win_ptr, MotionNotify, PointerMotionMask, mouse_move,
			&game);
	}
	mlx_loop_hook(game.mlx.mlx_ptr, (int (*)())render_game, &game);
	mlx_hook(game.mlx.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		&game);
	mlx_loop(game.mlx.mlx_ptr);
	exit_w_error(&game, ERR_MLX_LOOP);
}
