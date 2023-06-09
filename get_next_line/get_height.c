/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:25:53 by fnovais-          #+#    #+#             */
/*   Updated: 2022/11/28 18:07:01 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../so_long.h"

void	get_height(t_map *game, int fd)
{
	char	*line;
	int	h;
	int	p;
	int	e;
	int	c;
	
	h = 0;
	p = 0;
	e = 0;
	c = 0;
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
}
/*
void	get_height(t_map *game, int fd)
{
	char	*line;
	int	h;
	
	h = 0;
	while ((line = get_next_line(fd)) != NULL)
		h++;
	game->height = h;
}
*/
