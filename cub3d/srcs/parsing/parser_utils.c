/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:32:48 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/09/30 13:32:49 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_print(int c)
{
	if (c > 32 && c < 127)
		return (1);
	else
		return (0);
}

int	open_file(t_game *game, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd(RED "Error", 2);
		perror("fd");
		ft_putstr_fd(RESET, 2);
		exit_w_error(game, NULL);
	}
	return (fd);
}

int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

void	check_top_bottom(t_game *game, char **map, int i, int j)
{
	while (ft_isspace(map[i][j]))
		j++;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			exit_w_error(game, ERR_WALL);
		j++;
	}
}

int	position_not_valid(t_game *game, char **map)
{
	int	i;
	int	j;

	i = (int)game->player.pos_y;
	j = (int)game->player.pos_x;
	if (ft_strlen(map[i - 1]) < (size_t)j || ft_strlen(map[i + 1]) < (size_t)j
		|| ft_isspace(map[i][j - 1]) || ft_isspace(map[i][j + 1])
		|| ft_isspace(map[i - 1][j]) || ft_isspace(map[i + 1][j]))
		return (1);
	return (0);
}
