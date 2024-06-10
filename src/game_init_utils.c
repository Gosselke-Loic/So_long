/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:28:42 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/04 12:24:11 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	build_image(char *buffer, t_vector2D start,
				t_sprite image2, t_sprite image)
{
	int	og;
	int	width;
	int	pixel;
	int	height;

	height = -1;
	while (++height < image.height)
	{
		width = -1;
		while (++width < image.width)
		{
			pixel = ((start.height + height) * image2.line_length)
				+ ((start.width + width) * 4);
			og = (height * image.line_length) + (width * 4);
			if (!(image.addr[og] == 0 && image.addr[og + 1] == 0
					&& image.addr[og + 2] == 0))
			{
				buffer[pixel + 0] = image.addr[og + 0];
				buffer[pixel + 1] = image.addr[og + 1];
				buffer[pixel + 2] = image.addr[og + 2];
				buffer[pixel + 3] = image.addr[og + 3];
			}
		}
	}
}

static void	build_floor(t_build_image b, t_game *game,
				char *buffer, t_sprite *map)
{
	if (game->map[b.height][b.width] == 'P')
		build_image(buffer, b.start, *map, game->sprites_map[3]);
	if (game->map[b.height][b.width] == 'C'
		|| game->map[b.height][b.width] == '0'
		|| game->map[b.height][b.width] == 'A')
		build_image(buffer, b.start, *map, game->sprites_map[0]);
	if (game->map[b.height][b.width] == 'E')
		build_image(buffer, b.start, *map, game->sprites_map[2]);
}

void	set_blocks(t_game *game, t_vector2D start,
				char *buffer, t_sprite *map)
{
	int	width;
	int	height;

	height = 0;
	while (height < game->height_map)
	{
		width = 0;
		while (width < game->width_map)
		{
			start.width -= game->sprites_map[0].width / 2;
			build_floor((t_build_image){width, start, height},
				game, buffer, map);
			width++;
			start.height += game->sprites_map[0].height / 4;
		}
		height++;
		start.height = game->sprites_map[0].height / 2
			+ ((game->sprites_map[0].height / 4) * height);
		start.width = (game->width_map * game->sprites_map[0].width / 2)
			+ ((game->sprites_map[0].width / 2) * height);
	}
}

static void	build_objects(t_build_image b, t_game *game,
				char *buffer, t_sprite *map)
{
	if (game->map[b.height][b.width] == 'P')
		build_image(buffer, (t_vector2D){b.start.width + 8, b.start.height - 7},
			*map, render_player(game));
	if (game->map[b.height][b.width] == 'A')
		build_image(buffer, (t_vector2D){b.start.width + 8, b.start.height - 7},
			*map, render_enemy(game, (t_vector2D){b.width, b.height}));
	if (game->map[b.height][b.width] == 'C')
		build_image(buffer, b.start, *map, game->sprites_map[4]);
	if (game->map[b.height][b.width] == '1' && b.width != (game->width_map - 1)
		&& b.height != (game->height_map - 1))
		build_image(buffer, b.start, *map, game->sprites_map[1]);
}

void	set_objects(t_game *game, t_vector2D start,
				char *buffer, t_sprite *map)
{
	int	width;
	int	height;

	height = 0;
	while (height < game->height_map)
	{
		width = 0;
		while (width < game->width_map)
		{
			start.width -= CELL_SIZE / 2;
			build_objects((t_build_image){width, start, height},
				game, buffer, map);
			width++;
			start.height += CELL_SIZE / 4;
		}
		height++;
		start.height = ((CELL_SIZE / 4) * height);
		start.width = (game->width_map * CELL_SIZE / 2)
			+ ((CELL_SIZE / 2) * height);
	}
}
