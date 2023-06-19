/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:54:12 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/14 00:59:11 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	access_sprite_bonus(t_game *game)
{
	int	len;

	len = 64;
	game->pics.i_wall = mlx_xpm_file_to_image(game->mlx, WALL, &len, &len);
	game->pics.i_floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &len, &len);
	game->pics.i_player = mlx_xpm_file_to_image(game->mlx, PLAYER, &len, &len);
	game->pics.i_exit = mlx_xpm_file_to_image(game->mlx, EXIT, &len, &len);
	game->pics.i_collect = mlx_xpm_file_to_image(game->mlx, COL, &len, &len);
	game->pics.i_tr = mlx_xpm_file_to_image(game->mlx, GTR, &len, &len);
	game->pics.i_tl = mlx_xpm_file_to_image(game->mlx, FTL, &len, &len);
	game->pics.i_br = mlx_xpm_file_to_image(game->mlx, HBR, &len, &len);
	game->pics.i_bl = mlx_xpm_file_to_image(game->mlx, JBL, &len, &len);
	game->pics.i_l = mlx_xpm_file_to_image(game->mlx, VL, &len, &len);
	game->pics.i_r = mlx_xpm_file_to_image(game->mlx, NR, &len, &len);
	game->pics.i_t = mlx_xpm_file_to_image(game->mlx, BT, &len, &len);
	game->pics.i_b = mlx_xpm_file_to_image(game->mlx, MB, &len, &len);	
}
