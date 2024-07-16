/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:51:56 by youchen           #+#    #+#             */
/*   Updated: 2024/07/16 07:59:54 by ymomen           ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_data	data;

	read_file_parse(ac, av, &data);
	mlx_image_to_window(data.imgs.mlx, data.imgs.map, 0, 0);
	mlx_loop_hook(data.imgs.mlx, movement, &data);
	mlx_loop(data.imgs.mlx);
	free_map_info(&data);
	return (0);
}