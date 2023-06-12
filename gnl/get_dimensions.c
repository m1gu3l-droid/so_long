/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:25:53 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/09 21:19:48 by fnovais-         ###   ########.fr       */
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

void	get_dimensions(t_map *game, int fd)
{
	char	*line;
	int	h;
	
	h = 1;
	if ((line = get_next_line(fd)) != NULL)
	{
		game->width = ft_strlen_width((char *)line);
		while ((line = get_next_line(fd)) != NULL)
		{
			if (ft_strchr_gnl(line, 'P') != 0)
				game->player += ft_strchr_gnl(line, 'P');
			if (ft_strchr_gnl(line, 'E') != 0)
				game->exit += ft_strchr_gnl(line, 'E');
			if (ft_strchr_gnl(line, 'C') != 0)
				game->collect += ft_strchr_gnl(line, 'C');
			h++;
		}
	game->height = h;
	game->score = game->collect;
	printf("h: %d\n", game->height);
	printf("w: %d\n", game->width);
	}
}

