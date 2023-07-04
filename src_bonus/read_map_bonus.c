/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:42:44 by fnovais-          #+#    #+#             */
/*   Updated: 2023/07/04 02:42:46 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

size_t	ft_strlen_rm(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c] != '\0' && s[c] != '\n')
		c++;
	return (c);
}

void	read_backup(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = game->height + 1;
	game->lay_back = malloc(sizeof(char *) * j);
	if (!game->lay_back)
		quit_game("Error\n", game);
	while (i < j)
	{
		game->lay_back[i] = ft_strtrim(game->layout[i], "\0");
		i++;
	}
}

void	read_map(t_game *game, int fd)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = game->height + 1;
	game->layout = (char **)malloc(sizeof(char *) * j);
	if (!game->layout)
		quit_game("Error\n", game);
	while (i < j)
	{
		line = get_next_line(fd);
		game->layout[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	read_backup(game);
}
