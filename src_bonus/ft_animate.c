/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 02:42:35 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/20 02:52:04 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	animate(t_game *game)
{
	int	c;

	c = game->player_x * game->player_y;
	ft_putenemy(game->enem_x, game->enem_y, c, game);
}
