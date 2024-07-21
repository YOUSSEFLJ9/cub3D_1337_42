/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_horz_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:44:16 by youchen           #+#    #+#             */
/*   Updated: 2024/07/19 21:44:33 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_horz_facing(t_horz_info *info, double ray_angle)
{
	info->down = ray_angle > 0 && ray_angle < M_PI;
	info->up = !info->down;
	info->right = ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI;
	info->left = !info->right;
}

void	init_horz_ray(double ray_angle, t_horz_info *horz, t_data *data)
{
	double	adjacent;
	double	opposite;

	player_horz_facing(horz, ray_angle);
	horz->y_intercept = floor(data->player.y / TILE_SIZE) * TILE_SIZE;
	if (horz->down)
		horz->y_intercept += TILE_SIZE;
	opposite = horz->y_intercept - data->player.y;
	adjacent = opposite / tan(ray_angle);
	horz->x_intercept = data->player.x + adjacent;
	horz->y_step = TILE_SIZE;
	if (horz->up)
		horz->y_step *= -1;
	horz->x_step = fabs(TILE_SIZE / tan(ray_angle));
	if (horz->left)
		horz->x_step *= -1;
	horz->next_horz_touch_x = horz->x_intercept;
	horz->next_horz_touch_y = horz->y_intercept;
}

t_ray_horz	cast_horz_ray(double ray_angle, t_data	*data)
{
	t_horz_info	horz;
	t_ray_horz	horz_ray;

	init_horz_ray(ray_angle, &horz, data);
	horz_ray.found_hit = 0;
	while (keep_checking(data, horz.next_horz_touch_x, horz.next_horz_touch_y))
	{
		if (hit_horz(data, horz))
		{
			if (hit_horz(data, horz) == 2)
				horz_ray.door = 1;
			else
				horz_ray.door = 0;
			horz_ray.wall_hit_x = horz.next_horz_touch_x;
			horz_ray.wall_hit_y = horz.next_horz_touch_y;
			horz_ray.found_hit = 1;
			break ;
		}
		else
		{
			horz.next_horz_touch_x += horz.x_step;
			horz.next_horz_touch_y += horz.y_step;
		}
	}
	return (horz_ray);
}
