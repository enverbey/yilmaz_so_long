/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:07:19 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/22 13:04:06 by envyilma         ###   ########.fr       */
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

static void
	sprites_coin(t_vars *s, int i, int j, int *k)
{
	if (*k >= 2)
		*k = 0;
	if (*k % 2 == 1)
		put_image(s, s->coin, i, j);
	else
		put_image(s, s->coin2, i, j);
}

void
	put_all_image_to_mlx_window(t_vars *s)
{
	int			i;
	int			j;
	static int	k = 0;

	k++;
	i = -1;
	while (i++, s->map[i])
	{
		j = -1;
		while (j++, s->map[i][j])
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
				sprites_coin(s, i, j, &k);
			if (s->map[i][j] == 'G')
				put_image(s, s->ghost, i, j);
		}
	}
}
