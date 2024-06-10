/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:44:21 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/22 09:48:43 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	general_errors(int error)
{
	if (error == -1)
		ft_putstr_fd("Error\nMalloc error\n", 2);
	if (error == -2)
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
}

void	map_errors(int error)
{
	if (error == -3)
		ft_putstr_fd("Error\nInvalid extension map\n", 2);
	if (error == -4)
		ft_putstr_fd("Error\nNot be able to open the map\n", 2);
	if (error == -5)
		ft_putstr_fd("Error\nEmpty map or double new line\n", 2);
	if (error == -6)
		ft_putstr_fd("Error\nInvalid character in map\n", 2);
	if (error == -7)
		ft_putstr_fd("Error\nMap not rectangular or not closed by walls\n", 2);
	if (error == -8)
		ft_putstr_fd("Error\nExit or start repetition\n", 2);
	if (error == -9)
		ft_putstr_fd("Error\nNeed 1 item('C'), 1 exit('E'), 1 start('P')\n", 2);
	if (error == -10)
		ft_putstr_fd("Error\nNo solution available\n", 2);
}

void	game_errors(int error)
{
	if (error == -11)
		ft_putstr_fd("Error\nMinilbx or Window can't be initialized\n", 2);
	if (error == -12)
		ft_putstr_fd("Error\nError to upload sprites\n", 2);
	if (error == -13)
		ft_putstr_fd("Error\nError to cleanup the window\n", 2);
}
