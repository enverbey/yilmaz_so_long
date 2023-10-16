/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 23:46:00 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/16 12:50:31 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "so_long_checker.h"
#include <fcntl.h>
#include <unistd.h>

static void	exit_situation(int fd, char *line, char *map_path)
{
	free(map_path);
	if (line)
		free(line);
	close(fd);
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

char	*create_map_line(char *map_path)
{
	int		fd;
	int		i;
	char	line[10];
	char	*join;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("File could not be read\n", 1), NULL);
	i = read(fd, line, 9);
	line[i] = '\0';
	join = NULL;
	while (i)
	{
		join = ft_strjoin_free(join, line);
		if (!join)
			exit_situation(fd, line, map_path);
		i = read(fd, line, 9);
		line[i] = '\0';
	}
	return (free(map_path), close(fd), join);
}

void	create_map(char *map_path, char ***map1, char ***map2)
{
	char	*line;

	line = create_map_line(map_path);
	if (!line)
		return (ft_putstr_fd("Error\n", 1), exit(1));
	*map1 = my_split(line, '\n');
	if (!(*map1))
		return (free(line), ft_putstr_fd("Error\n", 1), exit(1));
	*map2 = my_split(line, '\n');
	if (!(*map2))
		return (free(line), free_map(*map1), \
			ft_putstr_fd("Error\n", 1), exit(1));
	free(line);
}
