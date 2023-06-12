/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:53:42 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/09 23:53:44 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	val_move(t_map *game, int y, int x, int key)
{
	if (game->layout[y][x] == '1')
		return (-1);
	if (game->layout[y][x] == 'C')
		game->score--;
	if (game->score > 0 && game->layout[y][x] == 'E')
		return (1);
	if (game->score == 0 && game->layout[y][x] == 'E')
	{
		ft_printf("-.- boring -.- \n");
		closure(game);
	}
	if (key != W && key != S && key != A && key != D)
		return (-1);
	return (0);
}

void	input_move(t_map *game, int y, int x, int key)
{
	int	outcome;
	int	col;
	int	row;

	col = game->player_y;
	row = game->player_x;
	(void)key;
	outcome = val_move(game, y, x, key);
	if (outcome != -1)
	{
		game->player_y = y;
		game->player_x = x;
		if (game->layout[y][x] == 'E' && game->score > 0)
		{
			game->layout[col][row] = '0';
			game->layout[y][x] = 'E';
			game->temp = 1;
		}
		if (game->layout[y][x] == 'E' && game->score == 0)
		{
			game->layout[col][row] = '0';
			game->layout[y][x] = 'E';
		}
		if (game->layout[y][x] == 'C' || game->layout[y][x] == '0')
		{
			if (game->temp == 1)
			{
				game->layout[col][row] = 'E';
				game->temp = 0;
			}
			else
				game->layout[col][row] = '0';
			game->layout[y][x] = 'P';
		}
		ft_printf("move: %d\n", game->moves++);
		render_img(game);
	}
}	

int	control_key(int key, t_map *game)
{
	int	col;
	int	row;
	
	col = game->player_y;
	row = game->player_x;
	if (key == ESC)
	{
		game->dying = -1;
		closure(game);
	}
	if (key == W)
		col--;
	if (key == S)
		col++;
	if (key == A)
		row--;
	if (key == D)
		row++;
	if (game->dying != -1)
		input_move(game, col, row, key);
	return (0);
}
