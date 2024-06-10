/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:52:07 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/23 10:27:45 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	only_walls(char *line_map)
{
	int	i;

	i = -1;
	while (line_map[++i])
	{
		if (line_map[i] != '1')
			return (0);
	}
	return (1);
}

static void	check_characters(t_checks_map *map, char c,
							int height, int width)
{
	if (c == 'P')
	{
		map->start_pos.height = height;
		map->start_pos.width = width;
		map->start++;
	}
	if (c == 'E')
		map->exit++;
	if (c == 'C')
		map->item++;
	if (c == 'A')
		map->enemies++;
}

static int	loop_linemap(char *line_map, int height,
						t_checks_map *map, int flag_wall)
{
	int	i;

	i = 0;
	if (flag_wall && !only_walls(line_map))
		return (-7);
	else if (!flag_wall)
	{
		if (line_map[0] != '1' || line_map[(get_width(line_map) - 1)] != '1')
			return (-7);
		while (line_map[++i])
		{
			if (line_map[i] != '0' && line_map[i] != 'C' && line_map[i] != 'E'
				&& line_map[i] != 'P' && line_map[i] != '1'
				&& line_map[i] != '\n' && line_map[i] != 'A')
				return (-6);
			check_characters(map, line_map[i], height, i);
		}
	}
	return (get_width(line_map));
}

int	invalid_map(t_game *game, t_checks_map *checks_map, char **map)
{
	int	i;
	int	len;

	i = -1;
	while (map[++i])
	{
		len = loop_linemap(map[i], i, checks_map, (i == 0
					|| i == game->height_map));
		if (len == 0)
			return (-7);
		if (len < 0)
			return (len);
		if ((checks_map->exit > 1) || checks_map->start > 1)
			return (-8);
		game->width_map = len;
	}
	if (checks_map->item == 0 || checks_map->exit == 0
		|| checks_map->start == 0)
		return (-9);
	game->items = checks_map->item;
	return (0);
}
