/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:07:19 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/16 12:13:05 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../../include/so_long.h"

void
	put_image(t_vars *s, void *image, int i, int j)
{
	mlx_put_image_to_window(s->mlx, s->mlx_win, image,
		j * SRPITE_SIZE, i * SRPITE_SIZE);
}

void
	put_all_image_to_mlx_window(t_vars *s)
{
	int	i;
	int	j;

	i = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (s->map[i][j] == '1')
				put_image(s, s->wall, i, j);
			if (s->map[i][j] == '0')
				put_image(s, s->empty, i, j);
			if (s->map[i][j] == 'P')
				put_image(s, s->pac_man, i, j);
			if (s->map[i][j] == 'E')
				put_image(s, s->portal, i, j);
			if (s->map[i][j] == 'C')
				put_image(s, s->coin, i, j);
			j++;
		}
		i++;
	}
}
