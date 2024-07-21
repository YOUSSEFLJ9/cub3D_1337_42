/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:04:05 by ymomen            #+#    #+#             */
/*   Updated: 2024/07/20 12:25:12 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void free_imgs(t_data *data)
{
	t_img	*imgs;

	imgs = &data->imgs;
	if (imgs->north)
	mlx_delete_image(imgs->mlx, imgs->north);
	if (imgs->south)
		mlx_delete_image(imgs->mlx, imgs->south);
	if (imgs->west)
		mlx_delete_image(imgs->mlx, imgs->west);
	if (imgs->east)
		mlx_delete_image(imgs->mlx, imgs->east);
	if (imgs->door)
		mlx_delete_image(imgs->mlx, imgs->door);
	if (imgs->ceiling)
		mlx_delete_image(imgs->mlx, imgs->ceiling);
	if (imgs->map)
		mlx_delete_image(imgs->mlx, imgs->map);
	if (imgs->minimap)
		mlx_delete_image(imgs->mlx, imgs->minimap);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	free_map_info(t_data *data)
{
	t_map_info	*map;

	map = &data->map_info;
	if (map->north_txt)
		free(map->north_txt);
	if (map->south_txt)
		free(map->south_txt);
	if (map->west_txt)
		free(map->west_txt);
	if (map->east_txt)
		free(map->east_txt);
	if (map->ceiling)
		free(map->ceiling);
	if (map->door)
		free(map->door);
	if (map->map)
		free_it_v2(map->map, map->height_map);
}

void	free_it_v2(char **s, int i)
{
	while (i-- && s[i])
		free(s[i]);
	free(s);
}
