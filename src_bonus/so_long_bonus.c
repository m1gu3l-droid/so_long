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

#include "../so_long_bonus.h"
#include <pthread.h>

pthread_mutex_t game_mutex;

void	animation(t_game *game, t_entity *ent)
{
		if (ent->frame == 2)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->pics.i_ivared, ent->pos.x * 64,
				ent->pos.y * 64);
			ent->frame = 3;
		}
		if (ent->frame == 3)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->pics.i_ivared, ent->pos.x * 64,
				ent->pos.y * 64);
			ent->frame = 4;
		}
		if (ent->frame == 4)
		{
			ent->frame = 0;
			return;
		}
		if (ent->frame == 0)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->pics.i_ivawhite, ent->pos.x * 64,
				ent->pos.y * 64);
			ent->frame = 1;
		}
		if (ent->frame == 1)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->pics.i_ivawhite, ent->pos.x * 64,
				ent->pos.y * 64);
			ent->frame = 2;
		}
}

void* animation_thread(void* arg)
{
	pthread_mutex_lock(&game_mutex);
	t_game* game = (t_game*)arg;
	int	i = -1;
	
	while (++i < game->num_tax)
	{
		animation(game, &game->taxes[i]);
	}
	pthread_mutex_unlock(&game_mutex);
	return NULL;
}

void* rendering_thread(void* arg)
{
	pthread_mutex_lock(&game_mutex);
	t_game* game = (t_game*)arg;
	render_sprite_bonus(game);
	pthread_mutex_unlock(&game_mutex);

	return NULL;
}

int update(t_game* game)
{
    // Create the animation thread
    pthread_t animation_thread_id;
    pthread_create(&animation_thread_id, NULL, animation_thread, (void*)game);

    // Perform rendering logic in the main thread
    pthread_mutex_lock(&game_mutex);
    render_sprite_bonus(game);
    pthread_mutex_unlock(&game_mutex);

    // Wait for the animation thread to finish
    pthread_join(animation_thread_id, NULL);

    return 1;
}

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
	pthread_mutex_init(&game_mutex, NULL);
	pthread_t rendering_thread_id;
	pthread_create(&rendering_thread_id, NULL, rendering_thread, (void*)game);
	access_sprite_bonus(game);
	render_sprite_bonus(game);
	mlx_hook(game->win, 02, 1L << 0, control_key_bonus, game);
	mlx_hook(game->win, 17, 1L << 17, closure, game);
	usleep(M_CALLS);
	mlx_loop_hook(game->mlx, update, game);
	usleep(M_CALLS);
	mlx_loop(game->mlx);
	pthread_mutex_destroy(&game_mutex);
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
