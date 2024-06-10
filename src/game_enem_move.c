/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enem_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:59:37 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/23 11:34:42 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	safe_path(t_game *game, int height, int width)
{
	if (safe(game->height_map, game->width_map, height, width)
		&& game->visited[height][width] == 0)
		return (1);
	return (0);
}

static t_queue	*calc_path(t_game *game, int i, int j)
{
	t_queue	head;
	t_queue	*queue;

	queue = NULL;
	new_node(&queue, game->enemy_lst[i].pos.height,
		game->enemy_lst[i].pos.width, "DOWN");
	while (queue)
	{
		head = *queue;
		j = -1;
		if (game->map[head.h][head.w] == 'P')
			return (queue);
		free_first(&queue);
		while (++j < 4)
		{
			if (safe_path(game, head.h + game->d.h[j], head.w + game->d.w[j]))
			{
				new_node(&queue, head.h + game->d.h[j],
					head.w + game->d.w[j], get_direction(j));
				game->visited[head.h + game->d.h[j]][head.w + game->d.w[j]] = 1;
			}
		}
	}
	free_nodes(&queue);
	return (NULL);
}

static int	make_move_enem(t_game *game)
{
	int			i;
	t_queue		*path;

	i = -1;
	path = NULL;
	while (++i < game->enemies)
	{
		game->visited = visited_move_enem(game);
		if (game->visited == NULL)
			return (0);
		game->visited[game->enemy_lst[i].pos.height]
		[game->enemy_lst[i].pos.width] = 1;
		path = calc_path(game, i, 0);
		if (!path || game->map[path->h][path->w] == '1')
			move_enemy(game, i, get_direction(rand() % (3 - 0 + 1) + 0));
		else if (path)
			move_enemy(game, i, path->direction);
		free_nodes(&path);
	}
	return (1);
}

int	move_enemies(t_game *game)
{
	if (game->player.turns_frz > 0)
	{
		game->player.turns_frz--;
		return (1);
	}
	else if (game->player.turns_frz == 0)
	{
		if (!make_move_enem(game))
			return (0);
	}
	return (1);
}
