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
		mlx_put_image_to_window(game->mlx, game->win, game->pics.i_floor, x, y);
	}
	if (c == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->pics.i_wall, x, y);
	}
	if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->pics.i_player, x, y);
	}
	if (c == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->pics.i_collect, x, y);
	}
	if (c == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->pics.i_exit, x, y);
	}
}

void	render_img(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->height)
	{
		while (j < game->width)
		{
			image_to_map(j, i, game->layout[i][j], game);
			j++;
		}
		i++;
	}
}
