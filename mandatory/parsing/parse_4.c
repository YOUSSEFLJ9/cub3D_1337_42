/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:49:43 by ymomen            #+#    #+#             */
/*   Updated: 2024/07/21 19:27:27 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_retation(t_data *data)
{
	char	c;

	c = data->player.position_side;
	if (c == 'N')
		data->player.rotation_angle = 3 * M_PI_2;
	else if (c == 'S')
		data->player.rotation_angle = M_PI_2;
	else if (c == 'W')
		data->player.rotation_angle = M_PI;
	else if (c == 'E')
		data->player.rotation_angle = 0;
	data->player.rotation_speed = ROTATION_SPEED * (M_PI / 180);
	data->player.move_speed = MOVE_SPEED;
	data->player.fov = 60 * (M_PI / 180);
	data->imgs.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3D", false);
	data->imgs.map = mlx_new_image(data->imgs.mlx, WIN_WIDTH, WIN_HEIGHT);
	open_textures(data);
}

void	free_imgs(t_data *data)
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
	if (imgs->map)
		mlx_delete_image(imgs->mlx, imgs->map);
}

void	open_image(char *path, mlx_image_t **img, t_data *data)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
	{
		free_map_info(data);
		error_and_exit("Error\nTexture not found\n", -9);
	}
	*img = mlx_texture_to_image(data->imgs.mlx, texture);
	mlx_delete_texture(texture);
}

void	open_textures(t_data *data)
{
	open_image(data->map_info.north_txt, &data->imgs.north, data);
	open_image(data->map_info.south_txt, &data->imgs.south, data);
	open_image(data->map_info.west_txt, &data->imgs.west, data);
	open_image(data->map_info.east_txt, &data->imgs.east, data);
	if (!data->imgs.north || !data->imgs.south || !data->imgs.west
		|| !data->imgs.east)
	{
		free_map_info(data);
		free_imgs(data);
		error_and_exit("Error\nTexture not found\n", -9);
	}
}
