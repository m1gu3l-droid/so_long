/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:13:35 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/09 21:22:35 by fnovais-         ###   ########.fr       */
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

void	read_map(t_map *game, int fd)
{
	char	*line;
	int	i;

	i = 0;
	game->layout = malloc(sizeof(char*) * game->height + 1);
	while ((line = get_next_line(fd)) != NULL)
	{
		game->layout[i] = malloc(sizeof(char) * ft_strlen_rm(line) + 1);
		game->layout[i] = line;
		ft_printf("line %d: %s", i, game->layout[i]);
		i++;
	}
}
