/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:25:53 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/15 05:10:52 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen_width(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

void	get_dimensions(t_game *game, int fd)
{
	char	*line;
	int		h;

	h = 0;
	line = get_next_line(fd);
	if (line != NULL)
	{
		game->width = ft_strlen_width((char *)line);
		while (line != NULL)
		{
			if (ft_strchr_gnl(line, 'P') != 0)
				game->player += ft_strchr_gnl(line, 'P');
			if (ft_strchr_gnl(line, 'E') != 0)
				game->exit += ft_strchr_gnl(line, 'E');
			if (ft_strchr_gnl(line, 'C') != 0)
				game->collect += ft_strchr_gnl(line, 'C');
			h++;
			free(line);
			line = get_next_line(fd);
		}
		game->height = h;
		game->score = game->collect;
	}
	free(line);
}
