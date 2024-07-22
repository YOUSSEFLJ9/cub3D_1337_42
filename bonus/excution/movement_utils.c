/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:52:03 by youchen           #+#    #+#             */
/*   Updated: 2024/07/22 01:15:52 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_data *data)
{
	int	mv_speed;
	int	adjacent;
	int	oposite;

	mv_speed = data->player.move_speed;
	adjacent = mv_speed * cos(data->player.rotation_angle);
	oposite = mv_speed * sin(data->player.rotation_angle);
	if (!validate_step(data, adjacent, oposite, 0))
	{
		data->player.x += adjacent;
		data->player.y += oposite;
		data->rand = 1;
		data->move = WALKING;
	}
}

void	running_forward(t_data *data)
{
	int	mv_speed;
	int	adjacent;
	int	oposite;

	mv_speed = data->player.move_speed;
	adjacent = (mv_speed * 1.2) * cos(data->player.rotation_angle);
	oposite = (mv_speed * 1.2) * sin(data->player.rotation_angle);
	if (!validate_step(data, adjacent, oposite, 0))
	{
		data->player.x += adjacent;
		data->player.y += oposite;
		data->rand = 1;
		data->move = WALKING;
	}
}

void	move_backward(t_data *data)
{
	int	mv_speed;
	int	adjacent;
	int	oposite;

	mv_speed = data->player.move_speed;
	adjacent = mv_speed * cos(data->player.rotation_angle);
	oposite = mv_speed * sin(data->player.rotation_angle);
	if (!validate_step(data, adjacent, oposite, 1))
	{
		data->player.x -= adjacent;
		data->player.y -= oposite;
		data->rand = 1;
		data->move = WALKING;
	}
}

void	move_left(t_data *data)
{
	int	mv_speed;
	int	adjacent;
	int	oposite;

	mv_speed = data->player.move_speed;
	adjacent = mv_speed * cos(data->player.rotation_angle + M_PI_2);
	oposite = mv_speed * sin(data->player.rotation_angle + M_PI_2);
	if (!validate_step(data, adjacent, oposite, 2))
	{
		data->player.x += adjacent;
		data->player.y += oposite;
		data->rand = 1;
		data->move = WALKING;
	}
}

void	move_right(t_data *data)
{
	int	mv_speed;
	int	adjacent;
	int	oposite;

	mv_speed = data->player.move_speed;
	adjacent = mv_speed * cos(data->player.rotation_angle + M_PI_2);
	oposite = mv_speed * sin(data->player.rotation_angle + M_PI_2);
	if (!validate_step(data, adjacent, oposite, 3))
	{
		data->player.x -= adjacent;
		data->player.y -= oposite;
		data->rand = 1;
		data->move = WALKING;
	}
}
