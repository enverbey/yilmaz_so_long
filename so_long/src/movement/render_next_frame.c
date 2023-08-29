/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:07:40 by envyilma          #+#    #+#             */
/*   Updated: 2023/08/29 16:38:32 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../../resources/minilibx/mlx.h"

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
