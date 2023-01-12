/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_up_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:02:29 by ibenmain          #+#    #+#             */
/*   Updated: 2023/01/12 21:28:13 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_max_line(t_data *data)
{
	int	start;

	start = data->i;
	data->biggest_line = 0;
	while (data->all_map[start])
	{
		if (ft_strlen(data->all_map[start]) > data->biggest_line)
			data->biggest_line = ft_strlen(data->all_map[start]);
		start++;
	}
}

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
	if (i && line[i] == '\n')
		return (1);
	return (0);
}

void	ft_parssing_map(t_data *data)
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
			{
				break ;
			}
			ft_passing_error(data, data->all_map[data->i] + j);
			data->map1.nb_dir += 1;
		}
		data->i++;
	}
}

// void	ft_get_space(tab, data)

char	*ft_duplicat(char *str, t_data *data)
{
	char	*tab;
	int		i;

	tab = (char *)malloc(sizeof(char) * data->biggest_line);
	if (!tab)
		ft_print_error("error allocation", data);
	i = 0;
	while (str[i] != '\n')
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_dup_with_space(char *line, t_data *data)
{
	char	*tab;
	int		i;
	int		len;
	int		j;

	tab = (char *)malloc(sizeof(char *) * data->biggest_line);
	if (!tab)
		ft_print_error("error allocation", data);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			j = i;
			len = ft_strlen(tab);
			while (j < data->biggest_line - 1)
				tab[j++] = ' ';
			tab[j] = '\0';
		}
		else
			tab[i] = line[i];
		i++;
	}
	return (tab);
}

char	*ft_line(char *line, t_data *data)
{
	char	*tab;

	tab = NULL;
	if (ft_strlen(line) == data->biggest_line)
	{
		tab = ft_strdup(line);
	}
	return (tab);
}

char	*ft_check_size_line(char	*line, t_data *data)
{
	char	*tab;
	if (ft_strlen(line) == data->biggest_line)
	{
		tab = ft_duplicat(line, data);
	}
	else if (line[ft_strlen(line)] == '\n')
	{
		tab = ft_dup_with_space(line, data);
	}
	else
	{
		tab = ft_line(line, data);
	}
	return (tab);
}

void	ft_divide_down_map(t_data *data)
{
	int		k;

	data->map = (char **)malloc(sizeof(char *) * \
		((data->line_map - data->i) + 1));
	if (!data->map)
		ft_print_error("Error allocation", data);
	k = 0;
	while (data->all_map[data->i])
	{
		data->map[k] = ft_check_size_line(data->all_map[data->i], data);
		k++;
		data->i++;
	}
	data->map[k] = NULL;
}
