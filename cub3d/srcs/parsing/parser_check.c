/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:32:25 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/09/30 13:32:26 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_missing(t_game *game, t_config *config)
{
	if (config->north_tex == NULL)
		exit_w_error(game, ERR_MISS_N);
	if (config->south_tex == NULL)
		exit_w_error(game, ERR_MISS_S);
	if (config->east_tex == NULL)
		exit_w_error(game, ERR_MISS_E);
	if (config->west_tex == NULL)
		exit_w_error(game, ERR_MISS_W);
	if (config->floor == NULL)
		exit_w_error(game, ERR_MISS_F);
	if (config->ceiling == NULL)
		exit_w_error(game, ERR_MISS_C);
}

static void	check_valid_file(t_game *game, char *file)
{
	int	fd;
	int	i;

	i = ft_strlen(file) - 1;
	if (file[i] != 'm' || file[i - 1] != 'p' || file[i - 2] != 'x' || file[i
			- 3] != '.')
		exit_w_error(game, ERR_XPM);
	fd = open_file(game, file);
	close(fd);
}

static bool	check_valid_rgb(int *rgb)
{
	int	i;

	i = 0;
	while (i <= 2)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (false);
		i++;
	}
	return (true);
}

static size_t	rgb_to_hex(int *rgb)
{
	size_t	hex;

	hex = ((rgb[0] & 0xFF) << 16) | ((rgb[1] & 0xFF) << 8) | (rgb[2] & 0xFF);
	return (hex);
}

void	check_infos(t_game *game, t_config *config)
{
	check_missing(game, config);
	check_valid_file(game, config->north_tex);
	check_valid_file(game, config->south_tex);
	check_valid_file(game, config->east_tex);
	check_valid_file(game, config->west_tex);
	if (check_valid_rgb(config->floor) == false)
		exit_w_error(game, ERR_FLOOR);
	if (check_valid_rgb(config->ceiling) == false)
		exit_w_error(game, ERR_CEIL);
	config->floor_hex = rgb_to_hex(config->floor);
	config->ceiling_hex = rgb_to_hex(config->ceiling);
}
