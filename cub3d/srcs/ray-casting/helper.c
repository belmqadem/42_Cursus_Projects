/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:50:04 by mchihab           #+#    #+#             */
/*   Updated: 2024/10/11 14:55:19 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_line(t_game *game, t_mini_helper *helper)
{
	helper->x = helper->player_rect_x + 3.5;
	helper->y = helper->player_rect_y + 3.5;
	helper->dx = helper->ray_end_x - helper->player_rect_x;
	helper->dy = helper->ray_end_y - helper->player_rect_y;
	if (abs(helper->dx) > abs(helper->dy))
		helper->steps = abs(helper->dx);
	else
		helper->steps = abs(helper->dy);
	helper->i = 0;
	while (helper->i <= helper->steps)
	{
		put_pixel(&game->mlx, (int)(helper->x + 0.5), (int)(helper->y + 0.5),
			0xFF0000);
		helper->x += (float)helper->dx / (float)helper->steps;
		helper->y += (float)helper->dy / (float)helper->steps;
		helper->i++;
	}
}
