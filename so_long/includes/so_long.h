/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:06:53 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/04/28 02:20:16 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// **** Header files **** //
# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>

// **** Colors **** //
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[0m"

// **** Messages **** //
# define ERR_BORDER "** ERROR **\n** The map must be surrounded by walls **"
# define ERR_RECT "** ERROR **\n** The map must be rectangular **"
# define ERR_CHARS "** ERROR **\n** The map must contain 1 E, at least 1 C \
and 1 P **"
# define ERR_PATH "** ERROR **\n** The map must contain a valid path **"
# define GAME_OVER "\n__________Game Over!_________\n\n Wanna give it another \
shot?\n\n"
# define WIN_MSG "\n_______🎉 Congratulations 🎉_______\n\n       \
You won with %d moves\n\n"

// **** Tile Size **** //
# define SIZE 100

// **** Key codes **** //
# define ESC 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

// **** Structs **** //
typedef struct s_img
{
	void	*player;
	void	*wall;
	void	*floor;
	void	*exit_1;
	void	*exit_0;
	void	*obj;
	int		img_w;
	int		img_h;
}	t_img;

typedef struct s_map
{
	char	**map;
	int		wd;
	int		hg;
}	t_map;

typedef struct s_count
{
	int	c_coll;
	int	c_exit;
	int	c_player;
}	t_count;

typedef struct s_position
{
	int	x_p;
	int	y_p;
	int	x_e;
	int	y_e;
}	t_position;

typedef struct s_mlx_data
{
	void		*mlx_connection;
	void		*mlx_window;
	int			moves;
	t_img		img;
	t_map		map;
	t_count		elem;
	t_position	pos;
}	t_mlx_data;

// **** Utils Functions **** //
int		file_is_valid(char *str);
int		count_chars(char *str, char c);
int		calc_width(char *str);
void	print_error(char *err);
void	set_count(t_count *elem);
void	free_arr(char **arr);
void	get_position(char **map, int *x, int *y);
char	**ft_strdup_double(char **str, int hg);
int		open_file(char *av);
char	*get_line_dimension(int fd, t_mlx_data *data);

// **** Parsing the map **** //
char	**parse_map(char *av, t_mlx_data *data);
char	*read_map(int fd, t_mlx_data *data);
int		check_elements(char *map, char *line, int wd);
void	check_walls(char **map, int wd, int hg, char *map_read);
void	check_elem_count(char **map, t_mlx_data *data, char *map_read);
void	check_valid_path(char **map_cp, char **map, char *map_r);
void	fill_path(char **map, int x, int y);
int		is_path_valid(char **map);

// **** Setting window **** //
void	import_images(t_mlx_data *data);
void	render_textures(t_mlx_data *data);
void	set_floor(t_mlx_data *data);
void	set_element(t_mlx_data *data, char elem, int x, int y);

// **** Hooks event **** //
int		on_destroy(t_mlx_data *data);
int		on_keypress(int keysym, t_mlx_data *data);
void	handle_moves(int keysym, t_mlx_data *data);
void	exit_game(t_mlx_data *data, int code);
void	set_player(t_mlx_data *data, int x, int y);
void	play_game(t_mlx_data *data, int x, int y);
void	win_and_exit(t_mlx_data *data, int x, int y);
void	step_up(t_mlx_data *data);
void	step_down(t_mlx_data *data);
void	step_right(t_mlx_data *data);
void	step_left(t_mlx_data *data);

#endif