/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:09:23 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/23 11:30:36 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	int	move_check;

	if (keycode == KEY_ESC)
		on_destroy(game, EXIT_SUCCESS);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_check = movement(game, "UP");
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_check = movement(game, "RIGHT");
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_check = movement(game, "DOWN");
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_check = movement(game, "LEFT");
	if (keycode == KEY_E && game->uses_freeze > 0)
	{
		game->player.turns_frz += 2;
		game->uses_freeze--;
	}
	if (move_check == -1)
		on_destroy(game, EXIT_FAILURE);
	return (0);
}

void	set_map(t_game *game)
{
	t_sprite	map;
	t_vector2D	start;
	char		*buffer;

	start = (t_vector2D){game->width_map * game->sprites_map[0].width / 2,
		game->sprites_map[0].height / 2};
	map.img = mlx_new_image(game->mlx, (game->width_map + game->height_map)
			* game->sprites_map[0].width, (game->height_map + game->width_map)
			* game->sprites_map[0].height);
	map.width = (game->width_map + game->height_map)
		* game->sprites_map[0].width;
	map.height = (game->height_map + game->width_map)
		* game->sprites_map[0].height;
	buffer = mlx_get_data_addr(map.img, &map.bits_per_pixel,
			&map.line_length, &map.endian);
	set_blocks(game, start, buffer, &map);
	start = (t_vector2D){game->width_map * game->sprites_map[0].width / 2, 0};
	set_objects(game, start, buffer, &map);
	mlx_put_image_to_window(game->mlx, game->windx, map.img, 0, 0);
	mlx_destroy_image(game->mlx, map.img);
}

static int	check_sprites(t_game *game)
{
	if (game->sprites_map == NULL || game->player.sprites.sprites_up == NULL
		|| game->player.sprites.sprites_up == NULL
		|| game->player.sprites.sprites_right == NULL
		|| game->player.sprites.sprites_left == NULL
		|| game->player.sprites.sprites_idle == NULL)
	{
		game_errors(-12);
		return (0);
	}
	if ((game->enemies > 0 && game->enemy_lst)
		&& (game->sprites_enemy.sprites_up == NULL
			|| game->sprites_enemy.sprites_right == NULL
			|| game->sprites_enemy.sprites_idle == NULL
			|| game->sprites_enemy.sprites_left == NULL))
	{
		game_errors(-12);
		return (0);
	}
	return (1);
}

int	upload_sprites(t_game *game)
{
	game->sprites_map = generate_map(game);
	game->player.sprites.sprites_up = player_up(game);
	game->player.sprites.sprites_idle = player_idle(game);
	game->player.sprites.sprites_right = player_right(game);
	game->player.sprites.sprites_left = player_left(game);
	if (game->enemies > 0)
	{
		game->sprites_enemy.sprites_up = enemy_up(game);
		game->sprites_enemy.sprites_right = enemy_right(game);
		game->sprites_enemy.sprites_idle = enemy_idle(game);
		game->sprites_enemy.sprites_left = enemy_left(game);
	}
	if (!check_sprites(game))
		return (0);
	return (1);
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		game_errors(-11);
		return (0);
	}
	if (game->height_map <= game->width_map)
		game->windx = mlx_new_window(game->mlx, game->width_map * CELL_SIZE,
				game->width_map * CELL_SIZE, "So_long");
	else
		game->windx = mlx_new_window(game->mlx, game->height_map * CELL_SIZE,
				game->height_map * CELL_SIZE, "So_long");
	if (!game->windx)
	{	
		game_errors(-11);
		return (0);
	}
	return (1);
}
