/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:12:10 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/16 12:59:19 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../checker/so_long_checker.h"
#include "../../include/so_long.h"
#include <stdlib.h>
#include <stdio.h>

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

int
	render_next_frame(t_vars *vars)
{
	int	x;
	int	y;

	if (vars->speed != 800)
	{
		vars->speed++;
		return (0);
	}
	x = vars->pac_vector_x;
	y = vars->pac_vector_y;
	if (vars->moving == 2)
		move_right(vars, x, y);
	else if (vars->moving == 0)
		move_left(vars, x, y);
	else if (vars->moving == 1)
		move_down(vars, x, y);
	else if (vars->moving == 13)
		move_up (vars, x, y);
	vars->speed = 0;
	mlx_clear_window(vars->mlx, vars->mlx_win);
	put_all_image_to_mlx_window(vars);
	return (0);
}

void	so_long(char **map)
{
	t_vars	*s;

	s = (t_vars *)malloc(sizeof(t_vars));
	if (!s)
		return (free_map(map), exit(1));
	s->map = map;
	get_len(map, &s->map_widht, &s->map_height);
	s->number_of_coin = get_size_of_coin(map);
	set_location_player(map, &s->pac_vector_x, &s->pac_vector_y);
	s->mlx = mlx_init();
	if (!s->mlx)
		return (free_map(map), exit(1));
	s->mlx_win = mlx_new_window(s->mlx, SRPITE_SIZE * s->map_widht, \
		SRPITE_SIZE * s->map_height, "Pac-Man!");
	if (!s->mlx_win)
		return (free_map(map), free(s));
	s->speed = 0;
	s->number_move = 0;
	s->moving = -1;
	set_all_sprites(s);
	mlx_hook(s->mlx_win, 02, (1L << 0), key_down, s);
	mlx_hook(s->mlx_win, 03, (1L << 1), key_up, s);
	mlx_hook(s->mlx_win, 17, 0, close_game, s);
	mlx_loop_hook(s->mlx, render_next_frame, s);
	mlx_loop(s->mlx);
}
