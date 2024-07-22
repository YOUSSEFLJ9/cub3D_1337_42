/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:05:31 by ymomen            #+#    #+#             */
/*   Updated: 2024/07/22 00:21:21 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_draw_rays_minimap(t_data *data)
{
	t_cord	end;
	t_cord	strt;
	double	ray_distance;
	int		i;

	i = 0;
	ray_distance = 0;
	strt.x = WIN_W_MINI / 2;
	strt.y = WIN_H_MINI / 2;
	while (i < WIN_WIDTH)
	{
		ray_distance = (data->rays[i].distance * MINI_TS) / TILE_SIZE;
		end.x = WIN_W_MINI / 2 + (ray_distance) * cos(data->rays[i].ray_angle);
		end.y = WIN_H_MINI / 2 + (ray_distance) * sin(data->rays[i].ray_angle);
		ft_draw_line(strt, end, data, 0xA6A600FF);
		i++;
	}
}

void	ft_draw_player(t_data *data)
{
	t_cord	cord;
	int		radius;
	t_cord	p;

	p.x = WIN_W_MINI / 2;
	p.y = WIN_H_MINI / 2;
	cord.x = (p.x + 20 * cos(data->player.rotation_angle));
	cord.y = (p.y + 20 * sin(data->player.rotation_angle));
	ft_draw_line(p, cord, data, 0x000000FF);
	radius = 5;
	cord.y = p.y - radius;
	while (cord.y < p.y + radius)
	{
		cord.x = p.x - radius;
		while (cord.x < p.x + radius)
		{
			if (pow(cord.x - p.x, 2) + pow(cord.y - p.y, 2) < pow(radius, 2))
				mlx_put_pixel(data->imgs.minimap, cord.x, cord.y, 0x00FF00FF);
			cord.x++;
		}
		cord.y++;
	}
}

void	draw_pixel_minimap(t_data *data, t_cord p, t_cord cont, t_cord xy)
{
	int	radius;

	radius = WIN_W_MINI / 2;
	if (p.x >= 0 && p.y >= 0 && p.x < data->map_info.width_map * MINI_TS \
	&& p.y < data->map_info.height_map * MINI_TS && pow(p.x - xy.x, 2) + \
pow(p.y - xy.y, 2) < pow(radius, 2))
	{
		if (data->map_info.map[p.y / MINI_TS][p.x / MINI_TS] == '1')
			mlx_put_pixel(data->imgs.minimap, cont.y, cont.x, 0x004DFF);
		else if (data->map_info.map[p.y / MINI_TS][p.x / MINI_TS] == '0' || \
data->map_info.map[p.y / MINI_TS][p.x / MINI_TS] == data->player.position_side)
			mlx_put_pixel(data->imgs.minimap, cont.y, cont.x, 0xFFFFFFFF);
		else if (data->map_info.map[p.y / MINI_TS][p.x / MINI_TS] == 'D')
			mlx_put_pixel(data->imgs.minimap, cont.y, cont.x, 0x663300FF);
		else if (data->map_info.map[p.y / MINI_TS][p.x / MINI_TS] == 'O')
			mlx_put_pixel(data->imgs.minimap, cont.y, cont.x, 0x006600FF);
		else
			mlx_put_pixel(data->imgs.minimap, cont.y, cont.x, 0x000000FF);
	}
	else if (pow(p.x - xy.x, 2) + pow(p.y - xy.y, 2) < pow(radius, 2))
		mlx_put_pixel(data->imgs.minimap, cont.y, cont.x, 0x000000FF);
}

void	ft_mini_map(t_data *data, int x, int y)
{
	t_cord	p;
	t_cord	cont;
	int		radius;

	cont.x = 0;
	radius = WIN_W_MINI / 2;
	p.y = y - radius;
	while (p.y < y + radius)
	{
		cont.y = 0;
		p.x = x - radius;
		while (p.x < x + radius)
		{
			draw_pixel_minimap(data, p, cont, (t_cord){x, y});
			p.x++;
			cont.y++;
		}
		p.y++;
		cont.x++;
	}
	ft_draw_rays_minimap(data);
	ft_draw_player(data);
}
