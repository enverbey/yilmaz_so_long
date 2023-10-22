/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_rectangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 00:34:51 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/16 08:59:23 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

void	get_len(char **map, int *width, int *height)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[0][x])
		x++;
	while (map[y])
		y++;
	*width = x;
	*height = y;
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

int	is_map_rectangle(char **map)
{
	int	width;
	int	height;
	int	i;
	int	j;

	get_len(map, &width, &height);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((!i || i == height || !j || j == width) && map[i][j] != '1')
				return (ft_putstr("Map is not complare wall!!\n"), 0);
			if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E')
				control_asset(map[i][j], 0);
			else if (map[i][j] != '1' && map[i][j] != '0')
				return (ft_putstr("Unrecognized char found on the map.\n"), 0);
		}
		if (width != j)
			return (ft_putstr("Map is not rectangular!!!\n"), 0);
	}
	if (!control_asset('x', 1))
		return (ft_putstr("Not enough collectable!\n"), 0);
	return (1);
}
