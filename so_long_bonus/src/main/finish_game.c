/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:05:03 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/22 15:12:32 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../checker/so_long_checker.h"
#include "../../include/so_long.h"
#include <stdlib.h>

static void	finsih_game_cont(t_vars	*vars)
{
	if (!!vars->coin2)
		mlx_destroy_image(vars->mlx, vars->coin2);
	if (!vars->empty)
		mlx_destroy_image(vars->mlx, vars->empty);
	if (!!vars->portal)
		mlx_destroy_image(vars->mlx, vars->portal);
	if (!!vars->ghost)
		mlx_destroy_image(vars->mlx, vars->ghost);
	if (!!vars->mlx_win)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
}

void	finish_game(t_vars	*vars)
{
	if (!!vars->map)
		free_map(vars->map);
	if (!!vars->pac_man_up)
		mlx_destroy_image(vars->mlx, vars->pac_man_up);
	if (!!vars->pac_man_down)
		mlx_destroy_image(vars->mlx, vars->pac_man_down);
	if (!!vars->pac_man_right)
		mlx_destroy_image(vars->mlx, vars->pac_man_right);
	if (!!vars->pac_man_left)
		mlx_destroy_image(vars->mlx, vars->pac_man_left);
	if (!!vars->wall)
		mlx_destroy_image(vars->mlx, vars->wall);
	if (!!vars->coin)
		mlx_destroy_image(vars->mlx, vars->coin);
	finsih_game_cont(vars);
	if (!!vars)
		free(vars);
	exit (0);
}
