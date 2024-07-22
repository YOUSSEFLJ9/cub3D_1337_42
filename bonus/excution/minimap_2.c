/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 00:09:56 by ymomen            #+#    #+#             */
/*   Updated: 2024/07/22 00:40:37 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_cord	init(t_cord str, t_cord end, t_cord *dist, int *error)
{
	t_cord	step;

	dist->x = abs(end.x - str.x);
	dist->y = abs(end.y - str.y);
	*error = dist->x - dist->y;
	if (str.x < end.x)
		step.x = 1;
	else
		step.x = -1;
	if (str.y < end.y)
		step.y = 1;
	else
		step.y = -1;
	return (step);
}

void	update_value(t_cord *str, t_cord *s, int *err, t_cord *d)
{
	int	e2;

	e2 = 2 * *err;
	if (e2 > -d->y)
	{
		*err -= d->y;
		str->x += s->x;
	}
	if (e2 < d->x)
	{
		*err += d->x;
		str->y += s->y;
	}
}

void	ft_draw_line(t_cord str, t_cord end, t_data *data, int color)
{
	t_cord	d;
	t_cord	s;
	int		err;
	int		radius;

	s = init(str, end, &d, &err);
	radius = WIN_W_MINI / 2;
	while (true)
	{
		if (str.x >= 0 && str.y >= 0 && str.x < WIN_W_MINI && \
	str.y < WIN_H_MINI && (pow(str.x - radius, 2) + \
		pow(str.y - radius, 2)) < pow(radius, 2))
			mlx_put_pixel(data->imgs.minimap, str.x, str.y, color);
		if (str.x == end.x && str.y == end.y)
			break ;
		update_value(&str, &s, &err, &d);
	}
}
