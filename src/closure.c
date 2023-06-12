/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closure.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:53:55 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/12 03:38:38 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	quit_game(char *str, t_map *game)
{
	ft_printf("Error\n%s\n", str);
	if (game->layout[0])
		free_map(game);
	exit(0);
}

int	closure(t_map *game)
{
	if (game->layout)
		free_map(game);
	if (game->lay_back)
		free_map(game);
	free_sprite(game);
	free_player(game);
	ft_printf("Game Over!\nMoves: %d\n", game->moves);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
