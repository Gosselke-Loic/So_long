/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:44:45 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/23 10:27:53 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	safe(int height, int width, int height_i, int width_j)
{
	if ((height_i > 0 && height_i < height)
		&& (width_j > 0 && width_j < width))
		return (1);
	return (0);
}

static void	set_enemies(t_game *game)
{
	int	width;
	int	index;
	int	height;

	index = 0;
	height = -1;
	while (++height < game->height_map)
	{
		width = -1;
		while (++width < game->width_map)
		{
			if (game->map[height][width] == 'A')
			{
				game->enemy_lst[index].frame = 0;
				game->enemy_lst[index].direction = DOWN;
				game->enemy_lst[index].pos.width = width;
				game->enemy_lst[index].pos.height = height;
				index++;
			}
		}
	}
}

int	set_state(t_game *game)
{
	game->win = 0;
	game->time = 0;
	game->game_over = 0;
	game->uses_freeze = 1;
	game->enemy_lst = NULL;
	game->player.steps = 0;
	game->player.frame = 0;
	game->player.turns_frz = 0;
	game->player.direction = DOWN;
	if (game->enemies > 0)
	{
		init_to_calc(game);
		game->enemy_lst = ft_malloc((sizeof(t_enemy)
					* game->enemies), &game->alloc);
		if (game->enemy_lst == NULL)
			return (0);
		set_enemies(game);
	}
	return (1);
}

size_t	get_width(const char *str)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = -1;
	if (!str)
		return (0);
	while (str[++j])
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == 'E'
			|| str[i] == 'C' || str[i] == 'P' || str[i] == 'A')
			i++;
	}
	if (j != i)
		return (0);
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (*ptr1 && *ptr1 == *ptr2)
	{
		ptr1++;
		ptr2++;
	}
	return (*ptr1 - *ptr2);
}
