/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:38:24 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/14 01:15:25 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	start_map(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->direction = 0;
	game->collect = 0;
	game->num_play = 0;
	game->num_tax = 0;
	game->val_col = 0;
	game->score = 0;
	game->dying = 0;
	game->temp = 0;
	game->path = 0;
	game->moves = 1;
	game->exit = 0;
}

void	start_entities(t_game *game)
{
	int		i;
	t_place		p;

	i = 0;
	p = (t_place){-1, -1};
	game->taxes = calloc(game->num_tax, sizeof(t_entity));
	if (!game->taxes)
		end_game(game, 4);
	while (++p.y < game->height)
	{
		p.x = -1;
		while (++p.x < game->width)
		{
			if (game->layout[p.y][p.x] != 'T')
				continue ;
			game->taxes[i].frame = 0;
			game->taxes[i].pre = p;
			game->taxes[i++].pos = p;
		}
	}
}

void	start_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->height)
	{
		while (j < game->width)
		{	
			if (game->layout[i][j] == 'P')
			{
				game->me.pre.x = j;
				game->me.pre.y = i;
				game->me.pos.x = j;
				game->me.pos.y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
