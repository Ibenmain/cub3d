/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_up_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:02:29 by ibenmain          #+#    #+#             */
/*   Updated: 2023/01/08 00:58:57 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_error(char *str, void	*data)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	free(data);
	exit(1);
}

int	ft_check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == '1')
		i++;
	if (line[i + 1] == '\0')
		return (1);
	return (0);
}

void	ft_divide_up_map(t_data *data)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	data->map_dir = (char **)malloc(sizeof(char *) * (data->map1.nb_dir + 1));
	if (!data->map_dir)
		ft_print_error("Error allocation\n", data);
	while (data->all_map[i] || k < data->map1.nb_dir)
	{
		j = 0;
		if (data->all_map[i][0] != '\n')
		{
			while (data->all_map[i][j] == ' ')
				j++;
			if (ft_check_line(data->all_map[i] + j))
			{
				data->map_dir[k] = NULL;
				break ;
			}
			data->map_dir[k++] = data->all_map[i];
		}
		i++;
	}
}

void	ft_size_divide_map(t_data *data)
{
	int		j;

	data->i = 0;
	data->map1.nb_dir = 0;
	while (data->all_map[data->i])
	{
		j = 0;
		if (data->all_map[data->i][0] != '\n')
		{
			while (data->all_map[data->i][j] == ' ')
				j++;
			if (ft_check_line(data->all_map[data->i] + j))
				break ;
			data->map1.nb_dir += 1;
		}
		data->i++;
	}
}

void	ft_divide_down_map(t_data *data)
{
	int		j;
	int		k;

	data->map = (char **)malloc(sizeof(char *) * \
		((data->line_map - data->i) + 1));
	if (!data->map)
		ft_print_error("Error allocation", data);
	k = 0;
	while (data->all_map[data->i])
	{
		j = 0;
		data->map[k] = data->all_map[data->i];
		k++;
		data->i++;
	}
	data->map[k] = NULL;
}
