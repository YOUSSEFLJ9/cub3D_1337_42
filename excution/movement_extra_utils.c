/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_extra_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 08:58:20 by youchen           #+#    #+#             */
/*   Updated: 2024/07/11 09:25:11 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_corner(t_data *data, int x, int y)
{
	if (hit_wall(data, data->player.x, y) && hit_wall(data, x, data->player.y))
		return (1);
	return (0);
}

int	validate_step(t_data *data, int x, int y, int dir)
{
	int	new_x;
	int	new_y;

	if (dir == 0 || dir == 2)
	{
		new_x = data->player.x + x;
		new_y = data->player.y + y;
	}
	else
	{
		new_x = data->player.x - x;
		new_y = data->player.y - y;
	}
	if (is_corner(data, new_x, new_y))
		return (1);
	if (hit_wall(data, new_x, new_y))
		return (1);
	return (0);
}
