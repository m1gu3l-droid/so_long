/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:53:42 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/14 02:49:13 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	val_move_bonus(t_game *game, int y, int x, int key)
{
	if (key != W && key != S && key != A && key != D)
		return (-1);
	if (game->layout[y][x] == '1' || game->layout[y][x] == 'f' || game->layout[y][x] == 'g')
		return (-1);
	if (game->layout[y][x] == 'h' || game->layout[y][x] == 'j' || game->layout[y][x] == 'v')
		return (-1);
	if (game->layout[y][x] == 'b' || game->layout[y][x] == 'n' || game->layout[y][x] == 'm')
		return (-1);
	if (game->layout[y][x] == 'C')
		game->score--;
	if (game->score > 0 && game->layout[y][x] == 'E')
		game->temp = 1;
	if (game->score == 0 && game->layout[y][x] == 'E')
	{
		ft_printf("move: %d\n-.- boring -.- \n", game->moves);
		closure(game);
	}
	ft_printf("move: %d\n", game->moves++);
	return (0);
}

void	input_move_bonus(t_game *game, int y, int x, int key)
{
	int	outcome;
	int	cy;
	int	cx;

	cy = game->player_y;
	cx = game->player_x;
	(void)key;
	outcome = val_move_bonus(game, y, x, key);
	if (outcome != -1)
	{
		game->player_y = y;
		game->player_x = x;
		if (game->temp != 1 || game->layout[y][x] == 'E')
			game->layout[cy][cx] = '0';
		if (game->temp == 1 && game->layout[y][x] != 'E')
		{
			game->layout[cy][cx] = 'E';
			game->temp = 0;
		}
		if (game->layout[y][x] != 'E')
			game->layout[y][x] = 'P';
		if (game->layout[y][x] == 'E')
			game->layout[y][x] = 'E';
		render_sprite_bonus(game);
	}
}

int	control_key_bonus(int key, t_game *game)
{
	int	y;
	int	x;

	y = game->player_y;
	x = game->player_x;
	if (key == ESC)
	{
		game->dying = -1;
		closure(game);
	}
	if (key == W)
		y--;
	if (key == S)
		y++;
	if (key == A)
		x--;
	if (key == D)
		x++;
	if (game->dying != -1)
		input_move_bonus(game, y, x, key);
	return (0);
}
