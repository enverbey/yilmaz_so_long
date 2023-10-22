/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string_to_window.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:14:59 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/22 15:15:28 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../minilibx/mlx.h"
#include "../libft/include/libft.h"

void	put_string_to_window(t_vars *vars)
{
	char	*str;

	str = ft_itoa(vars->number_move);
	if (!str)
		finish_game(vars);
	mlx_string_put(vars->mlx, vars->mlx_win, 35, 40, 0xb0e2ff, str);
	free(str);
}
