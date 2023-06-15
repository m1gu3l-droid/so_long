/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 02:22:52 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/12 02:27:42 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **lay)
{
	(void)lay;
}

void	free_sprite(t_map *game)
{
	mlx_destroy_image(game->mlx, game->pics.i_player);
//	mlx_destroy_image(game->mlx, game->pics.i_exit);
//	mlx_destroy_image(game->mlx, game->pics.i_collect);
//	mlx_destroy_image(game->mlx, game->pics.i_wall);
//	mlx_destroy_image(game->mlx, game->pics.i_floor);
//	mlx_destroy_image(game->mlx, game->pics.i_me_food);
}

void	free_player(t_map *game)
{
	(void)game;
}
