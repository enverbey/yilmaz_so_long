/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ber.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:19:02 by envyilma          #+#    #+#             */
/*   Updated: 2023/08/29 16:40:53 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../resources/libft/include/libft.h"

int	is_ber(char *map)
{
	int	i;

	i = ft_strlen(map) - 1;
	if (i < 4)
		return (0);
	if (map[i] == 'r' && map[i - 1] == 'e' 
		&& map[i - 2] == 'b' && map[i - 3 == '.'])
		return (1);
	return (0);
}
