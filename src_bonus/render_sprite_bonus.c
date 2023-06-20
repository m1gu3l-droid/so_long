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

void	ft_putenemy(int x, int y, t_game *game)
{
	if ((game->enem.enem_z % 2) == 0)
		mlx_put_image_to_window(game->mlx, game->win,
				game->pics.i_ivared, x * 64, y * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win,
				game->pics.i_ivawhite, x * 64, y * 64);
}

void	sprite_to_map_bonus_2(int x, int y, char c, t_game *game)
{
	if (c == 'b')
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_t, x * 64, y * 64);
	if (c == 'f')
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_tl, x * 64, y * 64);
	if (c == 'g')
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_tr, x * 64, y * 64);
	if (c == 'h')
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_br, x * 64, y * 64);
	if (c == 'v')
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_l, x * 64, y * 64);
	if (c == 'n')
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_r, x * 64, y * 64);
	if (c == 'm')
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_b, x * 64, y * 64);
	if (c == 'j')
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_bl, x * 64, y * 64);
}

void	sprite_to_map_bonus(int x, int y, char c, t_game *game)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_floor, x * 64, y * 64);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_wall, x * 64, y * 64);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_player, x * 64, y * 64);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_collect, x * 64, y * 64);
	if (c == 'E' && game->temp != 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_exit, x * 64, y * 64);
	if (c == 'E' && game->temp == 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_me_food, x * 64, y * 64);
	if (c == 'T')
		ft_putenemy(x, y, game);
	else
		sprite_to_map_bonus_2(x, y, c, game);
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
