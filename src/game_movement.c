/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:15:52 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/23 09:36:02 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	int	move_up(t_game *game)
{
	if (!safe(game->height_map, game->width_map,
			(game->player.pos.height - 1), game->player.pos.width))
		return (0);
	if (!next_move_player(game, (game->player.pos.height - 1),
			game->player.pos.width))
		return (0);
	else
	{
		game->player.direction = UP;
		game->map[game->player.pos.height][game->player.pos.width] = '0';
		game->player.pos.height--;
		game->map[game->player.pos.height][game->player.pos.width] = 'P';
		game->player.steps++;
	}
	return (1);
}

static int	move_right(t_game *game)
{
	if (!safe(game->height_map, game->width_map,
			game->player.pos.height, (game->player.pos.width - 1)))
		return (0);
	if (!next_move_player(game, game->player.pos.height,
			game->player.pos.width - 1))
		return (0);
	else
	{
		game->player.direction = RIGHT;
		game->map[game->player.pos.height][game->player.pos.width] = '0';
		game->player.pos.width--;
		game->map[game->player.pos.height][game->player.pos.width] = 'P';
		game->player.steps++;
	}
	return (1);
}

static int	move_down(t_game *game)
{
	if (!safe(game->height_map, game->width_map,
			(game->player.pos.height + 1), game->player.pos.width))
		return (0);
	if (!next_move_player(game, (game->player.pos.height + 1),
			game->player.pos.width))
		return (0);
	else
	{
		game->player.direction = DOWN;
		game->map[game->player.pos.height][game->player.pos.width] = '0';
		game->player.pos.height++;
		game->map[game->player.pos.height][game->player.pos.width] = 'P';
		game->player.steps++;
	}
	return (1);
}

static int	move_left(t_game *game)
{
	if (!safe(game->height_map, game->width_map,
			game->player.pos.height, (game->player.pos.width + 1)))
		return (0);
	if (!next_move_player(game, game->player.pos.height,
			game->player.pos.width + 1))
		return (0);
	else
	{
		game->player.direction = LEFT;
		game->map[game->player.pos.height][game->player.pos.width] = '0';
		game->player.pos.width++;
		game->map[game->player.pos.height][game->player.pos.width] = 'P';
		game->player.steps++;
	}
	return (1);
}

int	movement(t_game *game, char *direction)
{
	if (ft_strcmp(direction, "UP") == 0)
	{
		if (!move_up(game))
			return (0);
	}
	if (ft_strcmp(direction, "RIGHT") == 0)
	{
		if (!move_right(game))
			return (0);
	}
	if (ft_strcmp(direction, "DOWN") == 0)
	{
		if (!move_down(game))
			return (0);
	}
	if (ft_strcmp(direction, "LEFT") == 0)
	{
		if (!move_left(game))
			return (0);
	}
	if (game->enemies > 0)
		if (!move_enemies(game))
			return (-1);
	return (1);
}
