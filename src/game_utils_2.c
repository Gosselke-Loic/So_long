/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:55:28 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/22 16:07:41 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_game(t_game *game)
{
	game->map = NULL;
	game->mlx = NULL;
	game->windx = NULL;
	game->alloc = NULL;
	game->visited = NULL;
	game->alloc_img = NULL;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_sprite	render_player(t_game *game)
{
	if (game->player.direction == DOWN)
		return (game->player.sprites.sprites_idle[game->player.frame]);
	if (game->player.direction == LEFT)
		return (game->player.sprites.sprites_left[game->player.frame]);
	if (game->player.direction == UP)
		return (game->player.sprites.sprites_up[game->player.frame]);
	if (game->player.direction == RIGHT)
		return (game->player.sprites.sprites_right[game->player.frame]);
	return (game->player.sprites.sprites_idle[game->player.frame]);
}

static void	check_ending(t_game *game, char c)
{
	if (c == 'W')
	{
		game->win = 0;
		ft_putstr_fd("You won\n", 1);
		on_destroy(game, EXIT_SUCCESS);
	}
	else if (c == 'G')
	{
		game->game_over = 0;
		ft_putstr_fd("Game Over\n", 1);
		on_destroy(game, EXIT_SUCCESS);
	}
}

int	refresh(t_game *game)
{
	if (game->win == 1 && game->game_over == 0)
	{
		check_ending(game, 'W');
		return (0);
	}
	else if (game->game_over == 1 && game->win == 0)
	{
		check_ending(game, 'G');
		return (-1);
	}
	else if (game->game_over == 0 && game->win == 0)
		refresh_frame(game);
	return (0);
}
