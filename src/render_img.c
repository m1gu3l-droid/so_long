/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:54:23 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/10 00:27:22 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	image_to_map(int x, int y, char c, t_map *game)
{
	if (c == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->pics.i_floor, x * 32, y * 32);
	}
	if (c == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->pics.i_wall, x * 32, y * 32);
	}
	if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->pics.i_player, x * 32, y * 32);
	}
	if (c == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->pics.i_collect, x * 32, y * 32);
	}
	if (c == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->pics.i_exit, x * 32, y * 32);
	}
}

void	render_img(t_map *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->height)
	{
		while (x < game->width)
		{
			image_to_map(x, y, game->layout[y][x], game);
			x++;
		}
		x = 0;
		y++;
	}
}
