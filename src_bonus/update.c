/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:43:28 by fnovais-          #+#    #+#             */
/*   Updated: 2023/07/04 02:43:31 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	delay_factor(int val)
{
	if (val < 100)
		return (50 + (val - 1) * (5000 - 4000) / ((500 - 1) + 5000));
	else
		return (30 + (val - 1) * (5000 - 4000) / ((500 - 1) + 5000));
}

void	animation(t_game *game, t_entity *ent)
{
	if (ent->frame == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_ivared, ent->pos.x * 64,
			ent->pos.y * 64);
		ent->frame = 0;
		return ;
	}
	if (ent->frame == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_ivawhite, ent->pos.x * 64,
			ent->pos.y * 64);
		ent->frame = 1;
		return ;
	}
}

void	coins_counter(t_game *game)
{
	char	*mvs;
	char	*str;

	str = "$";
	mvs = ft_itoa(game->collect - game->score);
	if (game->collect != game->collect - game->score)
	{
		mlx_string_put(game->mlx, game->win, 10,
			95, 0x00FFFE61, str);
		mlx_string_put(game->mlx, game->win, 20,
			95, 0x00FFFFFF, mvs);
	}
	else
	{
		mlx_string_put(game->mlx, game->win, 15,
			88, 0x00FFFE61, "BUY");
		mlx_string_put(game->mlx, game->win, 15,
			108, 0x00FFFE61, "FOOD");
	}
	free(mvs);
}

int	update(t_game *game)
{
	int	i;
	int	delay;
	int	factor;

	i = -1;
	factor = 0;
	while (++i < game->num_tax)
		animation(game, &game->taxes[i]);
	factor = delay_factor(game->num_tax);
	delay = M_CALLS * factor;
	usleep(delay);
	return (1);
}
