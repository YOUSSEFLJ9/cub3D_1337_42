/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:51:56 by youchen           #+#    #+#             */
/*   Updated: 2024/07/09 17:29:48 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_square(t_data *data, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	x = x * 100;
	y = y * 100;
	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			mlx_put_pixel(data->imgs.map, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_info.height_map)
	{
		x = 0;
		while (x < data->map_info.width_map)
		{
			if (data->map_info.map[y][x] == '1')
				draw_square(data, x, y, 0xFF00FF);
			else if (data->map_info.map[y][x] == '0')
				draw_square(data, x, y, 0xFFFFFF);
			else if (data->map_info.map[x][y] == 'E')
				draw_square(data, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

void mlx_draw_line(t_data *data, int x2, int y2, int color)
{
	int x1 = data->player.x;
	int y1 = data->player.y;
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = x1 < x2 ? 1 : -1;
	int sy = y1 < y2 ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;
	int e2;

	while (1)
	{
		mlx_put_pixel(data->imgs.map, x1, y1, color);
		if (x1 == x2 && y1 == y2)
			break;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void	draw_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			mlx_put_pixel(data->imgs.map, data->player.x + j, data->player.y + i, 0xF6faa4);
			j++;
		}
		i++;
	}

	/// draw line
	// draw line
	int line_length = 50; // adjust the length of the line as needed
	double angle = data->player.rotation_angle; // get the rotation angle of the player
	double end_x = data->player.x + line_length * cos(angle); // calculate the end point of the line in the x-axis
	double end_y = data->player.y + line_length * sin(angle); // calculate the end point of the line in the y-axis
	mlx_draw_line(data, end_x, end_y, 0xFF0000); // draw the line from the player's position to the end point
}

void	draw(void *arg)
{
	t_data	*data;

	data = arg;
	// draw_map(data);
	// draw_player(data);
	cast_all_rays(data, data->rays);
	render_walls(data, data->rays);

}

int	main(int ac, char **av)
{
	t_data	data;

	read_file_parse(ac, av, &data);
	mlx_image_to_window(data.imgs.mlx, data.imgs.map, 0, 0);
	mlx_loop_hook(data.imgs.mlx, movement, &data);
	mlx_loop(data.imgs.mlx);
	return (0);
}
