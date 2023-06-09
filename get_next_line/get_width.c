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

int	ft_strlen_width(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

void	get_width(t_map *game, int fd)
{
	int		w;
//	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return;
	buffer = read_line(fd, buffer);
	if (!buffer)
		return;
	w = ft_strlen_width((char *)buffer);
	game->width = w;
}
