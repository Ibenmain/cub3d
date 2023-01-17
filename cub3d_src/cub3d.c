/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:09:42 by ibenmain          #+#    #+#             */
/*   Updated: 2023/01/17 23:16:02 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mlx_wind(t_data *data)
{
	data->len = get_line_map(data);
	data->mlx.mx = mlx_init();
	if (!data->mlx.mx)
		return (-1);
	data->mlx.mlx_win = mlx_new_window(data->mlx.mx, data->line_max \
		* SIZE_IMG, data->len * SIZE_IMG, "./cub3d");
	if (!data->mlx.mlx_win)
		return (-1);
	data->img.img = mlx_new_image(data->mlx.mx, \
		(data->line_max) * SIZE_MINI, data->len * SIZE_MINI);
	data->img.addr = mlx_get_data_addr(data->img.img, \
		&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	ft_put_image_to_win(data, data->len);
	mlx_loop(data->mlx.mx);
	return (0);
}

// void	draw_circle(t_data *data, int x, int y, int color)
// {
//     double	i;
//     double	j;
//     double	angle;
//     double	x1;
//     double	y1;

//     j = 0;
//     while (j < 5)
//     {
//         i = 0;
//         while (i < 360)
//         {
//             angle = i;
//             x1 = j * cos(angle * M_PI / 180);
//             y1 = j * sin(angle * M_PI / 180);
//             my_mlx_pixel_put(data, y + y1, x + x1, color);
//             i += 0.1;
//         }
//         j += 0.1;
//     }
// }

void	ft_player_movement(t_data *data)
{

}

void	ft_cub3d(t_data *data)
{
	ft_mlx_wind(data);
	ft_player_movement(data);
}
