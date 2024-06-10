/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enem_move_utils_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:30:19 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/23 11:35:02 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_game_over(t_game *game, int pos_h, int pos_w)
{
	if (game->map[pos_h][pos_w] == 'P' || ((pos_h == game->player.pos.height)
		&& (pos_w == game->player.pos.width)))
	{
		game->game_over = 1;
		return (1);
	}
	return (0);
}

static int	check_pos(t_game *game, int height, int width)
{
	if (game->map[height][width] == '1' || game->map[height][width] == 'C'
		|| game->map[height][width] == 'A' || game->map[height][width] == 'E')
		return (1);
	else
		return (0);
}

int	**visited_move_enem(t_game *game)
{
	int	i;
	int	j;
	int	**array;

	array = ft_malloc((game->height_map * sizeof(int *)), &game->alloc);
	if (array == NULL)
		return (NULL);
	i = -1;
	while (++i < game->height_map)
	{
		j = -1;
		array[i] = ft_malloc((game->width_map * sizeof(int)), &game->alloc);
		if (array[i] == NULL)
			return (NULL);
		while (++j < game->width_map)
		{
			if (check_pos(game, i, j))
				array[i][j] = 1;
			else
				array[i][j] = 0;
		}
	}
	return (array);
}

char	*get_direction(int number)
{
	if (number == 0)
		return ("UP");
	if (number == 1)
		return ("LEFT");
	if (number == 2)
		return ("DOWN");
	return ("RIGHT");
}

int	init_to_calc(t_game *game)
{
	game->d.w = ft_malloc(4 * sizeof(int), &game->alloc);
	game->d.h = ft_malloc(4 * sizeof(int), &game->alloc);
	if (game->d.w == NULL || game->d.h == NULL)
		return (0);
	game->d.w[0] = 0;
	game->d.w[1] = 1;
	game->d.w[2] = 0;
	game->d.w[3] = -1;
	game->d.h[0] = -1;
	game->d.h[1] = 0;
	game->d.h[2] = 1;
	game->d.h[3] = 0;
	return (1);
}
