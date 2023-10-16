/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:49:45 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/16 10:15:03 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../checker/so_long_checker.h"
#include "../../include/so_long.h"

int	main(int ac, char **av)
{
	if (ac == 2)
		so_long(so_long_checker(av[1]));
	else if (ac != 2)
		return (ft_putstr("Error\nWrong argumen number !!"), 1);
	return (0);
}
