/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_resolver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:07:04 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/22 13:32:47 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_pos(t_game *game, int height, int width)
{
	if (game->map[height][width] == '1')
		return (1);
	else
		return (0);
}

static	int	**init_visited(t_game *game, int height, int width)
{
	int	i;
	int	j;
	int	**array;

	array = ft_malloc((height * sizeof(int *)), &game->alloc);
	if (array == NULL)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		j = -1;
		array[i] = ft_malloc((width * sizeof(int)), &game->alloc);
		if (array[i] == NULL)
			return (NULL);
		while (++j < width)
			array[i][j] = check_pos(game, i, j);
	}
	return (array);
}

static	int	have_path(t_game *game, int **visited, int i, int j)
{
	t_direction	direc;

	direc = (t_direction){0, 0, 0, 0};
	if (safe(game->height_map, game->width_map, i, j)
		&& game->map[i][j] != '1' && visited[i][j] == 0)
	{
		visited[i][j] = 1;
		if (game->map[i][j] == 'E')
			return (1);
		direc.north = have_path(game, visited, i - 1, j);
		if (direc.north)
			return (1);
		direc.west = have_path(game, visited, i, j - 1);
		if (direc.west)
			return (1);
		direc.south = have_path(game, visited, i + 1, j);
		if (direc.south)
			return (1);
		direc.east = have_path(game, visited, i, j + 1);
		if (direc.east)
			return (1);
	}
	return (0);
}

static int	logic_resolver(t_game *game)
{
	int		i;
	int		j;
	int		**visited;

	i = -1;
	visited = init_visited(game, game->height_map, game->width_map);
	if (visited == NULL)
		return (-1);
	while (game->map[++i] != NULL)
	{
		j = -1;
		while (game->map[i][++j] != '\0')
		{
			if (game->map[i][j] == 'P' && visited[i][j] == 0)
			{	
				if (have_path(game, visited, i, j))
					return (1);
			}
		}
	}
	return (-10);
}

int	resolve(t_game *game)
{
	int	error;

	error = logic_resolver(game);
	if (error < 0)
	{
		if (error == -1)
			general_errors(error);
		else
			map_errors(error);
		return (0);
	}
	return (1);
}
