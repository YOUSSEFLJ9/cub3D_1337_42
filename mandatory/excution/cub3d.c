/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:51:56 by youchen           #+#    #+#             */
/*   Updated: 2024/07/16 10:51:51 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw(void *arg)
{
	t_data	*data;

	data = arg;
	cast_all_rays(data, data->rays);
	render_walls(data, data->rays);
}

void	cursor_rotate(double xpos, double ypos, void *param)
{
	t_data	*data;
	int		half_width;
	int		half_height;

	data = param;
	half_width = data->map_info.window_width / 2;
	half_height = data->map_info.window_height / 2;
	if (xpos < half_width)
		rotate_left(data);
	else
		rotate_right(data);
	mlx_set_mouse_pos(data->imgs.mlx, half_width, half_height);
}

int	main(int ac, char **av)
{
	t_data	data;

	read_file_parse(ac, av, &data);
	mlx_image_to_window(data.imgs.mlx, data.imgs.map, 0, 0);
	mlx_loop_hook(data.imgs.mlx, movement, &data);
	mlx_cursor_hook(data.imgs.mlx, cursor_rotate, &data);
	mlx_loop(data.imgs.mlx);
	free_map_info(&data);
	return (0);
}
