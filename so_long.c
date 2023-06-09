/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:54:11 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/03 04:07:01 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	fd;
		int	a;
		t_map	map;
		
		a = 0;
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return 1;
		char *line;
		while ((line = get_next_line(fd)) != NULL)
		{
			map.layout[a] = line;
			ft_printf("%s", map.layout[a]);
			free(line);
			a++;
		}
		close(fd);
	}
	return (0);
}
