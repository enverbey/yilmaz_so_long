/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:34:46 by envyilma          #+#    #+#             */
/*   Updated: 2023/08/29 16:39:30 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../resources/minilibx/mlx.h"
#include "../../include/so_long.h"
#include <stdlib.h>

void	finish_game(t_vars	*vars)
{
	free_map(vars->map);
	mlx_destroy_image(vars->mlx, vars->pac_man_up);
	mlx_destroy_image(vars->mlx, vars->pac_man_down);
	mlx_destroy_image(vars->mlx, vars->pac_man_right);
	mlx_destroy_image(vars->mlx, vars->pac_man_left);
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->coin);
	mlx_destroy_image(vars->mlx, vars->empty);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	free(vars);
	exit (0);
}
