/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dimensions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:42:03 by fnovais-          #+#    #+#             */
/*   Updated: 2023/07/04 02:42:05 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
				game->num_play += ft_strchr_gnl(line, 'P');
			if (ft_strchr_gnl(line, 'E') != 0)
				game->exit += ft_strchr_gnl(line, 'E');
			if (ft_strchr_gnl(line, 'C') != 0)
				game->collect += ft_strchr_gnl(line, 'C');
			if (ft_strchr_gnl(line, 'T') != 0)
				game->num_tax += ft_strchr_gnl(line, 'T');
			h++;
			free(line);
			line = get_next_line(fd);
		}
		game->height = h;
		game->score = game->collect;
	}
}
