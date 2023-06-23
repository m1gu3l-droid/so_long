/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 02:53:10 by fnovais-          #+#    #+#             */
/*   Updated: 2023/06/20 02:53:22 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
#include <unistd.h>
#include <time.h>
#include <pthread.h>

typedef struct {
	t_game *game;
	t_entity *ent;
} ThreadData;

void* animation_thread(void* arg)
{
	ThreadData* data = (ThreadData*)arg;
	t_game* game = data->game;
	t_entity* ent = data->ent;

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
		return NULL;
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
	return NULL;
}

void* render_sprite_bonus_thread(void* arg)
{
	t_game* game = (t_game*)arg;

	render_sprite_bonus(game);

	return NULL;
}

int update(t_game* game)
{
	pthread_t thread;
	ThreadData data;
	int i = -1;

	while (++i < game->num_tax)
	{
		data.game = game;
		data.ent = &game->taxes[i];

		// Create thread for the animation function
		if (pthread_create(&thread, NULL, animation_thread, (void*)&data) != 0)
		{
			fprintf(stderr, "Failed to create the animation thread\n");
			return 0;
		}
		usleep(M_CALLS - game->num_tax);
		// Call the render_sprite_bonus function concurrently
		render_sprite_bonus_thread((void*)game);
		// Wait for the animation thread to finish
		pthread_join(thread, NULL);
	}

	return 1;
}

/*
#include "../so_long_bonus.h"
#include <unistd.h>
#include <time.h>
#include <pthread.h>

void*	animation(t_game *game, t_entity *ent)
{

	ThreadData* data = (ThreadData*)arg;
	t_game game = data->game;
	if (ent->frame == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->pics.i_ivared, ent->pos.x * 64, 
				ent->pos.y * 64);
		ent->frame = 2;
	}
	if (ent->frame == 2)
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
//	usleep(M_CALLS);
}

int	update(t_game *game)

{
	pthread_t	thread;
	ThreadData data;
	
	data.game = t_game_initialization();
	if (pthread_create(&thread, NULL, animation, (void*)&data) != 0)
	{
		fprintf(stderr, "Failed\n");
		return (1);
	}
	render_sprite_bonus((void*)&data);
	pthread_join(thread, NULL);
	return (0);
}

{
	int	i = -1;
	while (++i < game->num_tax)
	{
		animation(game, &game->taxes[i]);
		usleep(M_CALLS);
	}
	render_sprite_bonus(game);
	return (1);
}
*/
