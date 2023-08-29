/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:08:11 by envyilma          #+#    #+#             */
/*   Updated: 2023/08/29 16:53:17 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../resources/libft/include/libft.h"
#include "../../include/so_long.h"
#include <fcntl.h>
#include <stdlib.h>

char	**copy_map(char **map)
{
	char	**copy;
	int		i;
	int		j;
	int		x;

	x = 0;
	get_len(map, &i, &j);
	copy = (char **)malloc(sizeof(char *) * (i + 1));
	while (map[x])
	{
		copy[x] = (char *)malloc(sizeof(char) * (j + 1));
		ft_strlcpy(copy[x], map[x], (j + 1));
		x++;
	}
	copy[x] = NULL;
	return (copy);
}

char	**checker(char *str)
{
	int		fd;
	char	*map_path;
	char	**map;

	map_path = ft_strjoin("../resources/map/", str);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (free(map_path), error_message("Map not found", NULL), NULL);
	if (!is_ber(str))
		error_message("Invalid file tipe", 0);
	map = create_map(map_path, fd);
	is_map_rectangle(map);
	if (!check_game_logic(copy_map(map)))
		error_message("Map is not logic!!", map);
	free(map_path);
	return (map);
}
