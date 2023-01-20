/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:59:01 by ibenmain          #+#    #+#             */
/*   Updated: 2023/01/20 19:27:00 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_data_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '0' && data->map[i][j] != '1' \
				&& data->map[i][j] != ' ')
			{
				data->player.i = i * TILE_SIZE + TILE_SIZE / 2;
				data->player.j = j * TILE_SIZE + TILE_SIZE / 2;
				break ;
			}
			j++;
		}
		i++;
	}
}
