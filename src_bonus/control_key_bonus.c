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

void	end_game(t_game *game, int a)
{
	if (a == 2)
	{
		ft_printf("move: %d\n-.- yey, you bought food! -.- \n", game->moves);
		closure(game);
	}
	if (a == 3)
	{
		ft_printf("-.- nothing is certain, but death and taxes -.- \n");
		closure(game);
	}
	if (a == 4)
	{
		ft_printf("-.- not able to charge taxes -.- \n");
		closure(game);
	}
}

int	val_move_bonus(t_game *game, int y, int x, int key)
{
	if (key != W && key != S && key != A && key != D && key != KUP
		&& key != KDOWN && key != KLEFT && key != KRIGHT)
		return (-1);
	if (game->layout[y][x] == '1')
		return (-1);
	if (game->layout[y][x] == 'C')
		game->score--;
	if (game->score > 0 && game->layout[y][x] == 'E')
		game->temp = 1;
	if (game->score == 0 && game->layout[y][x] == 'E')
		end_game(game, 2);
	if (game->layout[y][x] == 'T')
		end_game(game, 3);
	return (0);
}

void	input_move_bonus(t_game *game, int x, int y, int key)
{
	int	outcome;

	outcome = val_move_bonus(game, y, x, key);
	if (outcome != -1)
	{
		game->direction = key;
		game->me.pos.y = y;
		game->me.pos.x = x;
		if (game->temp != 1 || game->layout[y][x] == 'E')
			game->layout[game->me.pre.y][game->me.pre.x] = '0';
		if (game->temp == 1 && game->layout[y][x] != 'E')
		{
			game->layout[game->me.pre.y][game->me.pre.x] = 'E';
			game->temp = 0;
		}
		if (game->layout[y][x] != 'E')
			game->layout[y][x] = 'P';
		if (game->layout[y][x] == 'E')
			game->layout[y][x] = 'E';
//		render_sprite_bonus(game);
	}
}

int	control_key_bonus(int key, t_game *game)
{
	int	y;
	int	x;
	
	if (game->me.pos.y > 0 && game->me.pos.y < game->height)
		game->me.pre.y = game->me.pos.y;
	if (game->me.pos.x > 0 && game->me.pos.x < game->width)
		game->me.pre.x = game->me.pos.x;
	y = game->me.pre.y;
	x = game->me.pre.x;
	if (key == ESC)
	{
		game->dying = -1;
		closure(game);
	}
	if (key == W || key == KUP)
		y--;
	if (key == S || key == KDOWN)
		y++;
	if (key == A || key == KLEFT)
		x--;
	if (key == D || key == KRIGHT)
		x++;
	if (game->dying != -1)
		input_move_bonus(game, x, y, key);
	return (0);
}
