/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enem_move_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:28:02 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/10 13:10:21 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	move_up(t_game *game, int enemy)
{
	if (!safe_path_enem(game, (game->enemy_lst[enemy].pos.height - 1),
			game->enemy_lst[enemy].pos.width))
		return (0);
	if (check_game_over(game, (game->enemy_lst[enemy].pos.height - 1),
			game->enemy_lst[enemy].pos.width))
		return (0);
	else
	{
		game->enemy_lst[enemy].direction = UP;
		game->map[game->enemy_lst[enemy].pos.height]
		[game->enemy_lst[enemy].pos.width] = '0';
		game->enemy_lst[enemy].pos.height--;
		game->map[game->enemy_lst[enemy].pos.height]
		[game->enemy_lst[enemy].pos.width] = 'A';
	}
	return (1);
}

static int	move_right(t_game *game, int enemy)
{
	if (!safe_path_enem(game, game->enemy_lst[enemy].pos.height,
			(game->enemy_lst[enemy].pos.width - 1)))
		return (0);
	if (check_game_over(game, game->enemy_lst[enemy].pos.height,
			(game->enemy_lst[enemy].pos.width - 1)))
		return (0);
	else
	{
		game->enemy_lst[enemy].direction = RIGHT;
		game->map[game->enemy_lst[enemy].pos.height]
		[game->enemy_lst[enemy].pos.width] = '0';
		game->enemy_lst[enemy].pos.width--;
		game->map[game->enemy_lst[enemy].pos.height]
		[game->enemy_lst[enemy].pos.width] = 'A';
	}
	return (1);
}

static int	move_down(t_game *game, int enemy)
{
	if (!safe_path_enem(game, (game->enemy_lst[enemy].pos.height + 1),
			game->enemy_lst[enemy].pos.width))
		return (0);
	if (check_game_over(game, (game->enemy_lst[enemy].pos.height + 1),
			game->enemy_lst[enemy].pos.width))
		return (0);
	else
	{
		game->enemy_lst[enemy].direction = DOWN;
		game->map[game->enemy_lst[enemy].pos.height]
		[game->enemy_lst[enemy].pos.width] = '0';
		game->enemy_lst[enemy].pos.height++;
		game->map[game->enemy_lst[enemy].pos.height]
		[game->enemy_lst[enemy].pos.width] = 'A';
	}
	return (1);
}

static int	move_left(t_game *game, int enemy)
{
	if (!safe_path_enem(game, game->enemy_lst[enemy].pos.height,
			(game->enemy_lst[enemy].pos.width + 1)))
		return (0);
	if (check_game_over(game, game->enemy_lst[enemy].pos.height,
			(game->enemy_lst[enemy].pos.width + 1)))
		return (0);
	else
	{
		game->enemy_lst[enemy].direction = LEFT;
		game->map[game->enemy_lst[enemy].pos.height]
		[game->enemy_lst[enemy].pos.width] = '0';
		game->enemy_lst[enemy].pos.width++;
		game->map[game->enemy_lst[enemy].pos.height]
		[game->enemy_lst[enemy].pos.width] = 'A';
	}
	return (1);
}

int	move_enemy(t_game *game, int enemy, char *direction)
{
	if (ft_strcmp(direction, "UP") == 0)
		move_up(game, enemy);
	if (ft_strcmp(direction, "RIGHT") == 0)
		move_right(game, enemy);
	if (ft_strcmp(direction, "DOWN") == 0)
		move_down(game, enemy);
	if (ft_strcmp(direction, "LEFT") == 0)
		move_left(game, enemy);
	return (1);
}
