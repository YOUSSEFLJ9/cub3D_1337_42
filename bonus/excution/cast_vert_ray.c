/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_vert_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:54:32 by youchen           #+#    #+#             */
/*   Updated: 2024/07/10 13:14:03 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_vert_facing(t_vert_info *info, double ray_angle)
{
	info->right = ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI;
	info->left = !info->right;
	info->down = ray_angle > 0 && ray_angle < M_PI;
	info->up = !info->down;
}

void	init_vert_ray(double ray_angle, t_vert_info *vert, t_data *data)
{
	double	adjacent;
	double	opposite;

	player_vert_facing(vert, ray_angle);
	vert->x_intercept = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
	if (vert->right)
		vert->x_intercept += TILE_SIZE;
	adjacent = vert->x_intercept - data->player.x;
	opposite = adjacent * tan(ray_angle);
	vert->y_intercept = data->player.y + opposite;
	vert->x_step = TILE_SIZE;
	if (vert->left)
		vert->x_step *= -1;
	vert->y_step = fabs(TILE_SIZE * tan(ray_angle));
	if (vert->up)
		vert->y_step *= -1;
	vert->next_vert_touch_x = vert->x_intercept;
	vert->next_vert_touch_y = vert->y_intercept;
}

t_ray_vert	cast_vert_ray(double ray_angle, t_data *data)
{
	t_vert_info	vert;
	t_ray_vert	vert_ray;

	init_vert_ray(ray_angle, &vert, data);
	vert_ray.found_hit = 0;
	while (keep_checking(data, vert.next_vert_touch_x, vert.next_vert_touch_y))
	{
		if (hit_vert(data, vert))
		{
			vert_ray.wall_hit_x = vert.next_vert_touch_x;
			vert_ray.wall_hit_y = vert.next_vert_touch_y;
			vert_ray.found_hit = 1;
			break ;
		}
		else
		{
			vert.next_vert_touch_x += vert.x_step;
			vert.next_vert_touch_y += vert.y_step;
		}
	}
	return (vert_ray);
}
