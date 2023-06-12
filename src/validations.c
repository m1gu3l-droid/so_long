/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 02:33:04 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/12 03:39:04 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//is rectangular
int	val_rectangular(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = ft_strlen_width(game->layout[j]);
	while (game->layout[++j])
	{
		if (i != ft_strlen_width(game->layout[j]))
			return (1);
	}
	return (0);
}
/* /is bounded
int	val_vault(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->layout[j])
	{
		while (game->layout[j][i])
		{
			if ((j == 0 || j == game->height) && !(ft_strchr(&game->layout[j][i], 1)))
				return (1);
			i++;
		}
		j++;
	}
	i = 0;
	j = 0;
	while (game->layout[j])
	{
		while (game->layout[j][i])
		{
			if ((i == 0 || i == game->width) && !(ft_strchr(&game->layout[j][i], 1)))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
*/
//valid entities: 1 player, 1 exit, 1 or more collectibles
int	val_characters(t_map *game)
{
	if (game->player != 1)
		return (1);
	if (game->exit != 1)
		return (1);
	if (game->collect < 1)
		return (1);
	return (0);
}
//valid path
bool	val_path(t_map *game, char c, int x, int y)
{
	static bool	exit = false;
	int	collect;

	collect = 0;
	if (x < 0 || y < 0)
		return (false);
	if (x > game->width || y > game->height)
		return (false);
	if (game->layout[y][x] == 'E')
		exit = true;
	if (game->layout[y][x] == 'C')
		collect++;
	if (game->layout[y][x] == 'X')
		return (false);
	game->layout[y][x] = 'X';
	
	val_path(game, c, x + 1, y);
	val_path(game, c, x - 1, y);
	val_path(game, c, x, y + 1);
	val_path(game, c, x, y - 1);
	return (collect == game->collect && exit);
}

int	val_path_param(t_map *game)
{
	char	c;
	int	x;
	int	y;
	bool	outcome;
	
	c = game->layout[game->player_y][game->player_x];
	x = game->player_x;
	y = game->player_y;
	outcome = val_path(game, c, x, y);
	return (outcome);
}

void	validations(t_map *game)
{
	if (val_rectangular(game) == 1)
		quit_game("your map should be rectangular\n", game);
//	if (val_vault(game) == 1)
//		quit_game("your map should be surrounded by walls\n", game);
	if (val_characters(game) == 1)
		quit_game("your map should have 1 P, 1 E and 1 or more C's\n", game);
	if (&val_path_param == false)
		quit_game("your map should have a valid path\n", game);
}
