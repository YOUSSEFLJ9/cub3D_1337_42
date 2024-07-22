/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:51:56 by youchen           #+#    #+#             */
/*   Updated: 2024/07/22 01:15:21 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cursor_rotate(double xpos, double ypos, void *param)
{
	t_data	*data;
	int		half_width;
	int		half_height;

	(void)ypos;
	data = (t_data *)param;
	half_width = data->map_info.window_width / 2;
	half_height = data->map_info.window_height / 2;
	if (data->player.release_mouse)
		return ;
	if (xpos < half_width)
		rotate_left(data);
	else
		rotate_right(data);
	mlx_set_cursor_mode(data->imgs.mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(data->imgs.mlx, half_width, half_height);
}

void	mouse_press(enum mouse_key mouse_key, enum action action
	, enum modifier_key modifier_key, void *arg)
{
	t_data	*data;

	(void)mouse_key;
	data = arg;
	if (action == MLX_PRESS)
	{
		if (modifier_key == MLX_MOUSE_BUTTON_LEFT)
			data->move = ATTACKING;
	}
}

void	draw(void *arg)
{
	t_data	*data;

	data = arg;
	if (data->rand)
	{
		cast_all_rays(data, data->rays);
		render_walls(data, data->rays);
		ft_mini_map(data, (data->player.x / TILE_SIZE) * MINI_TS, \
		(data->player.y / TILE_SIZE) * MINI_TS);
		data->rand = 0;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	read_file_parse(ac, av, &data);
	mlx_image_to_window(data.imgs.mlx, data.imgs.map, 0, 0);
	mlx_image_to_window(data.imgs.mlx, data.imgs.minimap, 1270, 20);
	mlx_loop_hook(data.imgs.mlx, movement, &data);
	mlx_cursor_hook(data.imgs.mlx, cursor_rotate, &data);
	mlx_mouse_hook(data.imgs.mlx, mouse_press, &data);
	mlx_loop_hook(data.imgs.mlx, animation, &data);
	mlx_loop(data.imgs.mlx);
	free_map_info(&data);
	free_imgs(&data);
	mlx_terminate(data.imgs.mlx);
	return (0);
}
