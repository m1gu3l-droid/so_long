/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:38:24 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/09 23:44:23 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start_position(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->layout[i])
	{
		while (game->layout[i][j])
		{	
			if (game->layout[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
	ft_printf("player: %d, %d\n", game->player_x, game->player_y);
}
