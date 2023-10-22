/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_of_coin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:45:44 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/16 11:47:02 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_size_of_coin(char **map)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	result = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				result++;
			j++;
		}
		i++;
	}
	return (result);
}
