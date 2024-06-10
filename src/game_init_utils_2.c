/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:03:25 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/19 13:54:40 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	find_enemy(t_game *game, t_vector2D pos)
{
	int	i;

	i = -1;
	while (++i < game->enemies)
	{
		if (game->enemy_lst[i].pos.width == pos.width
			&& game->enemy_lst[i].pos.height == pos.height)
			return (i);
	}
	return (0);
}

t_sprite	render_enemy(t_game *game, t_vector2D pos_enemy)
{
	int	i;

	i = find_enemy(game, pos_enemy);
	if (game->enemy_lst[i].direction == DOWN)
		return (game->sprites_enemy.sprites_idle[game->enemy_lst[i].frame]);
	if (game->enemy_lst[i].direction == LEFT)
		return (game->sprites_enemy.sprites_left[game->enemy_lst[i].frame]);
	if (game->enemy_lst[i].direction == UP)
		return (game->sprites_enemy.sprites_up[game->enemy_lst[i].frame]);
	if (game->enemy_lst[i].direction == RIGHT)
		return (game->sprites_enemy.sprites_right[game->enemy_lst[i].frame]);
	return (game->sprites_enemy.sprites_idle[game->enemy_lst[i].frame]);
}

t_sprite	create_sprite(t_game *game, char *path)
{
	t_sprite	sprite;

	sprite.img = mlx_xpm_file_to_image(game->mlx, path,
			&sprite.width, &sprite.height);
	if (!sprite.img)
		return (sprite);
	sprite.addr = mlx_get_data_addr(sprite.img, &sprite.bits_per_pixel,
			&sprite.line_length, &sprite.endian);
	malloc_add(&game->alloc_img, malloc_new(sprite.img));
	return (sprite);
}

static void	display_str(t_game *game, t_vector2D pos, char *str)
{
	mlx_string_put(game->mlx, game->windx, pos.height, pos.width,
		create_trgb(0, 255, 255, 255), str);
}

void	set_hud(t_game *game)
{
	char	*str;
	char	*temp;
	char	*str_itoa;

	temp = " moves";
	str_itoa = ft_itoa(game->player.steps);
	if (!str_itoa)
		return ;
	str = ft_strjoin(str_itoa, temp);
	display_str(game, (t_vector2D){20, 30}, str);
	free(str_itoa);
	free(str);
}
