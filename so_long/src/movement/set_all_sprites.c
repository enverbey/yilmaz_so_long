/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_all_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:01:39 by envyilma          #+#    #+#             */
/*   Updated: 2023/08/29 16:37:58 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../resources/minilibx/mlx.h"
#include "../../include/so_long.h"

void
	set_all_sprites(t_vars *s)
{
	int	i;
	int	j;

	s->pac_man_up = mlx_xpm_file_to_image(s->mlx, 
			"../resources/Sprites/Pac-Man/pac_semi_up.xpm", &i, &j);
	s->pac_man_down = mlx_xpm_file_to_image(s->mlx, 
			"../resources/Sprites/Pac-Man/pac_semi_down.xpm", &i, &j);
	s->pac_man_right = mlx_xpm_file_to_image(s->mlx, 
			"../resources/Sprites/Pac-Man/pac_semi_right.xpm", &i, &j);
	s->pac_man_left = mlx_xpm_file_to_image(s->mlx, 
			"../resources/Sprites/Pac-Man/pac_semi_left.xpm", &i, &j);
	s->wall = mlx_xpm_file_to_image(s->mlx, 
			"../resources/Sprites/Other/Walls/wall.xpm", &i, &j);
	s->portal = mlx_xpm_file_to_image(s->mlx, 
			"../resources/Sprites/Other/Portal/portal.xpm", &i, &j);
	s->coin = mlx_xpm_file_to_image(s->mlx, 
			"../resources/Sprites/Other/Pacdots/pacdot_food.xpm", &i, &j);
	s->empty = mlx_xpm_file_to_image(s->mlx, 
			"../resources/Sprites/Other/Walls/black.xpm", &i, &j);
	s->pac_man = s->pac_man_right;
}
