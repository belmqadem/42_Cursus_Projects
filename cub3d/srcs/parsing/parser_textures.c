/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:32:44 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/09/30 13:32:45 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	*extract_texture(t_game *game, char *line, int j)
{
	char	*path;
	int		len;
	int		i;

	while (line[j] && ft_isspace(line[j]))
		j++;
	len = j;
	while (line[len] && line[len] != '\n')
		len++;
	if (len == j)
		exit_w_error(game, ERR_TEX);
	path = ft_calloc((len - j + 1), sizeof(char));
	if (!path)
		exit_w_error(game, ERR_MALLOC);
	track_malloc_single(game->manager, path);
	i = 0;
	while (j < len)
		path[i++] = line[j++];
	i--;
	while (i >= 0 && ft_isspace(path[i]))
		path[i--] = '\0';
	return (path);
}

void	parse_textures(t_game *game, char *line, int j)
{
	if (line[j + 2] && is_print(line[j + 2]))
		exit_w_error(game, ERR_TEX);
	if (line[j] == 'N' && line[j + 1] == 'O' && !(game->config.north_tex))
		game->config.north_tex = extract_texture(game, line, j + 2);
	else if (line[j] == 'S' && line[j + 1] == 'O' && !(game->config.south_tex))
		game->config.south_tex = extract_texture(game, line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E' && !(game->config.west_tex))
		game->config.west_tex = extract_texture(game, line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A' && !(game->config.east_tex))
		game->config.east_tex = extract_texture(game, line, j + 2);
	else
		exit_w_error(game, ERR_TEX);
}
