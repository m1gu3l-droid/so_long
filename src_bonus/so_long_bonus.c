/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:43:07 by fnovais-          #+#    #+#             */
/*   Updated: 2023/07/04 02:43:09 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_args(char **av)
{
	int	i;

	i = ft_strlen(av[1]);
	if (!(ft_strnstr(av[1] + (i - 4), ".ber", 4)))
	{
		ft_printf("Error\nfile must be .ber\n");
		exit(0);
	}
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 64,
			game->height * 64, "so_long");
	access_sprite_bonus(game);
	render_sprite_bonus(game);
	mlx_hook(game->win, 02, 1L << 0, control_key_bonus, game);
	mlx_hook(game->win, 17, 1L << 17, closure, game);
	mlx_loop_hook(game->mlx, update, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	int		fd_g;
	int		fd_wh;
	t_game	game;

	if (ac != 2)
		ft_printf("Error\nTry: ./so_long [name_of_map_file].ber\n");
	if (ac == 2)
	{
		check_args(av);
		start_map(&game);
		fd_wh = open(av[1], O_RDONLY);
		fd_g = open(av[1], O_RDONLY);
		if (fd_wh == -1 || fd_g == -1)
			return (1);
		get_dimensions(&game, fd_wh);
		close(fd_wh);
		read_map(&game, fd_g);
		start_entities(&game);
		close(fd_g);
		start_position(&game);
		validations(&game);
		start_game(&game);
	}
	return (0);
}
