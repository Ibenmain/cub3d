/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_up_map1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:03:37 by ibenmain          #+#    #+#             */
/*   Updated: 2023/01/08 13:24:32 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_map(char *name_map, t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	data->all_map = (char **)malloc(sizeof(char *) * (data->line_map + 1));
	if (!data->all_map)
		ft_print_error("Error allocation\n", data);
	fd = open(name_map, O_RDONLY);
	if (fd == -1)
		ft_print_error("can't open file\n", data);
	i = -1;
	line = get_next_line(fd);
	while (++i < data->line_map)
	{
		data->all_map[i] = line;
		line = get_next_line(fd);
	}
	data->all_map[i] = NULL;
	free(line);
	close(fd);
}

void	ft_range_of_color(char	*line, t_data *data)
{
	char	**tab;

	tab = ft_split(line, ',');
	if ((ft_atoi(tab[0]) < 0 || ft_atoi(tab[0]) > 255) || \
		(ft_atoi(tab[1]) < 0 || ft_atoi(tab[1]) > 255) || \
		(ft_atoi(tab[2]) < 0 || ft_atoi(tab[2]) > 255))
		ft_print_error("Error map", data);
	data->val1 = ft_atoi(tab[0]);
	data->val2 = ft_atoi(tab[1]);
	data->val3 = ft_atoi(tab[2]);
}

void	ft_color_and_floor(char **tab, t_data *data)
{
	if (!ft_strcmp(tab[0], "F") && ft_strlen(tab[0]) == 1)
	{
		data->map1.floor_line = tab[0];
		ft_range_of_color(tab[1], data);
	}
	else if (!ft_strcmp(tab[0], "C") && ft_strlen(tab[0]) == 1)
	{
		data->map1.color_line = tab[0];
		ft_range_of_color(tab[1], data);
	}
}

void	ft_directione(char **tab, t_data *data)
{
	if (!ft_strcmp(tab[0], "NO") && ft_strlen(tab[0]) == 2)
	{
		data->map1.no_line = tab[0];
		data->map1.no_path = tab[1];
		data->map1.no_dup += 1;
	}
	else if (!ft_strcmp(tab[0], "SO") && ft_strlen(tab[0]) == 2)
	{
		data->map1.so_line = tab[0];
		data->map1.so_path = tab[1];
		data->map1.so_dup += 1;
	}
	else if (!ft_strcmp(tab[0], "WE") && ft_strlen(tab[0]) == 2)
	{
		data->map1.we_line = tab[0];
		data->map1.we_path = tab[1];
		data->map1.we_dup += 1;
	}
	else if (!ft_strcmp(tab[0], "EA") && ft_strlen(tab[0]) == 2)
	{
		data->map1.ea_line = tab[0];
		data->map1.ea_path = tab[1];
		data->map1.ea_dup += 1;
	}
	ft_color_and_floor(tab, data);
}

void	ft_check_error_map_dir(t_data *data)
{
	int		i;
	char	**tab;

	i = 0;
	if (data->map1.nb_dir != 6)
		ft_print_error("Error map!", data);
	while (data->map_dir[i] && i < data->map1.nb_dir)
	{
		tab = ft_split(data->map_dir[i], ' ');
		if (ft_check_error_tab(tab) != 2)
		{
			ft_free(tab);
			ft_print_error("unvalid map\n", data);
		}
		ft_directione(tab, data);
		i++;
	}
}
