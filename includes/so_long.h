/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:41:10 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/23 11:42:39 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* Libraries Core */
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
/* Libraries External */
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

/* Define variables */
# define KEY_ESC 53
# define KEY_E 14

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define CELL_SIZE 32

# define DOWN 0
# define LEFT 1
# define RIGHT 3
# define UP	2

/* Structures */
typedef struct s_vector2D
{
	int				width;
	int				height;
}				t_vector2D;

typedef struct s_info
{
	int				e;
	int				c;
}				t_info;

typedef struct s_positions
{
	int				*w;
	int				*h;
}				t_positions;

typedef struct s_build_image
{
	int				width;
	t_vector2D		start;
	int				height;
}				t_build_image;

typedef struct s_queue
{
	int				w;
	int				h;
	struct s_queue	*next;
	char			*direction;
}				t_queue;

typedef struct s_checks_map
{
	int				exit;
	int				item;
	int				start;
	int				enemies;
	t_vector2D		start_pos;
}				t_checks_map;

typedef struct s_direction
{
	int				west;
	int				east;
	int				north;
	int				south;
}				t_direction;

typedef struct s_sprite
{
	void			*img;
	char			*addr;
	int				width;
	int				endian;
	int				height;
	int				line_length;
	int				bits_per_pixel;
}				t_sprite;

typedef struct s_sprites
{
	t_sprite		*sprites_up;
	t_sprite		*sprites_idle;
	t_sprite		*sprites_left;
	t_sprite		*sprites_right;
}				t_sprites;

typedef struct s_player
{
	t_vector2D		pos;
	int				frame;
	int				steps;
	t_sprites		sprites;
	int				turns_frz;
	int				direction;
}				t_player;

typedef struct s_enemy
{
	t_vector2D		pos;
	int				frame;
	int				direction;
}				t_enemy;

typedef struct s_game
{
	t_positions		d;
	int				win;
	long long		time;
	void			*mlx;
	char			**map;
	int				items;
	void			*windx;
	t_player		player;
	t_collect		*alloc;
	int				enemies;
	int				width_map;
	int				**visited;
	int				game_over;
	t_enemy			*enemy_lst;
	t_collect		*alloc_img;
	int				height_map;
	int				uses_freeze;
	t_sprite		*sprites_map;
	t_sprites		sprites_enemy;
}				t_game;

/* Game errors */
void		map_errors(int error);
void		game_errors(int error);
void		general_errors(int error);
/* Game free */
int			close_window(t_game *game);
void		on_destroy(t_game *game, int code);
/* Game utils */
int			set_state(t_game *game);
size_t		get_width(const char *str);
int			safe(int height, int width, int i, int j);
int			ft_strcmp(const char *s1, const char *s2);
/* Game utils 2 */
int			refresh(t_game *game);
t_sprite	render_player(t_game *game);
int			create_trgb(int t, int r, int g, int b);
/* Game map */
int			parse_map(t_game *game, const char *path);
/* Game map utils */
int			invalid_map(t_game *game, t_checks_map *checks_map, char **map);
/* Game resolver */
int			resolve(t_game *game);
/* Game init */
void		set_map(t_game *game);
int			init_game(t_game *game);
int			upload_sprites(t_game *game);
int			key_hook(int keycode, t_game *game);
/* Game init utils */
void		set_blocks(t_game *game, t_vector2D start,
				char *buffer, t_sprite *map);
void		set_objects(t_game *game, t_vector2D start,
				char *buffer, t_sprite *map);
/* Game init utils 2 */
void		set_hud(t_game *game);
void		set_game(t_game *game);
t_sprite	create_sprite(t_game *game, char *path);
t_sprite	render_enemy(t_game *game, t_vector2D pos_enemy);
/* Game init utils 3 */
void		refresh_frame(t_game *game);
/* Game sprites */
t_sprite	*player_up(t_game *game);
t_sprite	*player_left(t_game *game);
t_sprite	*player_idle(t_game *game);
t_sprite	*player_right(t_game *game);
t_sprite	*generate_map(t_game *game);
/* Game sprites 2 */
t_sprite	*enemy_up(t_game *game);
t_sprite	*enemy_left(t_game *game);
t_sprite	*enemy_idle(t_game *game);
t_sprite	*enemy_right(t_game *game);
/* Game movement */
int			movement(t_game *game, char *direction);
/* Game movement utils */
int			next_move_player(t_game *game, int height, int width);
/* Game enem movement */
int			move_enemies(t_game *game);
/* Game enem movement utils */
int			move_enemy(t_game *game, int enemy, char *direction);
/* Game enem movement utils 2 */
void		free_first(t_queue **queue);
void		free_nodes(t_queue **queue);
t_queue		*get_last_node(t_queue *queue);
int			safe_path_enem(t_game *game, int pos_h, int pos_w);
void		new_node(t_queue **queue, int height, int width, char *direction);
/* Game enem movement utils 3 */
int			init_to_calc(t_game *game);
char		*get_direction(int number);
int			**visited_move_enem(t_game *game);
int			check_game_over(t_game *game, int pos_h, int pos_w);

#endif