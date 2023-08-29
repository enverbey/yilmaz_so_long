/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:57:01 by envyilma          #+#    #+#             */
/*   Updated: 2023/08/29 16:40:34 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../resources/libft/src/ft_printf/ft_printf.h"
#include "../../include/so_long.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		so_long(checker(av[1]));
	}
	else if (ac != 2)
		ft_printf("Error\nWrong argumen number !!");
	return (0);
}
