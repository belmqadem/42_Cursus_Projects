/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:32:31 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/09/30 13:32:32 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	is_invalid_number(char *str)
{
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '\0')
		return (true);
	while (*str)
	{
		if (!ft_isdigit(*str) && !ft_isspace(*str))
			return (true);
		str++;
	}
	return (false);
}

static int	*set_color_rgb(t_game *game, char *line)
{
	int		*color_rgb;
	char	**char_rgb;
	int		i;

	if (count_char(line, ',') != 2)
		return (0);
	char_rgb = ft_split(line, ',');
	track_malloc_array(game->manager, char_rgb);
	color_rgb = ft_calloc(3, sizeof(int));
	if (!color_rgb)
		exit_w_error(game, ERR_MALLOC);
	track_malloc_single(game->manager, color_rgb);
	i = -1;
	while (char_rgb[++i])
	{
		if (is_invalid_number(char_rgb[i]))
			return (0);
		color_rgb[i] = ft_atoi(char_rgb[i]);
	}
	return (color_rgb);
}

void	parse_colors(t_game *game, char *line, int j)
{
	if (line[j + 1] && is_print(line[j + 1]))
		exit_w_error(game, ERR_COLOR);
	if (line[j] == 'F' && !(game->config.floor))
	{
		game->config.floor = set_color_rgb(game, line + j + 1);
		if (!game->config.floor)
			exit_w_error(game, ERR_FLOOR);
	}
	else if (line[j] == 'C' && !(game->config.ceiling))
	{
		game->config.ceiling = set_color_rgb(game, line + j + 1);
		if (!game->config.ceiling)
			exit_w_error(game, ERR_CEIL);
	}
	else
		exit_w_error(game, ERR_COLOR);
}
