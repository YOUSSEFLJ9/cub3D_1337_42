/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:38:02 by youchen           #+#    #+#             */
/*   Updated: 2024/07/10 13:14:23 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	keep_checking(t_data *data, int x, int y)
{
	if (x < 0 || x >= data->map_info.window_width * TILE_SIZE)
		return (0);
	if (y < 0 || y >= data->map_info.window_height * TILE_SIZE)
		return (0);
	return (1);
}

int	hit_horz(t_data *data, t_horz_info info)
{
	int	x;
	int	y;

	x = info.next_horz_touch_x;
	y = info.next_horz_touch_y;
	if (info.up)
		y--;
	if (hit_wall(data, x, y))
		return (1);
	return (0);
}

int	hit_vert(t_data *data, t_vert_info info)
{
	int	x;
	int	y;

	x = info.next_vert_touch_x;
	y = info.next_vert_touch_y;
	if (info.left)
		x--;
	if (hit_wall(data, x, y))
		return (1);
	return (0);
}
