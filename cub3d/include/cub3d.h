/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:07:03 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/10/11 14:55:46 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "tools.h"

//					__  _ __    		//
//	    	 __  __/ /_(_) /____		//
//			/ / / / __/ / / ___/		//
//			/ /_/ / /_/ / (__  ) 		//
//			\__,_/\__/_/_/____/  		//

int				check_valid_arg(int ac, char **av);
int				count_char(char *str, char c);
void			exit_w_error(t_game *game, char *err);
void			exit_w_success(t_game *game);
void			free_arr(char **arr);
t_mem_manager	*init_mem_manager(void);
void			track_malloc_single(t_mem_manager *manager, void *ptr);
void			track_malloc_array(t_mem_manager *manager, char **array);
void			free_all(t_mem_manager *manager);
void			init_before_parse(t_game *game);
void			init_player(t_player *player);
void			init_mlx(t_mlx *mlx);
void			init_config(t_config *config);
void			complete_init(t_game *game, t_config *config);
void			print_game_controls(t_game *game);
int				on_destroy(t_game *game);
int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);
void			free_textures(t_game *game);

//						            _            		//
//			 ____  ____ ___________(_)___  ____ _		//
//			/ __ \/ __ `/ ___/ ___/ / __ \/ __ `/		//
//			/ /_/ / /_/ / /  (__  ) / / / / /_/ / 		//
//			/ .___/\__,_/_/  /____/_/_/ /_/\__, /  		//
//			/_/                            /____/   	//

void			parsing(t_game *game, char *file);
int				open_file(t_game *game, char *file);
int				is_print(int c);
int				count_lines(int fd);
void			parse_textures(t_game *game, char *line, int j);
void			parse_colors(t_game *game, char *line, int j);
void			parse_map(t_game *game, char **data, int i);
void			analyze_map(t_game *game, char **map);
void			check_elements_bonus(t_game *game, char **map);
void			check_walls_bonus(t_game *game, char **map, int i, int j);
void			check_valid_door(t_game *game, char **map, int i, int j);
void			check_top_bottom(t_game *game, char **map, int i, int j);
int				position_not_valid(t_game *game, char **map);
void			check_infos(t_game *game, t_config *config);
void			init_textures(t_game *game, t_config *config);
void			print_infos(t_game *game);

//		    			                       __  _            		//
//			 _________ ___  ___________ ______/ /_(_)___  ____ _		//
//			/ ___/ __ `/ / / / ___/ __ `/ ___/ __/ / __ \/ __ `/		//
//			/ /  / /_/ / /_/ / /__/ /_/ (__  ) /_/ / / / / /_/ / 		//
//			/_/   \__,_/\__, /\___/\__,_/____/\__/_/_/ /_/\__, /  		//
//						/____/                            /____/   		//

void			put_pixel(t_mlx *mlx, int x, int y, size_t color);
int				check_collision(t_game *game, float new_x, float new_y);
void			move_player(t_game *game, float move_speed);
void			render_map(t_game *game);
void			draw_ceiling(t_game *game);
void			draw_floor(t_game *game);
int				render_game(t_game *game);
void			init_game(t_game *game);
void			init_dda(t_game *game, t_dda *dda, float ray_dir_x,
					float ray_dir_y);
void			init_player_direction(t_player *player);
void			draw_plane(t_game *game);
int				mouse_move(int x, int y, t_game *game);
t_texture		*select_texture(t_game *game, t_dda *dda);
t_texture		*valid_texture(t_game *game, t_dda *dda, int i);
int				calculate_tex_x(t_game *game, t_dda *dda, t_texture *texture,
					float wallX);
float			calculate_wall_x(t_game *game, t_dda *dda);
void			calculate_draw_range(t_game *game, t_dda *dda);
void			calculate_perpendicular_wall_distance(t_game *game, t_dda *dda,
					float ray_dir_x, float ray_dir_y);
void			calculate_side_distances(t_game *game, t_dda *dda,
					float ray_dir_x, float ray_dir_y);
void			perform_dda(t_game *game, float ray_dir_x,
					float ray_dir_y, int screen_column);
void			draw_wall(t_game *game, t_dda *dda, int screen_column);
void			interact_with_door(t_game *game);
void			toggle_door(t_game *game, int player_x, int player_y);
void			handle_movement(t_game *game);
int				mouse_click(int button, int x, int y, t_game *game);
void			rotate_player(t_game *game, float angle);
void			move_right(t_game *game);
void			move_left(t_game *game);
void			move_backward(t_game *game);
void			move_forward(t_game *game);
void			init_bonus_textures(t_game *game);
void			init_paths(char *texture_path[BONUS_TEX]);
void			update_hand_animation(t_game *game);
void			render_animation_frame(t_game *game);
void			draw_mini_map(t_game *game);
void			check_and_draw_tile(t_game *game, t_mini_map *m_map);
void			draw_line(t_game *game, t_mini_helper *helper);

#endif
