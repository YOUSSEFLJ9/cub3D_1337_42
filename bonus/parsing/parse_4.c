/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:49:43 by ymomen            #+#    #+#             */
/*   Updated: 2024/07/20 20:34:17 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_edges(char **map, int i, int j)
{
	t_cord	count;

	if (map[i - 1][j] == '1' && map[i + 1][j] == '1')
		return (1);
	else if (map[i][j - 1] == '1' && map[i][j + 1] == '1')
		return (1);
	count.x = 0;
	count.y = 0;
	if (map[i - 1][j] == '1')
		count.x++;
	if (map[i + 1][j] == '1')
		count.x++;
	if (map[i][j - 1] == '1')
		count.y++;
	if (map[i][j + 1] == '1')
		count.y++;
	if (count.x == 2 && count.y == 2)
		return (1);
	return (0);
}

int	ft_check_door(t_map_info *map, int i, int j)
{
	int	count;
	count = 0;
	if (map->map[i][j] == 'D')
	{

		if (!check_edges(map->map, i, j))
			return (0);
		if (i == 0 || i == map->height_map - 1
			|| j == 0 || j == map->width_map - 1)
			return (0);
		if (map->map[i - 1][j] == ' ' || map->map[i + 1][j] == ' '
			|| map->map[i][j - 1] == ' ' || map->map[i][j + 1] == ' ')
			return (0);
	}
	return (1);
}

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
	data->imgs.minimap = mlx_new_image(data->imgs.mlx, WIN_WIDTH_MINI,
			WIN_HEIGHT_MINI);
	open_textures(data);
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
	open_image(data->map_info.north_txt, &(data->imgs.north), data);
	open_image(data->map_info.south_txt, &(data->imgs.south), data);
	open_image(data->map_info.west_txt, &(data->imgs.west), data);
	open_image(data->map_info.east_txt, &(data->imgs.east), data);
	open_image(data->map_info.ceiling, &(data->imgs.ceiling), data);
	open_image(data->map_info.door, &(data->imgs.door), data);

	if (!data->imgs.north || !data->imgs.south || !data->imgs.west
		|| !data->imgs.east || !data->imgs.ceiling || !data->imgs.door)
	{
		free_map_info(data);
		free_imgs(data);
		error_and_exit("Error\nTexture not found\n", -9);
	}
}