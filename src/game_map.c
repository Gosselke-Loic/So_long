/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:41:57 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/23 09:52:38 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_lines(char *buff)
{
	int	i;
	int	count;

	if (!buff)
		return (0);
	i = -1;
	count = 0;
	while (buff[++i])
	{
		if (buff[i] == '\n' && buff[i + 1] == '\n')
			return (0);
		else if (buff[i] == '\n' && buff[i + 1] != '\n')
			count++;
	}
	return (count);
}

static char	*read_file(int fd)
{
	int		byte;
	char	*str;
	char	*temp;
	char	buff[1084];

	str = NULL;
	byte = 1;
	while (byte)
	{
		byte = read(fd, buff, 1084);
		buff[byte] = '\0';
		temp = str;
		str = ft_strjoin(temp, buff);
		free(temp);
		temp = NULL;
	}
	return (str);
}

static void	init_checks(t_checks_map *checks)
{
	checks->exit = 0;
	checks->item = 0;
	checks->start = 0;
	checks->enemies = 0;
	checks->start_pos.width = 0;
	checks->start_pos.height = 0;
}

static int	validity_map(t_game *game, char **map)
{
	int				error;
	t_checks_map	checks_map;

	if (map == NULL)
	{
		map_errors(-5);
		return (0);
	}
	init_checks(&checks_map);
	error = invalid_map(game, &checks_map, map);
	if (error != 0)
	{
		map_errors(error);
		return (0);
	}
	game->map = map;
	game->enemies = checks_map.enemies;
	game->player.pos.width = checks_map.start_pos.width;
	game->player.pos.height = checks_map.start_pos.height;
	return (1);
}

int	parse_map(t_game *game, const char *path)
{
	int		fd;
	char	*buff;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		map_errors(-4);
		return (0);
	}
	buff = read_file(fd);
	game->height_map = count_lines(buff);
	if (game->height_map == 0)
	{
		map_errors(-5);
		free(buff);
		return (0);
	}
	if (!validity_map(game, ft_split(buff, '\n', &game->alloc)))
	{
		free(buff);
		return (0);
	}
	free(buff);
	close(fd);
	return (1);
}
