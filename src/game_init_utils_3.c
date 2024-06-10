/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:46:41 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/23 11:23:40 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static long long	millitimestamp(void)
{
	struct timeval	timeval;
	long long		microtime;

	gettimeofday(&timeval, NULL);
	microtime = timeval.tv_sec * 1000LL + timeval.tv_usec / 1000;
	return (microtime);
}

static void	fps(t_game *game)
{
	long long	now;

	now = millitimestamp();
	if (now > game->time)
		game->time = now;
}

static void	reset_frame(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->enemies)
	{
		if (game->enemy_lst[i].frame == 5)
			game->enemy_lst[i].frame = 0;
		else
			game->enemy_lst[i].frame++;
	}
}

void	refresh_frame(t_game *game)
{
	long long	now;
	long long	diff_milli;

	now = millitimestamp();
	diff_milli = now - game->time;
	if (diff_milli > 140)
	{
		fps(game);
		set_map(game);
		if (game->player.frame == 5)
			game->player.frame = 0;
		else
			game->player.frame++;
		reset_frame(game);
		set_hud(game);
	}
}
