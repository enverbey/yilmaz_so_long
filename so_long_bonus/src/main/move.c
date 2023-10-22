/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:08:51 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/22 14:42:21 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../libft/include/libft.h"
#include "../minilibx/mlx.h"

void	move_up(t_vars *vars, int x, int y)
{
	if ((vars->map[x - 1][y] == 'E' && vars->number_of_coin == 0) \
		|| vars->map[x - 1][y] == 'G')
		finish_game(vars);
	else if (vars->map[x - 1][y] == 'E')
		return ;
	if (vars->map[x - 1][y] != '1')
	{
		if (vars->map[x - 1][y] == 'C')
			vars->number_of_coin--;
		vars->pac_man = vars->pac_man_up;
		vars->number_move++;
		vars->map[x][y] = '0';
		vars->map[x - 1][y] = 'P';
		vars->pac_vector_x--;
	}
}

void	move_down(t_vars *vars, int x, int y)
{
	if ((vars->map[x + 1][y] == 'E' && vars->number_of_coin == 0) \
		|| vars->map[x + 1][y] == 'G')
		finish_game(vars);
	else if (vars->map[x + 1][y] == 'E')
		return ;
	if (vars->map[x + 1][y] != '1')
	{
		if (vars->map[x + 1][y] == 'C')
			vars->number_of_coin--;
		vars->pac_man = vars->pac_man_down;
		vars->number_move++;
		vars->map[x][y] = '0';
		vars->map[x + 1][y] = 'P';
		vars->pac_vector_x++;
	}
}

void	move_right(t_vars *vars, int x, int y)
{
	if ((vars->map[x][y + 1] == 'E' && vars->number_of_coin == 0) \
		|| vars->map[x][y + 1] == 'G')
		finish_game(vars);
	else if (vars->map[x][y + 1] == 'E')
		return ;
	if (vars->map[x][y + 1] != '1')
	{
		if (vars->map[x][y + 1] == 'C')
			vars->number_of_coin--;
		vars->number_move++;
		vars->pac_man = vars->pac_man_right;
		vars->map[x][y] = '0';
		vars->map[x][y + 1] = 'P';
		vars->pac_vector_y++;
	}
}

void	move_left(t_vars *vars, int x, int y)
{
	if ((vars->map[x][y - 1] == 'E' && vars->number_of_coin == 0) \
		|| vars->map[x][y - 1] == 'G')
		finish_game(vars);
	else if (vars->map[x][y - 1] == 'E')
		return ;
	if (vars->map[x][y - 1] != '1')
	{
		if (vars->map[x][y - 1] == 'C')
			vars->number_of_coin--;
		vars->pac_man = vars->pac_man_left;
		vars->number_move++;
		vars->map[x][y] = '0';
		vars->map[x][y - 1] = 'P';
		vars->pac_vector_y--;
	}
}
