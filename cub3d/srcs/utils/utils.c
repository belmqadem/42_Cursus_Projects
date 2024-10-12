/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:33:08 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/10/08 10:45:48 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_game_controls(t_game *game)
{
	printf(BHBLUE "\n");
	printf("      _  _      ___ _   _      __\n");
	printf("     /  / \\ |\\ | | |_) / \\ |  (_ \n");
	printf("     \\_ \\_/ | \\| | | \\ \\_/ |_ __)\n\n");
	printf("W: Move Forward\t\tS: Move Backward\n");
	printf("A: Move Left\t\tD: Move Right\n");
	printf("<: Rotate Left\t\t>: Rotate Right\n");
	if (game->bonus)
		printf("E: Interact with Door\tF: Shoot\n");
	printf(RESET "\n");
}

int	on_destroy(t_game *game)
{
	exit_w_success(game);
	return (0);
}

void	complete_init(t_game *game, t_config *config)
{
	config->textures[3].img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			config->east_tex, &config->textures[3].width,
			&config->textures[3].height);
	config->textures[3].img_add = (int *)mlx_get_data_addr(
			config->textures[3].img_ptr, &config->textures[3].bpp,
			&config->textures[3].line_size, &config->textures[3].endian);
	if (!config->textures[0].img_ptr || !config->textures[1].img_ptr
		|| !config->textures[2].img_ptr || !config->textures[3].img_ptr)
		exit_w_error(game, ERR_MLX_IMAGE);
	if (game->bonus)
	{
		config->textures[4].img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
				"./textures/bonus/door.xpm", &config->textures[4].width,
				&config->textures[4].height);
		config->textures[4].img_add = (int *)mlx_get_data_addr(
				config->textures[4].img_ptr, &config->textures[4].bpp,
				&config->textures[4].line_size, &config->textures[4].endian);
		if (!config->textures[4].img_ptr)
			exit_w_error(game, ERR_MLX_IMAGE);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode < MAX_KEYCODES)
		game->keys[keycode] = true;
	if (game->bonus)
	{
		if (keycode == XK_e)
			interact_with_door(game);
		if (keycode == XK_f)
		{
			if (game->animation_playing)
				game->animation_playing = 0;
			else
			{
				game->animation_playing = 1;
				game->animation_frame = 0;
			}
		}
	}
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode < MAX_KEYCODES)
		game->keys[keycode] = false;
	return (0);
}
