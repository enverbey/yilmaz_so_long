/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_of_coin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:01:03 by envyilma          #+#    #+#             */
/*   Updated: 2023/08/29 16:39:15 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	get_size_of_coin(char **map, int *number_of_coin)
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
	*number_of_coin = result;
}
