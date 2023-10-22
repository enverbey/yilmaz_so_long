/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_location_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:48:09 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/22 13:55:11 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	set_location_player(char **map, int *x, int *y)
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

void	set_location_ghost(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'G')
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

void	set_location_(char **map, t_vars *s)
{
	set_location_player(map, &s->pac_vector_x, &s->pac_vector_y);
	set_location_ghost(map, &s->ghost_vector_x, &s->ghost_vector_y);
	s->ghost_have_coin = 0;
}
