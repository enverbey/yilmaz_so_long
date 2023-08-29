/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:04:59 by envyilma          #+#    #+#             */
/*   Updated: 2023/08/29 14:09:45 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 20230827L

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

// -> checker
char	**checker(char *str);
char	**create_map(char *map_path, int fd);
void	free_map(char **map);
void	error_message(char *message, char **map);
int		check_game_logic(char **map);
int		is_ber(char *map);
void	get_len(char **map, int *i, int *j);
void	is_map_rectangle(char **map);

// -> main
void	so_long(char **map);

// -> movement
void	finish_game(t_vars	*vars);
void	get_size_of_coin(char **map, int *number_of_coin);
void	move_up(t_vars *vars, int x, int y);
void	move_down(t_vars *vars, int x, int y);
void	move_right(t_vars *vars, int x, int y);
void	move_left(t_vars *vars, int x, int y);
int		render_next_frame(t_vars *vars);
void	set_all_sprites(t_vars *s);
void	set_location_player(char **map, int *x, int *y);
void	put_all_image_to_mlx_window(t_vars *s);

#endif