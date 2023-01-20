/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:09:42 by ibenmain          #+#    #+#             */
/*   Updated: 2023/01/21 00:58:53 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_pressed(int keycode, t_data *data)
{
	if(keycode == S)
		data->player.walkdirection = -1;
	else if(keycode == W)
		data->player.walkdirection = 1;
	else if(keycode == RIGHT_KEY)
		data->player.turndirection = -1;
	else if(keycode == LEFT_KEY)
		data->player.turndirection = 1;
	else if (keycode == A)
		data->player.sidedirection = -1;
	else if (keycode == D)
		data->player.sidedirection = 1;
	else if(keycode == ESC)
		exit(0);
	return (0);
}

int key_release(int keycode, t_data *data)
{
	if(keycode == W)
		data->player.walkdirection = 0;
	else if(keycode == S)
		data->player.walkdirection = 0;
	else if(keycode == RIGHT_KEY)
		data->player.turndirection = 0;
	else if(keycode == LEFT_KEY)
		data->player.turndirection = 0;
	else if (keycode == A)
		data->player.sidedirection = 0;
	else if (keycode == D)
		data->player.sidedirection = 0;
	return 0;
}


int	ft_mlx_wind(t_data *data)
{
	data->len = get_line_map(data);
	data->mlx.mx = mlx_init();
	if (!data->mlx.mx)
		return (-1);
	data->mlx.mlx_win = mlx_new_window(data->mlx.mx, \
		LENGHT_WIN, WIDTH_WIN, "./cub3d");
	if (!data->mlx.mlx_win)
		return (-1);
	data->img.img = mlx_new_image(data->mlx.mx, LENGHT_WIN, WIDTH_WIN);
	data->img.addr = mlx_get_data_addr(data->img.img, \
		&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	// mlx_hook(data->mlx.mlx_win, 02, 0L, &ft_player_movement, data);
	mlx_hook(data->mlx.mlx_win, 2 ,1L<<0 ,key_pressed, data);//key press hook
	mlx_hook(data->mlx.mlx_win,03 ,1L<<1 , key_release, data);// key realas hook
	mlx_loop_hook(data->mlx.mx, &ft_player_movement, data);
	mlx_loop(data->mlx.mx);
	return (0);
}

void	draw_circle(t_data *data, int x, int y, int color)
{
	double	i;
	double	j;
	double	angle;
	double	x1;
	double	y1;

	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 360)
		{
			angle = i;
			x1 = j * cos(angle * M_PI / 180);
			y1 = j * sin(angle * M_PI / 180);
			my_mlx_pixel_put(data, y + y1, x + x1, color);
			i += 0.1;
		}
		j += 0.1;
	}
}

void	draw_line(t_data *data, int x, int y, int color)
{
	double	i;
	double	j;
	double	x1;
	double	y1;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 2)
		{
			x1 = j * cos(data->player.rotationangl) * 5;
			y1 = j * sin(data->player.rotationangl) * 5;
			my_mlx_pixel_put(data, y + y1, x + x1, color);
			i += 0.1;
		}
		j += 0.1;
	}
}

void	ft_player_up(t_data *data)
{
	double	movestep;

	// data->player.walkdirection = 1; /*-1 if back, +1 if front*/
	movestep = data->player.movespeed * data->player.walkdirection;
	data->player.i += cos(data->player.rotationangl) * movestep;
	data->player.j += sin(data->player.rotationangl) * movestep;
	// data->player.walkdirection = 0;
}

void	ft_player_down(t_data *data)
{
	double	movestep;

	// data->player.walkdirection = -1;
	movestep = data->player.movespeed * data->player.walkdirection;
	data->player.i += cos(data->player.rotationangl) * movestep;
	data->player.j += sin(data->player.rotationangl) * movestep;
	// data->player.walkdirection = 0;
}

// void	ft_player_left(t_data *data)
// {
// 	double	movestep;

// 	data->player.turndirection = 1;
//	data->player.rotationangl += data->player.turndirection * data->player.rotationspeed;
// 	movestep = data->player.movespeed * data->player.walkdirection;
// 	data->player.i += cos(data->player.rotationangl) * movestep;
// 	data->player.j += sin(data->player.rotationangl) * movestep;
// 	data->player.turndirection = 0;
// }

void	ft_player_left(t_data *data)
{
	// data->player.sidedirection = -1;
	data->player.i += cos(data->player.rotationangl \
		+ 90 * (M_PI / 180)) * data->player.movespeed;
	data->player.j += sin(data->player.rotationangl \
		+ 90 * (M_PI / 180)) * data->player.movespeed;
	// data->player.sidedirection = 0;
}

void	ft_player_right(t_data *data)
{
	// data->player.sidedirection = -1;
	double angle =  90 * (M_PI / 180);
	angle *= data->player.sidedirection;
	
	data->player.i += cos(data->player.rotationangl \
		+ angle) * data->player.movespeed;
	data->player.j += sin(data->player.rotationangl \
		+ angle) * data->player.movespeed;
	// data->player.sidedirection = 0;
}

int	ft_player_movement(t_data *data)
{
	if (data->player.walkdirection != 0)
		ft_player_up(data);
	// if (data->player.walkdirection == -1)
	// 	ft_player_down(data);
	// if (data->player.sidedirection == -1)
	// 	ft_player_left(data);
	if (data->player.sidedirection != 0)
		ft_player_right(data);
	if (data->player.turndirection != 0)
		data->player.rotationangl += data->player.rotationspeed * data->player.turndirection;
	// if (data->player.turndirection == -1)
	// 	data->player.rotationangl += data->player.rotationspeed * data->player.turndirection;
	ft_put_image_to_win(data);
	return (0);
}

void	ft_cub3d(t_data *data)
{
	ft_data_player(data);
	ft_mlx_wind(data);
}
