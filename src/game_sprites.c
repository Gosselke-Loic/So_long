/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:25:23 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/19 13:52:08 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_sprite	*generate_map(t_game *game)
{
	t_sprite	*sprites;

	sprites = ft_malloc((sizeof(t_sprite) * 5), &game->alloc);
	if (!sprites)
	{
		general_errors(-1);
		return (NULL);
	}
	sprites[0] = create_sprite(game, "./assets/sprites/floor.xpm");
	if (!sprites[0].img)
		return (NULL);
	sprites[1] = create_sprite(game, "./assets/sprites/wall.xpm");
	if (!sprites[1].img)
		return (NULL);
	sprites[2] = create_sprite(game, "./assets/sprites/floor_end.xpm");
	if (!sprites[2].img)
		return (NULL);
	sprites[3] = create_sprite(game, "./assets/sprites/floor_start.xpm");
	if (!sprites[3].img)
		return (NULL);
	sprites[4] = create_sprite(game, "./assets/sprites/item.xpm");
	if (!sprites[4].img)
		return (NULL);
	return (sprites);
}

t_sprite	*player_up(t_game *game)
{
	t_sprite	*sprites;

	sprites = ft_malloc((sizeof(t_sprite) * 6), &game->alloc);
	if (!sprites)
	{
		general_errors(-1);
		return (NULL);
	}
	sprites[0] = create_sprite(game, "./assets/sprites/mage_up_1.xpm");
	sprites[1] = create_sprite(game, "./assets/sprites/mage_up_2.xpm");
	sprites[2] = create_sprite(game, "./assets/sprites/mage_up_3.xpm");
	sprites[3] = create_sprite(game, "./assets/sprites/mage_up_4.xpm");
	sprites[4] = create_sprite(game, "./assets/sprites/mage_up_5.xpm");
	sprites[5] = create_sprite(game, "./assets/sprites/mage_up_6.xpm");
	if (!sprites[0].img || !sprites[1].img || !sprites[2].img
		|| !sprites[3].img || !sprites[4].img || !sprites[5].img)
		return (NULL);
	return (sprites);
}

t_sprite	*player_idle(t_game *game)
{
	t_sprite	*sprites;

	sprites = ft_malloc((sizeof(t_sprite) * 6), &game->alloc);
	if (!sprites)
	{
		general_errors(-1);
		return (NULL);
	}
	sprites[0] = create_sprite(game, "./assets/sprites/mage_idle_1.xpm");
	sprites[1] = create_sprite(game, "./assets/sprites/mage_idle_2.xpm");
	sprites[2] = create_sprite(game, "./assets/sprites/mage_idle_3.xpm");
	sprites[3] = create_sprite(game, "./assets/sprites/mage_idle_4.xpm");
	sprites[4] = create_sprite(game, "./assets/sprites/mage_idle_5.xpm");
	sprites[5] = create_sprite(game, "./assets/sprites/mage_idle_6.xpm");
	if (!sprites[0].img || !sprites[1].img || !sprites[2].img
		|| !sprites[3].img || !sprites[4].img || !sprites[5].img)
		return (NULL);
	return (sprites);
}

t_sprite	*player_right(t_game *game)
{
	t_sprite	*sprites;

	sprites = ft_malloc((sizeof(t_sprite) * 6), &game->alloc);
	if (!sprites)
	{
		general_errors(-1);
		return (NULL);
	}
	sprites[0] = create_sprite(game, "./assets/sprites/mage_right_1.xpm");
	sprites[1] = create_sprite(game, "./assets/sprites/mage_right_2.xpm");
	sprites[2] = create_sprite(game, "./assets/sprites/mage_right_3.xpm");
	sprites[3] = create_sprite(game, "./assets/sprites/mage_right_4.xpm");
	sprites[4] = create_sprite(game, "./assets/sprites/mage_right_5.xpm");
	sprites[5] = create_sprite(game, "./assets/sprites/mage_right_6.xpm");
	if (!sprites[0].img || !sprites[1].img || !sprites[2].img
		|| !sprites[3].img || !sprites[4].img || !sprites[5].img)
		return (NULL);
	return (sprites);
}

t_sprite	*player_left(t_game *game)
{
	t_sprite	*sprites;

	sprites = ft_malloc((sizeof(t_sprite) * 6), &game->alloc);
	if (!sprites)
	{
		general_errors(-1);
		return (NULL);
	}
	sprites[0] = create_sprite(game, "./assets/sprites/mage_left_1.xpm");
	sprites[1] = create_sprite(game, "./assets/sprites/mage_left_2.xpm");
	sprites[2] = create_sprite(game, "./assets/sprites/mage_left_3.xpm");
	sprites[3] = create_sprite(game, "./assets/sprites/mage_left_4.xpm");
	sprites[4] = create_sprite(game, "./assets/sprites/mage_left_5.xpm");
	sprites[5] = create_sprite(game, "./assets/sprites/mage_left_6.xpm");
	if (!sprites[0].img || !sprites[1].img || !sprites[2].img
		|| !sprites[3].img || !sprites[4].img || !sprites[5].img)
		return (NULL);
	return (sprites);
}
