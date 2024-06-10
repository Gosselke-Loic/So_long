/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:58:56 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/23 09:59:32 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_img_clear(t_collect **lst, void *mlx_ptr)
{
	t_collect	*tmp;

	if (*lst)
	{
		while (*lst != NULL)
		{
			tmp = (*lst)->next;
			mlx_destroy_image(mlx_ptr, (*lst)->ptr);
			free(*lst);
			*lst = tmp;
		}
	}
}

void	on_destroy(t_game *game, int code)
{
	ft_malloc_clear(&game->alloc);
	ft_img_clear(&game->alloc_img, game->mlx);
	if (game->windx)
		mlx_destroy_window(game->mlx, game->windx);
	if (game->mlx)
		mlx_destroy(game->mlx);
	exit(code);
}

int	close_window(t_game *game)
{
	on_destroy(game, EXIT_SUCCESS);
	return (0);
}
