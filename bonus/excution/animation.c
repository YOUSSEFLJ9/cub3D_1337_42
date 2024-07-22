/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:07:15 by ymomen            #+#    #+#             */
/*   Updated: 2024/07/22 00:44:54 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_animated(t_data *data, int start)
{
	if (data->move == NORMAL)
	{
		if (start < 23 && start >= 0)
			return (++start);
		return (0);
	}
	else if (data->move == WALKING)
	{
		if (start < 40 && start > 23)
			return (++start);
		return (24);
	}
	else if (data->move == ATTACKING)
	{
		if (start < 60 && start > 40)
			return (++start);
		return (41);
	}
	return (0);
}

void	animation(void *arg)
{
	t_data		*data;
	static int	count;
	static int	start;
	char		*num;
	char		path[50];

	strcpy(path, "textures/frames/");
	data = arg;
	count++;
	if (count == 4)
	{
		start = get_animated(data, start);
		printf("%d\n", start);
		count = 0;
		num = ft_itoa(start);
		strlcat(path, num, 50);
		free(num);
		strlcat(path, ".png", 50);
		if (data->imgs.amination)
			mlx_delete_image(data->imgs.mlx, data->imgs.amination);
		data->imgs.amination = NULL;
		open_image(path, &data->imgs.amination, data);
		mlx_image_to_window(data->imgs.mlx, data->imgs.amination, 0, 200);
	}
}
