/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:54:11 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/09 21:44:35 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_map(t_map *game)
{
	game->width = 0;
	game->height = 0;
	game->player = 0;
	game->collect = 0;
	game->exit = 0;
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	fd_g;
		int	fd_w;
		int	fd_h;
		t_map	game;
		
		fd_w = open(av[1], O_RDONLY);
		fd_h = open(av[1], O_RDONLY);
		if (fd_w == -1 || fd_h == -1)
			return 1;
//		check_args(&game, ac, av);
		start_map(&game);
		get_width(&game, fd_w);
		close(fd_w);
		get_height(&game, fd_h);
		close(fd_h);
		fd_g = open(av[1], O_RDONLY);
		read_map(&game, fd_g);
		close(fd_g);
	}
	return (0);
}
