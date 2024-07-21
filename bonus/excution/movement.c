/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 08:18:30 by youchen           #+#    #+#             */
/*   Updated: 2024/07/20 12:32:55 by ymomen           ###   ########.fr       */
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

void open_door(t_data *data)
{
	int	x;
	int	y;

	x = data->player.x / TILE_SIZE;
	y = data->player.y / TILE_SIZE;
	if (data->map_info.map[y + 1][x] == 'D')
		data->map_info.map[y + 1][x] = 'O';
	else if (data->map_info.map[y - 1][x] == 'D')
		data->map_info.map[y - 1][x] = 'O';
	else if (data->map_info.map[y][x + 1] == 'D')
		data->map_info.map[y][x + 1] = 'O';
	else if (data->map_info.map[y][x - 1] == 'D')
		data->map_info.map[y][x - 1] = 'O';
	data->rand = 1;
}

void close_door(t_data *data)
{
	int	x;
	int	y;

	x = data->player.x / TILE_SIZE;
	y = data->player.y / TILE_SIZE;
	if (data->map_info.map[y + 1][x] == 'O')
		data->map_info.map[y + 1][x] = 'D';
	else if (data->map_info.map[y - 1][x] == 'O')
		data->map_info.map[y - 1][x] = 'D';
	else if (data->map_info.map[y][x + 1] == 'O')
		data->map_info.map[y][x + 1] = 'D';
	else if (data->map_info.map[y][x - 1] == 'O')
		data->map_info.map[y][x - 1] = 'D';
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
	if (mlx_is_key_down(data->imgs.mlx, MLX_KEY_O))
		open_door(data);
	if (mlx_is_key_down(data->imgs.mlx, MLX_KEY_C))
		close_door(data);
	if (mlx_is_key_down(data->imgs.mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->imgs.mlx);
	draw(data);
}
