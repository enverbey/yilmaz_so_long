/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_checker.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 23:04:54 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/16 10:53:54 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_CHECKER_H
# define SO_LONG_CHECKER_H

char	**so_long_checker(char *str);
int		is_ber(char *str);
void	create_map(char *map_path, char ***map1, char ***map2);
void	free_map(char **map);
int		is_map_rectangle(char **map);
int		check_game_logic(char **map);
void	get_len(char **map, int *width, int *height);

#endif