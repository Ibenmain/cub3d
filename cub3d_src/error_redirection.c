/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:11:02 by ibenmain          #+#    #+#             */
/*   Updated: 2023/01/14 23:12:32 by ibenmain         ###   ########.fr       */
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

int	ft_check_character(char c)
{
	if (c != '0' && c != '1' && c != ' ' && c != 'N' \
		&& c != 'S' && c != 'W' && c != 'E')
		return (1);
	return (0);
}

void	ft_check_wall_backgroun(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_check_character(data->map[i][j]))
				ft_print_error("Error: invalid character", data);
			j++;
		}
		i++;
	}
}

void	ft_check_redirection(t_data *data)
{
	if (ft_check_wall(data))
		ft_print_error("error 1...", data);
	ft_check_wall_backgroun(data);
	// ft_check_(data);
	// ft_check_backbground(data);
}
