/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_all_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:58:34 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/22 14:47:47 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../../include/so_long.h"
#include "../libft/include/libft.h"

static void
	set_all_sprites_cont(t_vars *s)
{
	int	i;
	int	j;

	s->coin = mlx_xpm_file_to_image(s->mlx,
			"./src/Sprites/Other/Pacdots/pacdot_food.xpm", &i, &j);
	s->coin2 = mlx_xpm_file_to_image(s->mlx,
			"./src/Sprites/Other/Pacdots/pacdot_powerup.xpm", &i, &j);
	s->empty = mlx_xpm_file_to_image(s->mlx,
			"./src/Sprites/Other/Walls/black.xpm", &i, &j);
	s->ghost = mlx_xpm_file_to_image(s->mlx,
			"./src/Sprites/Ghosts/B/ghost_up1.xpm", &i, &j);
}

void
	set_all_sprites(t_vars *s)
{
	int	i;
	int	j;

	s->pac_man_up = mlx_xpm_file_to_image(s->mlx,
			"./src/Sprites/Pac-Man/pac_semi_up.xpm", &i, &j);
	s->pac_man_down = mlx_xpm_file_to_image(s->mlx,
			"./src/Sprites/Pac-Man/pac_semi_down.xpm", &i, &j);
	s->pac_man_right = mlx_xpm_file_to_image(s->mlx,
			"./src/Sprites/Pac-Man/pac_semi_right.xpm", &i, &j);
	s->pac_man_left = mlx_xpm_file_to_image(s->mlx,
			"./src/Sprites/Pac-Man/pac_semi_left.xpm", &i, &j);
	s->wall = mlx_xpm_file_to_image(s->mlx,
			"./src/Sprites/Other/Walls/wall.xpm", &i, &j);
	s->portal = mlx_xpm_file_to_image(s->mlx,
			"./src/Sprites/Other/Portal/portal.xpm", &i, &j);
	set_all_sprites_cont(s);
	if (!s->pac_man_up || !s->pac_man_down || !s->pac_man_right
		|| !s->pac_man_left || !s->wall || !s->portal
		|| !s->coin || !s->coin2 || !s->empty || !s->ghost)
		return (ft_putstr("Some xpm file can't open\n"), finish_game(s));
	s->pac_man = s->pac_man_right;
}
