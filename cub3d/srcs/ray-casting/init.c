/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:50:08 by mchihab           #+#    #+#             */
/*   Updated: 2024/10/09 17:50:09 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_player_direction(t_player *player)
{
	if (player->direction == 'N')
	{
		player->dir_x = 0.0;
		player->dir_y = -1.0;
	}
	else if (player->direction == 'S')
	{
		player->dir_x = 0.0;
		player->dir_y = 1.0;
	}
	else if (player->direction == 'W')
	{
		player->dir_x = -1.0;
		player->dir_y = 0.0;
	}
	else if (player->direction == 'E')
	{
		player->dir_x = 1.0;
		player->dir_y = 0.0;
	}
}

void	init_game(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
		exit_w_error(game, ERR_MLX_INIT);
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr, game->mlx.img_width,
			game->mlx.img_height, "cub3D");
	if (!game->mlx.win_ptr)
		exit_w_error(game, ERR_MLX_WINDOW);
	game->mlx.img_ptr = mlx_new_image(game->mlx.mlx_ptr, game->mlx.img_width,
			game->mlx.img_height);
	if (!game->mlx.img_ptr)
		exit_w_error(game, ERR_MLX_IMAGE);
	game->mlx.img_data = mlx_get_data_addr(game->mlx.img_ptr, &game->mlx.bpp,
			&game->mlx.line_size, &game->mlx.endian);
	if (!game->mlx.img_data)
		exit_w_error(game, ERR_MLX_IMAGE);
	init_textures(game, &game->config);
	if (game->bonus)
		init_bonus_textures(game);
	print_game_controls(game);
	init_player_direction(&game->player);
}

void	init_dda(t_game *game, t_dda *dda, float ray_dir_x, float ray_dir_y)
{
	dda->map_x = (int)(game->player.pos_x);
	dda->map_y = (int)(game->player.pos_y);
	dda->delta_dist_x = fabs(1 / ray_dir_x);
	dda->delta_dist_y = fabs(1 / ray_dir_y);
	dda->hit = 0;
}

void	init_paths(char *texture_path[BONUS_TEX])
{
	texture_path[0] = "./textures/bonus/f-one.xpm";
	texture_path[1] = "./textures/bonus/f-two.xpm";
	texture_path[2] = "./textures/bonus/f-three.xpm";
	texture_path[3] = "./textures/bonus/f-four.xpm";
	texture_path[4] = "./textures/bonus/f-five.xpm";
	texture_path[5] = "./textures/bonus/f-six.xpm";
}

void	init_bonus_textures(t_game *game)
{
	int		i;
	char	*texture_paths[BONUS_TEX];

	init_paths(texture_paths);
	game->bonus_textures = malloc(sizeof(t_texture) * BONUS_TEX);
	if (!game->bonus_textures)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < BONUS_TEX)
	{
		game->bonus_textures[i].img_ptr = mlx_xpm_file_to_image(
				game->mlx.mlx_ptr,
				texture_paths[i], &game->bonus_textures[i].width,
				&game->bonus_textures[i].height);
		if (!game->bonus_textures[i].img_ptr)
			exit_w_error(game, ERR_MLX_IMAGE);
		game->bonus_textures[i].img_add = (int *)mlx_get_data_addr(
				game->bonus_textures[i].img_ptr,
				&game->bonus_textures[i].bpp,
				&game->bonus_textures[i].line_size,
				&game->bonus_textures[i].endian);
		if (!game->bonus_textures[i].img_add)
			exit_w_error(game, ERR_MLX_IMAGE);
		i++;
	}
}
