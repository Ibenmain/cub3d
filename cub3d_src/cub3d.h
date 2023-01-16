/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:24:59 by ibenmain          #+#    #+#             */
/*   Updated: 2023/01/16 21:50:45 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft_cub/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# define BUFFER_SIZE 1024

# define SIZE_IMG 60
# define SIZE_MINI 15

typedef struct s_map1
{
	int		nb_dir;
	int		no_dup;
	int		so_dup;
	int		we_dup;
	int		ea_dup;
	char	*no_line;
	char	*no_path;
	char	*so_line;
	char	*so_path;
	char	*we_line;
	char	*we_path;
	char	*ea_line;
	char	*ea_path;
	char	*floor_line;
	char	*color_line;
	int		f_dup;
	int		c_dup;
}				t_map1;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_dir{
	int		n;
	int		s;
	int		w;
	int		e;
	int		x;
}		t_dir;

typedef struct s_mlx{
	void	*mx;
	void	*mlx_win;
}		t_mlx;

typedef struct s_data{
	char	**all_map;
	char	**map_dir;
	char	**map;
	int		line_map;
	int		i;
	int		j;
	int		biggest_line;
	int		val1;
	int		val2;
	int		val3;
	t_map1	map1;
	t_dir	dir;
	t_mlx	mlx;
	t_img	img;

}		t_data;

char	*get_next_line(int fd);
int		find_new_line(char *string);
char	*get_line(char *str);
char	*get_rest(char *str);
char	*ft_concat(char *s1, char *s2);
void	ft_get_map(char *name_map, t_data *data);
void	ft_map_size(char *map, t_data *data);
void	ft_divide_down_map(t_data *data);
int		ft_check_name_map(char *map_name);
void	ft_print_error(char *str, void	*data);
int		ft_check_line(char *line);
int		ft_check_error_tab(char **tab);
void	ft_get_map(char *name_map, t_data *data);
void	ft_directione(char **tab, t_data *data);
void	ft_range_of_color(char	*line, t_data *data);
void	ft_color_and_floor(char **tab, t_data *data);
void	ft_free(char	**tab);
void	ft_convert_to_int(char **tab, t_data *data);
void	ft_check_error_color(char **tab, t_data *data);
//---------------------------------------------------------
void	ft_passing_error(t_data *data, char *line);
void	ft_parssing_map(t_data *data);
void	ft_check_duplicat(t_data *data);
void	ft_get_max_line(t_data *data);
void	ft_check_redirection(t_data *data);
int		ft_check_wall(t_data *data);
char	*ft_duplicat(char *str, t_data *data);
char	*ft_dup_with_space(char *line, t_data *data);
void	ft_cub3d(t_data *data);
int		ft_mlx_wind(t_data *data);
int		get_line_map(t_data *data);
int		ft_check_spase(char *line);
int		get_line_map(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_rectangle(int x, int y, t_data *data, int color);
void	ft_put_image_to_win(t_data *data, int line_map);

#endif