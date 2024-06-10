/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:40:58 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/22 09:28:32 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	next_move_player(t_game *game, int height, int width)
{
	if (game->map[height][width] == '1')
		return (0);
	if (game->map[height][width] == 'A')
	{
		game->game_over = 1;
		return (0);
	}
	if (game->map[height][width] == 'C')
	{
		game->map[height][width] = '0';
		game->items--;
		return (1);
	}
	if (game->map[height][width] == 'E')
	{
		if (game->items == 0)
		{
			game->win = 1;
			return (0);
		}
		return (0);
	}
	return (1);
}
