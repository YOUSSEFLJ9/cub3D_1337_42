/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 08:18:30 by youchen           #+#    #+#             */
/*   Updated: 2024/07/22 08:13:03 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_left(t_data *data)
{
	data->player.rotation_angle -= data->player.rotation_speed;
	data->player.rotation_angle = normalize_angle(data->player.rotation_angle);
	data->rand = 1;
}

void	rotate_right(t_data *data)
{
	data->player.rotation_angle += data->player.rotation_speed;
	data->player.rotation_angle = normalize_angle(data->player.rotation_angle);
	data->rand = 1;
}

void	movement_1(t_data *data)
{
	if (mlx_is_key_down(data->imgs.mlx, MLX_KEY_O))
		open_door(data);
	if (mlx_is_key_down(data->imgs.mlx, MLX_KEY_C))
		close_door(data);
	if (mlx_is_key_down(data->imgs.mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->imgs.mlx);
	if (mlx_is_key_down(data->imgs.mlx, MLX_KEY_W)
		&& mlx_is_key_down(data->imgs.mlx, MLX_KEY_LEFT_SHIFT))
		running_forward(data);
	if (mlx_is_key_down(data->imgs.mlx, MLX_KEY_E))
	{
		mlx_set_cursor_mode(data->imgs.mlx, MLX_MOUSE_HIDDEN);
		data->player.release_mouse = 0;
	}
	else if (mlx_is_key_down(data->imgs.mlx, MLX_KEY_X))
	{
		mlx_set_cursor_mode(data->imgs.mlx, MLX_MOUSE_NORMAL);
		data->player.release_mouse = 1;
	}
}

void	movement(void *arg)
{
	t_data	*data;

	data = arg;
	data->move = NORMAL;
	if (mlx_is_key_down(data->imgs.mlx, MLX_KEY_W)
		|| mlx_is_key_down(data->imgs.mlx, MLX_KEY_UP))
		move_forward(data);
	if (mlx_is_key_down(data->imgs.mlx, MLX_KEY_S)
		|| mlx_is_key_down(data->imgs.mlx, MLX_KEY_DOWN))
		move_backward(data);
	if (mlx_is_key_down(data->imgs.mlx, MLX_KEY_A))
		move_right(data);
	if (mlx_is_key_down(data->imgs.mlx, MLX_KEY_D))
		move_left(data);
	if (mlx_is_key_down(data->imgs.mlx, MLX_KEY_LEFT))
		rotate_left(data);
	if (mlx_is_key_down(data->imgs.mlx, MLX_KEY_RIGHT))
		rotate_right(data);
	movement_1(data);
	draw(data);
}
