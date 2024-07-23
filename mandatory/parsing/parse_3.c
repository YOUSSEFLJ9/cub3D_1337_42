/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:48:34 by ymomen            #+#    #+#             */
/*   Updated: 2024/07/23 12:00:44 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

size_t	len_map(t_list *hd)
{
	int	len;
	int	max_len;

	max_len = 0;
	while (hd)
	{
		len = ft_strlen(hd->str);
		if (len > max_len)
			max_len = len;
		hd = hd->next;
	}
	return (max_len);
}

int	valid_chars(char c)
{
	if (c == '1' || c == '0')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

int	parce_color(char *line, int i)
{
	int	c[3];
	int	j;

	j = -1;
	while (++j < 3)
	{
		c[j] = 0;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (!ft_isdigit(line[i]))
			return (0);
		while (ft_isdigit(line[i]) && c[j] >= 0 && c[j] <= 255)
			c[j] = c[j] * 10 + line[i++] - '0';
		if (line[i] && line[i] != ',' && line[i] != ' '
			&& line[i] != '\t' && line[i] != '\n')
			return (0);
		if ((line[i] == ',' && line[i + 1] == ',') || (line[i] == ',' && j > 1))
			return (0);
		i++;
	}
	if (c[0] < 0 || c[0] > 255 || c[1] < 0 || c[1] > 255
		|| c[2] < 0 || c[2] > 255)
		return (0);
	return (c[0] << 24 | c[1] << 16 | c[2] << 8 | 0x000000FF);
}

int	check_map_line(char *line)
{
	int	l;

	l = 0;
	while (line && line[l])
	{
		while (line[l] == ' ' || line[l] == '\t')
			l++;
		if (!valid_chars(line[l]) && line[l])
			return (0);
		if (!line[l])
			return (2);
		l++;
		while (line[l] == ' ' || line[l] == '\t' || line[l] == '\n')
			l++;
	}
	return (1);
}

void	trime(t_data *data)
{
	char	**map;
	int		r;
	int		c;

	map = data->map_info.map;
	c = 0;
	while (map[c])
	{
		r = 0;
		while (map[c][r])
		{
			if (map[c][r] == '\n')
			{
				map[c][r] = ' ';
				break ;
			}
			r++;
		}
		c++;
	}
	data->map_info.width_map--;
	data->map_info.map = map;
}
