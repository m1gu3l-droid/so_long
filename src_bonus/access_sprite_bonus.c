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
	game->pics.i_me_food = mlx_xpm_file_to_image(game->mlx, MFD, &len, &len);
	game->pics.i_ivared = mlx_xpm_file_to_image(game->mlx, I_R, &len, &len);
	game->pics.i_ivawhite = mlx_xpm_file_to_image(game->mlx, I_W, &len, &len);
	game->pics.p_left = mlx_xpm_file_to_image(game->mlx, M_L, &len, &len);
	game->pics.p_right = mlx_xpm_file_to_image(game->mlx, M_R, &len, &len);
	game->pics.p_up = mlx_xpm_file_to_image(game->mlx, M_U, &len, &len);
	game->pics.p_down = mlx_xpm_file_to_image(game->mlx, M_D, &len, &len);
}
