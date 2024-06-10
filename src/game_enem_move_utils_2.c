/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enem_move_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:26:36 by lgosselk          #+#    #+#             */
/*   Updated: 2024/01/22 16:07:10 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	safe_path_enem(t_game *game,
	int pos_h, int pos_w)
{
	if (game->map[pos_h][pos_w] == '1' || game->map[pos_h][pos_w] == 'C'
		|| game->map[pos_h][pos_w] == 'A' || game->map[pos_h][pos_w] == 'E')
		return (0);
	if ((pos_h > 0 && pos_h < game->height_map)
		&& (pos_w > 0 && pos_w < game->width_map))
		return (1);
	return (0);
}

t_queue	*get_last_node(t_queue *queue)
{
	t_queue	*temp;

	if (!queue)
		return (queue);
	while (queue)
	{
		temp = queue;
		queue = queue->next;
	}
	return (temp);
}

void	free_first(t_queue **queue)
{
	t_queue	*current;

	if (*queue == NULL)
		return ;
	current = *queue;
	*queue = (*queue)->next;
	free(current);
}

void	free_nodes(t_queue **queue)
{
	t_queue	*temp;
	t_queue	*next;

	if (*queue)
	{
		temp = *queue;
		while (temp)
		{
			next = temp->next;
			free(temp);
			temp = next;
		}
		*queue = NULL;
	}
}

void	new_node(t_queue **queue,
	int height, int width, char *direction)
{
	t_queue	*new_node;
	t_queue	*last_node;

	if (queue == NULL)
		return ;
	new_node = (t_queue *) malloc(sizeof(t_queue));
	if (new_node == NULL)
		return ;
	new_node->w = width;
	new_node->h = height;
	new_node->next = NULL;
	new_node->direction = direction;
	if (*queue == NULL)
		*queue = new_node;
	else
	{
		last_node = get_last_node(*queue);
		last_node->next = new_node;
	}
}
