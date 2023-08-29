/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:45:11 by envyilma          #+#    #+#             */
/*   Updated: 2023/08/29 19:22:06 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	get_len(char **map, int *i, int *j)
{
	*i = 0;
	*j = 0;
	while (map[*i])
		(*i)++;
	while (map[0][*j])
		(*j)++;
}

int	control_asset(char C, int last)
{
	static int	p = 0;
	static int	e = 0;
	static int	coin = 0;

	if (C == 'P')
		p++;
	else if (C == 'E')
		e++;
	else if (C == 'C')
		coin++;
	if (last == 1)
	{
		if (p != 1 || e != 1 || coin < 1)
			return (0);
		return (1);
	}
	return (2);
}

void	is_map_rectangle(char **map)
{
	int	lenght;
	int	height;
	int	i;
	int	j;

	get_len(map, &height, &lenght);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((i == 0 || i == (height - 1) || j == 0 || j == (lenght - 1)) 
				&& map[i][j] != '1')
				error_message("Map is not complere wall!!!", map);
			if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E')
				control_asset(map[i][j], 0);
			else if (map[i][j] != '1' && map[i][j] != '0')
				error_message("Unrecognized character found on the map.", map);
		}
		if (lenght != j)
			error_message("Map is not rectangular!!!", map);
	}
	if (!control_asset('x', 1))
		error_message("Not enough collectable!!", map);
}
