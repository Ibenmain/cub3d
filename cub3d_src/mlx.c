/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:30:20 by ibenmain          #+#    #+#             */
/*   Updated: 2023/01/17 23:12:16 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_spase(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (1);
	return (0);
}

int	get_line_map(t_data *data)
{
	int	line;
	int	i;

	i = 0;
	line = 0;
	data->line_max = 0;
	while (data->map[i])
	{
		if (data->line_max < ft_strlen(data->map[i]))
			data->line_max = ft_strlen(data->map[i]);
		if (ft_check_spase(data->map[i]))
			break ;
		line += 1;
		i++;
	}
	return (line);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= data->line_max * SIZE_MINI \
		&& y >= 0 && y <= data->len * SIZE_MINI)
	{
		dst = data->img.addr + (y * data->img.line_length + x * \
			(data->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_rectangle(int x, int y, t_data *data, int color)
{
	int	i;
	int	j;

	i = x * SIZE_MINI;
	while (i < x * SIZE_MINI + SIZE_MINI)
	{
		j = y * SIZE_MINI;
		while (j < y * SIZE_MINI + SIZE_MINI)
		{
			if (i % SIZE_MINI == 0 || j % SIZE_MINI == 0)
				my_mlx_pixel_put(data, j, i, 0x0033FFFF);
			else
				my_mlx_pixel_put(data, j, i, color);
			j++;
		}
		i++;
	}
}

void	ft_put_image_to_win(t_data *data, int line_map)
{
	int		i;
	int		j;
	int		color;

	i = 0;
	while (i < line_map)
	{
		j = 0;
		while (j < data->line_max)
		{
			if (data->map[i][j] != ' ')
			{
				if (data->map[i][j] == '1')
					color = 0x000066CC;
				else if (data->map[i][j] == '0')
					color = 0x00CCCCFF;
				else
					color = 0x00990000;
				draw_rectangle(i, j, data, color);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx.mx, data->mlx.mlx_win, \
		data->img.img, 0, 0);
}
