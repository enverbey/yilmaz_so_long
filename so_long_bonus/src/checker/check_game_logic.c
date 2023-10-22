/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_logic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 00:58:20 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/22 18:40:33 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "so_long_checker.h"

void
	test_logic(char **map, int x, int y)
{
	map[x][y] = '.';
	if (map[x + 1][y] == 'E')
		map[x + 1][y] = '.';
	else if (map[x - 1][y] == 'E')
		map[x - 1][y] = '.';
	else if (map[x][y + 1] == 'E')
		map[x][y + 1] = '.';
	else if (map[x][y - 1] == 'E')
		map[x][y - 1] = '.';
	if (map[x + 1][y] == '0' || map[x + 1][y] == 'C' || map[x + 1][y] == 'G')
		test_logic(map, x + 1, y);
	if (map[x - 1][y] == '0' || map[x - 1][y] == 'C' || map[x - 1][y] == 'G')
		test_logic(map, x - 1, y);
	if (map[x][y + 1] == '0' || map[x][y + 1] == 'C' || map[x][y + 1] == 'G')
		test_logic(map, x, y + 1);
	if (map[x][y - 1] == '0' || map[x][y - 1] == 'C' || map[x][y - 1] == 'G')
		test_logic(map, x, y - 1);
}

void
	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	is_logic(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = -1;
		while (++j, map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_game_logic(char **map)
{
	int	x;
	int	y;
	int	result;

	find_player(map, &x, &y);
	test_logic(map, x, y);
	result = is_logic(map);
	free_map(map);
	return (result);
}
