/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:09:42 by ibenmain          #+#    #+#             */
/*   Updated: 2023/01/16 21:53:13 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mlx_wind(t_data *data)
{
	int		line_map;

	line_map = get_line_map(data);
	data->mlx.mx = mlx_init();
	if (!data->mlx.mx)
		return (-1);
	data->mlx.mlx_win = mlx_new_window(data->mlx.mx, \
		(ft_strlen(data->map[0]) - 1) * SIZE_IMG, line_map * SIZE_IMG, "./cub3d");
	if (!data->mlx.mlx_win)
		return (-1);
	data->img.img = mlx_new_image(data->mlx.mx, \
		(ft_strlen(data->map[0]) - 1) * SIZE_MINI, line_map * SIZE_MINI);
	data->img.addr = mlx_get_data_addr(data->img.img, \
		&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	ft_put_image_to_win(data, line_map);
	mlx_loop(data->mlx.mx);
	return (0);
}

void	ft_cub3d(t_data *data)
{
	ft_mlx_wind(data);
}
