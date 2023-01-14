/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_up_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:37:57 by ibenmain          #+#    #+#             */
/*   Updated: 2023/01/14 23:16:43 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_range_of_color(char *line, t_data *data)
{
	char	**tab;
	char	*path;
	int		len;

	path = ft_strcpy(line);
	tab = ft_split(path, ',');
	ft_check_error_color(tab, data);
	ft_convert_to_int(tab, data);
	len = ft_check_error_tab(tab);
	if (len != 3)
		ft_print_error("Error: the number of RGB\
 must be three separated by comma", data);
	data->val1 = ft_atoi(tab[0]);
	data->val2 = ft_atoi(tab[1]);
	data->val3 = ft_atoi(tab[2]);
}

void	ft_color_and_floor(char **tab, t_data *data)
{
	if (!ft_strcmp(tab[0], "F"))
	{
		data->map1.floor_line = tab[0];
		data->map1.f_dup += 1;
		ft_range_of_color(tab[1], data);
	}
	else if (!ft_strcmp(tab[0], "C"))
	{
		data->map1.color_line = tab[0];
		data->map1.c_dup += 1;
		ft_range_of_color(tab[1], data);
	}
	else
		ft_print_error("Error: some characters is wrong\n", data);
}
