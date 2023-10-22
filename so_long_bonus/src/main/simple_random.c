/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_random.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:05:22 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/22 15:48:24 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int	simple_random(void)
{
	static double	seed = 1.0;
	int				number;

	seed = fmod(seed * 16807, 2147483647);
	number = ((seed / 2147483647.0) * 100000);
	return (number % 4);
}
