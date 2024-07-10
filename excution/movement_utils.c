/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:52:03 by youchen           #+#    #+#             */
/*   Updated: 2024/07/10 13:14:10 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_data *data)
{
	int	mv_speed;
	int	new_x;
	int	new_y;

	mv_speed = data->player.move_speed;
	new_x = mv_speed * cos(data->player.rotation_angle);
	new_y = mv_speed * sin(data->player.rotation_angle);
	if (!hit_wall(data, data->player.x + new_x, data->player.y + new_y))
	{
		data->player.x += new_x;
		data->player.y += new_y;
	}
}

void	move_backward(t_data *data)
{
	int	mv_speed;
	int	new_x;
	int	new_y;

	mv_speed = data->player.move_speed;
	new_x = mv_speed * cos(data->player.rotation_angle);
	new_y = mv_speed * sin(data->player.rotation_angle);
	if (!hit_wall(data, data->player.x - new_x, data->player.y - new_y))
	{
		data->player.x -= new_x;
		data->player.y -= new_y;
	}
}

void	move_left(t_data *data)
{
	int	mv_speed;
	int	new_x;
	int	new_y;

	mv_speed = data->player.move_speed;
	new_x = mv_speed * cos(data->player.rotation_angle + M_PI_2);
	new_y = mv_speed * sin(data->player.rotation_angle + M_PI_2);
	if (!hit_wall(data, data->player.x + new_x, data->player.y + new_y))
	{
		data->player.x += new_x;
		data->player.y += new_y;
	}
}

void	move_right(t_data *data)
{
	int	mv_speed;
	int	new_x;
	int	new_y;

	mv_speed = data->player.move_speed;
	new_x = mv_speed * cos(data->player.rotation_angle + M_PI_2);
	new_y = mv_speed * sin(data->player.rotation_angle + M_PI_2);
	if (!hit_wall(data, data->player.x - new_x, data->player.y - new_y))
	{
		data->player.x -= new_x;
		data->player.y -= new_y;
	}
}
