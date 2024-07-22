/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:58:02 by ymomen            #+#    #+#             */
/*   Updated: 2024/07/21 18:58:12 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	open_door(t_data *data)
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

void	close_door(t_data *data)
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
