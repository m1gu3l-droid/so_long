/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:54:23 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/20 02:52:09 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	render(t_game *game, t_img *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		img, x * 64, y * 64);
}

void	ft_putplayer(int x, int y, t_game *game)
{
	if (game->direction == W || game->direction == KUP)
		render(game, game->pics.p_up, x, y);
	else if (game->direction == S || game->direction == KDOWN)
		render(game, game->pics.p_down, x, y);
	else if (game->direction == A || game->direction == KLEFT)
		render(game, game->pics.p_left, x, y);
	else if (game->direction == D || game->direction == KRIGHT)
		render(game, game->pics.p_right, x, y);
	else
		render(game, game->pics.i_player, x, y);
}

void	sprite_to_map_bonus(int x, int y, char c, t_game *game)
{
	if (c == '0')
		render(game, game->pics.i_floor, x, y);
	if (c == '1')
		render(game, game->pics.i_wall, x, y);
	if (c == 'P')
		ft_putplayer(x, y, game);
	if (c == 'C')
		render(game, game->pics.i_collect, x, y);
	if (c == 'E' && game->temp != 1)
		render(game, game->pics.i_exit, x, y);
	if (c == 'E' && game->temp == 1)
		render(game, game->pics.i_me_food, x, y);
}

void	render_sprite_bonus(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->height)
	{
		while (x < game->width)
		{
			sprite_to_map_bonus(x, y, game->layout[y][x], game);
			x++;
		}
		x = 0;
		y++;
	}
}
