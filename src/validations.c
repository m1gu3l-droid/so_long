/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 02:33:04 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/27 20:18:27 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	val_rectangular(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = ft_strlen_width(game->layout[j]);
	while (j < game->height)
	{
		if (i != ft_strlen_width(game->layout[j]))
			return (1);
		j++;
	}
	return (0);
}

int	val_vault(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->height)
	{
		while (i < game->width)
		{
			if (j == 0 || j == game->height - 1)
			{
				if (game->layout[j][i] != '1')
					return (1);
			}
			if (i == 0 || i == game->width - 1)
			{
				if (game->layout[j][i] != '1')
					return (1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	val_char(t_game *game)
{
	int	i;
	int	j;

i = 0;
	j = 0;
	while (j < game->height)
	{
		while (i < game->width)
		{
			if (game->layout[j][i] != '1' && game->layout[j][i] != '0'
				&& game->layout[j][i] != 'C' && game->layout[j][i] != 'P'
					&& game->layout[j][i] != 'E')
				return (1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	val_characters(t_game *game)
{
	if (game->player != 1)
		return (1);
	if (game->exit != 1)
		return (1);
	if (game->collect < 1)
		return (1);
	return (0);
}

void	validations(t_game *game)
{
	if (val_rectangular(game) == 1)
		quit_game("your map should be rectangular\n", game);
	if (val_vault(game) == 1)
		quit_game("your map should be surrounded by walls\n", game);
	if (val_characters(game) == 1)
		quit_game("your map should have 1 P, 1 E and 1 or more C's\n", game);
	if (val_char(game) == 1)
		quit_game("your map has unkown characters\n", game);
	if (val_path_param(game) == false)
		quit_game("your map should have a valid path\n", game);
}
