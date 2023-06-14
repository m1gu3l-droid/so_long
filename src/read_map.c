/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:13:35 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/14 00:54:32 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen_rm(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c] != '\0' && s[c] != '\n')
		c++;
	return (c);
}

void	read_backup(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->lay_back = malloc(sizeof(char *) * game->height + 1);	
	while (i < game->height)
	{
		game->lay_back[i] = malloc(sizeof(char) * ft_strlen_rm(game->layout[i]) + 1);
		while (j < game->width)
		{	
			game->lay_back[i][j] = game->layout[i][j];
			j++;
		}
		j = 0;
		i++;
	}
}

void	read_map(t_map *game, int fd)
{
	char	*line;
	int		i;

	i = 0;
	game->layout = malloc(sizeof(char *) * game->height + 1);
	while ((line = get_next_line(fd)) != NULL)
	{
		game->layout[i] = malloc(sizeof(char) * ft_strlen_rm(line) + 1);
		game->layout[i] = line;
		i++;
	}
	read_backup(game);
}
