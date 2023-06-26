/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 02:53:10 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/20 02:53:22 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	delay_factor(int val, int min, int max, int out_min, int out_max)
{
	if (val < 100 )
	 	return (30 + (val - min) * (out_max - out_min) / ((max - min) + out_max));
	else
		return (30 + (val - min) * (out_max - out_min) / ((max - min) + out_max));
}

void animation(t_game *game, t_entity *ent)
{
	if (ent->frame == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_ivared, ent->pos.x * 64,
			ent->pos.y * 64);
		ent->frame = 0;
		return;
	}
/*	if (ent->frame == 3)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_ivared, ent->pos.x * 64,
			ent->pos.y * 64);
		ent->frame = 4;
	}
	if (ent->frame == 4)
	{
		ent->frame = 5;
		return;
	}
	if (ent->frame == 5)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_ivawhite, ent->pos.x * 64,
			ent->pos.y * 64);
		ent->frame = 0;
	}
*/	if (ent->frame == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_ivawhite, ent->pos.x * 64,
			ent->pos.y * 64);
		ent->frame = 1;
		return;
	}
/*	if (ent->frame == 1)
	{
		ent->frame = 2;
		return;
	}*/
}

int update(t_game* game)
{
	int	i;
	int	delay;
	int	min;
	int	max;
	int	min_del;
	int	max_del;
	int	factor;
	
	i = -1;
	min = 1;
	max = 500;
	min_del = 4000;
	max_del = 5000;
	factor = 0;
	while (++i < game->num_tax)
	{
		animation(game, &game->taxes[i]);
	}
	factor = delay_factor(game->num_tax, min, max, min_del, max_del);
	delay = M_CALLS * factor;
	render_sprite_bonus(game);
	usleep(delay);
	return 1;
}
