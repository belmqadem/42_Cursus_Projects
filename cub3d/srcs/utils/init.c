/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:33:01 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/10/12 14:03:51 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_textures(t_game *game, t_config *config)
{
	config->textures = ft_calloc(5, sizeof(t_texture));
	if (!config->textures)
		exit_w_error(game, ERR_MALLOC);
	config->textures[0].img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			config->north_tex, &config->textures[0].width,
			&config->textures[0].height);
	config->textures[0].img_add = (int *)mlx_get_data_addr(
			config->textures[0].img_ptr, &config->textures[0].bpp,
			&config->textures[0].line_size, &config->textures[0].endian);
	config->textures[1].img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			config->south_tex, &config->textures[1].width,
			&config->textures[1].height);
	config->textures[1].img_add = (int *)mlx_get_data_addr(
			config->textures[1].img_ptr, &config->textures[1].bpp,
			&config->textures[1].line_size, &config->textures[1].endian);
	config->textures[2].img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			config->west_tex, &config->textures[2].width,
			&config->textures[2].height);
	config->textures[2].img_add = (int *)mlx_get_data_addr(
			config->textures[2].img_ptr, &config->textures[2].bpp,
			&config->textures[2].line_size, &config->textures[2].endian);
	complete_init(game, config);
}

void	init_config(t_config *config)
{
	config->north_tex = NULL;
	config->south_tex = NULL;
	config->west_tex = NULL;
	config->east_tex = NULL;
	config->floor = NULL;
	config->ceiling = NULL;
	config->floor_hex = 0x0;
	config->ceiling_hex = 0x0;
	config->map = NULL;
	config->all_data = NULL;
	config->map_wd = 0;
	config->map_hg = 0;
	config->eom = 0;
	config->fd = -1;
	config->lines = 0;
	config->textures = NULL;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->img_ptr = NULL;
	mlx->img_data = NULL;
	mlx->img_width = WIN_WD;
	mlx->img_height = WIN_HG;
	mlx->bpp = 0;
	mlx->line_size = 0;
	mlx->endian = 0;
}

void	init_player(t_player *player)
{
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->move_speed = 0.019;
	player->rot_speed = 0.01;
	player->direction = '\0';
}

void	init_before_parse(t_game *game)
{
	int	i;

	game->manager = init_mem_manager();
	if (!game->manager)
		exit_w_error(NULL, ERR_MALLOC);
	init_config(&game->config);
	init_mlx(&game->mlx);
	init_player(&game->player);
	game->bonus = false;
	i = -1;
	while (++i < MAX_KEYCODES)
		game->keys[i] = false;
	game->mouse_locked = true;
	game->bonus_textures = NULL;
	game->animation_active = false;
	game->animation_playing = false;
	game->animation_frame = 0;
	game->total_frames = BONUS_TEX;
}
