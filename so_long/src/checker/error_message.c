/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:15:11 by envyilma          #+#    #+#             */
/*   Updated: 2023/08/29 16:50:17 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../resources/libft/include/libft.h"
#include <stdlib.h>

void	free_map(char **map)
{
	int	ecx;

	ecx = -1;
	while (++ecx, map[ecx])
	{
		free(map[ecx]);
		map[ecx] = (void *)0;
	}
	free(map);
	map = (void *)0;
}

void	error_message(char *message, char **map)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(message, 1);
	if (map)
		free_map(map);
	exit (-1);
}
