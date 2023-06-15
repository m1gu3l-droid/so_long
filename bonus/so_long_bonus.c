/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:54:11 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/14 00:49:30 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(t_map *game, int ac, char **av)
{
	int	i;

	i = ft_strlen(av[1]);
	if (ac != 2)
		quit_game("Try: ./so_long [name_of_map_file].ber\n", game);
	if (!(ft_strnstr(av[1] + (i - 4), ".ber", 4)))
	{
		ft_printf("Error\nfile must be .ber\n");
		exit(0);
	}
}

void	start_map(t_map *game)
{
	game->width = 0;
	game->height = 0;
	game->player = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->collect = 0;
	game->val_col = 0;
	game->score = 0;
	game->dying = 0;
	game->temp = 0;
	game->moves = 1;
	game->exit = 0;
}

void	start_game(t_map *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 64,
			game->height * 64, "so_long");
	mlx_hook(game->win, 02, 1L << 0, control_key, game);
	mlx_hook(game->win, 17, 1L << 17, closure, game);
	access_img(game);
	render_img(game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	int		fd_g;
	int		fd_wh;
	t_map	game;

	if (ac == 2)
	{	
		fd_wh = open(av[1], O_RDONLY);
		fd_g = open(av[1], O_RDONLY);
		if (fd_wh == -1 || fd_g == -1)
			return (1);
		check_args(&game, ac, av);
		start_map(&game);
		get_dimensions(&game, fd_wh);
		close(fd_wh);
		read_map(&game, fd_g);
		close(fd_g);
		start_position(&game);
		validations(&game);
		start_game(&game);
	}
	return (0);
}
