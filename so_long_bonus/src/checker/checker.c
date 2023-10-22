/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:01:53 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/16 10:10:03 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "so_long_checker.h"

char	**so_long_checker(char *str)
{
	char	*map_path;
	char	**map;
	char	**map_copy;

	if (!is_ber(str))
		return (ft_putstr_fd("Invalid file tipe\n", 1), exit(1), NULL);
	map_path = ft_strdup(str);
	if (!map_path)
		exit (1);
	create_map(map_path, &map, &map_copy);
	if (!is_map_rectangle(map))
		return (free_map(map), free_map(map_copy), exit(1), NULL);
	if (!check_game_logic(map_copy))
		return (ft_putstr("Game is not logic\n"), free_map(map), exit(1), NULL);
	return (map);
}
