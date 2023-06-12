/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:54:12 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/10 00:21:12 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	access_img(t_map *game)
{
	int	len;

	len = 32;
	game->pics.i_wall = mlx_xpm_file_to_image(game->mlx, WALL, &len, &len);
	game->pics.i_floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &len, &len);
	game->pics.i_player = mlx_xpm_file_to_image(game->mlx, PLAYER, &len, &len);
	game->pics.i_exit = mlx_xpm_file_to_image(game->mlx, EXIT, &len, &len);
	game->pics.i_collect = mlx_xpm_file_to_image(game->mlx, COLLECT, &len, &len);
}
