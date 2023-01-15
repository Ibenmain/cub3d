/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:11:02 by ibenmain          #+#    #+#             */
/*   Updated: 2023/01/15 14:34:14 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_wall(t_data *data)
{
	char	*line;
	char	*line2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = data->map[0];
	line2 = data->map[data->j - 1];
	while (line[i] && line2[j])
	{
		if ((line[i] != '1' && line[i] != ' ') \
			|| (line2[j] != '1' && line2[j] != ' '))
			return (1);
		i++;
		j++;
	}
	return (0);
}

int	ft_check_character(char c, t_data *data)
{
	if (c == 'N')
		data->dir.N += 1;
	else if (c == 'S')
		data->dir.S += 1;
	else if (c == 'W')
		data->dir.W += 1;
	else if (c == 'E')
		data->dir.E += 1;
	if (c != '0' && c != '1' && c != ' ' && c != 'N' \
		&& c != 'S' && c != 'W' && c != 'E')
		return (1);
	return (0);
}

void	ft_check_char_dup(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_check_character(data->map[i][j], data))
				ft_print_error("Error: invalid character", data);
			j++;
		}
		i++;
	}
}

void	ft_check_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0' && (data->map[i][j - 1] == ' ' \
				|| data->map[i][j + 1] == ' ' || data->map[i - 1][j] == ' ' \
					|| data->map[i + 1][j] == ' '))
				ft_print_error("Error: invalid character (spaces)", data);
			j++;
		}
		i++;
	}
}

void	ft_check_redirection(t_data *data)
{
	if (ft_check_wall(data))
		ft_print_error("Error: invalid map", data);
	ft_check_char_dup(data);
	ft_check_background(data);
}
