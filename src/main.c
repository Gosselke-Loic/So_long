/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:45:10 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/23 09:58:35 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	invalid_ext(char *arg)
{
	char	*extension;

	extension = ft_strrchr(arg, '.');
	if (extension == NULL)
		return (1);
	if (ft_strcmp(extension, ".ber") != 0)
		return (1);
	return (0);
}

static int	early_errors(char **argv, int argc_equal_2)
{
	if (!argc_equal_2)
	{
		general_errors(-2);
		return (1);
	}
	if (invalid_ext(argv[1]))
	{
		map_errors(-3);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	srand(time(NULL));
	if (early_errors(argv, argc == 2))
		return (EXIT_FAILURE);
	set_game(&game);
	if (!parse_map(&game, argv[1]) || !resolve(&game) || !init_game(&game)
		|| !upload_sprites(&game) || !set_state(&game))
		on_destroy(&game, EXIT_FAILURE);
	mlx_hook(game.windx, 2, (1L << 0), key_hook, &game);
	mlx_loop_hook(game.mlx, refresh, &game);
	mlx_hook(game.windx, 17, (1L << 0), close_window, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
