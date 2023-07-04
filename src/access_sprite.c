/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:44:23 by fnovais-          #+#    #+#             */
/*   Updated: 2023/07/04 02:44:25 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	access_sprite(t_game *game)
{
	int	len;

	len = 64;
	game->pics.i_wall = mlx_xpm_file_to_image(game->mlx, WALL, &len, &len);
	game->pics.i_floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &len, &len);
	game->pics.i_player = mlx_xpm_file_to_image(game->mlx, PLAYER, &len, &len);
	game->pics.i_exit = mlx_xpm_file_to_image(game->mlx, EXIT, &len, &len);
	game->pics.i_collect = mlx_xpm_file_to_image(game->mlx, COL, &len, &len);
	game->pics.i_me_food = mlx_xpm_file_to_image(game->mlx, MFD, &len, &len);
}
