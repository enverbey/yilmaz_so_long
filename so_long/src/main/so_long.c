/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:28:17 by envyilma          #+#    #+#             */
/*   Updated: 2023/08/29 17:34:28 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../resources/minilibx/mlx.h"
#include "../../include/so_long.h"
#include "../../../resources/libft/include/libft.h"
#include <stdlib.h>

int	key_down(int keycode, t_vars *vars)
{
	if (keycode == 53)
		finish_game(vars);
	vars->moving = keycode;
	return (0);
}

int	key_up(int keycode, t_vars *vars)
{
	(void)keycode;
	vars->moving = -1;
	return (0);
}

int	close_game(t_vars *vars)
{
	finish_game(vars);
	return (0);
}

void
	so_long(char **map)
{
	t_vars	*s;

	s = (t_vars *)malloc(sizeof(t_vars));
	s->map = map;
	get_len(map, &s->map_height, &s->map_widht);
	get_size_of_coin(map, &s->number_of_coin);
	set_location_player(map, &s->pac_vector_x, &s->pac_vector_y);
	s->mlx = mlx_init();
	s->mlx_win = mlx_new_window(s->mlx, SRPITE_SIZE * s->map_widht,
			SRPITE_SIZE * s->map_height, "Pac-Man!");
	s->speed = 0;
	s->number_move = 0;
	set_all_sprites(s);
	mlx_hook(s->mlx_win, 02, (1L << 0), key_down, s);
	mlx_hook(s->mlx_win, 03, (1L << 1), key_up, s);
	mlx_hook(s->mlx_win, 17, 0, close_game, s);
	mlx_loop_hook(s->mlx, render_next_frame, s);
	mlx_loop(s->mlx);
}
