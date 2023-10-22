/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ghost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:19:02 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/22 14:06:34 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	move_up_g(t_vars *vars, int x, int y)
{
	if (vars->map[x - 1][y] == '1' || vars->map[x - 1][y] == 'E')
		return ;
	if (vars->map[x - 1][y] == 'P')
		finish_game(vars);
	if (vars->map[x - 1][y] != '1')
	{
		if (vars->ghost_have_coin == 1)
			vars->map[x][y] = 'C';
		else
			vars->map[x][y] = '0';
		if (vars->map[x - 1][y] == 'C')
			vars->ghost_have_coin = 1;
		else
			vars->ghost_have_coin = 0;
		vars->map[x - 1][y] = 'G';
		vars->ghost_vector_x--;
	}
}

static void	move_down_g(t_vars *vars, int x, int y)
{
	if (vars->map[x + 1][y] == '1' || vars->map[x + 1][y] == 'E')
		return ;
	if (vars->map[x + 1][y] == 'P')
		finish_game(vars);
	if (vars->map[x + 1][y] != '1')
	{
		if (vars->ghost_have_coin == 1)
			vars->map[x][y] = 'C';
		else
			vars->map[x][y] = '0';
		if (vars->map[x + 1][y] == 'C')
			vars->ghost_have_coin = 1;
		else
			vars->ghost_have_coin = 0;
		vars->map[x + 1][y] = 'G';
		vars->ghost_vector_x++;
	}
}

static void	move_right_g(t_vars *vars, int x, int y)
{
	if (vars->map[x][y + 1] == '1' || vars->map[x][y + 1] == 'E')
		return ;
	if (vars->map[x][y + 1] == 'P')
		finish_game(vars);
	if (vars->map[x][y + 1] != '1')
	{
		if (vars->ghost_have_coin == 1)
			vars->map[x][y] = 'C';
		else
			vars->map[x][y] = '0';
		if (vars->map[x][y + 1] == 'C')
			vars->ghost_have_coin = 1;
		else
			vars->ghost_have_coin = 0;
		vars->map[x][y + 1] = 'G';
		vars->ghost_vector_y++;
	}
}

static void	move_left_g(t_vars *vars, int x, int y)
{
	if (vars->map[x][y - 1] == '1' || vars->map[x][y - 1] == 'E')
		return ;
	if (vars->map[x][y - 1] == 'P')
		finish_game(vars);
	if (vars->map[x][y - 1] != '1')
	{
		if (vars->ghost_have_coin == 1)
			vars->map[x][y] = 'C';
		else
			vars->map[x][y] = '0';
		if (vars->map[x][y - 1] == 'C')
			vars->ghost_have_coin = 1;
		else
			vars->ghost_have_coin = 0;
		vars->map[x][y - 1] = 'G';
		vars->ghost_vector_y--;
	}
}

void	move_ghost(t_vars *vars)
{
	int			move_direction;
	static int	speed = 0;

	if (speed != 2)
	{
		speed++;
		return ;
	}
	move_direction = simple_random();
	if (move_direction == 0)
		move_up_g(vars, vars->ghost_vector_x, vars->ghost_vector_y);
	if (move_direction == 1)
		move_down_g(vars, vars->ghost_vector_x, vars->ghost_vector_y);
	if (move_direction == 2)
		move_left_g(vars, vars->ghost_vector_x, vars->ghost_vector_y);
	if (move_direction == 3)
		move_right_g(vars, vars->ghost_vector_x, vars->ghost_vector_y);
	speed = 0;
}
