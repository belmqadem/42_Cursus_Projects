/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:32:57 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/10/01 12:17:03 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_textures(t_game *game)
{
	int	i;

	i = 0;
	if (game->bonus_textures)
	{
		while (i < BONUS_TEX)
		{
			if (game->bonus_textures[i].img_ptr)
			{
				mlx_destroy_image(game->mlx.mlx_ptr,
					game->bonus_textures[i].img_ptr);
				game->bonus_textures[i].img_ptr = NULL;
			}
			i++;
		}
		free(game->bonus_textures);
		game->bonus_textures = NULL;
	}
}

void	exit_w_error(t_game *game, char *err)
{
	if (game)
	{
		if (game->mlx.img_ptr)
			mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img_ptr);
		if (game->mlx.mlx_ptr && game->mlx.win_ptr)
			mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
		if (game->mlx.mlx_ptr)
		{
			mlx_destroy_display(game->mlx.mlx_ptr);
			mlx_loop_end(game->mlx.mlx_ptr);
			free(game->mlx.mlx_ptr);
			game->mlx.mlx_ptr = NULL;
		}
		if (game->config.fd > 0)
			close(game->config.fd);
		free_all(game->manager);
	}
	ft_putstr_fd(RED, 2);
	ft_putendl_fd(err, 2);
	ft_putstr_fd(RESET, 2);
	exit(EXIT_FAILURE);
}

void	exit_w_success(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 5)
		if (game->config.textures[i].img_ptr)
			mlx_destroy_image(game->mlx.mlx_ptr,
				game->config.textures[i].img_ptr);
	free(game->config.textures);
	game->config.textures = NULL;
	free_textures(game);
	mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img_ptr);
	game->mlx.img_ptr = NULL;
	mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	game->mlx.win_ptr = NULL;
	mlx_destroy_display(game->mlx.mlx_ptr);
	mlx_loop_end(game->mlx.mlx_ptr);
	free(game->mlx.mlx_ptr);
	game->mlx.mlx_ptr = NULL;
	if (game->config.fd > 0)
		close(game->config.fd);
	free_all(game->manager);
	exit(EXIT_SUCCESS);
}
