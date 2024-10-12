/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:07:47 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/10/12 23:28:29 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

// == Includes == //
# include "../libft/libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>

// == Colors == //
# define RED 			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define MAGENTA		"\x1b[35m"
# define CYAN			"\x1b[36m"
# define BHBLUE			"\e[1;94m"
# define BOLD			"\x1b[1m"
# define UNDERLINE		"\x1b[4m"
# define RESET			"\x1b[0m"

// == Macros == //
# define INVALID_ARG	"Error\nInvalid number of arguments."
# define INVALID_EXTS	"Error\nInvalid file extension."
# define ERR_MALLOC		"Error\nFailed to initialize memory manager."
# define ERR_TEX		"Error\nInvalid texture format."
# define ERR_COLOR		"Error\nInvalid RGB color format."
# define ERR_FLOOR		"Error\nInvalid RGB format for floor color."
# define ERR_CEIL		"Error\nInvalid RGB format for ceiling color."
# define ERR_NOMAP		"Error\nNo map found in file."
# define ERR_WALL		"Error\nMap is not properly enclosed by walls."
# define ERR_SMALL		"Error\nMap is too small."
# define INVALID_ELEM	"Error\nInvalid element in map content."
# define INVALID_POS	"Error\nInvalid player starting position."
# define INVALID_D_POS	"Error\nInvalid door position."
# define INVALID_NUM	"Error\nMap contains more than one player."
# define ERR_PLAYER		"Error\nMap is missing a player."
# define ERR_LAST		"Error\nMap should be the last element in the file."
# define ERR_MISS_N		"Error\nMissing north wall texture."
# define ERR_MISS_S		"Error\nMissing south wall texture."
# define ERR_MISS_E		"Error\nMissing east wall texture."
# define ERR_MISS_W		"Error\nMissing west wall texture."
# define ERR_MISS_F		"Error\nMissing floor color definition."
# define ERR_MISS_C		"Error\nMissing ceiling color definition."
# define ERR_XPM		"Error\nTexture file must be in .xpm format."
# define ERR_MLX_INIT	"Error\nFailed to initialize MLX."
# define ERR_MLX_WINDOW	"Error\nFailed to create MLX window."
# define ERR_MLX_IMAGE	"Error\nFailed to create MLX image."
# define ERR_MLX_TEX	"Error\nFailed to load MLX texture."
# define ERR_MLX_HOOKS	"Error\nFailed to set MLX hooks."
# define ERR_MLX_LOOP	"Error\nFailed to start the MLX loop."
# define WIN_WD			720		// Window width
# define WIN_HG			640		// Window height
# define TEXTURE_SIZE	64		// Dimensions of the textures (64 * 64)
# define FOV			45		// Field of view in degrees
# define RAY_COUNT		100		// Number of rays to cast for the FOV
# define MAX_KEYCODES	65365	// Maximum number of keycodes
# define PLAYER_OFFSET	0.06	// Offset for player collision detection
# define DOOR_OFFSET	0.06		// Offset for player collision detection
# define BONUS_TEX		6		// Number of bonus textures for animation
# define MINI_MAP_SCALE	10		// Scale factor for tiles
# define SAFE_DISTANCE	0.2		// Safe distance for door interaction

// == STRUCTURES == //
typedef enum e_mem_type
{
	SINGLE,
	ARRAY
}						t_mem_type;

typedef struct s_mem_block
{
	void				*ptr;
	t_mem_type			type;
	struct s_mem_block	*next;
}						t_mem_block;

typedef struct s_mem_manager
{
	t_mem_block			*head;
}						t_mem_manager;

typedef struct s_texture
{
	void				*img_ptr;
	int					*img_add;
	int					width;
	int					height;
	int					bpp;
	int					line_size;
	int					endian;
}						t_texture;

typedef struct s_mini_map
{
	int					map_x;
	int					map_y;
	int					tile_x;
	int					tile_y;
	size_t				color;
	int					start_x;
	int					start_y;
	int					mini_map_width;
	int					mini_map_height;
}						t_mini_map;

typedef struct s_mini_helper
{
	int		dx;
	int		dy;
	int		steps;
	int		i;
	float	x;
	float	y;
	int		ray_end_x;
	int		ray_end_y;
	int		player_rect_x;
	int		player_rect_y;
}						t_mini_helper;

typedef struct s_config
{
	char				*north_tex;
	char				*south_tex;
	char				*west_tex;
	char				*east_tex;
	int					*floor;
	int					*ceiling;
	size_t				floor_hex;
	size_t				ceiling_hex;
	char				**map;
	char				**all_data;
	int					map_wd;
	int					map_hg;
	int					eom;
	int					fd;
	int					lines;
	t_texture			*textures;
}						t_config;

typedef struct s_player
{
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	float				move_speed;
	float				rot_speed;
	char				direction;
}						t_player;

typedef struct s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*img_data;
	int					img_width;
	int					img_height;
	int					bpp;
	int					line_size;
	int					endian;
}						t_mlx;

typedef struct s_dda
{
	int					map_x;
	int					map_y;
	float				delta_dist_x;
	float				delta_dist_y;
	float				side_dist_x;
	float				side_dist_y;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	float				perp_wall_dist;
	int					line_height;
	int					draw_start;
	int					draw_end;
	float				wall_x;
	int					tex_x;
	float				tex_step;
	float				tex_pos;
	size_t				color;
	bool				is_door;
}						t_dda;

typedef struct s_ray
{
	float				ray_dir_x;
	float				ray_dir_y;
	float				start_angle;
	float				step_angle;
}						t_ray;

typedef struct s_game
{
	t_mem_manager		*manager;
	t_config			config;
	t_player			player;
	t_mlx				mlx;
	t_dda				dda;
	t_ray				ray;
	bool				bonus;
	bool				keys[65536];
	bool				mouse_locked;
	t_texture			*bonus_textures;
	bool				animation_active;
	bool				animation_playing;
	int					animation_frame;
	int					total_frames;
}						t_game;

#endif
