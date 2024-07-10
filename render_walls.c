/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:09:54 by youchen           #+#    #+#             */
/*   Updated: 2024/07/10 11:03:27 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color_wall(int was_hit_vertical)
{
	if (was_hit_vertical)
		return (0x2e4e5e);
	return (0x3f5e6d);
}

void	draw_wall(t_data *data, int i,
		int wall_height, int was_hit_vertical)
{
	int	start;
	int	end;
	int	color;
	int	y;

	if (wall_height > data->map_info.window_height)
		wall_height = data->map_info.window_height;
	start = (data->map_info.window_height / 2) - (wall_height / 2);
	end = (data->map_info.window_height / 2) + (wall_height / 2);
	color = get_color_wall(was_hit_vertical);
	y = 0;
	while (y < start)
	{
		mlx_put_pixel(data->imgs.map, i, y, data->map_info.ceiling_clr);
		y++;
	}
	while (y < end)
	{
		mlx_put_pixel(data->imgs.map, i, y, color);
		y++;
	}
	while (y < data->map_info.window_height)
	{
		mlx_put_pixel(data->imgs.map, i, y, data->map_info.floor_clr);
		y++;
	}
}

void	render_walls(t_data *data, t_ray *rays)
{
	int		i;
	int		wall_height;
	int		scale;
	int		fix_distance;
	double	angle;

	i = 0;
	scale = 120000;
	while (i < data->map_info.rays_num)
	{
		angle = rays[i].ray_angle - data->player.rotation_angle;
		fix_distance = rays[i].distance * cos(angle);
		printf("fix_distance: %d\n", fix_distance);
		if (fix_distance <= 0)
			fix_distance = 1;
		wall_height = (scale / fix_distance);
		draw_wall(data, i, wall_height, rays[i].was_hit_vertical);
		i++;
	}
}
