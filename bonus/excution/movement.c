/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 08:18:30 by youchen           #+#    #+#             */
/*   Updated: 2024/07/16 15:25:55 by ymomen           ###   ########.fr       */
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

void	movement(void *arg)
{
	t_data	*data;

	data = arg;
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
	if (mlx_is_key_down(data->imgs.mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->imgs.mlx);
	draw(data);
}
