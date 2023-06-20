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

#include "../so_long_bonus.h"

void	free_layout(t_game *game)
{
	int	i;

	i = 0;
	while (game->layout[i])
	{
		free(game->layout[i]);
		i++;
	}
	free(game->layout);
}

void	free_layback(t_game *game)
{
	int	i;

	i = 0;
	while (game->lay_back[i])
	{
		free(game->lay_back[i]);
		i++;
	}
	free(game->lay_back);
}

void	free_sprite(t_game *game)
{
	mlx_destroy_image(game->mlx, game->pics.i_exit);
	if (game->pics.i_collect)
		mlx_destroy_image(game->mlx, game->pics.i_collect);
	if (game->pics.i_player)
		mlx_destroy_image(game->mlx, game->pics.i_player);
	if (game->pics.i_wall)
		mlx_destroy_image(game->mlx, game->pics.i_wall);
	if (game->pics.i_floor)
		mlx_destroy_image(game->mlx, game->pics.i_floor);
	if (game->pics.i_me_food)
		mlx_destroy_image(game->mlx, game->pics.i_me_food);
	mlx_destroy_display(game->mlx);
	free_layout(game);
	free(game->mlx);
}

void	quit_game(char *str, t_game *game)
{
	ft_printf("Error\n%s", str);
	if (game->layout[0])
		free_layout(game);
	if (game->path == 0)
		free_layback(game);
	exit(0);
}

int	closure(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_sprite(game);
	if (game->dying == -1)
		ft_printf("-.- game over! -.-\n", game->moves);
	exit(0);
}
