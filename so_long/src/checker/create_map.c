/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:27:45 by envyilma          #+#    #+#             */
/*   Updated: 2023/08/29 16:52:48 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../resources/libft/src/get_next_line/get_next_line.h"
#include "../../include/so_long.h"
#include <unistd.h>
#include <stdlib.h>

char	**create_map(char *map_path, int fd)
{
	char	*tmp;
	char	*line;
	char	*line2;
	char	**map;

	tmp = get_next_line(fd);
	if (!tmp)
		return (free(map_path), close(fd), error_message("Empty!", 0), NULL);
	line = ((void *)0);
	while (tmp)
	{
		line2 = ft_strjoin(line, tmp);
		free(line);
		free(tmp);
		tmp = get_next_line(fd);
		if (line2)
			line = ft_strdup(line2);
		free(line2);
	}
	map = ft_split(line2, '\n');
	free(line);
	close (fd);
	if (!map)
		return (error_message("Map not splited!!!", 0), NULL);
	return (map);
}
