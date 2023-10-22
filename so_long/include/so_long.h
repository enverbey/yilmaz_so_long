/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:11:23 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/16 12:12:51 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SRPITE_SIZE 32
# define IMAGE_HEIGHT 32
# define IMAGE_HEIGHT 32

typedef struct s_vars{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*pac_man;
	void	*pac_man_up;
	void	*pac_man_down;
	void	*pac_man_right;
	void	*pac_man_left;
	void	*wall;
	void	*portal;
	void	*coin;
	void	*empty;
	int		pac_vector_x;
	int		pac_vector_y;
	int		moving;
	int		speed;
	int		number_move;
	int		number_of_coin;
	int		map_height;
	int		map_widht;
}	t_vars;

// -> main
void	so_long(char **map);
int		get_size_of_coin(char **map);
void	set_location_player(char **map, int *x, int *y);
void	set_all_sprites(t_vars *s);
void	finish_game(t_vars	*vars);
void	put_all_image_to_mlx_window(t_vars *s);
// -> movement
void	move_left(t_vars *vars, int x, int y);
void	move_right(t_vars *vars, int x, int y);
void	move_down(t_vars *vars, int x, int y);
void	move_up(t_vars *vars, int x, int y);

#endif