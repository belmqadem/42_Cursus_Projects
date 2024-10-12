/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:32:34 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/09/30 13:32:35 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("\n");
}

void	print_infos(t_game *game)
{
	printf(BOLD UNDERLINE "Game Configuration Info\n\n" RESET);
	printf(BOLD "Textures:\n" RESET);
	printf(GREEN "NORTH texture:\t" RESET "%s\n", game->config.north_tex);
	printf(GREEN "EAST texture:\t" RESET "%s\n", game->config.east_tex);
	printf(GREEN "SOUTH texture:\t" RESET "%s\n", game->config.south_tex);
	printf(GREEN "WEST texture:\t" RESET "%s\n\n", game->config.west_tex);
	printf(BOLD "Colors:\n" RESET);
	printf(GREEN "FLOOR color:\t" RESET "%d,%d,%d\t", game->config.floor[0],
		game->config.floor[1], game->config.floor[2]);
	printf(GREEN "HEXA VALUE:\t" RESET "%zX\n", game->config.floor_hex);
	printf(GREEN "CEILING color:\t" RESET "%d,%d,%d\t", game->config.ceiling[0],
		game->config.ceiling[1], game->config.ceiling[2]);
	printf(GREEN "HEXA VALUE:\t" RESET "%zX\n\n", game->config.ceiling_hex);
	printf(BOLD "MAP Content:\n" RESET);
	print_map(game->config.map);
	printf(BOLD "Player Infos:\n" RESET);
	printf(GREEN "Player X position:\t" RESET "%.2f\n", game->player.pos_x);
	printf(GREEN "Player Y position:\t" RESET "%.2f\n", game->player.pos_y);
	printf(GREEN "Player direction:\t" RESET "%c\n", game->player.direction);
	printf(BOLD UNDERLINE "\nEnd of Configuration Info\n" RESET);
}
