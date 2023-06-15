/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 00:59:53 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/14 01:03:42 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//valid path
bool	val_path(t_map *game, int x, int y)
{
	static bool	f_exit = false;

	if (x < 0 || y < 0)
		return (false);
	if (x >= game->width || y >= game->height)
		return (false);
	if (game->lay_back[y][x] == 'E')
		f_exit = true;
	if (game->lay_back[y][x] == 'C')
		game->val_col++;
	if (game->lay_back[y][x] == 'X')
		return (false);
	if (game->lay_back[y][x] == '1')
		return (false);
	game->lay_back[y][x] = 'X';
	val_path(game, x + 1, y);
	val_path(game, x - 1, y);
	val_path(game, x, y + 1);
	val_path(game, x, y - 1);
	return (game->val_col == game->collect && f_exit);
}

bool	val_path_param(t_map *game)
{
//	char	c;
	int		x;
	int		y;
	bool	outcome;

//	c = game->lay_back[game->player_y][game->player_x];
	x = game->player_x;
	y = game->player_y;
	outcome = val_path(game, x, y);
	free_layback(game);
	game->path = 1;
	return (outcome);
}
